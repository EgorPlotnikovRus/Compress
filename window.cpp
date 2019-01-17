#include "window.h"
#include "compress.h"
#include "decompress.h"
#include <string>
#include <iostream>

QString strIn;
QString strOut;

Window::Window() : QObject(){}

void Window::getWay()
{
    QFileDialog* fd = new QFileDialog;
    strIn = fd->getOpenFileName();

    QFile file(strIn);
    QString s = file.fileName();
    strOut = s.section(".", 0, 0);

    emit changeText(strIn);
}

void Window::compFunc()
{
    std::string sIn = strIn.toUtf8().constData();
    std::string sOut = strOut.toUtf8().constData();
    sOut += ".bin";
    compress(sIn, sOut);
}

void Window::decompFunc()
{
    std::string sIn = strIn.toUtf8().constData();
    std::string sOut = strOut.toUtf8().constData();
    sOut += ".txt";
    decompress(sIn, sOut);
}
