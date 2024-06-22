#ifndef MYREACT_H
#define MYREACT_H
#include<QGraphicsRectItem>
#include<QKeyEvent>
class myReact: public QGraphicsRectItem
{
public:
    void keyPressEvent(QKeyEvent* event);
};

#endif // MYREACT_H
