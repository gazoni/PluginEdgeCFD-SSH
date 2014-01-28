#pragma once
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
#include <qstring.h>
#include <QFile>
#include <QFileInfo>


#include "forms.h"
#include "formOrdenado.h"
#include "ui_runedgecfd.h"


using namespace std;

class io 
{

public:
	io();
	~io(void);
	

public:
	//REESCREVE O ARQUIVO .MAC PARA ADEQUAR AO NOME DO ARQUIVO DB DO ANSYS
	static void Escreve_OPENMAC(QString pathdb, QDir filePath);

	//ESCREVE O ARQUIVO DE DADOS CORRESPONDENTE A ABA SETUP
	static void Escreve_SETUPFile(QString jobname, QDir filePath, QMap<int, Forms>, Ui::runEdgeCFDClass *ui);
	
	//ESCREVE O ARQUIVO DE DADOS CORRESPONDENTE A ABA PRE
	static void Escreve_PREFile(QString jobname, QDir filePath, QMap<int, Forms>, Ui::runEdgeCFDClass *ui);
	
	//ESCREVE O ARQUIVO DE DADOS CORRESPONDENTE A ABA INPUT
	static void Escreve_INPUTFile(QString jobname, QDir filePath, QMap<int, Forms>, Ui::runEdgeCFDClass *ui);
	
	//ESCREVE O ARQUIVO DE DADOS CORRESPONDENTE A ABA FSI
	static void Escreve_FSIFile(QString jobname, QDir filePath, QMap<int, Forms>,Ui::runEdgeCFDClass *ui);
	
	//ESCREVE O ARQUIVO DE DADOS CORRESPENDENTE A ABA MATERIAL
	static void Escreve_MaterialFile(QString jobname, QDir filePath, QMap<int, MATERIAL>,Ui::runEdgeCFDClass *ui);

private:
	
	

};

