#include "mainwindow.h"
#include <QApplication>
#include <QSpinBox>
#include <QSlider>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QSpinBox* sbox = w.findChild<QSpinBox *>(QString("spinBox"));
    if (sbox)
        sbox->setValue(3);
    QSlider* slider = w.findChild<QSlider *>(QString("horizontalSlider"));
    if (slider)
        slider->setValue(50);
    slider = w.findChild<QSlider *>(QString("rSlider"));
    if (slider)
        slider->setValue(255);
    slider = w.findChild<QSlider *>(QString("gSlider"));
    if (slider)
        slider->setValue(255);
    w.show();
    
    return a.exec();
}
