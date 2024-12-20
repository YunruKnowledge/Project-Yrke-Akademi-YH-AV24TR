#include "fractalwindow.h"
#include <iostream>
#include <QPalette>
#include <QPainter>

FractalWindow::FractalWindow(QWidget *parent) : QMainWindow{parent}
{
    setWindowTitle("C++ Fraktali");
    draw = false;

    fractalImage = QImage(100, 100, QImage::Format_RGBA8888);
    fractalImage.fill({0, 0, 0});
    setAutoFillBackground(true);

    QPixmap pixmap = QPixmap::fromImage(fractalImage);
    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    setPalette(palette);
}

void FractalWindow::keyPressEvent(QKeyEvent *key){

    switch (key->key()) {
    case Qt::Key::Key_Escape:
        exit(0);
        break;
    case Qt::Key::Key_W:
        break;
    case Qt::Key::Key_A:
        break;
    case Qt::Key::Key_S:
        break;
    case Qt::Key::Key_D:
        break;
    case Qt::Key::Key_R:
        break;
    case Qt::Key::Key_Space:
        break;
    }
}

void FractalWindow::mouseReleaseEvent(QMouseEvent *event){
    draw = false;
    std::cout << "Mouse Relesed!" << std::endl;
}

void FractalWindow::mousePressEvent(QMouseEvent *event){
    draw = true;
}

void FractalWindow::mouseMoveEvent(QMouseEvent *event){
    int x = event->pos().x();
    int y = event->pos().y();

    if (draw){
        fractalImage.setPixelColor(x, y, {255, 255, 255});
        update();
    }
}

void FractalWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);

    painter.drawImage(0, 0, fractalImage);

    for(int x = 0; x < w; x += step){
        for(int y = 0; y < h; y += step){
            double zr = (x - w/2) / scale + oR;
            double zi = (y - h/2) / scale + oI;

            int shade = 0;

            if (square){
                shade = (int) (mandelbrot2(0, 0, 0, zr, zi) / mit * 255);
            }
            else{
                shade = (int) (mandelbrot3(0, 0, 0, zr, zi) / mit * 255);
            }

            painter.setPen(QColor(shade, shade, shade));
            painter.drawRect(x, y, step, step);
        }
    }
}

void FractalWindow::resizeEvent(QResizeEvent *event){
    QMainWindow::resizeEvent(event);

    int x = geometry().width();
    int y = geometry().height();

    w = x;
    h = y;

    fractalImage = QImage(x, y, QImage::Format_RGBA8888);
    fractalImage.fill({0, 0, 0});
}

double FractalWindow::mandelbrot2(double it, double zr, double zi, double cr, double ci){
    double nr = zr*zr - zi*zi + cr;
    double ni = 2*zr*zi + ci;

    if (sqrt(nr*nr + ni*ni) >= 2){
        return it;
    }

    if(it >= mit){
        return mit;
    }

    return mandelbrot2(it++, nr, ni, cr, ci);
}

double FractalWindow::mandelbrot3(double it, double zr, double zi, double cr, double ci){
    double nr = zr*zr*zr - 3*zr*zi*zi + cr;
    double ni = 3*zr*zr*zi - zi*zi*zi + ci;

    if (sqrt(nr*nr + ni*ni) >= 2){
        return it;
    }

    if(it >= mit){
        return mit;
    }

    return mandelbrot2(it++, nr, ni, cr, ci);
}
