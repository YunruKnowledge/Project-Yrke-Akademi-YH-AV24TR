#include <QApplication>
#include "fractalwindow.h"

int main(int argc, char *argv[]){
    QApplication app(argc, argv);

    FractalWindow window;
    window.showFullScreen();

    app.exec();
}
