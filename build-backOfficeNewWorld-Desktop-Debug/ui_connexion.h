/********************************************************************************
** Form generated from reading UI file 'connexion.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNEXION_H
#define UI_CONNEXION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_connexion
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QFormLayout *formLayout;
    QLabel *labelPseudo;
    QLineEdit *lineEditPseudo;
    QLabel *labelMdp;
    QLineEdit *lineEditMdp;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtonConnect;
    QPushButton *pushButtonCancel;

    void setupUi(QDialog *connexion)
    {
        if (connexion->objectName().isEmpty())
            connexion->setObjectName(QStringLiteral("connexion"));
        connexion->resize(400, 300);
        verticalLayout = new QVBoxLayout(connexion);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label = new QLabel(connexion);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(13);
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        labelPseudo = new QLabel(connexion);
        labelPseudo->setObjectName(QStringLiteral("labelPseudo"));
        QFont font1;
        font1.setPointSize(12);
        labelPseudo->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, labelPseudo);

        lineEditPseudo = new QLineEdit(connexion);
        lineEditPseudo->setObjectName(QStringLiteral("lineEditPseudo"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditPseudo);

        labelMdp = new QLabel(connexion);
        labelMdp->setObjectName(QStringLiteral("labelMdp"));
        labelMdp->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, labelMdp);

        lineEditMdp = new QLineEdit(connexion);
        lineEditMdp->setObjectName(QStringLiteral("lineEditMdp"));
        lineEditMdp->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditMdp);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButtonConnect = new QPushButton(connexion);
        pushButtonConnect->setObjectName(QStringLiteral("pushButtonConnect"));

        horizontalLayout->addWidget(pushButtonConnect);

        pushButtonCancel = new QPushButton(connexion);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));

        horizontalLayout->addWidget(pushButtonCancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(connexion);

        QMetaObject::connectSlotsByName(connexion);
    } // setupUi

    void retranslateUi(QDialog *connexion)
    {
        connexion->setWindowTitle(QApplication::translate("connexion", "Dialog", 0));
        label->setText(QApplication::translate("connexion", "Connexion", 0));
        labelPseudo->setText(QApplication::translate("connexion", "Pseudo", 0));
        lineEditPseudo->setText(QApplication::translate("connexion", "admin", 0));
        labelMdp->setText(QApplication::translate("connexion", "Mot de Passe", 0));
        lineEditMdp->setText(QApplication::translate("connexion", "admin", 0));
        pushButtonConnect->setText(QApplication::translate("connexion", "Connexion", 0));
        pushButtonCancel->setText(QApplication::translate("connexion", "Annuler", 0));
    } // retranslateUi

};

namespace Ui {
    class connexion: public Ui_connexion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNEXION_H
