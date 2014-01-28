#ifndef CONFIGANSYS_H
#define CONFIGANSYS_H


// includes C/C++
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <time.h>
#include <Windows.h>
#include <time.h>
#include <dos.h>
#include <time.h>
#include <Windows.h>
#include <algorithm>


//includes QT
#include <QDir>
#include <QFileDialog>
#include <QStringList>
#include <QProcess>
#include <QTextStream>
#include <QMessageBox>
#include <QMap>
#include <QVector>
#include <QList>
#include <QSpacerItem>
#include <qDebug>
#include <QQueue>
#include <QFile>
#include <QString>
#include <QStringList>
#include <QProcess>
#include <QWidget>


namespace Ui {
class configAnsys;
}

class configAnsys : public QWidget
{
    Q_OBJECT
    
public:
    explicit configAnsys(QWidget *parent = 0);
    ~configAnsys();
    
	//variaveis
	QString VersaoAtual;
	QString VerAnsys11;
	QString VerAnsys12;
	QString VerAnsys13;
	QString VerAnsys14;

	//metodos
	void VerificaPathsAnsys(); //verifica se existem paths do ansys instalados no computador

public slots:
	void slotcloseWindow();	//fecha a janela de configuracao do ansys
	void slotSetAnsysVersion();	// usuario pode realizar a escolha da versao do ansys

signals:
	void updateAnsysVersion(QString VersaoAtual);

private:
    Ui::configAnsys *ui;
};

#endif // CONFIGANSYS_H
