#include "car.h"

Car::Car(int num_checkpoint, const int points[8][2], QWidget* parent)
    : QWidget(parent),
    speed(2), m_corner(0), n(0)
{
    num_checkpoints = num_checkpoint;
    for (int i = 0; i < num_checkpoints; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            point[i][j] = points[i][j];
        }
    }
}

void Car::move()
{
    m_x += sin(m_corner) * speed;
    m_y -= cos(m_corner) * speed;
}

void Car::findTarget()
{
    float tx = point[n][0];
    float ty = point[n][1];
    float beta = m_corner - atan2(tx - m_x, -ty + m_y);
    if (sin(beta) < 0)
    {
        m_corner += 0.005 * speed;
    }
    else
    {
        m_corner -= 0.005 * speed;
    }
    if ((m_x - tx) * (m_x - tx) + (m_y - ty) * (m_y - ty) < 25 * 25)
    {
        n = (n + 1) % num_checkpoints;
    }
}

void Car::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setBrush(Qt::blue);
    painter.drawRect(-15, -25, 30, 50);
}
