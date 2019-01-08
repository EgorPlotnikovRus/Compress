#include "window.h"
#include "compress.h"
#include <string>
#include <iostream>

Window::Window() : QObject(){}

void Window::getWay()
{
    QFileDialog* fd = new QFileDialog;
    fd->show();
    strIn = fd->getOpenFileName();

    QFile file(strIn);
    QString s = file.fileName();
    strOut = s.section(".", 0, 0);

//    qDebug() << strIn;
//    qDebug() << strOut;

    emit changeText(strIn);
}

void Window::compFunc()
{
    std::string sIn = strIn.toUtf8().constData();
    std::string sOut = strOut.toUtf8().constData();
    sOut += ".asd";
    compress(sIn, sOut);
}
