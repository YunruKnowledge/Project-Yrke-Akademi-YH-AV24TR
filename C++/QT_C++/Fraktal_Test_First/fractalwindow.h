#ifndef FRACTALWINDOW_H
#define FRACTALWINDOW_H

#pragma once

#include <QMainWindow>
#include <QWidget>
#include <QMouseEvent>
#include <QImage>

class FractalWindow : public QMainWindow
{
    bool draw;
    QImage fractalImage;

    int w = 800; // Width
    int h = 800; // Height

    int step = 700;
    double mit = 20;     // Max Ittaration
    double scale = 585;  // Scale
    double oI;           // Origin I
    double oR;           // Origin R

    bool square = true;
    bool mouseDown = false;

    double lastMouseX;
    double lastMouseY;

public:
    FractalWindow(QWidget *parent = nullptr);

    void keyPressEvent(QKeyEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

    void paintEvent(QPaintEvent *event) override;

    void resizeEvent(QResizeEvent *event) override;

    double mandelbrot2(double it, double zr, double zi, double cr, double ci);

    double mandelbrot3(double it, double zr, double zi, double cr, double ci);
};

#endif // FRACTALWINDOW_H
