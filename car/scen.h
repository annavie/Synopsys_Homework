#ifndef RACINGSCENE_H
#define RACINGSCENE_H

#include <QWidget>
#include <QPainter>
#include <QKeyEvent>
#include "car.h"

class RacingScene : public QWidget {
    Q_OBJECT
public:
    RacingScene(QWidget *parent = nullptr);
    ~RacingScene();

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    QRect trackRect;
    Car *m_car;
    double m_rotationSpeed;

    void drawCar(QPainter &painter);

    static constexpr int carWidth = 60;
    static constexpr int carHeight = 30;
    static constexpr int wheelRadius = 10;
};

#endif // RACINGSCENE_H
