#include "passerelle.h"
#include "pdf.h"
#include <iostream>
#include <QGuiApplication>
#include <QTextDocument>
#include <QPdfWriter>
#include "template.h"

using namespace std;

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);
    if(argc>1)
        Passerelle::setUserId(atoi(argv[1]));
    else
        Passerelle::setUserId(0);
    Passerelle::setDatabase();

    Pdf pdf("test");
    pdf.imprimer();

    qDebug() <<"fin du programme";
    return 0;
}
