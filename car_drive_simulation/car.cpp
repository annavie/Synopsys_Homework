#include "car.h"
#include <QPainter>
#include <QKeyEvent>
#include <QtMath>

// Car implementation

Car::Car(const QString &imagePath, const QPointF &startPosition)
    : position(startPosition), rotation(0.0) {
    carImage.load(imagePath);
}

void Car::moveForward() {
    position.rx() += moveSpeed * qCos(qDegreesToRadians(rotation));
    position.ry() -= moveSpeed * qSin(qDegreesToRadians(rotation));
}

void Car::moveBackward() {
    position.rx() -= moveSpeed * qCos(qDegreesToRadians(rotation));
    position.ry() += moveSpeed * qSin(qDegreesToRadians(rotation));
}

void Car::steerLeft() {
    rotation -= rotationSpeed;
    if (rotation < 0) rotation += 360;
}

void Car::steerRight() {
    rotation += rotationSpeed;
    if (rotation >= 360) rotation -= 360;
}

QPointF Car::getPosition() const {
    return position;
}

QImage Car::getImage() const {
    return carImage;
}

float Car::getRotation() const {
    return rotation;
}

// CarWidget implementation

CarWidget::CarWidget(QWidget *parent)
    : QWidget(parent), kLeft(false), kRight(false), kUp(false), kDown(false) {
    car = new Car(":/car/car.png", QPointF(100, 100));

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &CarWidget::updatePosition);
    timer->start(30);

    setFixedSize(800, 600);
    setFocus();
}

void CarWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    // Draw the board
    painter.setPen(Qt::black);
    painter.drawRect(50, 50, 700, 500); // Board boundaries

    // Draw the car
    QImage carImage = car->getImage();
    QTransform transform;
    transform.translate(car->getPosition().x() + carImage.width() / 2,
                        car->getPosition().y() + carImage.height() / 2);
    transform.rotate(car->getRotation());
    transform.translate(-carImage.width() / 2, -carImage.height() / 2);

    painter.setTransform(transform);
    painter.drawImage(0, 0, carImage);
}

void CarWidget::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_Left: kLeft = true; break;
    case Qt::Key_Right: kRight = true; break;
    case Qt::Key_Up: kUp = true; break;
    case Qt::Key_Down: kDown = true; break;
    }
}

void CarWidget::keyReleaseEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_Left: kLeft = false; break;
    case Qt::Key_Right: kRight = false; break;
    case Qt::Key_Up: kUp = false; break;
    case Qt::Key_Down: kDown = false; break;
    }
}

void CarWidget::updatePosition() {
    if (kLeft) car->steerLeft();
    if (kRight) car->steerRight();
    if (kUp) car->moveForward();
    if (kDown) car->moveBackward();

    ensureCarInBounds(); // Ensure the car stays within the bounds after each movement
    update();
}

void CarWidget::ensureCarInBounds() {
    // Get the dimensions of the board
    int minX = 50;
    int minY = 50;
    int maxX = 750;
    int maxY = 550;

    // Get the dimensions of the car
    int carWidth = car->getImage().width();
    int carHeight = car->getImage().height();

    // Ensure the car stays within the bounds
    if (car->getPosition().x() < minX) {
        car->getPosition().setX(minX);
    }
    if (car->getPosition().x() + carWidth > maxX) {
        car->getPosition().setX(maxX - carWidth);
    }
    if (car->getPosition().y() < minY) {
        car->getPosition().setY(minY);
    }
    if (car->getPosition().y() + carHeight > maxY) {
        car->getPosition().setY(maxY - carHeight);
    }
}
