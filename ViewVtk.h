#pragma once
/*=========================================================================

  Program:   Visualization VTK
  Module:    ViewVtk.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  LAMCE
  Leandro Gazoni
  2013
=========================================================================*/

//includes C++
#include<iostream>
#include<vector>
#include<cstring>
#include<fstream>

//includes do VTK


#include <vtkSmartPointer.h>
#include <vtkImageViewer2.h>
#include <vtkDICOMImageReader.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <QVTKWidget.h>
// First include the required header files for the VTK classes we are using.
#include "vtkConeSource.h"
#include <vtkSphereSource.h>
#include <vtkUnstructuredGrid.h>
#include <vtkUnstructuredGridAlgorithm.h>
#include <vtkUnstructuredGridReader.h>
#include <vtkDataSetReader.h>
#include <vtkDataSetMapper.h>
#include <vtkDataSetToUnstructuredGridFilter.h>

#include <vtkSmartPointer.h>
#include "vtkPolyDataMapper.h"
#include "vtkRenderWindow.h"
#include "vtkRendererCollection.h"
#include "vtkCamera.h"
#include "vtkActor.h"
#include <vtkMapperCollection.h>
#include "vtkActorCollection.h"
#include "vtkDataObjectCollection.h"
#include "vtkCollection.h"
#include "vtkRenderer.h"
#include "vtkProperty.h" 
#include "vtkRenderWindowInteractor.h"
#include "vtkHierarchicalPolyDataMapper.h"

#include "vtkEnSightGoldReader.h"
#include "vtkEnSightReader.h"
#include "vtkGenericEnSightReader.h"
#include "vtkCompositeDataPipeline.h"
#include "vtkGeometryFilter.h"
#include "vtkMultiBlockDataSet.h"
#include <vtkCompositeDataGeometryFilter.h>
#include <vtkInformation.h>

#include <vtkMultiBlockDataSetAlgorithm.h>
#include "vtkMultiBlockDataSet.h"
#include <vtkDataSetMapper.h>
#include <vtkExtractBlock.h>


#include "vtkSmartPointer.h"
#define VTK_CREATE(type, name) vtkSmartPointer<type> name = vtkSmartPointer<type>::New()


#include <QFileDialog>
#include <qfile.h>
#include <QMessageBox>



#include <qheaderview.h>
#include <qstandarditemmodel.h>



#include <QMainWindow>
#include <qDebug>

#include "ui_runedgecfd.h"

using namespace std;

class ViewVtk : public QMainWindow
{
public:
	ViewVtk();
	ViewVtk(Ui::runEdgeCFDClass *uivtk);
	~ViewVtk(void);

	void ChamadaNavio(Ui::runEdgeCFDClass *uivtk);
	void UpdateCone(Ui::runEdgeCFDClass *uivtk, int id);
	//void UpdateModelAnsys(Ui::runEdgeCFDClass *uivtk, int id);
	void ChangeWireframe(bool wf);
	vector<string> LeituraArquivoEnsigth(const char *casefile, Ui::runEdgeCFDClass *uivtk);
	void ReconfigureBlocks(Ui::runEdgeCFDClass *uivtk);

//Variaveis
private:
	//Ui::runEdgeCFDClass *uivtk;

	vtkGenericEnSightReader *reader;

public:
	 vtkSmartPointer<vtkSphereSource> *sphere;
	 vtkConeSource *cone;

	 vtkPolyDataMapper *coneMapper;
	 vtkPolyDataMapper *sphereMapper;
	 vtkHierarchicalPolyDataMapper *mapper0;
	 vtkHierarchicalPolyDataMapper *mapper1;
	 
	 vtkActor *coneActor;
	 vtkActor *sphereActor;

	 vtkRenderer *ren1;
	 vtkRenderer *ren2;

	 //Variável para armazenar o numero de blocos da malha lida
	 //é atualizada na função LeituraArquivoEnsigth
	 int numberOfBlocks;

	 vtkDataSetMapper *mapper;
	 vtkActor *actorEnsigth;
	 vtkActor *actor;
	 vtkMapperCollection *mapperCollection;
	 vtkActorCollection *actorsCollection;
	 vtkCollection *blocksCollection;
	 vtkCollection *compositeCollection;

	 //Pegar a informação de multiblocos do reader
	 vtkMultiBlockDataSet *multiBDS;

};


/*

void Sistab::slotGEO(){

	QString filename = QFileDialog::getOpenFileName( this, tr("Open File"),"",tr("VTK Files(*.geo *.GEO)"));

	FILE *file;
    file = freopen(filename.toAscii(), "r", stdin);
    if(file != NULL)
    {


		map<int, vector<double> > mapcoord; //coordenadas dos pontos
		map<QString, vector<int> > mappart;	//pontos por partes
		vector<QString> namespart;	//nomes das partes


		int numpart = 0;
		int numele = 0;
		int ele = 0;
		int part = 0;

        string linha;
        char buffer[256];
		        
        cin.getline(buffer,256);

		cin.getline(buffer,256);
		linha = buffer;
		numpart = atoi(linha.c_str());
		
		cin.getline(buffer,256);
		cin.getline(buffer,256);
		cin.getline(buffer,256);
        linha = buffer;

        if(linha.compare("coordinates") == 0)
        {
            cin.getline(buffer,256);
            linha = buffer;
			numele = atoi(linha.c_str());

        }
		while(ele < numele){
			cin.getline(buffer,256);
			linha = buffer;
			
			int nu;
			double x;
			double y;
			double z;
			vector<double> vectemp;

			stringstream stream;
            stream.str(linha);
            stream >> nu;
            stream >> x;
			vectemp.push_back(x);
			stream >> y;
			vectemp.push_back(y);
			stream >> z;
			vectemp.push_back(z);
			mapcoord[nu] = vectemp;

			//cout << nu << "-" << x << "-" << y << "-" << z << endl;

			ele++;
		}

		while(part < numpart){

			int i = 0;
			cin.getline(buffer,256);
			linha = buffer;
			QString lin = QString::fromStdString(linha);
			if(lin.contains("part",true))
			{
				cin.getline(buffer,256);
				string qlinha = buffer;
				namespart.push_back(QString::fromStdString(linha));
				cin.getline(buffer,256);
				cin.getline(buffer,256);
				linha = buffer;
				int nump = atoi(linha.c_str());

				vector<int> temp;
				while(i < nump){
					cin.getline(buffer,256);
					linha = buffer;
					int ponto = atoi(linha.c_str());

					//cout << qlinha << ponto << endl;
					temp.push_back(ponto);

					i++;
				}

				mappart[namespart[part]] = temp;
				
				//cout << "------------------------------------------------------" << endl;
			}

			part++;
	
		}
		
		fclose(file);

	//visualizar com VTK

	}
}

*/