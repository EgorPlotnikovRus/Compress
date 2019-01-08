#include "window.h"
#include "head.h"
#include "compress.h"
#include "decompress.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QWidget wgt;
    QHBoxLayout* phb = new QHBoxLayout;
    QLineEdit* le = new QLineEdit;
    QPushButton* pDialog = new QPushButton;
    QPushButton* pCom = new QPushButton;
    QPushButton* pDecom = new QPushButton;
    QFileSystemModel model;
    Window win;

    model.setRootPath(QDir::rootPath());

    pCom->setText("Compress");
    pDecom->setText("Decompress");
    pDialog->setText("...");

    phb->addWidget(le);
    phb->addWidget(pDialog);
    phb->addWidget(pCom);
    phb->addWidget(pDecom);

    wgt.setLayout(phb);

    wgt.show();

    QObject::connect(pDialog, SIGNAL(clicked(bool)), &win, SLOT(getWay()));
    QObject::connect(&win, SIGNAL(changeText(QString)), le, SLOT(setText(QString)));
    QObject::connect(pCom, SIGNAL(clicked(bool)), &win, SLOT(compFunc()));

//    decompress(InputFileCoding, OutputFileDecoding);
//    compress(InputFileDecoding,  OutputFileCoding);

    return app.exec();
}
