#include <QApplication>
#include "scen.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    RacingScene game;
    game.setWindowTitle("Car Racing Game");
    game.setGeometry(100, 100, 500, 700);
    game.show();
    return app.exec();
}
