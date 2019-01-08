#include "window.h"

Window::Window() : QObject(){}

void Window::getWay()
{
    QString strIn;
    QFileDialog* fd = new QFileDialog;
    fd->show();
    strIn = fd->getOpenFileName();

    QFile file(strIn);
    QString s = file.fileName();
    QString strOut = s.section(".", 0, 0);

    qDebug() << strIn;
    qDebug() << strOut;

    emit changeText(strIn);
}
