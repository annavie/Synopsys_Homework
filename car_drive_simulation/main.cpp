#include <QApplication>
#include "car.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    CarWidget widget;
    widget.show();

    return app.exec();
}
