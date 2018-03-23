#include "mainwindow.h"
#include "connexion.h"
#include "ui_mainwindow.h"
#include <QCheckBox>
#include <QSqlQuery>
#include <QDebug>
#include <QBitmap>


MainWindow::MainWindow(connexion *laConnexion, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    uneConnexion=laConnexion;
    setWindowTitle(uneConnexion->leLogin);

    this->chargetableWidgetValidationProduit();
    this->clearProduit();

    this->chargetableWidgetValidationVariete();
    this->clearVariete();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonQuit_clicked()
{
    this->close();
}

//Valider des Produits
void MainWindow::validerProduit()
{
    //update

    QString numeroProduit=sender()->property("produitNum").toString();
    QSqlQuery maRequete;
    maRequete.prepare("UPDATE Produit SET produitValid=1 WHERE produitNum=?;");
    maRequete.addBindValue(numeroProduit);
    if(maRequete.exec())
    {
        this->chargetableWidgetValidationProduit();
        this->clearProduit();
    }

}

void MainWindow::chargetableWidgetValidationProduit()
{
    qDebug()<<"void MainWindow::chargetableWidgetValidationProduit()";

    QSqlQuery maRequete;
    maRequete.prepare("SELECT produitNum, rayonLib, produitNom, produitImg from Produit inner join Rayon on Produit.rayonNum=Rayon.rayonNum where not produitValid");

    if (maRequete.exec())
    {
        ui->tableWidgetValidationProduit->setRowCount(0);
        while(maRequete.next())
        {
            //ajout d'une ligne
            ui->tableWidgetValidationProduit->setRowCount(ui->tableWidgetValidationProduit->rowCount()+1);
            //on remplit le numéro du produit
            ui->tableWidgetValidationProduit->setItem(ui->tableWidgetValidationProduit->rowCount()-1,0, new QTableWidgetItem(maRequete.value("produitNum").toString()));
            //On cache la colonne qui contient le numéro du produit
            ui->tableWidgetValidationProduit->hideColumn(0);

            ui->tableWidgetValidationProduit->setItem(ui->tableWidgetValidationProduit->rowCount()-1,1, new QTableWidgetItem(maRequete.value("produitNom").toString()));

            ui->tableWidgetValidationProduit->setItem(ui->tableWidgetValidationProduit->rowCount()-1,2, new QTableWidgetItem(maRequete.value("produitImg").toString()));
            ui->tableWidgetValidationProduit->hideColumn(2);

            ui->tableWidgetValidationProduit->setItem(ui->tableWidgetValidationProduit->rowCount()-1,3, new QTableWidgetItem(maRequete.value("rayonLib").toString()));

            //Création de la checkBox
            QCheckBox * checkProduit= new QCheckBox("Validé",ui->tableWidgetValidationProduit);
            //ajout d'une proppriété de la QCheckBox numeroProduit avec comme valeur l'identifiant du produit auquel la case a cocher correspond
            checkProduit->setProperty("produitNum", maRequete.value("produitNum").toString());
            connect(checkProduit,SIGNAL(stateChanged(int)),this,SLOT(validerProduit()));
            ui->tableWidgetValidationProduit->setCellWidget(ui->tableWidgetValidationProduit->rowCount()-1,4, checkProduit);


        }//fin du pour chaque produit à valider
    }
    else
        qDebug()<<"List produit erreur: "+QSqlDatabase::database().lastError().text();


}



void MainWindow::on_tableWidgetValidationProduit_clicked(const QModelIndex &index)
{
    //On reactive les labels
    ui->labelVRayon->setEnabled(true);
    ui->labelVProduit->setEnabled(true);
    ui->textEditVDescr->setEnabled(true);
    ui->labelVImg->setEnabled(true);
    ui->checkBoxVProduit->setEnabled(true);
    ui->pushButtonVOk->setEnabled(true);
    //On change leur contenu
    ui->labelVProduit->setText(ui->tableWidgetValidationProduit->item(index.row(),1)->text());
    QString fileName="/home/mlebeau/public_html/NW 2.0/backOfficeNewWorld/ImgRessources/"+ui->tableWidgetValidationProduit->item(index.row(),2)->text();
    ui->labelVImg->setPixmap(QPixmap(fileName).scaled(200,200));
    ui->labelVRayon->setText(ui->tableWidgetValidationProduit->item(index.row(),3)->text());
    ui->checkBoxVProduit->setCheckState(((QCheckBox*)(ui->tableWidgetValidationProduit->cellWidget(index.row(),4)))->checkState());
}

void MainWindow::on_pushButtonVOk_clicked()
{
    //Ouverture de la base

    //On crée une QSqlQuery
    QSqlQuery maRequete;
    //On prepare une requete de modification d'un produit
    maRequete.prepare("UPDATE Produit SET produitValid=1 WHERE produitNum=?;");
    //On remplace le ? par l'id caché dans la colonne 0 de la table
    maRequete.addBindValue(ui->tableWidgetValidationProduit->item(ui->tableWidgetValidationProduit->currentRow(),0)->text());
    //Si la requete s'execute
    if (maRequete.exec())
    {
        //On recharge la tablewidget
        this->chargetableWidgetValidationProduit();
        //On appelle la methode clearProduit() pour les réinitialiser
        this->clearProduit();
    }

    //Fermeture de la base


}

void MainWindow::clearProduit()
{
    //On remet l'ancien texte des label
    ui->labelVProduit->setText("Produit");
    ui->textEditVDescr->clear();
    ui->labelVImg->setText("Image");
    ui->labelVRayon->setText("Rayon");
    ui->checkBoxVProduit->setCheckState(Qt::Unchecked);
    //On les desactive
    ui->labelVProduit->setEnabled(false);
    ui->labelVImg->setEnabled(false);
    ui->labelVRayon->setEnabled(false);
    ui->checkBoxVProduit->setEnabled(false);
}

void MainWindow::on_pushButtonVSuppr_clicked()
{

    QSqlQuery maRequete;
    maRequete.prepare("DELETE FROM Produit WHERE produitNum=?");
    maRequete.addBindValue(ui->tableWidgetValidationProduit->item(ui->tableWidgetValidationProduit->currentRow(),0)->text());
    if(maRequete.exec())
    {
        this->chargetableWidgetValidationProduit();
        this->clearProduit();
    }

}

//Valider des Variétés

void MainWindow::validerVariete()
{
    //update

    QString numeroVariete=sender()->property("varieteNum").toString();
    QSqlQuery maRequeteVVariete;
    maRequeteVVariete.prepare("UPDATE Variete SET varieteValid=1 WHERE varieteId=?;");
    maRequeteVVariete.addBindValue(numeroVariete);
    if(maRequeteVVariete.exec())
    {
        this->chargetableWidgetValidationVariete();
        this->clearProduit();
    }

}

void MainWindow::chargetableWidgetValidationVariete(){

    QSqlQuery maRequeteVariete;
    maRequeteVariete.prepare("SELECT varieteNum, varieteNom, produitNom, varieteDescr, varieteImg from Variete INNER JOIN Produit on Variete.produitNum=Produit.produitNum Where varieteValid=?;");
    maRequeteVariete.addBindValue("0");
    if(maRequeteVariete.exec())
    {
        ui->tableWidgetValidationVariete->setRowCount(0);
        while(maRequeteVariete.next())
        {
            ui->tableWidgetValidationVariete->setRowCount(ui->tableWidgetValidationVariete->rowCount()+1);
            ui->tableWidgetValidationVariete->setItem(ui->tableWidgetValidationVariete->rowCount()-1,0,new QTableWidgetItem(maRequeteVariete.value("varieteNum").toString()));
            ui->tableWidgetValidationVariete->hideColumn(0);
            ui->tableWidgetValidationVariete->setItem(ui->tableWidgetValidationVariete->rowCount()-1,1,new QTableWidgetItem(maRequeteVariete.value("produitNom").toString()));
            ui->tableWidgetValidationVariete->setItem(ui->tableWidgetValidationVariete->rowCount()-1,2,new QTableWidgetItem(maRequeteVariete.value("varieteNom").toString()));
            ui->tableWidgetValidationVariete->setItem(ui->tableWidgetValidationVariete->rowCount()-1,3,new QTableWidgetItem(maRequeteVariete.value("varieteDescr").toString()));
            ui->tableWidgetValidationVariete->hideColumn(3);
            ui->tableWidgetValidationVariete->setItem(ui->tableWidgetValidationVariete->rowCount()-1,4,new QTableWidgetItem(maRequeteVariete.value("varieteImg").toString()));
            ui->tableWidgetValidationVariete->hideColumn(4);

            QCheckBox * checkVariete=new QCheckBox("Validé",ui->tableWidgetValidationVariete);
            checkVariete->setProperty("varieteNum",maRequeteVariete.value("varieteNum").toString());
            connect(checkVariete,SIGNAL(stateChanged(int)),this,SLOT(validerVariete()));
            ui->tableWidgetValidationVariete->setCellWidget(ui->tableWidgetValidationVariete->rowCount()-1,5,checkVariete);
        }

    }
    else
        qDebug()<<"List variete erreur: "+QSqlDatabase::database().lastError().text();
}

void MainWindow::on_tableWidgetValidationVariete_clicked(const QModelIndex &index)
{
    //On reactive les labels
    ui->labelVProduitVariete->setEnabled(true);
    ui->labelVVariete->setEnabled(true);
    ui->textEditVDescrVariete->setEnabled(true);
    ui->labelVImgVariete->setEnabled(true);
    ui->checkBoxVVariete->setEnabled(true);
    ui->pushButtonVOkVariete->setEnabled(true);
    //On change leur contenu
    ui->labelVProduitVariete->setText(ui->tableWidgetValidationVariete->item(index.row(),1)->text());
    ui->labelVVariete->setText(ui->tableWidgetValidationVariete->item(index.row(),2)->text());
    ui->textEditVDescrVariete->setText(ui->tableWidgetValidationVariete->item(index.row(),3)->text());
    QString fileName="/home/mlebeau/public_html/NW 2.0/backOfficeNewWorld/ImgRessources/"+ui->tableWidgetValidationProduit->item(index.row(),4)->text();
    ui->labelVImgVariete->setPixmap(QPixmap(fileName).scaled(200,200));
    ui->checkBoxVVariete->setCheckState(((QCheckBox*)(ui->tableWidgetValidationVariete->cellWidget(index.row(),5)))->checkState());
}


void MainWindow::on_pushButtonVOkVariete_clicked()
{
    //On crée une QSqlQuery
    QSqlQuery maRequete;
    //On prepare une requete de modification d'un produit
    maRequete.prepare("UPDATE Variete SET varieteValid=1 WHERE varieteNum=?;");
    //On remplace le ? par l'id caché dans la colonne 0 de la table
    maRequete.addBindValue(ui->tableWidgetValidationVariete->item(ui->tableWidgetValidationVariete->currentRow(),0)->text());
    //Si la requete s'execute
    if (maRequete.exec())
    {
        //On recharge la tablewidget
        this->chargetableWidgetValidationVariete();
        //On appelle la methode clearProduit() pour les réinitialiser
        this->clearVariete();
    }
}

void MainWindow::clearVariete()
{
    //On remet l'ancien texte des label
    ui->labelVProduitVariete->setText("Produit");
    ui->labelVVariete->setText("Variete");
    ui->textEditVDescrVariete->clear();
    ui->labelVImgVariete->setText("Image");
    ui->checkBoxVVariete->setCheckState(Qt::Unchecked);
    //On les desactive
    ui->labelVProduitVariete->setEnabled(false);
    ui->labelVVariete->setEnabled(false);
    ui->labelVImgVariete->setEnabled(false);
    ui->checkBoxVVariete->setEnabled(false);
}

void MainWindow::on_pushButtonVSupprVariete_clicked()
{
    QSqlQuery maRequete;
    maRequete.prepare("DELETE FROM Variete WHERE varieteNum=?");
    maRequete.addBindValue(ui->tableWidgetValidationVariete->item(ui->tableWidgetValidationVariete->currentRow(),0)->text());
    if(maRequete.exec())
    {
        this->chargetableWidgetValidationVariete();
        this->clearVariete();
    }
}

//Valider Producteur
void MainWindow::validerUtilisateur()
{
    //update

    QString numeroUser=sender()->property("userId").toString();
    QSqlQuery maRequeteVUser;
    maRequeteVUser.prepare("UPDATE Utilisateur SET userValid=1 WHERE userId=?;");
    maRequeteVUser.addBindValue(numeroUser);
    if(maRequeteVUser.exec())
    {
        this->chargetableWidgetValidationUser();
        //this->clearProduit();
    }

}


void MainWindow::chargetableWidgetValidationUser(){

   /* QSqlQuery maRequeteVariete;
    maRequeteVariete.prepare("SELECT numeroVarieteP, nomVarieteP, nomProduit, descrVarieteP, imgVarieteP from VarieteP INNER JOIN Produit on VarieteP.numeroProduit=Produit.numeroProduit Where validVarieteP=?;");
    maRequeteVariete.addBindValue("0");
    if(maRequeteVariete.exec())
    {
        ui->tableWidgetValidationVariete->setRowCount(0);
        while(maRequeteVariete.next())
        {
            ui->tableWidgetValidationVariete->setRowCount(ui->tableWidgetValidationVariete->rowCount()+1);
            ui->tableWidgetValidationVariete->setItem(ui->tableWidgetValidationVariete->rowCount()-1,0,new QTableWidgetItem(maRequeteVariete.value("numeroVarieteP").toString()));
            ui->tableWidgetValidationVariete->hideColumn(0);
            ui->tableWidgetValidationVariete->setItem(ui->tableWidgetValidationVariete->rowCount()-1,1,new QTableWidgetItem(maRequeteVariete.value("nomProduit").toString()));
            ui->tableWidgetValidationVariete->setItem(ui->tableWidgetValidationVariete->rowCount()-1,2,new QTableWidgetItem(maRequeteVariete.value("nomVarieteP").toString()));
            ui->tableWidgetValidationVariete->setItem(ui->tableWidgetValidationVariete->rowCount()-1,3,new QTableWidgetItem(maRequeteVariete.value("descrVarieteP").toString()));
            ui->tableWidgetValidationVariete->hideColumn(3);
            ui->tableWidgetValidationVariete->setItem(ui->tableWidgetValidationVariete->rowCount()-1,4,new QTableWidgetItem(maRequeteVariete.value("imgVarieteP").toString()));
            ui->tableWidgetValidationVariete->hideColumn(4);

            QCheckBox * checkVariete=new QCheckBox("Validé",ui->tableWidgetValidationVariete);
            checkVariete->setProperty("numeroVariete",maRequeteVariete.value("numeroVarieteP").toString());
            connect(checkVariete,SIGNAL(stateChanged(int)),this,SLOT(validerVariete()));
            ui->tableWidgetValidationVariete->setCellWidget(ui->tableWidgetValidationVariete->rowCount()-1,5,checkVariete);
        }

    }*/

}




