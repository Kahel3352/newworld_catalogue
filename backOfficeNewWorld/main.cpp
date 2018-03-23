#include "mainwindow.h"
#include <QApplication>
#include "connexion.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase maBase;
    maBase=QSqlDatabase::addDatabase("QMYSQL3");
    maBase.setHostName("localhost");
    maBase.setUserName("mlebeau");
    maBase.setPassword("passf203");
    maBase.setDatabaseName("dbmlnewworld");
    maBase.open();
    connexion maConnexion;
    if (maConnexion.exec()==QDialog::Accepted)
    {
        MainWindow w(&maConnexion);
        w.show();
        return a.exec();
    }
    else
    {
        return -124;
    }
}
