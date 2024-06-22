#include "myreact.h"
#include <cmath> // Include <cmath> for trigonometric functions

void myReact::keyPressEvent(QKeyEvent *event)
{
    const qreal turnSpeed = 5.0; // Adjust this value for the turning speed
    const qreal moveSpeed = 10.0; // Adjust this value for the movement speed
    qreal angle = rotation();

    if (event->key() == Qt::Key_Left) {
        angle -= turnSpeed;
        setRotation(angle);
    } else if (event->key() == Qt::Key_Right) {
        angle += turnSpeed;
        setRotation(angle);
    } else if (event->key() == Qt::Key_Up) {
        qreal radAngle = qDegreesToRadians(angle);
        qreal dx = moveSpeed * qSin(radAngle);
        qreal dy = -moveSpeed * qCos(radAngle);
        setPos(x() + dx, y() + dy);
    } else if (event->key() == Qt::Key_Down) {
        qreal radAngle = qDegreesToRadians(angle);
        qreal dx = -moveSpeed * qSin(radAngle);
        qreal dy = moveSpeed * qCos(radAngle);
        setPos(x() + dx, y() + dy);
    }
}
