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
    Passerelle::setDatabase();

    Pdf pdf("test");
    pdf.imprimer();

    qDebug() <<"fin du programme";
    return 0;
}
