#ifndef SSH_H
#define SSH_H

// Windows
#pragma once

#include <Windows.h>

//includes C++
// includes C/C++
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>
#include <time.h>
#include <Windows.h>
#include <time.h>
#include <dos.h>
#include <time.h>
#include <Windows.h>
#include <algorithm>



//Includes do QT
#include <QDoubleValidator>
#include <QtGui/QMainWindow>
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
#include <QMessageBox>
#include <QProcess>
#include <QPalette>
#include <QDateTime>
#include <qmouseeventtransition.h>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QEvent>
#include <qobject.h>
#include <QTableWidgetItem> 
#include <QTreeWidgetItem>
#include <QColorDialog>
#include <QDecoration>
#include <QFileDialog>
#include <qfile.h>
#include <QMessageBox>

#include <qheaderview.h>
#include <qstandarditemmodel.h>

#include <QMainWindow>
#include <qDebug>
#include <QProcess>
#include <qstringlist.h>

//ui
#include "ui_runedgecfd.h"

// name spaces
using namespace std;

class CallSSH : public QMainWindow
{
public:
	CallSSH(Ui::runEdgeCFDClass *uissh);
	~CallSSH();
	
public:
	//VARIAVEIS
	Ui::runEdgeCFDClass *uissh;
	QProcess *process;

	//METODOS
	void WrapCallSSH(QString host, QString user, int port, QString passwd, QString cmd, Ui::runEdgeCFDClass *uissh); // executa uma chamada de ssh ou dispara job na fila
	void AtualizaJanela(); //atualiza o conteudo realizado no ssh em uma janela da interface "textEdit_ssh"

	void LerArquivoLog(QString filename);

	void CopiarArquivosSolver();




};




#endif // SSH_H