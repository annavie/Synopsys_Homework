#ifndef CARWIDGETANDCAR_H
#define CARWIDGETANDCAR_H

#include <QWidget>
#include <QImage>
#include <QPointF>
#include <QTimer>
#include <deque>

class Car {
public:
    Car(const QString &imagePath, const QPointF &startPosition);

    void moveForward();
    void moveBackward();
    void steerLeft();
    void steerRight();

    QPointF getPosition() const;
    QImage getImage() const;
    float getRotation() const;

private:
    QImage carImage;
    QPointF position;
    float rotation; // Degrees
    const float moveSpeed = 5.0;
    const float rotationSpeed = 5.0;
};
class CarWidget : public QWidget {
    Q_OBJECT

public:
    CarWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private slots:
    void updatePosition();

private:
    void ensureCarInBounds();

    Car *car;
    QTimer *timer;
    bool kLeft, kRight, kUp, kDown;
    QRect boardBounds; // Define the boundaries of the board
};

#endif // CARWIDGETANDCAR_H
