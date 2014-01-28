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

//class formulario {
//    int componenteDOF;
//	string labelDOF;
//	float valorDOF;
//    
//    public:
//        formulario(int v1, string label, float v2)
//        {
//            componenteDOF = v1;
//            labelDOF = label;
//			valorDOF = v2;
//        }
//        int getcomponentDOF()
//        {
//            return componenteDOF;
//        }
//        string getlabelDOF()
//        {
//            return labelDOF;
//        }
//		float getvalorDOF()
//		{
//			return valorDOF;
//		}
//
//		//ORNDENA OS ELEMENTOS DO VETOR
//		bool OrdenaItens(formulario &a, formulario &b)
//		{
//			if (a.componenteDOF > b.componenteDOF) 
//				return true;
//			return false;
//		}
//};

struct formOrdenado{
  
	int		compDOF_ord;
	string	labelDOF_ord;
	float	valorDOF_ord; 

};
typedef struct formOrdenado FormOrd;