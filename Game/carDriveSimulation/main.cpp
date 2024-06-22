#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>
#include <QPixmap>
#include <QLabel>
#include <QMessageBox>
#include <QMediaPlayer>
#include <QElapsedTimer>

class CarGame : public QWidget {
    Q_OBJECT

public:
    CarGame(QWidget *parent = nullptr) : QWidget(parent), speed(0), direction(0), winCondition(None) {
        carImage.load("images/car.png");
        padImage.load("images/race_pads.png");
        hitImage.load("images/collision.png");
        trophyImage.load("images/trophy.png");

        carPos = QPointF(10, 730);
        initPads();
        initTrophies();

        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &CarGame::updateGame);
        timer->start(30);

        elapsedTimer.start();
        setFixedSize(1024, 768);
        setFocus();
    }

protected:
    void paintEvent(QPaintEvent *event) override {
        QPainter painter(this);

        if (winCondition == None) {
            painter.drawPixmap(carPos, carImage.transformed(QTransform().rotate(direction)));
        } else if (winCondition == Crash) {
            painter.drawPixmap(carPos, hitImage);
        }

        for (const auto &pad : pads) {
            painter.drawPixmap(pad, padImage);
        }

        for (const auto &trophy : trophies) {
            painter.drawPixmap(trophy, trophyImage);
        }

        QString timerText = QString::number(20 - elapsedTimer.elapsed() / 1000.0, 'f', 2);
        painter.setPen(Qt::yellow);
        painter.setFont(QFont("Arial", 75));
        painter.drawText(20, 60, timerText);

        if (winCondition == Crash) {
            painter.setPen(Qt::red);
            painter.drawText(250, 700, "Press Space to Retry");
        } else if (winCondition == Win) {
            painter.setPen(Qt::green);
            painter.drawText(250, 700, "Press Space to Advance");
        }
    }

    void keyPressEvent(QKeyEvent *event) override {
        if (winCondition == None) {
            switch (event->key()) {
            case Qt::Key_Right: kRight = -5; break;
            case Qt::Key_Left: kLeft = 5; break;
            case Qt::Key_Up: kUp = 2; break;
            case Qt::Key_Down: kDown = -2; break;
            case Qt::Key_Escape: qApp->quit(); break;
            }
        } else if (event->key() == Qt::Key_Space) {
            if (winCondition == Win) {
                // Start level 2
            } else if (winCondition == Crash) {
                // Restart level 1
                resetGame();
            }
        } else if (event->key() == Qt::Key_Escape) {
            qApp->quit();
        }
    }

    void keyReleaseEvent(QKeyEvent *event) override {
        switch (event->key()) {
        case Qt::Key_Right: kRight = 0; break;
        case Qt::Key_Left: kLeft = 0; break;
        case Qt::Key_Up: kUp = 0; break;
        case Qt::Key_Down: kDown = 0; break;
        }
    }

private slots:
    void updateGame() {
        float rad = qDegreesToRadians(direction);
        carPos.rx() += -speed * sin(rad);
        carPos.ry() += -speed * cos(rad);
        speed += (kUp + kDown);
        if (speed > 10) speed = 10;
        if (speed < -10) speed = -10;
        direction += (kRight + kLeft);

        checkCollisions();
        update();
    }

private:
    enum WinCondition { None, Crash, Win };

    QPixmap carImage;
    QPixmap padImage;
    QPixmap hitImage;
    QPixmap trophyImage;

    QPointF carPos;
    QVector<QPointF> pads;
    QVector<QPointF> trophies;

    float speed;
    float direction;
    int kLeft, kRight, kUp, kDown;
    QTimer *timer;
    QElapsedTimer elapsedTimer;
    WinCondition winCondition;

    void initPads() {
        pads = {
            {0, 10}, {600, 10}, {1100, 10}, {100, 150},
            {600, 150}, {100, 300}, {800, 300}, {400, 450},
            {700, 450}, {200, 600}, {900, 600}, {400, 750},
            {800, 750}
        };
    }

    void initTrophies() {
        trophies = {{285, 0}};
    }

    void checkCollisions() {
        for (const auto &pad : pads) {
            if (QRectF(carPos, carImage.size()).intersects(QRectF(pad, padImage.size()))) {
                winCondition = Crash;
                speed = 0;
                return;
            }
        }

        for (auto it = trophies.begin(); it != trophies.end(); ++it) {
            if (QRectF(carPos, carImage.size()).intersects(QRectF(*it, trophyImage.size()))) {
                winCondition = Win;
                trophies.erase(it);
                return;
            }
        }

        if (elapsedTimer.elapsed() > 20000) {
            winCondition = Crash;
        }
    }

    void resetGame() {
        carPos = QPointF(10, 730);
        speed = direction = 0;
        kLeft = kRight = kUp = kDown = 0;
        winCondition = None;
        elapsedTimer.restart();
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    CarGame game;
    game.show();
    return app.exec();
}
