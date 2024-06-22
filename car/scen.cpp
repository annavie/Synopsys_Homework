#include "scen.h"
#include <QPainter>
#include <QKeyEvent>
#include <QDebug>

RacingScene::RacingScene(QWidget *parent) : QWidget(parent), m_car(new Car()), m_rotationSpeed(0.1) {}

RacingScene::~RacingScene() {
    delete m_car;
}

void RacingScene::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.fillRect(trackRect, Qt::green); // Draw the racing track
    drawCar(painter);
}

void RacingScene::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_Left:
        m_car->rotateLeft(m_rotationSpeed);
        break;
    case Qt::Key_Right:
        m_car->rotateRight(m_rotationSpeed);
        break;
    case Qt::Key_Up:
        m_car->moveForward();
        break;
    case Qt::Key_Down:
        m_car->moveBackward();
        break;
    }
    update();
}

void RacingScene::drawCar(QPainter &painter) {
    painter.save();
    painter.translate(m_car->x(), m_car->y());
    painter.rotate(-m_car->angle() * 180 / M_PI); // Convert radians to degrees

    // Load car image
    QImage carImage(":/img/images/car.png");
    if (carImage.isNull()) {
        qDebug() << "Failed to load car image";
        return;
    }

    // Draw car image
    painter.drawImage(-carImage.width() / 2, -carImage.height() / 2, carImage);

    painter.restore();
}
