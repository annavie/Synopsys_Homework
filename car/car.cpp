#include "car.h"
Car::Car(int x, int y, double angle, double speed)
    : m_x(x), m_y(y), m_angle(angle), m_speed(speed) {
    m_angle = M_PI / 2; // Set default angle to face upwards
}

void Car::moveForward() {
    m_x += m_speed * cos(m_angle);
    m_y -= m_speed * sin(m_angle); // y-axis is inverted in Qt
    ensureWithinBounds();
}

void Car::moveBackward() {
    m_x -= m_speed * cos(m_angle);
    m_y += m_speed * sin(m_angle); // y-axis is inverted in Qt
    ensureWithinBounds();
}

void Car::rotateLeft(double rotationSpeed) {
    m_angle += rotationSpeed;
}

void Car::rotateRight(double rotationSpeed) {
    m_angle -= rotationSpeed;
}

int Car::x() const {
    return m_x;
}

int Car::y() const {
    return m_y;
}

double Car::angle() const {
    return m_angle;
}

void Car::ensureWithinBounds() {
    m_x = std::clamp(m_x, trackLeftBound, trackRightBound);
    m_y = std::clamp(m_y, trackTopBound, trackBottomBound);
}
