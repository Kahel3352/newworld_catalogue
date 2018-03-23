#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "connexion.h"
#include <QMainWindow>
#include <QSqlError>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(connexion *laConnexion, QWidget *parent = 0);
    ~MainWindow();

public slots:
    void validerProduit();
    void validerVariete();
    void validerUtilisateur();
private slots:
    void on_pushButtonQuit_clicked();
    void on_tableWidgetValidationProduit_clicked(const QModelIndex &index);

    void on_pushButtonVOk_clicked();

    void on_pushButtonVSuppr_clicked();


    void on_tableWidgetValidationVariete_clicked(const QModelIndex &index);

    void on_pushButtonVOkVariete_clicked();

    void on_pushButtonVSupprVariete_clicked();

private:
    QSqlDatabase * maBase;
    connexion *uneConnexion;
    int ligneSelec;
    Ui::MainWindow *ui;
    //Valider des Produits
    void chargetableWidgetValidationProduit();
    void clearProduit();

    //Valider des Variétés
    void chargetableWidgetValidationVariete();
    void clearVariete();

    //Valider des Producteur
    void chargetableWidgetValidationUser();
};

#endif // MAINWINDOW_H
