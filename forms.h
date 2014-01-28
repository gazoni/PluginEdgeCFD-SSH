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
#include <QSpinBox		>
#include <QSpacerItem	>	
#include <QComboBox		>
#include <QDoubleSpinBox	>
using namespace std;

struct forms{
  
	QComboBox		*componenteDOF;
	QComboBox		*labelDOF;
	QDoubleSpinBox	*valorDOF; 

};
typedef struct forms Forms;


struct material{

	QSpinBox		*id;
	QDoubleSpinBox	*dens;
	QDoubleSpinBox	*visc;
	QDoubleSpinBox	*par3;
	QDoubleSpinBox	*par4;
	QDoubleSpinBox	*kxx;
	QDoubleSpinBox	*kyy;
	QDoubleSpinBox	*kzz;
	QDoubleSpinBox	*sph;
	QLineEdit		*name;

};
typedef struct material MATERIAL;



