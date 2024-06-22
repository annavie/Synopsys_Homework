#ifndef CAR_H
#define CAR_H

#include <cmath>
#include <algorithm>

class Car {
public:
    Car(int x = 100, int y = 400, double angle = 0, double speed = 5);

    void moveForward();
    void moveBackward();
    void rotateLeft(double rotationSpeed);
    void rotateRight(double rotationSpeed);

    int x() const;
    int y() const;
    double angle() const;

private:
    int m_x;
    int m_y;
    double m_angle; // Angle in radians
    double m_speed;

    static constexpr int trackLeftBound = 50;
    static constexpr int trackRightBound = 450;
    static constexpr int trackTopBound = 50;
    static constexpr int trackBottomBound = 650;

    void ensureWithinBounds();
};

#endif // CAR_H
