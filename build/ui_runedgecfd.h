/********************************************************************************
** Form generated from reading UI file 'runedgecfd.ui'
**
** Created: Mon 7. Oct 16:30:15 2013
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
#include <QtGui/QToolBox>
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
    QAction *actionRenderColor;
    QWidget *centralWidget;
    QGridLayout *gridLayout_24;
    QPushButton *pushButton_RunEdgeCFDSolver;
    QSpacerItem *horizontalSpacer_13;
    QTabWidget *tabWidget_View;
    QWidget *tab_config;
    QGridLayout *gridLayout_25;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *horizontalSpacer_15;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QLabel *label_workDir;
    QLineEdit *lineEdit_WorkingDir;
    QPushButton *pushButton_WorkingDir;
    QLabel *label_jobName;
    QLineEdit *lineEdit_jobName;
    QLabel *label_dbFile;
    QLineEdit *lineEdit_dbFile;
    QPushButton *pushButton_dbFile;
    QPushButton *pushButton_Run;
    QSpacerItem *horizontalSpacer_14;
    QLabel *label_AnsysVersion;
    QSpacerItem *horizontalSpacer_16;
    QWidget *tab_Setup;
    QGridLayout *gridLayout_21;
    QVTKWidget *qvtkWidget;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_20;
    QPushButton *pushButton_newDOF;
    QPushButton *pushButton_delDOF;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_23;
    QLineEdit *lineEdit_descriptionSetup;
    QToolBox *toolBox;
    QWidget *dof;
    QGridLayout *gridLayout_18;
    QPushButton *pushButtonSaveSetupFile;
    QScrollArea *scrollArea_Setup;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_19;
    QLabel *label_43;
    QLabel *label_41;
    QLabel *label_42;
    QSpacerItem *verticalSpacer_5;
    QWidget *parts;
    QGridLayout *gridLayout_22;
    QGridLayout *gridLayoutMesh;
    QTableWidget *tableWidget;
    QCheckBox *checkBoxWireframe;
    QPushButton *pushButton_RunSetupEdgeCFD;
    QSpacerItem *horizontalSpacer_12;
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
    QGridLayout *gridLayout_27;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_26;
    QSpinBox *spinBox_input1;
    QPushButton *pushButtonSaveInput;
    QLineEdit *lineEdit_InputFileName;
    QDoubleSpinBox *doubleSpinBox_input2;
    QDoubleSpinBox *doubleSpinBox_input1;
    QSpinBox *spinBox_input3;
    QSpinBox *spinBox_input2;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *horizontalSpacer_17;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_18;
    QWidget *tab_Fsi;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_4;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_8;
    QLabel *label_18;
    QDoubleSpinBox *doubleSpinBox_FSI_ALE1;
    QDoubleSpinBox *doubleSpinBox_FSI_ALE2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_14;
    QLineEdit *lineEdit_InertiaX11;
    QLineEdit *lineEdit_InertiaX12;
    QLineEdit *lineEdit_InertiaX13;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *lineEdit_InertiaX22;
    QLineEdit *lineEdit_InertiaX23;
    QSpacerItem *horizontalSpacer_7;
    QLineEdit *lineEdit_InertiaX33;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_22;
    QGridLayout *gridLayout_12;
    QLabel *label_20;
    QDoubleSpinBox *doubleSpinBox_MassCG1;
    QDoubleSpinBox *doubleSpinBox_MassCG2;
    QDoubleSpinBox *doubleSpinBox_MassCG3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_10;
    QGridLayout *gridLayout_16;
    QDoubleSpinBox *doubleSpinBox_VInitial_Wx;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_VInitial_vx;
    QDoubleSpinBox *doubleSpinBox_VInitial_vy;
    QDoubleSpinBox *doubleSpinBox_VInitial_vz;
    QDoubleSpinBox *doubleSpinBox_VInitial_Wy;
    QDoubleSpinBox *doubleSpinBox_VInitial_Wz;
    QLabel *label_35;
    QLabel *label_36;
    QLabel *label_37;
    QLabel *label_38;
    QLabel *label_39;
    QLabel *label_40;
    QGridLayout *gridLayout_17;
    QDoubleSpinBox *doubleSpinBox_nptf22;
    QDoubleSpinBox *doubleSpinBox_nptf12;
    QLabel *label_24;
    QDoubleSpinBox *doubleSpinBox_nptf21;
    QLabel *label_23;
    QDoubleSpinBox *doubleSpinBox_nptf11;
    QDoubleSpinBox *doubleSpinBox_nptf31;
    QDoubleSpinBox *doubleSpinBox_nptf32;
    QSpinBox *spinBox_nptf;
    QGridLayout *gridLayout_11;
    QLabel *label_19;
    QDoubleSpinBox *doubleSpinBox_MASSFSI;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_9;
    QGridLayout *gridLayout_15;
    QLabel *label_12;
    QSpinBox *spinBox_Ux;
    QSpinBox *spinBox_Uy;
    QSpinBox *spinBox_Uz;
    QSpinBox *spinBox_ROTx;
    QSpinBox *spinBox_ROTy;
    QSpinBox *spinBox_ROTz;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *label_29;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label_34;
    QGridLayout *gridLayout_13;
    QLabel *label_21;
    QDoubleSpinBox *doubleSpinBox_RotationCG1;
    QDoubleSpinBox *doubleSpinBox_RotationCG2;
    QDoubleSpinBox *doubleSpinBox_RotationCG3;
    QSpacerItem *horizontalSpacer_5;
    QGridLayout *gridLayout_7;
    QLabel *label_17;
    QComboBox *comboBox_FSI;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonSaveFSI;
    QSpacerItem *horizontalSpacer_11;
    QWidget *tab_Material;
    QGroupBox *groupBox_material;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_6;
    QPushButton *pushButton_newMaterial;
    QPushButton *pushButton_delMaterial;
    QPushButton *pushButton_saveMaterial;
    QSpacerItem *verticalSpacer_2;
    QScrollArea *scrollArea_material;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_2;
    QLabel *label_13;
    QLabel *label_6;
    QLabel *label;
    QLabel *label_10;
    QLabel *label_8;
    QLabel *label_7;
    QLabel *label_5;
    QLabel *label_14;
    QLabel *label_11;
    QLabel *label_9;
    QSpacerItem *verticalSpacer_3;
    QWidget *tabMesh;
    QGridLayout *gridLayout_10;
    QGroupBox *groupBox_6;
    QPushButton *pushButtonConnect;
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
        runEdgeCFDClass->resize(1106, 816);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../Users/Nacib/.designer/backup/Edge.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        runEdgeCFDClass->setWindowIcon(icon);
        actionExit = new QAction(runEdgeCFDClass);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../Users/Nacib/.designer/backup/cancel.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon1);
        actionAnsys_Path = new QAction(runEdgeCFDClass);
        actionAnsys_Path->setObjectName(QString::fromUtf8("actionAnsys_Path"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/ansys.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actionAnsys_Path->setIcon(icon2);
        actionAbout = new QAction(runEdgeCFDClass);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/about.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon3);
        actionSave = new QAction(runEdgeCFDClass);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/save.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon4);
        actionOpen = new QAction(runEdgeCFDClass);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/open.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon5);
        actionRenderColor = new QAction(runEdgeCFDClass);
        actionRenderColor->setObjectName(QString::fromUtf8("actionRenderColor"));
        centralWidget = new QWidget(runEdgeCFDClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_24 = new QGridLayout(centralWidget);
        gridLayout_24->setSpacing(6);
        gridLayout_24->setContentsMargins(11, 11, 11, 11);
        gridLayout_24->setObjectName(QString::fromUtf8("gridLayout_24"));
        pushButton_RunEdgeCFDSolver = new QPushButton(centralWidget);
        pushButton_RunEdgeCFDSolver->setObjectName(QString::fromUtf8("pushButton_RunEdgeCFDSolver"));

        gridLayout_24->addWidget(pushButton_RunEdgeCFDSolver, 0, 0, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(978, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_24->addItem(horizontalSpacer_13, 0, 1, 1, 1);

        tabWidget_View = new QTabWidget(centralWidget);
        tabWidget_View->setObjectName(QString::fromUtf8("tabWidget_View"));
        tab_config = new QWidget();
        tab_config->setObjectName(QString::fromUtf8("tab_config"));
        gridLayout_25 = new QGridLayout(tab_config);
        gridLayout_25->setSpacing(6);
        gridLayout_25->setContentsMargins(11, 11, 11, 11);
        gridLayout_25->setObjectName(QString::fromUtf8("gridLayout_25"));
        verticalSpacer_6 = new QSpacerItem(20, 38, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_25->addItem(verticalSpacer_6, 0, 1, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_25->addItem(verticalSpacer_7, 2, 1, 1, 1);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_25->addItem(horizontalSpacer_15, 1, 2, 1, 1);

        groupBox = new QGroupBox(tab_config);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_workDir = new QLabel(groupBox);
        label_workDir->setObjectName(QString::fromUtf8("label_workDir"));
        label_workDir->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout_5->addWidget(label_workDir, 0, 0, 1, 1);

        lineEdit_WorkingDir = new QLineEdit(groupBox);
        lineEdit_WorkingDir->setObjectName(QString::fromUtf8("lineEdit_WorkingDir"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_WorkingDir->sizePolicy().hasHeightForWidth());
        lineEdit_WorkingDir->setSizePolicy(sizePolicy1);
        lineEdit_WorkingDir->setMinimumSize(QSize(500, 0));
        lineEdit_WorkingDir->setReadOnly(false);

        gridLayout_5->addWidget(lineEdit_WorkingDir, 0, 1, 1, 1);

        pushButton_WorkingDir = new QPushButton(groupBox);
        pushButton_WorkingDir->setObjectName(QString::fromUtf8("pushButton_WorkingDir"));

        gridLayout_5->addWidget(pushButton_WorkingDir, 0, 2, 1, 1);

        label_jobName = new QLabel(groupBox);
        label_jobName->setObjectName(QString::fromUtf8("label_jobName"));
        label_jobName->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout_5->addWidget(label_jobName, 1, 0, 1, 1);

        lineEdit_jobName = new QLineEdit(groupBox);
        lineEdit_jobName->setObjectName(QString::fromUtf8("lineEdit_jobName"));
        sizePolicy1.setHeightForWidth(lineEdit_jobName->sizePolicy().hasHeightForWidth());
        lineEdit_jobName->setSizePolicy(sizePolicy1);
        lineEdit_jobName->setMinimumSize(QSize(500, 0));
        lineEdit_jobName->setAcceptDrops(true);
        lineEdit_jobName->setMaxLength(300);
        lineEdit_jobName->setDragEnabled(false);

        gridLayout_5->addWidget(lineEdit_jobName, 1, 1, 1, 1);

        label_dbFile = new QLabel(groupBox);
        label_dbFile->setObjectName(QString::fromUtf8("label_dbFile"));

        gridLayout_5->addWidget(label_dbFile, 2, 0, 1, 1);

        lineEdit_dbFile = new QLineEdit(groupBox);
        lineEdit_dbFile->setObjectName(QString::fromUtf8("lineEdit_dbFile"));
        sizePolicy1.setHeightForWidth(lineEdit_dbFile->sizePolicy().hasHeightForWidth());
        lineEdit_dbFile->setSizePolicy(sizePolicy1);
        lineEdit_dbFile->setMinimumSize(QSize(500, 0));
        lineEdit_dbFile->setMaxLength(300);
        lineEdit_dbFile->setReadOnly(true);

        gridLayout_5->addWidget(lineEdit_dbFile, 2, 1, 1, 1);

        pushButton_dbFile = new QPushButton(groupBox);
        pushButton_dbFile->setObjectName(QString::fromUtf8("pushButton_dbFile"));

        gridLayout_5->addWidget(pushButton_dbFile, 2, 2, 1, 1);

        pushButton_Run = new QPushButton(groupBox);
        pushButton_Run->setObjectName(QString::fromUtf8("pushButton_Run"));

        gridLayout_5->addWidget(pushButton_Run, 3, 0, 1, 1);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_14, 3, 2, 1, 1);

        label_AnsysVersion = new QLabel(groupBox);
        label_AnsysVersion->setObjectName(QString::fromUtf8("label_AnsysVersion"));
        QFont font;
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        font.setStrikeOut(false);
        label_AnsysVersion->setFont(font);
        label_AnsysVersion->setFocusPolicy(Qt::NoFocus);

        gridLayout_5->addWidget(label_AnsysVersion, 3, 1, 1, 1);

        label_workDir->raise();
        label_jobName->raise();
        label_dbFile->raise();
        lineEdit_WorkingDir->raise();
        lineEdit_jobName->raise();
        lineEdit_dbFile->raise();
        pushButton_WorkingDir->raise();
        pushButton_dbFile->raise();
        pushButton_Run->raise();
        label_AnsysVersion->raise();

        gridLayout_25->addWidget(groupBox, 1, 1, 1, 1);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_25->addItem(horizontalSpacer_16, 1, 0, 1, 1);

        tabWidget_View->addTab(tab_config, QString());
        tab_Setup = new QWidget();
        tab_Setup->setObjectName(QString::fromUtf8("tab_Setup"));
        gridLayout_21 = new QGridLayout(tab_Setup);
        gridLayout_21->setSpacing(6);
        gridLayout_21->setContentsMargins(11, 11, 11, 11);
        gridLayout_21->setObjectName(QString::fromUtf8("gridLayout_21"));
        qvtkWidget = new QVTKWidget(tab_Setup);
        qvtkWidget->setObjectName(QString::fromUtf8("qvtkWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(qvtkWidget->sizePolicy().hasHeightForWidth());
        qvtkWidget->setSizePolicy(sizePolicy2);
        qvtkWidget->setMinimumSize(QSize(750, 500));

        gridLayout_21->addWidget(qvtkWidget, 1, 1, 1, 3);

        groupBox_3 = new QGroupBox(tab_Setup);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy3);
        groupBox_3->setAlignment(Qt::AlignCenter);
        gridLayout_20 = new QGridLayout(groupBox_3);
        gridLayout_20->setSpacing(6);
        gridLayout_20->setContentsMargins(11, 11, 11, 11);
        gridLayout_20->setObjectName(QString::fromUtf8("gridLayout_20"));
        pushButton_newDOF = new QPushButton(groupBox_3);
        pushButton_newDOF->setObjectName(QString::fromUtf8("pushButton_newDOF"));

        gridLayout_20->addWidget(pushButton_newDOF, 0, 0, 1, 1);

        pushButton_delDOF = new QPushButton(groupBox_3);
        pushButton_delDOF->setObjectName(QString::fromUtf8("pushButton_delDOF"));

        gridLayout_20->addWidget(pushButton_delDOF, 0, 1, 1, 1);


        gridLayout_21->addWidget(groupBox_3, 0, 2, 1, 1);

        groupBox_2 = new QGroupBox(tab_Setup);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_23 = new QGridLayout(groupBox_2);
        gridLayout_23->setSpacing(6);
        gridLayout_23->setContentsMargins(11, 11, 11, 11);
        gridLayout_23->setObjectName(QString::fromUtf8("gridLayout_23"));
        lineEdit_descriptionSetup = new QLineEdit(groupBox_2);
        lineEdit_descriptionSetup->setObjectName(QString::fromUtf8("lineEdit_descriptionSetup"));

        gridLayout_23->addWidget(lineEdit_descriptionSetup, 0, 0, 1, 1);


        gridLayout_21->addWidget(groupBox_2, 0, 0, 1, 1);

        toolBox = new QToolBox(tab_Setup);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        sizePolicy3.setHeightForWidth(toolBox->sizePolicy().hasHeightForWidth());
        toolBox->setSizePolicy(sizePolicy3);
        dof = new QWidget();
        dof->setObjectName(QString::fromUtf8("dof"));
        dof->setGeometry(QRect(0, 0, 299, 480));
        gridLayout_18 = new QGridLayout(dof);
        gridLayout_18->setSpacing(6);
        gridLayout_18->setContentsMargins(11, 11, 11, 11);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        pushButtonSaveSetupFile = new QPushButton(dof);
        pushButtonSaveSetupFile->setObjectName(QString::fromUtf8("pushButtonSaveSetupFile"));

        gridLayout_18->addWidget(pushButtonSaveSetupFile, 0, 0, 1, 1);

        scrollArea_Setup = new QScrollArea(dof);
        scrollArea_Setup->setObjectName(QString::fromUtf8("scrollArea_Setup"));
        sizePolicy3.setHeightForWidth(scrollArea_Setup->sizePolicy().hasHeightForWidth());
        scrollArea_Setup->setSizePolicy(sizePolicy3);
        scrollArea_Setup->setContextMenuPolicy(Qt::DefaultContextMenu);
        scrollArea_Setup->setLayoutDirection(Qt::LeftToRight);
        scrollArea_Setup->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea_Setup->setWidgetResizable(true);
        scrollArea_Setup->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 275, 421));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout_19 = new QGridLayout();
        gridLayout_19->setSpacing(6);
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        label_43 = new QLabel(scrollAreaWidgetContents);
        label_43->setObjectName(QString::fromUtf8("label_43"));

        gridLayout_19->addWidget(label_43, 0, 2, 1, 1);

        label_41 = new QLabel(scrollAreaWidgetContents);
        label_41->setObjectName(QString::fromUtf8("label_41"));

        gridLayout_19->addWidget(label_41, 0, 0, 1, 1);

        label_42 = new QLabel(scrollAreaWidgetContents);
        label_42->setObjectName(QString::fromUtf8("label_42"));

        gridLayout_19->addWidget(label_42, 0, 1, 1, 1);


        gridLayout->addLayout(gridLayout_19, 0, 0, 1, 2);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 1, 0, 1, 2);

        scrollArea_Setup->setWidget(scrollAreaWidgetContents);

        gridLayout_18->addWidget(scrollArea_Setup, 1, 0, 1, 1);

        toolBox->addItem(dof, QString::fromUtf8("Define Components  - DOF"));
        parts = new QWidget();
        parts->setObjectName(QString::fromUtf8("parts"));
        parts->setGeometry(QRect(0, 0, 280, 138));
        gridLayout_22 = new QGridLayout(parts);
        gridLayout_22->setSpacing(6);
        gridLayout_22->setContentsMargins(11, 11, 11, 11);
        gridLayout_22->setObjectName(QString::fromUtf8("gridLayout_22"));
        gridLayoutMesh = new QGridLayout();
        gridLayoutMesh->setSpacing(6);
        gridLayoutMesh->setObjectName(QString::fromUtf8("gridLayoutMesh"));
        gridLayoutMesh->setSizeConstraint(QLayout::SetDefaultConstraint);
        tableWidget = new QTableWidget(parts);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy4);

        gridLayoutMesh->addWidget(tableWidget, 1, 0, 1, 1);

        checkBoxWireframe = new QCheckBox(parts);
        checkBoxWireframe->setObjectName(QString::fromUtf8("checkBoxWireframe"));

        gridLayoutMesh->addWidget(checkBoxWireframe, 0, 0, 1, 1);


        gridLayout_22->addLayout(gridLayoutMesh, 0, 0, 1, 1);

        toolBox->addItem(parts, QString::fromUtf8("Show Parts"));

        gridLayout_21->addWidget(toolBox, 1, 0, 1, 1);

        pushButton_RunSetupEdgeCFD = new QPushButton(tab_Setup);
        pushButton_RunSetupEdgeCFD->setObjectName(QString::fromUtf8("pushButton_RunSetupEdgeCFD"));

        gridLayout_21->addWidget(pushButton_RunSetupEdgeCFD, 0, 3, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_21->addItem(horizontalSpacer_12, 0, 1, 1, 1);

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
        gridLayout_27 = new QGridLayout(tab_Input);
        gridLayout_27->setSpacing(6);
        gridLayout_27->setContentsMargins(11, 11, 11, 11);
        gridLayout_27->setObjectName(QString::fromUtf8("gridLayout_27"));
        groupBox_5 = new QGroupBox(tab_Input);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_26 = new QGridLayout(groupBox_5);
        gridLayout_26->setSpacing(6);
        gridLayout_26->setContentsMargins(11, 11, 11, 11);
        gridLayout_26->setObjectName(QString::fromUtf8("gridLayout_26"));
        spinBox_input1 = new QSpinBox(groupBox_5);
        spinBox_input1->setObjectName(QString::fromUtf8("spinBox_input1"));
        spinBox_input1->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        gridLayout_26->addWidget(spinBox_input1, 1, 0, 1, 1);

        pushButtonSaveInput = new QPushButton(groupBox_5);
        pushButtonSaveInput->setObjectName(QString::fromUtf8("pushButtonSaveInput"));

        gridLayout_26->addWidget(pushButtonSaveInput, 0, 2, 1, 1);

        lineEdit_InputFileName = new QLineEdit(groupBox_5);
        lineEdit_InputFileName->setObjectName(QString::fromUtf8("lineEdit_InputFileName"));
        lineEdit_InputFileName->setReadOnly(true);

        gridLayout_26->addWidget(lineEdit_InputFileName, 0, 0, 1, 2);

        doubleSpinBox_input2 = new QDoubleSpinBox(groupBox_5);
        doubleSpinBox_input2->setObjectName(QString::fromUtf8("doubleSpinBox_input2"));
        doubleSpinBox_input2->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_input2->setDecimals(8);
        doubleSpinBox_input2->setValue(0.5);

        gridLayout_26->addWidget(doubleSpinBox_input2, 4, 1, 1, 1);

        doubleSpinBox_input1 = new QDoubleSpinBox(groupBox_5);
        doubleSpinBox_input1->setObjectName(QString::fromUtf8("doubleSpinBox_input1"));
        doubleSpinBox_input1->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_input1->setDecimals(8);
        doubleSpinBox_input1->setMaximum(9999.99);
        doubleSpinBox_input1->setValue(1);

        gridLayout_26->addWidget(doubleSpinBox_input1, 4, 0, 1, 1);

        spinBox_input3 = new QSpinBox(groupBox_5);
        spinBox_input3->setObjectName(QString::fromUtf8("spinBox_input3"));
        spinBox_input3->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        spinBox_input3->setValue(1);

        gridLayout_26->addWidget(spinBox_input3, 3, 0, 1, 1);

        spinBox_input2 = new QSpinBox(groupBox_5);
        spinBox_input2->setObjectName(QString::fromUtf8("spinBox_input2"));
        spinBox_input2->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        spinBox_input2->setValue(1);

        gridLayout_26->addWidget(spinBox_input2, 2, 0, 1, 1);


        gridLayout_27->addWidget(groupBox_5, 1, 1, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_27->addItem(verticalSpacer_8, 0, 1, 1, 1);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_27->addItem(horizontalSpacer_17, 1, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_27->addItem(verticalSpacer_4, 2, 1, 1, 1);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_27->addItem(horizontalSpacer_18, 1, 0, 1, 1);

        tabWidget_View->addTab(tab_Input, QString());
        tab_Fsi = new QWidget();
        tab_Fsi->setObjectName(QString::fromUtf8("tab_Fsi"));
        scrollArea = new QScrollArea(tab_Fsi);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 1111, 731));
        scrollArea->setMinimumSize(QSize(1111, 731));
        scrollArea->setMaximumSize(QSize(1111, 731));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 1109, 729));
        gridLayout_9 = new QGridLayout(scrollAreaWidgetContents_4);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(6);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_18 = new QLabel(scrollAreaWidgetContents_4);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_8->addWidget(label_18, 0, 0, 1, 3);

        doubleSpinBox_FSI_ALE1 = new QDoubleSpinBox(scrollAreaWidgetContents_4);
        doubleSpinBox_FSI_ALE1->setObjectName(QString::fromUtf8("doubleSpinBox_FSI_ALE1"));
        doubleSpinBox_FSI_ALE1->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_FSI_ALE1->setDecimals(8);
        doubleSpinBox_FSI_ALE1->setValue(0.3);

        gridLayout_8->addWidget(doubleSpinBox_FSI_ALE1, 1, 0, 1, 1);

        doubleSpinBox_FSI_ALE2 = new QDoubleSpinBox(scrollAreaWidgetContents_4);
        doubleSpinBox_FSI_ALE2->setObjectName(QString::fromUtf8("doubleSpinBox_FSI_ALE2"));
        doubleSpinBox_FSI_ALE2->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_FSI_ALE2->setDecimals(8);

        gridLayout_8->addWidget(doubleSpinBox_FSI_ALE2, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_2, 1, 2, 1, 1);


        gridLayout_9->addLayout(gridLayout_8, 1, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_9->addItem(verticalSpacer, 9, 0, 1, 3);

        gridLayout_14 = new QGridLayout();
        gridLayout_14->setSpacing(6);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        lineEdit_InertiaX11 = new QLineEdit(scrollAreaWidgetContents_4);
        lineEdit_InertiaX11->setObjectName(QString::fromUtf8("lineEdit_InertiaX11"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(lineEdit_InertiaX11->sizePolicy().hasHeightForWidth());
        lineEdit_InertiaX11->setSizePolicy(sizePolicy5);
        lineEdit_InertiaX11->setMaximumSize(QSize(81, 16777215));
        lineEdit_InertiaX11->setMaxLength(8);

        gridLayout_14->addWidget(lineEdit_InertiaX11, 1, 1, 1, 1);

        lineEdit_InertiaX12 = new QLineEdit(scrollAreaWidgetContents_4);
        lineEdit_InertiaX12->setObjectName(QString::fromUtf8("lineEdit_InertiaX12"));
        sizePolicy5.setHeightForWidth(lineEdit_InertiaX12->sizePolicy().hasHeightForWidth());
        lineEdit_InertiaX12->setSizePolicy(sizePolicy5);
        lineEdit_InertiaX12->setMaximumSize(QSize(81, 16777215));
        lineEdit_InertiaX12->setMaxLength(8);

        gridLayout_14->addWidget(lineEdit_InertiaX12, 1, 3, 1, 1);

        lineEdit_InertiaX13 = new QLineEdit(scrollAreaWidgetContents_4);
        lineEdit_InertiaX13->setObjectName(QString::fromUtf8("lineEdit_InertiaX13"));
        sizePolicy5.setHeightForWidth(lineEdit_InertiaX13->sizePolicy().hasHeightForWidth());
        lineEdit_InertiaX13->setSizePolicy(sizePolicy5);
        lineEdit_InertiaX13->setMaximumSize(QSize(81, 16777215));
        lineEdit_InertiaX13->setMaxLength(8);

        gridLayout_14->addWidget(lineEdit_InertiaX13, 1, 5, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(471, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_14->addItem(horizontalSpacer_6, 1, 6, 1, 1);

        lineEdit_InertiaX22 = new QLineEdit(scrollAreaWidgetContents_4);
        lineEdit_InertiaX22->setObjectName(QString::fromUtf8("lineEdit_InertiaX22"));
        sizePolicy5.setHeightForWidth(lineEdit_InertiaX22->sizePolicy().hasHeightForWidth());
        lineEdit_InertiaX22->setSizePolicy(sizePolicy5);
        lineEdit_InertiaX22->setMaximumSize(QSize(81, 16777215));
        lineEdit_InertiaX22->setMaxLength(8);

        gridLayout_14->addWidget(lineEdit_InertiaX22, 2, 3, 1, 1);

        lineEdit_InertiaX23 = new QLineEdit(scrollAreaWidgetContents_4);
        lineEdit_InertiaX23->setObjectName(QString::fromUtf8("lineEdit_InertiaX23"));
        sizePolicy5.setHeightForWidth(lineEdit_InertiaX23->sizePolicy().hasHeightForWidth());
        lineEdit_InertiaX23->setSizePolicy(sizePolicy5);
        lineEdit_InertiaX23->setMaximumSize(QSize(81, 16777215));
        lineEdit_InertiaX23->setMaxLength(8);

        gridLayout_14->addWidget(lineEdit_InertiaX23, 2, 5, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(471, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_14->addItem(horizontalSpacer_7, 2, 6, 1, 1);

        lineEdit_InertiaX33 = new QLineEdit(scrollAreaWidgetContents_4);
        lineEdit_InertiaX33->setObjectName(QString::fromUtf8("lineEdit_InertiaX33"));
        sizePolicy5.setHeightForWidth(lineEdit_InertiaX33->sizePolicy().hasHeightForWidth());
        lineEdit_InertiaX33->setSizePolicy(sizePolicy5);
        lineEdit_InertiaX33->setMaximumSize(QSize(81, 16777215));
        lineEdit_InertiaX33->setMaxLength(8);

        gridLayout_14->addWidget(lineEdit_InertiaX33, 3, 5, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(471, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_14->addItem(horizontalSpacer_8, 3, 6, 1, 1);

        label_15 = new QLabel(scrollAreaWidgetContents_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_14->addWidget(label_15, 1, 0, 1, 1);

        label_16 = new QLabel(scrollAreaWidgetContents_4);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_14->addWidget(label_16, 1, 2, 1, 1);

        label_25 = new QLabel(scrollAreaWidgetContents_4);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        gridLayout_14->addWidget(label_25, 1, 4, 1, 1);

        label_26 = new QLabel(scrollAreaWidgetContents_4);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        gridLayout_14->addWidget(label_26, 2, 2, 1, 1);

        label_27 = new QLabel(scrollAreaWidgetContents_4);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        gridLayout_14->addWidget(label_27, 2, 4, 1, 1);

        label_28 = new QLabel(scrollAreaWidgetContents_4);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        gridLayout_14->addWidget(label_28, 3, 4, 1, 1);

        label_22 = new QLabel(scrollAreaWidgetContents_4);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout_14->addWidget(label_22, 0, 0, 1, 7);


        gridLayout_9->addLayout(gridLayout_14, 5, 0, 1, 3);

        gridLayout_12 = new QGridLayout();
        gridLayout_12->setSpacing(6);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        label_20 = new QLabel(scrollAreaWidgetContents_4);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_12->addWidget(label_20, 0, 0, 1, 3);

        doubleSpinBox_MassCG1 = new QDoubleSpinBox(scrollAreaWidgetContents_4);
        doubleSpinBox_MassCG1->setObjectName(QString::fromUtf8("doubleSpinBox_MassCG1"));
        doubleSpinBox_MassCG1->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_MassCG1->setDecimals(8);
        doubleSpinBox_MassCG1->setValue(0.25);

        gridLayout_12->addWidget(doubleSpinBox_MassCG1, 1, 0, 1, 1);

        doubleSpinBox_MassCG2 = new QDoubleSpinBox(scrollAreaWidgetContents_4);
        doubleSpinBox_MassCG2->setObjectName(QString::fromUtf8("doubleSpinBox_MassCG2"));
        doubleSpinBox_MassCG2->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_MassCG2->setDecimals(8);
        doubleSpinBox_MassCG2->setSingleStep(0.1);
        doubleSpinBox_MassCG2->setValue(0.1);

        gridLayout_12->addWidget(doubleSpinBox_MassCG2, 1, 1, 1, 1);

        doubleSpinBox_MassCG3 = new QDoubleSpinBox(scrollAreaWidgetContents_4);
        doubleSpinBox_MassCG3->setObjectName(QString::fromUtf8("doubleSpinBox_MassCG3"));
        doubleSpinBox_MassCG3->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_MassCG3->setDecimals(8);
        doubleSpinBox_MassCG3->setSingleStep(0.1);
        doubleSpinBox_MassCG3->setValue(0.125);

        gridLayout_12->addWidget(doubleSpinBox_MassCG3, 1, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_12->addItem(horizontalSpacer_4, 1, 3, 1, 1);


        gridLayout_9->addLayout(gridLayout_12, 3, 0, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(174, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_10, 7, 2, 1, 1);

        gridLayout_16 = new QGridLayout();
        gridLayout_16->setSpacing(6);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        doubleSpinBox_VInitial_Wx = new QDoubleSpinBox(scrollAreaWidgetContents_4);
        doubleSpinBox_VInitial_Wx->setObjectName(QString::fromUtf8("doubleSpinBox_VInitial_Wx"));
        doubleSpinBox_VInitial_Wx->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_VInitial_Wx->setDecimals(8);
        doubleSpinBox_VInitial_Wx->setValue(0.25);

        gridLayout_16->addWidget(doubleSpinBox_VInitial_Wx, 2, 3, 1, 1);

        label_4 = new QLabel(scrollAreaWidgetContents_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_16->addWidget(label_4, 0, 0, 1, 6);

        doubleSpinBox_VInitial_vx = new QDoubleSpinBox(scrollAreaWidgetContents_4);
        doubleSpinBox_VInitial_vx->setObjectName(QString::fromUtf8("doubleSpinBox_VInitial_vx"));
        doubleSpinBox_VInitial_vx->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_VInitial_vx->setDecimals(8);
        doubleSpinBox_VInitial_vx->setValue(0.25);

        gridLayout_16->addWidget(doubleSpinBox_VInitial_vx, 2, 0, 1, 1);

        doubleSpinBox_VInitial_vy = new QDoubleSpinBox(scrollAreaWidgetContents_4);
        doubleSpinBox_VInitial_vy->setObjectName(QString::fromUtf8("doubleSpinBox_VInitial_vy"));
        doubleSpinBox_VInitial_vy->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_VInitial_vy->setDecimals(8);
        doubleSpinBox_VInitial_vy->setValue(0.25);

        gridLayout_16->addWidget(doubleSpinBox_VInitial_vy, 2, 1, 1, 1);

        doubleSpinBox_VInitial_vz = new QDoubleSpinBox(scrollAreaWidgetContents_4);
        doubleSpinBox_VInitial_vz->setObjectName(QString::fromUtf8("doubleSpinBox_VInitial_vz"));
        doubleSpinBox_VInitial_vz->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_VInitial_vz->setDecimals(8);
        doubleSpinBox_VInitial_vz->setValue(0.25);

        gridLayout_16->addWidget(doubleSpinBox_VInitial_vz, 2, 2, 1, 1);

        doubleSpinBox_VInitial_Wy = new QDoubleSpinBox(scrollAreaWidgetContents_4);
        doubleSpinBox_VInitial_Wy->setObjectName(QString::fromUtf8("doubleSpinBox_VInitial_Wy"));
        doubleSpinBox_VInitial_Wy->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_VInitial_Wy->setDecimals(8);
        doubleSpinBox_VInitial_Wy->setValue(0.25);

        gridLayout_16->addWidget(doubleSpinBox_VInitial_Wy, 2, 4, 1, 1);

        doubleSpinBox_VInitial_Wz = new QDoubleSpinBox(scrollAreaWidgetContents_4);
        doubleSpinBox_VInitial_Wz->setObjectName(QString::fromUtf8("doubleSpinBox_VInitial_Wz"));
        doubleSpinBox_VInitial_Wz->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_VInitial_Wz->setDecimals(8);
        doubleSpinBox_VInitial_Wz->setValue(0.25);

        gridLayout_16->addWidget(doubleSpinBox_VInitial_Wz, 2, 5, 1, 1);

        label_35 = new QLabel(scrollAreaWidgetContents_4);
        label_35->setObjectName(QString::fromUtf8("label_35"));

        gridLayout_16->addWidget(label_35, 1, 0, 1, 1);

        label_36 = new QLabel(scrollAreaWidgetContents_4);
        label_36->setObjectName(QString::fromUtf8("label_36"));

        gridLayout_16->addWidget(label_36, 1, 1, 1, 1);

        label_37 = new QLabel(scrollAreaWidgetContents_4);
        label_37->setObjectName(QString::fromUtf8("label_37"));

        gridLayout_16->addWidget(label_37, 1, 2, 1, 1);

        label_38 = new QLabel(scrollAreaWidgetContents_4);
        label_38->setObjectName(QString::fromUtf8("label_38"));

        gridLayout_16->addWidget(label_38, 1, 3, 1, 1);

        label_39 = new QLabel(scrollAreaWidgetContents_4);
        label_39->setObjectName(QString::fromUtf8("label_39"));

        gridLayout_16->addWidget(label_39, 1, 4, 1, 1);

        label_40 = new QLabel(scrollAreaWidgetContents_4);
        label_40->setObjectName(QString::fromUtf8("label_40"));

        gridLayout_16->addWidget(label_40, 1, 5, 1, 1);


        gridLayout_9->addLayout(gridLayout_16, 7, 0, 1, 2);

        gridLayout_17 = new QGridLayout();
        gridLayout_17->setSpacing(6);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        doubleSpinBox_nptf22 = new QDoubleSpinBox(scrollAreaWidgetContents_4);
        doubleSpinBox_nptf22->setObjectName(QString::fromUtf8("doubleSpinBox_nptf22"));
        doubleSpinBox_nptf22->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        gridLayout_17->addWidget(doubleSpinBox_nptf22, 3, 1, 1, 1);

        doubleSpinBox_nptf12 = new QDoubleSpinBox(scrollAreaWidgetContents_4);
        doubleSpinBox_nptf12->setObjectName(QString::fromUtf8("doubleSpinBox_nptf12"));
        doubleSpinBox_nptf12->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        gridLayout_17->addWidget(doubleSpinBox_nptf12, 2, 1, 1, 1);

        label_24 = new QLabel(scrollAreaWidgetContents_4);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_17->addWidget(label_24, 0, 0, 1, 3);

        doubleSpinBox_nptf21 = new QDoubleSpinBox(scrollAreaWidgetContents_4);
        doubleSpinBox_nptf21->setObjectName(QString::fromUtf8("doubleSpinBox_nptf21"));
        doubleSpinBox_nptf21->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_nptf21->setValue(10);

        gridLayout_17->addWidget(doubleSpinBox_nptf21, 3, 0, 1, 1);

        label_23 = new QLabel(scrollAreaWidgetContents_4);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout_17->addWidget(label_23, 1, 2, 4, 1);

        doubleSpinBox_nptf11 = new QDoubleSpinBox(scrollAreaWidgetContents_4);
        doubleSpinBox_nptf11->setObjectName(QString::fromUtf8("doubleSpinBox_nptf11"));
        doubleSpinBox_nptf11->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        gridLayout_17->addWidget(doubleSpinBox_nptf11, 2, 0, 1, 1);

        doubleSpinBox_nptf31 = new QDoubleSpinBox(scrollAreaWidgetContents_4);
        doubleSpinBox_nptf31->setObjectName(QString::fromUtf8("doubleSpinBox_nptf31"));
        doubleSpinBox_nptf31->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_nptf31->setValue(15);

        gridLayout_17->addWidget(doubleSpinBox_nptf31, 4, 0, 1, 1);

        doubleSpinBox_nptf32 = new QDoubleSpinBox(scrollAreaWidgetContents_4);
        doubleSpinBox_nptf32->setObjectName(QString::fromUtf8("doubleSpinBox_nptf32"));
        doubleSpinBox_nptf32->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_nptf32->setValue(2);

        gridLayout_17->addWidget(doubleSpinBox_nptf32, 4, 1, 1, 1);

        spinBox_nptf = new QSpinBox(scrollAreaWidgetContents_4);
        spinBox_nptf->setObjectName(QString::fromUtf8("spinBox_nptf"));
        spinBox_nptf->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        gridLayout_17->addWidget(spinBox_nptf, 1, 0, 1, 1);


        gridLayout_9->addLayout(gridLayout_17, 8, 0, 1, 3);

        gridLayout_11 = new QGridLayout();
        gridLayout_11->setSpacing(6);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        label_19 = new QLabel(scrollAreaWidgetContents_4);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_11->addWidget(label_19, 0, 0, 1, 2);

        doubleSpinBox_MASSFSI = new QDoubleSpinBox(scrollAreaWidgetContents_4);
        doubleSpinBox_MASSFSI->setObjectName(QString::fromUtf8("doubleSpinBox_MASSFSI"));
        doubleSpinBox_MASSFSI->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_MASSFSI->setDecimals(8);
        doubleSpinBox_MASSFSI->setMaximum(1e+06);
        doubleSpinBox_MASSFSI->setValue(0.081);

        gridLayout_11->addWidget(doubleSpinBox_MASSFSI, 1, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_11->addItem(horizontalSpacer_3, 1, 1, 1, 1);


        gridLayout_9->addLayout(gridLayout_11, 2, 0, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(214, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_9, 6, 1, 1, 1);

        gridLayout_15 = new QGridLayout();
        gridLayout_15->setSpacing(6);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        label_12 = new QLabel(scrollAreaWidgetContents_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_15->addWidget(label_12, 0, 0, 1, 6);

        spinBox_Ux = new QSpinBox(scrollAreaWidgetContents_4);
        spinBox_Ux->setObjectName(QString::fromUtf8("spinBox_Ux"));
        spinBox_Ux->setMinimum(-1);
        spinBox_Ux->setMaximum(1);
        spinBox_Ux->setValue(1);

        gridLayout_15->addWidget(spinBox_Ux, 2, 0, 1, 1);

        spinBox_Uy = new QSpinBox(scrollAreaWidgetContents_4);
        spinBox_Uy->setObjectName(QString::fromUtf8("spinBox_Uy"));
        spinBox_Uy->setMinimum(-1);
        spinBox_Uy->setMaximum(1);
        spinBox_Uy->setValue(1);

        gridLayout_15->addWidget(spinBox_Uy, 2, 1, 1, 1);

        spinBox_Uz = new QSpinBox(scrollAreaWidgetContents_4);
        spinBox_Uz->setObjectName(QString::fromUtf8("spinBox_Uz"));
        spinBox_Uz->setMinimum(-1);
        spinBox_Uz->setMaximum(1);

        gridLayout_15->addWidget(spinBox_Uz, 2, 2, 1, 1);

        spinBox_ROTx = new QSpinBox(scrollAreaWidgetContents_4);
        spinBox_ROTx->setObjectName(QString::fromUtf8("spinBox_ROTx"));
        spinBox_ROTx->setMinimum(-1);
        spinBox_ROTx->setMaximum(1);
        spinBox_ROTx->setValue(1);

        gridLayout_15->addWidget(spinBox_ROTx, 2, 3, 1, 1);

        spinBox_ROTy = new QSpinBox(scrollAreaWidgetContents_4);
        spinBox_ROTy->setObjectName(QString::fromUtf8("spinBox_ROTy"));
        spinBox_ROTy->setMinimum(-1);
        spinBox_ROTy->setMaximum(1);
        spinBox_ROTy->setValue(1);

        gridLayout_15->addWidget(spinBox_ROTy, 2, 4, 1, 1);

        spinBox_ROTz = new QSpinBox(scrollAreaWidgetContents_4);
        spinBox_ROTz->setObjectName(QString::fromUtf8("spinBox_ROTz"));
        spinBox_ROTz->setMinimum(-1);
        spinBox_ROTz->setMaximum(1);
        spinBox_ROTz->setValue(1);

        gridLayout_15->addWidget(spinBox_ROTz, 2, 5, 1, 1);

        label_30 = new QLabel(scrollAreaWidgetContents_4);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        gridLayout_15->addWidget(label_30, 1, 1, 1, 1);

        label_31 = new QLabel(scrollAreaWidgetContents_4);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        gridLayout_15->addWidget(label_31, 1, 2, 1, 1);

        label_29 = new QLabel(scrollAreaWidgetContents_4);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        gridLayout_15->addWidget(label_29, 1, 0, 1, 1);

        label_32 = new QLabel(scrollAreaWidgetContents_4);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        gridLayout_15->addWidget(label_32, 1, 3, 1, 1);

        label_33 = new QLabel(scrollAreaWidgetContents_4);
        label_33->setObjectName(QString::fromUtf8("label_33"));

        gridLayout_15->addWidget(label_33, 1, 4, 1, 1);

        label_34 = new QLabel(scrollAreaWidgetContents_4);
        label_34->setObjectName(QString::fromUtf8("label_34"));

        gridLayout_15->addWidget(label_34, 1, 5, 1, 1);


        gridLayout_9->addLayout(gridLayout_15, 6, 0, 1, 1);

        gridLayout_13 = new QGridLayout();
        gridLayout_13->setSpacing(6);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        label_21 = new QLabel(scrollAreaWidgetContents_4);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_13->addWidget(label_21, 0, 0, 1, 3);

        doubleSpinBox_RotationCG1 = new QDoubleSpinBox(scrollAreaWidgetContents_4);
        doubleSpinBox_RotationCG1->setObjectName(QString::fromUtf8("doubleSpinBox_RotationCG1"));
        doubleSpinBox_RotationCG1->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_RotationCG1->setDecimals(8);
        doubleSpinBox_RotationCG1->setValue(0.25);

        gridLayout_13->addWidget(doubleSpinBox_RotationCG1, 1, 0, 1, 1);

        doubleSpinBox_RotationCG2 = new QDoubleSpinBox(scrollAreaWidgetContents_4);
        doubleSpinBox_RotationCG2->setObjectName(QString::fromUtf8("doubleSpinBox_RotationCG2"));
        doubleSpinBox_RotationCG2->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_RotationCG2->setDecimals(8);
        doubleSpinBox_RotationCG2->setSingleStep(0.1);
        doubleSpinBox_RotationCG2->setValue(0.1);

        gridLayout_13->addWidget(doubleSpinBox_RotationCG2, 1, 1, 1, 1);

        doubleSpinBox_RotationCG3 = new QDoubleSpinBox(scrollAreaWidgetContents_4);
        doubleSpinBox_RotationCG3->setObjectName(QString::fromUtf8("doubleSpinBox_RotationCG3"));
        doubleSpinBox_RotationCG3->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBox_RotationCG3->setDecimals(8);
        doubleSpinBox_RotationCG3->setSingleStep(0.1);
        doubleSpinBox_RotationCG3->setValue(0.125);

        gridLayout_13->addWidget(doubleSpinBox_RotationCG3, 1, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_13->addItem(horizontalSpacer_5, 1, 3, 1, 1);


        gridLayout_9->addLayout(gridLayout_13, 4, 0, 1, 1);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_17 = new QLabel(scrollAreaWidgetContents_4);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_7->addWidget(label_17, 0, 0, 1, 2);

        comboBox_FSI = new QComboBox(scrollAreaWidgetContents_4);
        comboBox_FSI->setObjectName(QString::fromUtf8("comboBox_FSI"));

        gridLayout_7->addWidget(comboBox_FSI, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer, 1, 1, 1, 1);


        gridLayout_9->addLayout(gridLayout_7, 0, 0, 1, 1);

        pushButtonSaveFSI = new QPushButton(scrollAreaWidgetContents_4);
        pushButtonSaveFSI->setObjectName(QString::fromUtf8("pushButtonSaveFSI"));
        sizePolicy5.setHeightForWidth(pushButtonSaveFSI->sizePolicy().hasHeightForWidth());
        pushButtonSaveFSI->setSizePolicy(sizePolicy5);

        gridLayout_9->addWidget(pushButtonSaveFSI, 0, 3, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_11, 5, 3, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents_4);
        pushButtonSaveFSI->raise();
        tabWidget_View->addTab(tab_Fsi, QString());
        tab_Material = new QWidget();
        tab_Material->setObjectName(QString::fromUtf8("tab_Material"));
        groupBox_material = new QGroupBox(tab_Material);
        groupBox_material->setObjectName(QString::fromUtf8("groupBox_material"));
        groupBox_material->setGeometry(QRect(20, 20, 1071, 650));
        groupBox_material->setMinimumSize(QSize(1071, 650));
        groupBox_material->setMaximumSize(QSize(1071, 600));
        gridLayout_3 = new QGridLayout(groupBox_material);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox_7 = new QGroupBox(groupBox_material);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setAlignment(Qt::AlignCenter);
        gridLayout_6 = new QGridLayout(groupBox_7);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        pushButton_newMaterial = new QPushButton(groupBox_7);
        pushButton_newMaterial->setObjectName(QString::fromUtf8("pushButton_newMaterial"));

        gridLayout_6->addWidget(pushButton_newMaterial, 0, 0, 1, 1);

        pushButton_delMaterial = new QPushButton(groupBox_7);
        pushButton_delMaterial->setObjectName(QString::fromUtf8("pushButton_delMaterial"));

        gridLayout_6->addWidget(pushButton_delMaterial, 0, 1, 1, 1);


        gridLayout_3->addWidget(groupBox_7, 0, 1, 1, 1);

        pushButton_saveMaterial = new QPushButton(groupBox_material);
        pushButton_saveMaterial->setObjectName(QString::fromUtf8("pushButton_saveMaterial"));

        gridLayout_3->addWidget(pushButton_saveMaterial, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 2, 1, 1, 1);

        scrollArea_material = new QScrollArea(groupBox_material);
        scrollArea_material->setObjectName(QString::fromUtf8("scrollArea_material"));
        scrollArea_material->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 821, 608));
        gridLayout_4 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_13 = new QLabel(scrollAreaWidgetContents_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_2->addWidget(label_13, 0, 8, 1, 1);

        label_6 = new QLabel(scrollAreaWidgetContents_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 0, 2, 1, 1);

        label = new QLabel(scrollAreaWidgetContents_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_10 = new QLabel(scrollAreaWidgetContents_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_2->addWidget(label_10, 0, 6, 1, 1);

        label_8 = new QLabel(scrollAreaWidgetContents_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 0, 4, 1, 1);

        label_7 = new QLabel(scrollAreaWidgetContents_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 0, 3, 1, 1);

        label_5 = new QLabel(scrollAreaWidgetContents_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 0, 1, 1, 1);

        label_14 = new QLabel(scrollAreaWidgetContents_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_2->addWidget(label_14, 0, 9, 1, 1);

        label_11 = new QLabel(scrollAreaWidgetContents_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_2->addWidget(label_11, 0, 7, 1, 1);

        label_9 = new QLabel(scrollAreaWidgetContents_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_2->addWidget(label_9, 0, 5, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 0, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_3, 1, 0, 1, 1);

        scrollArea_material->setWidget(scrollAreaWidgetContents_2);

        gridLayout_3->addWidget(scrollArea_material, 0, 0, 3, 1);

        tabWidget_View->addTab(tab_Material, QString());
        tabMesh = new QWidget();
        tabMesh->setObjectName(QString::fromUtf8("tabMesh"));
        gridLayout_10 = new QGridLayout(tabMesh);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        groupBox_6 = new QGroupBox(tabMesh);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        pushButtonConnect = new QPushButton(groupBox_6);
        pushButtonConnect->setObjectName(QString::fromUtf8("pushButtonConnect"));
        pushButtonConnect->setGeometry(QRect(20, 30, 93, 28));

        gridLayout_10->addWidget(groupBox_6, 0, 0, 1, 1);

        tabWidget_View->addTab(tabMesh, QString());

        gridLayout_24->addWidget(tabWidget_View, 1, 0, 1, 2);

        runEdgeCFDClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(runEdgeCFDClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1106, 26));
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

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuConfigure->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionAbout);
        menuConfigure->addAction(actionAnsys_Path);
        menuConfigure->addSeparator();
        menuConfigure->addAction(actionRenderColor);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionSave);

        retranslateUi(runEdgeCFDClass);

        tabWidget_View->setCurrentIndex(6);
        toolBox->setCurrentIndex(0);


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
        actionRenderColor->setText(QApplication::translate("runEdgeCFDClass", "Render Color", 0, QApplication::UnicodeUTF8));
        pushButton_RunEdgeCFDSolver->setText(QApplication::translate("runEdgeCFDClass", "Run EdgeCFDSolver", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        tabWidget_View->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        groupBox->setTitle(QApplication::translate("runEdgeCFDClass", "Initial Setup", 0, QApplication::UnicodeUTF8));
        label_workDir->setText(QApplication::translate("runEdgeCFDClass", "Working Directory:", 0, QApplication::UnicodeUTF8));
        lineEdit_WorkingDir->setText(QString());
        pushButton_WorkingDir->setText(QApplication::translate("runEdgeCFDClass", "Browse", 0, QApplication::UnicodeUTF8));
        label_jobName->setText(QApplication::translate("runEdgeCFDClass", "Job Name:", 0, QApplication::UnicodeUTF8));
        label_dbFile->setText(QApplication::translate("runEdgeCFDClass", "Db File:", 0, QApplication::UnicodeUTF8));
        pushButton_dbFile->setText(QApplication::translate("runEdgeCFDClass", "Browse", 0, QApplication::UnicodeUTF8));
        pushButton_Run->setText(QApplication::translate("runEdgeCFDClass", "MAKE", 0, QApplication::UnicodeUTF8));
        label_AnsysVersion->setText(QApplication::translate("runEdgeCFDClass", "<html><head/><body><p><br/></p></body></html>", 0, QApplication::UnicodeUTF8));
        tabWidget_View->setTabText(tabWidget_View->indexOf(tab_config), QApplication::translate("runEdgeCFDClass", "File Management", 0, QApplication::UnicodeUTF8));
        tabWidget_View->setTabWhatsThis(tabWidget_View->indexOf(tab_config), QApplication::translate("runEdgeCFDClass", "<html><head/><body><p>Aba de configura\303\247\303\243o do nome do Arquivo (FILENAME)</p></body></html>", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("runEdgeCFDClass", "Create and Delete - DOF", 0, QApplication::UnicodeUTF8));
        pushButton_newDOF->setText(QApplication::translate("runEdgeCFDClass", "New", 0, QApplication::UnicodeUTF8));
        pushButton_delDOF->setText(QApplication::translate("runEdgeCFDClass", "Delete", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("runEdgeCFDClass", "GroupBox", 0, QApplication::UnicodeUTF8));
        lineEdit_descriptionSetup->setText(QApplication::translate("runEdgeCFDClass", "MODELO DE NAVIO FPSO EM ESCALA 1:100", 0, QApplication::UnicodeUTF8));
        pushButtonSaveSetupFile->setText(QApplication::translate("runEdgeCFDClass", "Save Setup File", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        scrollArea_Setup->setStatusTip(QApplication::translate("runEdgeCFDClass", "DOF Values", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        label_43->setText(QApplication::translate("runEdgeCFDClass", "VALOR", 0, QApplication::UnicodeUTF8));
        label_41->setText(QApplication::translate("runEdgeCFDClass", "COMPONENTE CC", 0, QApplication::UnicodeUTF8));
        label_42->setText(QApplication::translate("runEdgeCFDClass", "LABEL", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(dof), QApplication::translate("runEdgeCFDClass", "Define Components  - DOF", 0, QApplication::UnicodeUTF8));
        checkBoxWireframe->setText(QApplication::translate("runEdgeCFDClass", "Wireframe", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(parts), QApplication::translate("runEdgeCFDClass", "Show Parts", 0, QApplication::UnicodeUTF8));
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
        label_18->setText(QApplication::translate("runEdgeCFDClass", "$  Instante de tempo de in\303\255cio do movimento da malha ALE :  START_ALE ( 1 REAL*8 )", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("runEdgeCFDClass", "X11:", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("runEdgeCFDClass", "X12:", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("runEdgeCFDClass", "X13:", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("runEdgeCFDClass", "X22:", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("runEdgeCFDClass", "X23:", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("runEdgeCFDClass", "X33:", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("runEdgeCFDClass", "$  Tensor of Inertia  [M][L2]:", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("runEdgeCFDClass", "$  Center of mass : CG ( 3 REAL*8 )      [M]", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("runEdgeCFDClass", "$  Velocidade inicial prescritos [L/T] [1/T]:", 0, QApplication::UnicodeUTF8));
        label_35->setText(QApplication::translate("runEdgeCFDClass", "vx:", 0, QApplication::UnicodeUTF8));
        label_36->setText(QApplication::translate("runEdgeCFDClass", "vy:", 0, QApplication::UnicodeUTF8));
        label_37->setText(QApplication::translate("runEdgeCFDClass", "vz:", 0, QApplication::UnicodeUTF8));
        label_38->setText(QApplication::translate("runEdgeCFDClass", "Wx:", 0, QApplication::UnicodeUTF8));
        label_39->setText(QApplication::translate("runEdgeCFDClass", "Wy:", 0, QApplication::UnicodeUTF8));
        label_40->setText(QApplication::translate("runEdgeCFDClass", "Wz:", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("runEdgeCFDClass", "$  Fun\303\247\303\243o prescrita: nptf < 11 [L] ou [grau]", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("runEdgeCFDClass", "$ README\n"
"NGL_BODY =  0 LIVRE PARA DESLOCAR \n"
"NGL_BODY =  1 PRESO\n"
"NGL_BODY = -1 DESLOCAMENTO PRESCRITO, EXIGE NPTF > 0\n"
"\n"
"NPTF = PONTOS DA FUN\303\207\303\203O TEMPORAL DE DESCOLAMENTO PRESCRITO, S\303\223 \303\211 PERMITIDA UMA FUN\303\207\303\203O\n"
"Nptf < 11, S\303\263 permite at\303\251 10 pares de pontos para a fun\303\247\303\243o ( tempo e valor ).", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("runEdgeCFDClass", "$  Mass of the body  : MASSFSI ( 1 REAL*8 )      [M]", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("runEdgeCFDClass", "$  Movimentos prescritos: ngl_body(1:6) ", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("runEdgeCFDClass", "Uy:", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("runEdgeCFDClass", "Uz:", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("runEdgeCFDClass", "Ux:", 0, QApplication::UnicodeUTF8));
        label_32->setText(QApplication::translate("runEdgeCFDClass", "ROTx:", 0, QApplication::UnicodeUTF8));
        label_33->setText(QApplication::translate("runEdgeCFDClass", "ROTy:", 0, QApplication::UnicodeUTF8));
        label_34->setText(QApplication::translate("runEdgeCFDClass", "ROTz:", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("runEdgeCFDClass", "$  Center of rotation : CG ( 3 REAL*8 )      [M]", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("runEdgeCFDClass", "$  SolveFSI  (.TRUE. OR .FALSE.)  ", 0, QApplication::UnicodeUTF8));
        comboBox_FSI->clear();
        comboBox_FSI->insertItems(0, QStringList()
         << QApplication::translate("runEdgeCFDClass", ".TRUE.", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("runEdgeCFDClass", ".FALSE.", 0, QApplication::UnicodeUTF8)
        );
        pushButtonSaveFSI->setText(QApplication::translate("runEdgeCFDClass", "Save FSI File", 0, QApplication::UnicodeUTF8));
        tabWidget_View->setTabText(tabWidget_View->indexOf(tab_Fsi), QApplication::translate("runEdgeCFDClass", "FSI", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        groupBox_material->setToolTip(QApplication::translate("runEdgeCFDClass", "Material Proprieties", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        groupBox_material->setTitle(QApplication::translate("runEdgeCFDClass", "Material Setup", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("runEdgeCFDClass", "Create and Delete - Material", 0, QApplication::UnicodeUTF8));
        pushButton_newMaterial->setText(QApplication::translate("runEdgeCFDClass", "New", 0, QApplication::UnicodeUTF8));
        pushButton_delMaterial->setText(QApplication::translate("runEdgeCFDClass", "Delete", 0, QApplication::UnicodeUTF8));
        pushButton_saveMaterial->setText(QApplication::translate("runEdgeCFDClass", "Save Material", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("runEdgeCFDClass", "SPH", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("runEdgeCFDClass", "VISC", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("runEdgeCFDClass", "ID", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("runEdgeCFDClass", "KYY", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("runEdgeCFDClass", "PAR4", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("runEdgeCFDClass", "PAR3", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("runEdgeCFDClass", "DENS", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("runEdgeCFDClass", "NAME", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("runEdgeCFDClass", "KZZ", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("runEdgeCFDClass", "KXX", 0, QApplication::UnicodeUTF8));
        tabWidget_View->setTabText(tabWidget_View->indexOf(tab_Material), QApplication::translate("runEdgeCFDClass", "MATERIAL", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("runEdgeCFDClass", "SSH", 0, QApplication::UnicodeUTF8));
        pushButtonConnect->setText(QApplication::translate("runEdgeCFDClass", "Connect", 0, QApplication::UnicodeUTF8));
        tabWidget_View->setTabText(tabWidget_View->indexOf(tabMesh), QApplication::translate("runEdgeCFDClass", "MESH", 0, QApplication::UnicodeUTF8));
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
