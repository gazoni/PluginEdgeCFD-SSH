/********************************************************************************
** Form generated from reading UI file 'runedgecfd.ui'
**
** Created: Tue 27. Aug 18:46:25 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RUNEDGECFD_H
#define UI_RUNEDGECFD_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>


#include <qvtkwidget.h>

QT_BEGIN_NAMESPACE

class Ui_runEdgeCFDClass
{
public:
    QAction *actionExit;
    QAction *actionAnsys_Path;
    QAction *actionAbout;
    QAction *actionSave;
    QAction *actionOpen;
    QWidget *centralWidget;
    QTabWidget *tabWidget_View;
    QWidget *tab_config;
    QGroupBox *groupBox;
    QPushButton *pushButton_Run;
    QLabel *label_AnsysVersion;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_5;
    QLineEdit *lineEdit_jobName;
    QLabel *label_dbFile;
    QLineEdit *lineEdit_dbFile;
    QLineEdit *lineEdit_WorkingDir;
    QLabel *label_workDir;
    QPushButton *pushButton_WorkingDir;
    QLabel *label_jobName;
    QPushButton *pushButton_dbFile;
    QWidget *tab_Setup;
    QLabel *label_2;
    QGroupBox *groupBox_SETUP;
    QLabel *label_3;
    QScrollArea *scrollArea_Setup;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QPushButton *pushButtonSaveSetupFile;
    QGroupBox *groupBox_3;
    QPushButton *pushButton_newDOF;
    QPushButton *pushButton_delDOF;
    QLineEdit *lineEdit_descriptionSetup;
    QPushButton *pushButton_RunSetupEdgeCFD;
    QWidget *tab_Pre;
    QGroupBox *groupBox_4;
    QSpinBox *spinBox_NP;
    QSpinBox *spinBox_BLK;
    QSpinBox *spinBox_RED;
    QTextEdit *textEdit;
    QLabel *label_NP;
    QLabel *label_BLK;
    QLabel *label_RED;
    QSpinBox *spinBox_ORD;
    QLabel *label_ORD;
    QLabel *label_RCM;
    QSpinBox *spinBox_RCM;
    QSpinBox *spinBox_KEQ;
    QLabel *label_KEQ;
    QSpinBox *spinBox_FMT;
    QLabel *label_FMT;
    QLabel *label_ANS;
    QSpinBox *spinBox_ANS;
    QSpinBox *spinBox_PMV;
    QLabel *label_PMV;
    QSpinBox *spinBox_LDE;
    QLabel *label_LDE;
    QPushButton *pushButton_RunPreEdgeCFD;
    QWidget *tab_Input;
    QGroupBox *groupBox_5;
    QLineEdit *lineEdit_InputFileName;
    QSpinBox *spinBox_input1;
    QSpinBox *spinBox_input2;
    QSpinBox *spinBox_input3;
    QDoubleSpinBox *doubleSpinBox_input1;
    QDoubleSpinBox *doubleSpinBox_input2;
    QPushButton *pushButtonSaveInput;
    QWidget *tab_Fsi;
    QGroupBox *groupBox_6;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *comboBox_FSI;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_FSI_ALE1;
    QDoubleSpinBox *doubleSpinBox_FSI_ALE1_2;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox_MASSFSI;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_MassCG;
    QDoubleSpinBox *doubleSpinBox_MassCG_2;
    QDoubleSpinBox *doubleSpinBox_MassCG_3;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_RotationCG_3;
    QDoubleSpinBox *doubleSpinBox_RotationCG_2;
    QDoubleSpinBox *doubleSpinBox_RotationCG_1;
    QLabel *label_11;
    QDoubleSpinBox *doubleSpinBox_InertiaX11;
    QDoubleSpinBox *doubleSpinBox_InertiaX12;
    QDoubleSpinBox *doubleSpinBox_InertiaX13;
    QFrame *line;
    QFrame *line_2;
    QDoubleSpinBox *doubleSpinBox_InertiaX22;
    QDoubleSpinBox *doubleSpinBox_InertiaX23;
    QDoubleSpinBox *doubleSpinBox_InertiaX33;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *line_6;
    QLabel *label_12;
    QSpinBox *spinBox_Ux;
    QSpinBox *spinBox_Uy;
    QSpinBox *spinBox_Uz;
    QSpinBox *spinBox_ROTx;
    QSpinBox *spinBox_ROTy;
    QSpinBox *spinBox_ROTz;
    QLabel *label_13;
    QSpinBox *spinBox_nptf_1;
    QDoubleSpinBox *doubleSpinBox_nptf_2;
    QDoubleSpinBox *doubleSpinBox_nptf_3;
    QDoubleSpinBox *doubleSpinBox_nptf_4;
    QDoubleSpinBox *doubleSpinBox_nptf_5;
    QDoubleSpinBox *doubleSpinBox_nptf_6;
    QDoubleSpinBox *doubleSpinBox_nptf_7;
    QLabel *label_14;
    QPushButton *pushButtonSaveFSI;
    QWidget *tab_Material;
    QGroupBox *groupBox_material;
    QLabel *label_15;
    QScrollArea *scrollArea_material;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_4;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_7;
    QPushButton *pushButton_newMaterial;
    QPushButton *pushButton_delMaterial;
    QPushButton *pushButton_saveMaterial;
    QWidget *tabMesh;
    QVTKWidget *qvtkWidget;
    QTableWidget *tableWidget;
    QCheckBox *checkBoxWireframe;
    QPushButton *pushButton_RunEdgeCFDSolver;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuConfigure;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *runEdgeCFDClass)
    {
        if (runEdgeCFDClass->objectName().isEmpty())
            runEdgeCFDClass->setObjectName(QString::fromUtf8("runEdgeCFDClass"));
        runEdgeCFDClass->resize(1149, 900);
        runEdgeCFDClass->setMinimumSize(QSize(1136, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8("Edge.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        runEdgeCFDClass->setWindowIcon(icon);
        actionExit = new QAction(runEdgeCFDClass);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("cancel.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon1);
        actionAnsys_Path = new QAction(runEdgeCFDClass);
        actionAnsys_Path->setObjectName(QString::fromUtf8("actionAnsys_Path"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("ansys.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actionAnsys_Path->setIcon(icon2);
        actionAbout = new QAction(runEdgeCFDClass);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("about.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon3);
        actionSave = new QAction(runEdgeCFDClass);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("save.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon4);
        actionOpen = new QAction(runEdgeCFDClass);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("open.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon5);
        centralWidget = new QWidget(runEdgeCFDClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget_View = new QTabWidget(centralWidget);
        tabWidget_View->setObjectName(QString::fromUtf8("tabWidget_View"));
        tabWidget_View->setGeometry(QRect(10, 50, 1121, 780));
        tabWidget_View->setMinimumSize(QSize(1121, 780));
        tabWidget_View->setMaximumSize(QSize(1121, 710));
        tab_config = new QWidget();
        tab_config->setObjectName(QString::fromUtf8("tab_config"));
        groupBox = new QGroupBox(tab_config);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(220, 240, 711, 241));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        pushButton_Run = new QPushButton(groupBox);
        pushButton_Run->setObjectName(QString::fromUtf8("pushButton_Run"));
        pushButton_Run->setGeometry(QRect(10, 160, 93, 28));
        label_AnsysVersion = new QLabel(groupBox);
        label_AnsysVersion->setObjectName(QString::fromUtf8("label_AnsysVersion"));
        label_AnsysVersion->setGeometry(QRect(120, 160, 581, 40));
        QFont font;
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        font.setStrikeOut(false);
        label_AnsysVersion->setFont(font);
        label_AnsysVersion->setFocusPolicy(Qt::NoFocus);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 691, 141));
        gridLayout_5 = new QGridLayout(layoutWidget);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        lineEdit_jobName = new QLineEdit(layoutWidget);
        lineEdit_jobName->setObjectName(QString::fromUtf8("lineEdit_jobName"));
        lineEdit_jobName->setAcceptDrops(true);
        lineEdit_jobName->setMaxLength(300);
        lineEdit_jobName->setDragEnabled(false);

        gridLayout_5->addWidget(lineEdit_jobName, 1, 1, 1, 1);

        label_dbFile = new QLabel(layoutWidget);
        label_dbFile->setObjectName(QString::fromUtf8("label_dbFile"));

        gridLayout_5->addWidget(label_dbFile, 2, 0, 1, 1);

        lineEdit_dbFile = new QLineEdit(layoutWidget);
        lineEdit_dbFile->setObjectName(QString::fromUtf8("lineEdit_dbFile"));
        lineEdit_dbFile->setMaxLength(300);
        lineEdit_dbFile->setReadOnly(true);

        gridLayout_5->addWidget(lineEdit_dbFile, 2, 1, 1, 1);

        lineEdit_WorkingDir = new QLineEdit(layoutWidget);
        lineEdit_WorkingDir->setObjectName(QString::fromUtf8("lineEdit_WorkingDir"));
        lineEdit_WorkingDir->setReadOnly(false);

        gridLayout_5->addWidget(lineEdit_WorkingDir, 0, 1, 1, 1);

        label_workDir = new QLabel(layoutWidget);
        label_workDir->setObjectName(QString::fromUtf8("label_workDir"));
        label_workDir->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout_5->addWidget(label_workDir, 0, 0, 1, 1);

        pushButton_WorkingDir = new QPushButton(layoutWidget);
        pushButton_WorkingDir->setObjectName(QString::fromUtf8("pushButton_WorkingDir"));

        gridLayout_5->addWidget(pushButton_WorkingDir, 0, 2, 1, 1);

        label_jobName = new QLabel(layoutWidget);
        label_jobName->setObjectName(QString::fromUtf8("label_jobName"));
        label_jobName->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout_5->addWidget(label_jobName, 1, 0, 1, 1);

        pushButton_dbFile = new QPushButton(layoutWidget);
        pushButton_dbFile->setObjectName(QString::fromUtf8("pushButton_dbFile"));

        gridLayout_5->addWidget(pushButton_dbFile, 2, 2, 1, 1);

        tabWidget_View->addTab(tab_config, QString());
        tab_Setup = new QWidget();
        tab_Setup->setObjectName(QString::fromUtf8("tab_Setup"));
        label_2 = new QLabel(tab_Setup);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 251, 21));
        groupBox_SETUP = new QGroupBox(tab_Setup);
        groupBox_SETUP->setObjectName(QString::fromUtf8("groupBox_SETUP"));
        groupBox_SETUP->setGeometry(QRect(10, 60, 1091, 691));
        groupBox_SETUP->setMinimumSize(QSize(1091, 691));
        groupBox_SETUP->setMaximumSize(QSize(1091, 691));
        label_3 = new QLabel(groupBox_SETUP);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 30, 261, 16));
        scrollArea_Setup = new QScrollArea(groupBox_SETUP);
        scrollArea_Setup->setObjectName(QString::fromUtf8("scrollArea_Setup"));
        scrollArea_Setup->setGeometry(QRect(0, 50, 300, 600));
        scrollArea_Setup->setMinimumSize(QSize(300, 551));
        scrollArea_Setup->setMaximumSize(QSize(300, 600));
        scrollArea_Setup->setContextMenuPolicy(Qt::DefaultContextMenu);
        scrollArea_Setup->setLayoutDirection(Qt::LeftToRight);
        scrollArea_Setup->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea_Setup->setWidgetResizable(true);
        scrollArea_Setup->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 298, 598));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        scrollArea_Setup->setWidget(scrollAreaWidgetContents);
        pushButtonSaveSetupFile = new QPushButton(groupBox_SETUP);
        pushButtonSaveSetupFile->setObjectName(QString::fromUtf8("pushButtonSaveSetupFile"));
        pushButtonSaveSetupFile->setGeometry(QRect(980, 20, 101, 28));
        groupBox_3 = new QGroupBox(tab_Setup);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(740, 0, 211, 61));
        groupBox_3->setAlignment(Qt::AlignCenter);
        pushButton_newDOF = new QPushButton(groupBox_3);
        pushButton_newDOF->setObjectName(QString::fromUtf8("pushButton_newDOF"));
        pushButton_newDOF->setGeometry(QRect(10, 20, 93, 28));
        pushButton_delDOF = new QPushButton(groupBox_3);
        pushButton_delDOF->setObjectName(QString::fromUtf8("pushButton_delDOF"));
        pushButton_delDOF->setGeometry(QRect(110, 20, 93, 28));
        lineEdit_descriptionSetup = new QLineEdit(tab_Setup);
        lineEdit_descriptionSetup->setObjectName(QString::fromUtf8("lineEdit_descriptionSetup"));
        lineEdit_descriptionSetup->setGeometry(QRect(10, 30, 561, 22));
        pushButton_RunSetupEdgeCFD = new QPushButton(tab_Setup);
        pushButton_RunSetupEdgeCFD->setObjectName(QString::fromUtf8("pushButton_RunSetupEdgeCFD"));
        pushButton_RunSetupEdgeCFD->setGeometry(QRect(972, 20, 131, 28));
        tabWidget_View->addTab(tab_Setup, QString());
        tab_Pre = new QWidget();
        tab_Pre->setObjectName(QString::fromUtf8("tab_Pre"));
        groupBox_4 = new QGroupBox(tab_Pre);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 40, 1061, 691));
        spinBox_NP = new QSpinBox(groupBox_4);
        spinBox_NP->setObjectName(QString::fromUtf8("spinBox_NP"));
        spinBox_NP->setGeometry(QRect(20, 50, 60, 22));
        spinBox_NP->setMinimum(1);
        spinBox_NP->setMaximum(10000);
        spinBox_NP->setValue(1);
        spinBox_BLK = new QSpinBox(groupBox_4);
        spinBox_BLK->setObjectName(QString::fromUtf8("spinBox_BLK"));
        spinBox_BLK->setGeometry(QRect(100, 50, 60, 22));
        spinBox_BLK->setMaximum(10000);
        spinBox_BLK->setValue(4096);
        spinBox_RED = new QSpinBox(groupBox_4);
        spinBox_RED->setObjectName(QString::fromUtf8("spinBox_RED"));
        spinBox_RED->setGeometry(QRect(180, 50, 60, 22));
        spinBox_RED->setMaximum(1);
        textEdit = new QTextEdit(groupBox_4);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 90, 1031, 591));
        label_NP = new QLabel(groupBox_4);
        label_NP->setObjectName(QString::fromUtf8("label_NP"));
        label_NP->setGeometry(QRect(20, 30, 53, 16));
        label_BLK = new QLabel(groupBox_4);
        label_BLK->setObjectName(QString::fromUtf8("label_BLK"));
        label_BLK->setGeometry(QRect(100, 30, 53, 16));
        label_RED = new QLabel(groupBox_4);
        label_RED->setObjectName(QString::fromUtf8("label_RED"));
        label_RED->setGeometry(QRect(180, 30, 53, 16));
        spinBox_ORD = new QSpinBox(groupBox_4);
        spinBox_ORD->setObjectName(QString::fromUtf8("spinBox_ORD"));
        spinBox_ORD->setGeometry(QRect(260, 50, 60, 22));
        spinBox_ORD->setMaximum(1);
        label_ORD = new QLabel(groupBox_4);
        label_ORD->setObjectName(QString::fromUtf8("label_ORD"));
        label_ORD->setGeometry(QRect(260, 30, 53, 16));
        label_RCM = new QLabel(groupBox_4);
        label_RCM->setObjectName(QString::fromUtf8("label_RCM"));
        label_RCM->setGeometry(QRect(340, 30, 53, 16));
        spinBox_RCM = new QSpinBox(groupBox_4);
        spinBox_RCM->setObjectName(QString::fromUtf8("spinBox_RCM"));
        spinBox_RCM->setGeometry(QRect(340, 50, 60, 22));
        spinBox_RCM->setMaximum(1);
        spinBox_RCM->setValue(1);
        spinBox_KEQ = new QSpinBox(groupBox_4);
        spinBox_KEQ->setObjectName(QString::fromUtf8("spinBox_KEQ"));
        spinBox_KEQ->setGeometry(QRect(420, 50, 60, 22));
        spinBox_KEQ->setMaximum(1);
        label_KEQ = new QLabel(groupBox_4);
        label_KEQ->setObjectName(QString::fromUtf8("label_KEQ"));
        label_KEQ->setGeometry(QRect(420, 30, 53, 16));
        spinBox_FMT = new QSpinBox(groupBox_4);
        spinBox_FMT->setObjectName(QString::fromUtf8("spinBox_FMT"));
        spinBox_FMT->setGeometry(QRect(500, 50, 60, 22));
        spinBox_FMT->setMaximum(1);
        spinBox_FMT->setValue(1);
        label_FMT = new QLabel(groupBox_4);
        label_FMT->setObjectName(QString::fromUtf8("label_FMT"));
        label_FMT->setGeometry(QRect(500, 30, 53, 16));
        label_ANS = new QLabel(groupBox_4);
        label_ANS->setObjectName(QString::fromUtf8("label_ANS"));
        label_ANS->setGeometry(QRect(580, 30, 53, 16));
        spinBox_ANS = new QSpinBox(groupBox_4);
        spinBox_ANS->setObjectName(QString::fromUtf8("spinBox_ANS"));
        spinBox_ANS->setGeometry(QRect(580, 50, 60, 22));
        spinBox_ANS->setMaximum(1);
        spinBox_PMV = new QSpinBox(groupBox_4);
        spinBox_PMV->setObjectName(QString::fromUtf8("spinBox_PMV"));
        spinBox_PMV->setGeometry(QRect(660, 50, 60, 22));
        spinBox_PMV->setMaximum(1);
        label_PMV = new QLabel(groupBox_4);
        label_PMV->setObjectName(QString::fromUtf8("label_PMV"));
        label_PMV->setGeometry(QRect(660, 30, 53, 16));
        spinBox_LDE = new QSpinBox(groupBox_4);
        spinBox_LDE->setObjectName(QString::fromUtf8("spinBox_LDE"));
        spinBox_LDE->setGeometry(QRect(740, 50, 60, 22));
        spinBox_LDE->setMaximum(1);
        label_LDE = new QLabel(groupBox_4);
        label_LDE->setObjectName(QString::fromUtf8("label_LDE"));
        label_LDE->setGeometry(QRect(740, 30, 53, 16));
        pushButton_RunPreEdgeCFD = new QPushButton(groupBox_4);
        pushButton_RunPreEdgeCFD->setObjectName(QString::fromUtf8("pushButton_RunPreEdgeCFD"));
        pushButton_RunPreEdgeCFD->setGeometry(QRect(892, 40, 131, 28));
        tabWidget_View->addTab(tab_Pre, QString());
        tab_Input = new QWidget();
        tab_Input->setObjectName(QString::fromUtf8("tab_Input"));
        groupBox_5 = new QGroupBox(tab_Input);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(30, 40, 1071, 421));
        lineEdit_InputFileName = new QLineEdit(groupBox_5);
        lineEdit_InputFileName->setObjectName(QString::fromUtf8("lineEdit_InputFileName"));
        lineEdit_InputFileName->setGeometry(QRect(10, 30, 171, 22));
        lineEdit_InputFileName->setReadOnly(true);
        spinBox_input1 = new QSpinBox(groupBox_5);
        spinBox_input1->setObjectName(QString::fromUtf8("spinBox_input1"));
        spinBox_input1->setGeometry(QRect(10, 70, 46, 22));
        spinBox_input1->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        spinBox_input2 = new QSpinBox(groupBox_5);
        spinBox_input2->setObjectName(QString::fromUtf8("spinBox_input2"));
        spinBox_input2->setGeometry(QRect(10, 100, 46, 22));
        spinBox_input2->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        spinBox_input2->setValue(1);
        spinBox_input3 = new QSpinBox(groupBox_5);
        spinBox_input3->setObjectName(QString::fromUtf8("spinBox_input3"));
        spinBox_input3->setGeometry(QRect(10, 130, 46, 22));
        spinBox_input3->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        spinBox_input3->setValue(1);
        doubleSpinBox_input1 = new QDoubleSpinBox(groupBox_5);
        doubleSpinBox_input1->setObjectName(QString::fromUtf8("doubleSpinBox_input1"));
        doubleSpinBox_input1->setGeometry(QRect(60, 170, 80, 22));
        doubleSpinBox_input1->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_input1->setDecimals(4);
        doubleSpinBox_input1->setMaximum(9999.99);
        doubleSpinBox_input1->setValue(1);
        doubleSpinBox_input2 = new QDoubleSpinBox(groupBox_5);
        doubleSpinBox_input2->setObjectName(QString::fromUtf8("doubleSpinBox_input2"));
        doubleSpinBox_input2->setGeometry(QRect(150, 170, 80, 22));
        doubleSpinBox_input2->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_input2->setDecimals(4);
        doubleSpinBox_input2->setValue(0.5);
        pushButtonSaveInput = new QPushButton(groupBox_5);
        pushButtonSaveInput->setObjectName(QString::fromUtf8("pushButtonSaveInput"));
        pushButtonSaveInput->setGeometry(QRect(960, 20, 101, 28));
        tabWidget_View->addTab(tab_Input, QString());
        tab_Fsi = new QWidget();
        tab_Fsi->setObjectName(QString::fromUtf8("tab_Fsi"));
        groupBox_6 = new QGroupBox(tab_Fsi);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(30, 10, 1051, 721));
        label_5 = new QLabel(groupBox_6);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 20, 261, 16));
        label_6 = new QLabel(groupBox_6);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 50, 211, 16));
        comboBox_FSI = new QComboBox(groupBox_6);
        comboBox_FSI->setObjectName(QString::fromUtf8("comboBox_FSI"));
        comboBox_FSI->setGeometry(QRect(10, 70, 73, 22));
        label_7 = new QLabel(groupBox_6);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 100, 511, 16));
        doubleSpinBox_FSI_ALE1 = new QDoubleSpinBox(groupBox_6);
        doubleSpinBox_FSI_ALE1->setObjectName(QString::fromUtf8("doubleSpinBox_FSI_ALE1"));
        doubleSpinBox_FSI_ALE1->setGeometry(QRect(10, 130, 62, 22));
        doubleSpinBox_FSI_ALE1->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_FSI_ALE1->setValue(0.3);
        doubleSpinBox_FSI_ALE1_2 = new QDoubleSpinBox(groupBox_6);
        doubleSpinBox_FSI_ALE1_2->setObjectName(QString::fromUtf8("doubleSpinBox_FSI_ALE1_2"));
        doubleSpinBox_FSI_ALE1_2->setGeometry(QRect(80, 130, 62, 22));
        doubleSpinBox_FSI_ALE1_2->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        label_8 = new QLabel(groupBox_6);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 170, 571, 16));
        doubleSpinBox_MASSFSI = new QDoubleSpinBox(groupBox_6);
        doubleSpinBox_MASSFSI->setObjectName(QString::fromUtf8("doubleSpinBox_MASSFSI"));
        doubleSpinBox_MASSFSI->setGeometry(QRect(10, 190, 62, 22));
        doubleSpinBox_MASSFSI->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_MASSFSI->setDecimals(3);
        doubleSpinBox_MASSFSI->setValue(0.081);
        label_9 = new QLabel(groupBox_6);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 230, 371, 16));
        doubleSpinBox_MassCG = new QDoubleSpinBox(groupBox_6);
        doubleSpinBox_MassCG->setObjectName(QString::fromUtf8("doubleSpinBox_MassCG"));
        doubleSpinBox_MassCG->setGeometry(QRect(10, 250, 62, 22));
        doubleSpinBox_MassCG->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_MassCG->setDecimals(3);
        doubleSpinBox_MassCG->setValue(0.25);
        doubleSpinBox_MassCG_2 = new QDoubleSpinBox(groupBox_6);
        doubleSpinBox_MassCG_2->setObjectName(QString::fromUtf8("doubleSpinBox_MassCG_2"));
        doubleSpinBox_MassCG_2->setGeometry(QRect(80, 250, 62, 22));
        doubleSpinBox_MassCG_2->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_MassCG_2->setDecimals(3);
        doubleSpinBox_MassCG_2->setSingleStep(0.1);
        doubleSpinBox_MassCG_2->setValue(0.1);
        doubleSpinBox_MassCG_3 = new QDoubleSpinBox(groupBox_6);
        doubleSpinBox_MassCG_3->setObjectName(QString::fromUtf8("doubleSpinBox_MassCG_3"));
        doubleSpinBox_MassCG_3->setGeometry(QRect(150, 250, 62, 22));
        doubleSpinBox_MassCG_3->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_MassCG_3->setDecimals(3);
        doubleSpinBox_MassCG_3->setSingleStep(0.1);
        doubleSpinBox_MassCG_3->setValue(0.125);
        label_10 = new QLabel(groupBox_6);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 287, 281, 16));
        doubleSpinBox_RotationCG_3 = new QDoubleSpinBox(groupBox_6);
        doubleSpinBox_RotationCG_3->setObjectName(QString::fromUtf8("doubleSpinBox_RotationCG_3"));
        doubleSpinBox_RotationCG_3->setGeometry(QRect(150, 307, 62, 22));
        doubleSpinBox_RotationCG_3->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_RotationCG_3->setDecimals(3);
        doubleSpinBox_RotationCG_3->setSingleStep(0.1);
        doubleSpinBox_RotationCG_3->setValue(0.125);
        doubleSpinBox_RotationCG_2 = new QDoubleSpinBox(groupBox_6);
        doubleSpinBox_RotationCG_2->setObjectName(QString::fromUtf8("doubleSpinBox_RotationCG_2"));
        doubleSpinBox_RotationCG_2->setGeometry(QRect(80, 307, 62, 22));
        doubleSpinBox_RotationCG_2->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_RotationCG_2->setDecimals(3);
        doubleSpinBox_RotationCG_2->setSingleStep(0.1);
        doubleSpinBox_RotationCG_2->setValue(0.1);
        doubleSpinBox_RotationCG_1 = new QDoubleSpinBox(groupBox_6);
        doubleSpinBox_RotationCG_1->setObjectName(QString::fromUtf8("doubleSpinBox_RotationCG_1"));
        doubleSpinBox_RotationCG_1->setGeometry(QRect(10, 307, 62, 22));
        doubleSpinBox_RotationCG_1->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_RotationCG_1->setDecimals(3);
        doubleSpinBox_RotationCG_1->setValue(0.25);
        label_11 = new QLabel(groupBox_6);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 341, 411, 16));
        doubleSpinBox_InertiaX11 = new QDoubleSpinBox(groupBox_6);
        doubleSpinBox_InertiaX11->setObjectName(QString::fromUtf8("doubleSpinBox_InertiaX11"));
        doubleSpinBox_InertiaX11->setGeometry(QRect(30, 381, 62, 22));
        doubleSpinBox_InertiaX11->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_InertiaX11->setValue(7);
        doubleSpinBox_InertiaX12 = new QDoubleSpinBox(groupBox_6);
        doubleSpinBox_InertiaX12->setObjectName(QString::fromUtf8("doubleSpinBox_InertiaX12"));
        doubleSpinBox_InertiaX12->setGeometry(QRect(100, 381, 62, 22));
        doubleSpinBox_InertiaX12->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_InertiaX13 = new QDoubleSpinBox(groupBox_6);
        doubleSpinBox_InertiaX13->setObjectName(QString::fromUtf8("doubleSpinBox_InertiaX13"));
        doubleSpinBox_InertiaX13->setGeometry(QRect(170, 381, 62, 22));
        doubleSpinBox_InertiaX13->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        line = new QFrame(groupBox_6);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 370, 15, 100));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(groupBox_6);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(18, 364, 21, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        doubleSpinBox_InertiaX22 = new QDoubleSpinBox(groupBox_6);
        doubleSpinBox_InertiaX22->setObjectName(QString::fromUtf8("doubleSpinBox_InertiaX22"));
        doubleSpinBox_InertiaX22->setGeometry(QRect(100, 411, 62, 22));
        doubleSpinBox_InertiaX22->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_InertiaX22->setValue(7);
        doubleSpinBox_InertiaX23 = new QDoubleSpinBox(groupBox_6);
        doubleSpinBox_InertiaX23->setObjectName(QString::fromUtf8("doubleSpinBox_InertiaX23"));
        doubleSpinBox_InertiaX23->setGeometry(QRect(170, 411, 62, 22));
        doubleSpinBox_InertiaX23->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_InertiaX33 = new QDoubleSpinBox(groupBox_6);
        doubleSpinBox_InertiaX33->setObjectName(QString::fromUtf8("doubleSpinBox_InertiaX33"));
        doubleSpinBox_InertiaX33->setGeometry(QRect(170, 441, 62, 22));
        doubleSpinBox_InertiaX33->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_InertiaX33->setValue(6);
        line_3 = new QFrame(groupBox_6);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(18, 460, 21, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(groupBox_6);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(240, 371, 15, 100));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(groupBox_6);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(227, 460, 21, 16));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(groupBox_6);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(227, 364, 21, 16));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        label_12 = new QLabel(groupBox_6);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 490, 401, 16));
        spinBox_Ux = new QSpinBox(groupBox_6);
        spinBox_Ux->setObjectName(QString::fromUtf8("spinBox_Ux"));
        spinBox_Ux->setGeometry(QRect(20, 510, 46, 22));
        spinBox_Ux->setMinimum(-1);
        spinBox_Ux->setMaximum(1);
        spinBox_Ux->setValue(1);
        spinBox_Uy = new QSpinBox(groupBox_6);
        spinBox_Uy->setObjectName(QString::fromUtf8("spinBox_Uy"));
        spinBox_Uy->setGeometry(QRect(80, 510, 46, 22));
        spinBox_Uy->setMinimum(-1);
        spinBox_Uy->setMaximum(1);
        spinBox_Uy->setValue(1);
        spinBox_Uz = new QSpinBox(groupBox_6);
        spinBox_Uz->setObjectName(QString::fromUtf8("spinBox_Uz"));
        spinBox_Uz->setGeometry(QRect(140, 510, 46, 22));
        spinBox_Uz->setMinimum(-1);
        spinBox_Uz->setMaximum(1);
        spinBox_ROTx = new QSpinBox(groupBox_6);
        spinBox_ROTx->setObjectName(QString::fromUtf8("spinBox_ROTx"));
        spinBox_ROTx->setGeometry(QRect(200, 510, 46, 22));
        spinBox_ROTx->setMinimum(-1);
        spinBox_ROTx->setMaximum(1);
        spinBox_ROTx->setValue(1);
        spinBox_ROTy = new QSpinBox(groupBox_6);
        spinBox_ROTy->setObjectName(QString::fromUtf8("spinBox_ROTy"));
        spinBox_ROTy->setGeometry(QRect(260, 510, 46, 22));
        spinBox_ROTy->setMinimum(-1);
        spinBox_ROTy->setMaximum(1);
        spinBox_ROTy->setValue(1);
        spinBox_ROTz = new QSpinBox(groupBox_6);
        spinBox_ROTz->setObjectName(QString::fromUtf8("spinBox_ROTz"));
        spinBox_ROTz->setGeometry(QRect(320, 510, 46, 22));
        spinBox_ROTz->setMinimum(-1);
        spinBox_ROTz->setMaximum(1);
        spinBox_ROTz->setValue(1);
        label_13 = new QLabel(groupBox_6);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 550, 381, 16));
        spinBox_nptf_1 = new QSpinBox(groupBox_6);
        spinBox_nptf_1->setObjectName(QString::fromUtf8("spinBox_nptf_1"));
        spinBox_nptf_1->setGeometry(QRect(10, 580, 46, 22));
        spinBox_nptf_1->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_nptf_2 = new QDoubleSpinBox(groupBox_6);
        doubleSpinBox_nptf_2->setObjectName(QString::fromUtf8("doubleSpinBox_nptf_2"));
        doubleSpinBox_nptf_2->setGeometry(QRect(10, 610, 62, 22));
        doubleSpinBox_nptf_2->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_nptf_3 = new QDoubleSpinBox(groupBox_6);
        doubleSpinBox_nptf_3->setObjectName(QString::fromUtf8("doubleSpinBox_nptf_3"));
        doubleSpinBox_nptf_3->setGeometry(QRect(10, 640, 62, 22));
        doubleSpinBox_nptf_3->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_nptf_3->setValue(10);
        doubleSpinBox_nptf_4 = new QDoubleSpinBox(groupBox_6);
        doubleSpinBox_nptf_4->setObjectName(QString::fromUtf8("doubleSpinBox_nptf_4"));
        doubleSpinBox_nptf_4->setGeometry(QRect(10, 670, 62, 22));
        doubleSpinBox_nptf_4->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_nptf_4->setValue(15);
        doubleSpinBox_nptf_5 = new QDoubleSpinBox(groupBox_6);
        doubleSpinBox_nptf_5->setObjectName(QString::fromUtf8("doubleSpinBox_nptf_5"));
        doubleSpinBox_nptf_5->setGeometry(QRect(80, 610, 62, 22));
        doubleSpinBox_nptf_5->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_nptf_6 = new QDoubleSpinBox(groupBox_6);
        doubleSpinBox_nptf_6->setObjectName(QString::fromUtf8("doubleSpinBox_nptf_6"));
        doubleSpinBox_nptf_6->setGeometry(QRect(80, 640, 62, 22));
        doubleSpinBox_nptf_6->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_nptf_7 = new QDoubleSpinBox(groupBox_6);
        doubleSpinBox_nptf_7->setObjectName(QString::fromUtf8("doubleSpinBox_nptf_7"));
        doubleSpinBox_nptf_7->setGeometry(QRect(80, 670, 62, 22));
        doubleSpinBox_nptf_7->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_nptf_7->setValue(2);
        label_14 = new QLabel(groupBox_6);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(190, 590, 771, 111));
        pushButtonSaveFSI = new QPushButton(groupBox_6);
        pushButtonSaveFSI->setObjectName(QString::fromUtf8("pushButtonSaveFSI"));
        pushButtonSaveFSI->setGeometry(QRect(940, 20, 101, 28));
        tabWidget_View->addTab(tab_Fsi, QString());
        tab_Material = new QWidget();
        tab_Material->setObjectName(QString::fromUtf8("tab_Material"));
        groupBox_material = new QGroupBox(tab_Material);
        groupBox_material->setObjectName(QString::fromUtf8("groupBox_material"));
        groupBox_material->setGeometry(QRect(20, 20, 1071, 650));
        groupBox_material->setMinimumSize(QSize(1071, 650));
        groupBox_material->setMaximumSize(QSize(1071, 600));
        label_15 = new QLabel(groupBox_material);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(10, 20, 681, 41));
        scrollArea_material = new QScrollArea(groupBox_material);
        scrollArea_material->setObjectName(QString::fromUtf8("scrollArea_material"));
        scrollArea_material->setGeometry(QRect(0, 60, 700, 581));
        scrollArea_material->setMinimumSize(QSize(700, 500));
        scrollArea_material->setMaximumSize(QSize(700, 600));
        scrollArea_material->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 698, 579));
        gridLayout_4 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalSpacer = new QSpacerItem(20, 545, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 1, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));

        gridLayout_4->addLayout(gridLayout_2, 0, 0, 1, 1);

        scrollArea_material->setWidget(scrollAreaWidgetContents_2);
        groupBox_7 = new QGroupBox(groupBox_material);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(730, 20, 211, 61));
        groupBox_7->setAlignment(Qt::AlignCenter);
        pushButton_newMaterial = new QPushButton(groupBox_7);
        pushButton_newMaterial->setObjectName(QString::fromUtf8("pushButton_newMaterial"));
        pushButton_newMaterial->setGeometry(QRect(10, 20, 93, 28));
        pushButton_delMaterial = new QPushButton(groupBox_7);
        pushButton_delMaterial->setObjectName(QString::fromUtf8("pushButton_delMaterial"));
        pushButton_delMaterial->setGeometry(QRect(110, 20, 93, 28));
        pushButton_saveMaterial = new QPushButton(groupBox_material);
        pushButton_saveMaterial->setObjectName(QString::fromUtf8("pushButton_saveMaterial"));
        pushButton_saveMaterial->setGeometry(QRect(730, 90, 93, 28));
        tabWidget_View->addTab(tab_Material, QString());
        tabMesh = new QWidget();
        tabMesh->setObjectName(QString::fromUtf8("tabMesh"));
        qvtkWidget = new QVTKWidget(tabMesh);
        qvtkWidget->setObjectName(QString::fromUtf8("qvtkWidget"));
        qvtkWidget->setGeometry(QRect(170, 30, 921, 681));
        tableWidget = new QTableWidget(tabMesh);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(30, 30, 122, 182));
        checkBoxWireframe = new QCheckBox(tabMesh);
        checkBoxWireframe->setObjectName(QString::fromUtf8("checkBoxWireframe"));
        checkBoxWireframe->setGeometry(QRect(1000, 10, 91, 20));
        tabWidget_View->addTab(tabMesh, QString());
        pushButton_RunEdgeCFDSolver = new QPushButton(centralWidget);
        pushButton_RunEdgeCFDSolver->setObjectName(QString::fromUtf8("pushButton_RunEdgeCFDSolver"));
        pushButton_RunEdgeCFDSolver->setGeometry(QRect(10, 10, 141, 28));
        runEdgeCFDClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(runEdgeCFDClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1149, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuConfigure = new QMenu(menuBar);
        menuConfigure->setObjectName(QString::fromUtf8("menuConfigure"));
        runEdgeCFDClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(runEdgeCFDClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        runEdgeCFDClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(runEdgeCFDClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        runEdgeCFDClass->setStatusBar(statusBar);
        QWidget::setTabOrder(lineEdit_WorkingDir, pushButton_WorkingDir);
        QWidget::setTabOrder(pushButton_WorkingDir, lineEdit_jobName);
        QWidget::setTabOrder(lineEdit_jobName, pushButton_Run);
        QWidget::setTabOrder(pushButton_Run, tabWidget_View);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuConfigure->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionAbout);
        menuConfigure->addAction(actionAnsys_Path);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionSave);

        retranslateUi(runEdgeCFDClass);

        tabWidget_View->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(runEdgeCFDClass);
    } // setupUi

    void retranslateUi(QMainWindow *runEdgeCFDClass)
    {
        runEdgeCFDClass->setWindowTitle(QApplication::translate("runEdgeCFDClass", "runEdgeCFD - ver. 0.10", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("runEdgeCFDClass", "Exit", 0, QApplication::UnicodeUTF8));
        actionAnsys_Path->setText(QApplication::translate("runEdgeCFDClass", "Ansys Path", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("runEdgeCFDClass", "About", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("runEdgeCFDClass", "Save (Ctrl+S)", 0, QApplication::UnicodeUTF8));
        actionSave->setShortcut(QApplication::translate("runEdgeCFDClass", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("runEdgeCFDClass", "Open(Ctrl+O)", 0, QApplication::UnicodeUTF8));
        actionOpen->setIconText(QApplication::translate("runEdgeCFDClass", "Open(Ctrl+O)", 0, QApplication::UnicodeUTF8));
        actionOpen->setShortcut(QApplication::translate("runEdgeCFDClass", "Ctrl+O", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        tabWidget_View->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        groupBox->setTitle(QApplication::translate("runEdgeCFDClass", "Initial Setup", 0, QApplication::UnicodeUTF8));
        pushButton_Run->setText(QApplication::translate("runEdgeCFDClass", "MAKE", 0, QApplication::UnicodeUTF8));
        label_AnsysVersion->setText(QApplication::translate("runEdgeCFDClass", "<html><head/><body><p><br/></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_dbFile->setText(QApplication::translate("runEdgeCFDClass", "Db File:", 0, QApplication::UnicodeUTF8));
        lineEdit_WorkingDir->setText(QString());
        label_workDir->setText(QApplication::translate("runEdgeCFDClass", "Working Directory:", 0, QApplication::UnicodeUTF8));
        pushButton_WorkingDir->setText(QApplication::translate("runEdgeCFDClass", "Browse", 0, QApplication::UnicodeUTF8));
        label_jobName->setText(QApplication::translate("runEdgeCFDClass", "Job Name:", 0, QApplication::UnicodeUTF8));
        pushButton_dbFile->setText(QApplication::translate("runEdgeCFDClass", "Browse", 0, QApplication::UnicodeUTF8));
        tabWidget_View->setTabText(tabWidget_View->indexOf(tab_config), QApplication::translate("runEdgeCFDClass", "File Management", 0, QApplication::UnicodeUTF8));
        tabWidget_View->setTabWhatsThis(tabWidget_View->indexOf(tab_config), QApplication::translate("runEdgeCFDClass", "<html><head/><body><p>Aba de configura\303\247\303\243o do nome do Arquivo (FILENAME)</p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("runEdgeCFDClass", "DESCRIPTION", 0, QApplication::UnicodeUTF8));
        groupBox_SETUP->setTitle(QApplication::translate("runEdgeCFDClass", "Define Components  - DOF", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("runEdgeCFDClass", "#  COMPONENTE CC  LABEL   VALOR", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        scrollArea_Setup->setStatusTip(QApplication::translate("runEdgeCFDClass", "DOF Values", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        pushButtonSaveSetupFile->setText(QApplication::translate("runEdgeCFDClass", "Save Setup File", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("runEdgeCFDClass", "Create and Delete - DOF", 0, QApplication::UnicodeUTF8));
        pushButton_newDOF->setText(QApplication::translate("runEdgeCFDClass", "New", 0, QApplication::UnicodeUTF8));
        pushButton_delDOF->setText(QApplication::translate("runEdgeCFDClass", "Delete", 0, QApplication::UnicodeUTF8));
        lineEdit_descriptionSetup->setText(QApplication::translate("runEdgeCFDClass", "MODELO DE NAVIO FPSO EM ESCALA 1:100", 0, QApplication::UnicodeUTF8));
        pushButton_RunSetupEdgeCFD->setText(QApplication::translate("runEdgeCFDClass", "Run Setup EdgeCFD", 0, QApplication::UnicodeUTF8));
        tabWidget_View->setTabText(tabWidget_View->indexOf(tab_Setup), QApplication::translate("runEdgeCFDClass", "SETUP", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("runEdgeCFDClass", "JOIN", 0, QApplication::UnicodeUTF8));
        textEdit->setHtml(QApplication::translate("runEdgeCFDClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$====================================================	$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$ GENERAL RULES:					$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$ ============                                              			$</span></p>\n"
"<p style=\" margin-top:0px; margin"
                        "-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$                                                            			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$ - Do not skip lines or the program will produce an error   		$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$ - Lines started with $ are considered as comment lines     		$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$                                                            			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><spa"
                        "n style=\" font-size:8pt;\">$ INPUT PARAMETERS:                                          			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$ ===============                                          			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$                                                            			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$                                                            			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$ NP     : integer &gt; 0                                      "
                        " 			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$          number of processes to be generated               		$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$                                                            			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$ BLK   : integer                                            			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$         Controls the use of mesh coloring algorithm for    		$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin"
                        "-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$         vectorization purposes as following:               			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$         n &lt; 0: Group blocks in chunks                      			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$         n = 0: Do not perform mesh coloring                			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$         n &gt; 0: Group colored blocks (VECTORIZATION)        		$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$"
                        "         where &quot;n&quot; is the size of the block                 			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$                                                            			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$ RED   : integer (0 or 1)                                   			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$         0: Keep the original mesh                          			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$         1: Perform Lohner data reordering to build reduced 		$</span></p>\n"
""
                        "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$            edge structure                                  			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$                                                            			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$ ORD   : integer (0 or 1)                                   			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$         Controls if element ordering according to edges   		$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block"
                        "-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$         will be performed or not                           			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$         0: Do not perform element reordering               		$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$         1: Perform element reordering                      			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$                                                            			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$ RCM   : integer (0 or 1)  "
                        "                                 			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$         0: Keep original mesh                              			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$         1: Perform Reverse Cuthill Mckee data reordering  		$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$            to reduce matrix bandwidth                      			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$                                                            			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bot"
                        "tom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$ KEQ   : integer (0 or 1)                                   			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$         Equation numbering schemes                         			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$         0: Fully coupled                                   			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$         1: u-p segregated                                  			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span "
                        "style=\" font-size:8pt;\">$                                                            			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$ FMT   : integer (0 or 1)                                   			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$         0: Output data in binary format                    			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$         1: Output data in ASCII format                     			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$						$</span></p>\n"
"<p style=\" margin-top:0px; margin-bott"
                        "om:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$                                                            			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$ ANS   : integer (0 or 1)                                   			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$         0: Do not write Ansys macro file                   			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$         1: Writes Ansys macro file                         			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span s"
                        "tyle=\" font-size:8pt;\">$                                                            			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$ PMV   : integer (0 or 1)                                   			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$         0: Do not write PMVis                              			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$         1: Writes PMVis file                               			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$                                                            			"
                        "$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$ LDE   : integer (0 or 1)                                   			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$         apply edge reordering to prescribed edges          		$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$         0: Do not perform edge reordering                  			$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$         1: Performs edge reordering				$</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-inde"
                        "nt:0; text-indent:0px;\"><span style=\" font-size:8pt;\">$====================================================	$</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_NP->setText(QApplication::translate("runEdgeCFDClass", "NP", 0, QApplication::UnicodeUTF8));
        label_BLK->setText(QApplication::translate("runEdgeCFDClass", "BLK", 0, QApplication::UnicodeUTF8));
        label_RED->setText(QApplication::translate("runEdgeCFDClass", "RED", 0, QApplication::UnicodeUTF8));
        label_ORD->setText(QApplication::translate("runEdgeCFDClass", "ORD", 0, QApplication::UnicodeUTF8));
        label_RCM->setText(QApplication::translate("runEdgeCFDClass", "RCM", 0, QApplication::UnicodeUTF8));
        label_KEQ->setText(QApplication::translate("runEdgeCFDClass", "KEQ", 0, QApplication::UnicodeUTF8));
        label_FMT->setText(QApplication::translate("runEdgeCFDClass", "FMT", 0, QApplication::UnicodeUTF8));
        label_ANS->setText(QApplication::translate("runEdgeCFDClass", "ANS", 0, QApplication::UnicodeUTF8));
        label_PMV->setText(QApplication::translate("runEdgeCFDClass", "PMV", 0, QApplication::UnicodeUTF8));
        label_LDE->setText(QApplication::translate("runEdgeCFDClass", "LDE", 0, QApplication::UnicodeUTF8));
        pushButton_RunPreEdgeCFD->setText(QApplication::translate("runEdgeCFDClass", "Run PRE EdgeCFD", 0, QApplication::UnicodeUTF8));
        tabWidget_View->setTabText(tabWidget_View->indexOf(tab_Pre), QApplication::translate("runEdgeCFDClass", "PRE", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("runEdgeCFDClass", "INPUT.DAT", 0, QApplication::UnicodeUTF8));
        pushButtonSaveInput->setText(QApplication::translate("runEdgeCFDClass", "Save Input File", 0, QApplication::UnicodeUTF8));
        tabWidget_View->setTabText(tabWidget_View->indexOf(tab_Input), QApplication::translate("runEdgeCFDClass", "INPUT", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("runEdgeCFDClass", "FSI.DAT", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("runEdgeCFDClass", "$ Arquivo de Dados FSI: FPSO Section: roll", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("runEdgeCFDClass", "$  SolveFSI  (.TRUE. OR .FALSE.)  ", 0, QApplication::UnicodeUTF8));
        comboBox_FSI->clear();
        comboBox_FSI->insertItems(0, QStringList()
         << QApplication::translate("runEdgeCFDClass", ".TRUE.", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("runEdgeCFDClass", ".FALSE.", 0, QApplication::UnicodeUTF8)
        );
        label_7->setText(QApplication::translate("runEdgeCFDClass", "$  Instante de tempo de in\303\255cio do movimento da malha ALE :  START_ALE ( 1 REAL*8 )", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("runEdgeCFDClass", "$  Mass of the body  : MASSFSI ( 1 REAL*8 )      [M]", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("runEdgeCFDClass", "$  Center of mass : CG ( 3 REAL*8 )      [M]", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("runEdgeCFDClass", "$  Center of rotation : CG ( 3 REAL*8 )      [M]", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("runEdgeCFDClass", "$  Tensor of Inertia : X11 X12 X13 X22 X23 X33 ( 6 REAL*8 ) [M][L2]", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("runEdgeCFDClass", "$  Movimentos prescritos: ngl_body(1:6) Ux Uy Uz ROTx ROTy ROTz ", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("runEdgeCFDClass", "$  Fun\303\247\303\243o prescrita: nptf < 11 [L] ou [grau]", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("runEdgeCFDClass", "$ README\n"
"NGL_BODY =  0 LIVRE PARA DESLOCAR \n"
"NGL_BODY =  1 PRESO\n"
"NGL_BODY = -1 DESLOCAMENTO PRESCRITO, EXIGE NPTF > 0\n"
"\n"
"NPTF = PONTOS DA FUN\303\207\303\203O TEMPORAL DE DESCOLAMENTO PRESCRITO, S\303\223 \303\211 PERMITIDA UMA FUN\303\207\303\203O\n"
"Nptf < 11, S\303\263 permite at\303\251 10 pares de pontos para a fun\303\247\303\243o ( tempo e valor ).", 0, QApplication::UnicodeUTF8));
        pushButtonSaveFSI->setText(QApplication::translate("runEdgeCFDClass", "Save FSI File", 0, QApplication::UnicodeUTF8));
        tabWidget_View->setTabText(tabWidget_View->indexOf(tab_Fsi), QApplication::translate("runEdgeCFDClass", "FSI", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        groupBox_material->setToolTip(QApplication::translate("runEdgeCFDClass", "Material Proprieties", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        groupBox_material->setTitle(QApplication::translate("runEdgeCFDClass", "Material Setup", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("runEdgeCFDClass", "ID            DENS         VISC         PAR3          PAR4          KXX            KYY            KZZ            SPH            NAME\n"
"===============================================================================", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("runEdgeCFDClass", "Create and Delete - Material", 0, QApplication::UnicodeUTF8));
        pushButton_newMaterial->setText(QApplication::translate("runEdgeCFDClass", "New", 0, QApplication::UnicodeUTF8));
        pushButton_delMaterial->setText(QApplication::translate("runEdgeCFDClass", "Delete", 0, QApplication::UnicodeUTF8));
        pushButton_saveMaterial->setText(QApplication::translate("runEdgeCFDClass", "Save Material", 0, QApplication::UnicodeUTF8));
        tabWidget_View->setTabText(tabWidget_View->indexOf(tab_Material), QApplication::translate("runEdgeCFDClass", "MATERIAL", 0, QApplication::UnicodeUTF8));
        checkBoxWireframe->setText(QApplication::translate("runEdgeCFDClass", "Wireframe", 0, QApplication::UnicodeUTF8));
        tabWidget_View->setTabText(tabWidget_View->indexOf(tabMesh), QApplication::translate("runEdgeCFDClass", "MESH", 0, QApplication::UnicodeUTF8));
        pushButton_RunEdgeCFDSolver->setText(QApplication::translate("runEdgeCFDClass", "Run EdgeCFDSolver", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("runEdgeCFDClass", "File", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("runEdgeCFDClass", "Help", 0, QApplication::UnicodeUTF8));
        menuConfigure->setTitle(QApplication::translate("runEdgeCFDClass", "Configure", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class runEdgeCFDClass: public Ui_runEdgeCFDClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUNEDGECFD_H
