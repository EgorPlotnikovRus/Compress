#pragma once

#include <QObject>
#include <QtWidgets>
#include <QPushButton>
#include <QDebug>
#include <QFileDialog>
#include <QApplication>
#include <QWidget>

class Window : public QObject
{
    Q_OBJECT
private:
    QString str;

public:
    Window();

public slots:
    void getWay();
    void compFunc();
    void decompFunc();
signals:
    void changeText(QString);
};

