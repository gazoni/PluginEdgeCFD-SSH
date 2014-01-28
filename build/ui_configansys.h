/********************************************************************************
** Form generated from reading UI file 'configansys.ui'
**
** Created: Mon 7. Oct 16:30:15 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGANSYS_H
#define UI_CONFIGANSYS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_configAnsys
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QRadioButton *radioButton_ansys14;
    QPushButton *pushButtonQuitMenuAnsys;
    QRadioButton *radioButton_ansys11;
    QRadioButton *radioButton_ansys12;
    QRadioButton *radioButton_ansys13;
    QPushButton *pushButtonSaveAnsys;

    void setupUi(QWidget *configAnsys)
    {
        if (configAnsys->objectName().isEmpty())
            configAnsys->setObjectName(QString::fromUtf8("configAnsys"));
        configAnsys->resize(400, 300);
        groupBox = new QGroupBox(configAnsys);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 361, 261));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 30, 321, 201));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_ansys14 = new QRadioButton(layoutWidget);
        radioButton_ansys14->setObjectName(QString::fromUtf8("radioButton_ansys14"));

        gridLayout->addWidget(radioButton_ansys14, 3, 0, 1, 1);

        pushButtonQuitMenuAnsys = new QPushButton(layoutWidget);
        pushButtonQuitMenuAnsys->setObjectName(QString::fromUtf8("pushButtonQuitMenuAnsys"));

        gridLayout->addWidget(pushButtonQuitMenuAnsys, 4, 1, 1, 1);

        radioButton_ansys11 = new QRadioButton(layoutWidget);
        radioButton_ansys11->setObjectName(QString::fromUtf8("radioButton_ansys11"));

        gridLayout->addWidget(radioButton_ansys11, 0, 0, 1, 1);

        radioButton_ansys12 = new QRadioButton(layoutWidget);
        radioButton_ansys12->setObjectName(QString::fromUtf8("radioButton_ansys12"));

        gridLayout->addWidget(radioButton_ansys12, 1, 0, 1, 1);

        radioButton_ansys13 = new QRadioButton(layoutWidget);
        radioButton_ansys13->setObjectName(QString::fromUtf8("radioButton_ansys13"));

        gridLayout->addWidget(radioButton_ansys13, 2, 0, 1, 1);

        pushButtonSaveAnsys = new QPushButton(layoutWidget);
        pushButtonSaveAnsys->setObjectName(QString::fromUtf8("pushButtonSaveAnsys"));

        gridLayout->addWidget(pushButtonSaveAnsys, 4, 0, 1, 1);


        retranslateUi(configAnsys);

        QMetaObject::connectSlotsByName(configAnsys);
    } // setupUi

    void retranslateUi(QWidget *configAnsys)
    {
        configAnsys->setWindowTitle(QApplication::translate("configAnsys", "Configure Ansys version", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("configAnsys", "Ansys Versions:", 0, QApplication::UnicodeUTF8));
        radioButton_ansys14->setText(QApplication::translate("configAnsys", "RadioButton", 0, QApplication::UnicodeUTF8));
        pushButtonQuitMenuAnsys->setText(QApplication::translate("configAnsys", "close", 0, QApplication::UnicodeUTF8));
        radioButton_ansys11->setText(QApplication::translate("configAnsys", "RadioButton", 0, QApplication::UnicodeUTF8));
        radioButton_ansys12->setText(QApplication::translate("configAnsys", "RadioButton", 0, QApplication::UnicodeUTF8));
        radioButton_ansys13->setText(QApplication::translate("configAnsys", "RadioButton", 0, QApplication::UnicodeUTF8));
        pushButtonSaveAnsys->setText(QApplication::translate("configAnsys", "save", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class configAnsys: public Ui_configAnsys {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGANSYS_H
