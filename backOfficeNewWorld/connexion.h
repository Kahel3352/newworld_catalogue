#ifndef CONNEXION_H
#define CONNEXION_H
#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class connexion;
}

class connexion : public QDialog
{
    Q_OBJECT

public:
    explicit connexion(QWidget *parent = 0);
    ~connexion();
    QString leLogin;

private slots:
    void on_pushButtonConnect_clicked();
    void on_pushButtonCancel_clicked();

private:
    Ui::connexion *ui;
};

#endif // CONNEXION_H
