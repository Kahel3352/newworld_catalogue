#include "connexion.h"
#include "ui_connexion.h"
#include "QSqlQuery"
#include <QDebug>
#include <QSqlError>

connexion::connexion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::connexion)
{
    ui->setupUi(this);
    setWindowTitle("Connexion");
}

connexion::~connexion()
{
    delete ui;
}

void connexion::on_pushButtonConnect_clicked()
{
    //QDebug<<"void connexion::on_pushButtonConnect_clicked()";

    qDebug()<<QSqlDatabase::database().lastError();
    QSqlQuery maRequete;
    maRequete.prepare("SELECT * FROM Employe WHERE employePseudo=? and employeMdP=?");
    maRequete.addBindValue(ui->lineEditPseudo->text());
    maRequete.addBindValue(ui->lineEditMdp->text());

    if(maRequete.exec() && maRequete.size()==1)
    {
        leLogin=ui->lineEditPseudo->text();
        accept();
    }

    else
    {
        ui->labelPseudo->setStyleSheet("color:red;");
        ui->lineEditPseudo->clear();
        ui->labelMdp->setStyleSheet("color:red;");
        ui->lineEditMdp->clear();
    }


}

void connexion::on_pushButtonCancel_clicked()
{
    this->close();
}
