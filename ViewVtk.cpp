#include "ViewVtk.h"



//Construtor da Classe
ViewVtk::ViewVtk()
{	
	this->actorsCollection = vtkActorCollection::New();
	this->blocksCollection = vtkCollection::New();
	this->compositeCollection = vtkCollection::New();
	this->mapperCollection = vtkMapperCollection::New();
	this->reader = vtkGenericEnSightReader::New();
	this->multiBDS =vtkMultiBlockDataSet::New ();
}

ViewVtk::ViewVtk(Ui::runEdgeCFDClass *uivtk)
{	
	this->ren1 = vtkRenderer::New();
	ren1->SetBackground( 0.32, 0.34, 0.43 );
	uivtk->qvtkWidget->GetRenderWindow()->AddRenderer(this->ren1);
	
	this->actorsCollection = vtkActorCollection::New();
	this->blocksCollection = vtkCollection::New();
	this->compositeCollection = vtkCollection::New();
	this->mapperCollection = vtkMapperCollection::New();
	this->reader = vtkGenericEnSightReader::New();
	this->multiBDS =vtkMultiBlockDataSet::New ();
}

//Destrutor da Classe
ViewVtk::~ViewVtk(void)
{
	if(this->reader)
		this->reader->Delete();
	this->reader = NULL;

	if(this->ren1)
		this->ren1->Delete();
	this->ren1 = NULL;

	if(this->multiBDS)
		this->multiBDS->Delete();
	this->multiBDS = NULL;

	this->actorsCollection->RemoveAllItems();
	this->actorsCollection->Delete();

	this->blocksCollection->RemoveAllItems();
	this->blocksCollection->Delete();
	
	this->compositeCollection->RemoveAllItems();
	this->compositeCollection->Delete();
	
	this->mapperCollection->RemoveAllItems();
	this->mapperCollection->Delete();
}

//---------------------------- metodos --------------------------------
void ViewVtk::ChamadaNavio(Ui::runEdgeCFDClass *uivtk)
{

	cone = vtkConeSource::New();
	cone->SetHeight( 3.0 );
	cone->SetRadius( 1.0 );
	cone->SetResolution( 10 );
	coneMapper = vtkPolyDataMapper::New();
	coneMapper->SetInputConnection( cone->GetOutputPort() );
	
	coneActor = vtkActor::New();
	coneActor->SetMapper( coneMapper );
		

	//ren1 = vtkRenderer::New();
	//ren1->AddActor( coneActor );
	//ren1->SetBackground( 0.1, 0.2, 0.4 );

	/*vtkRenderWindow *renWin = vtkRenderWindow::New();
	renWin->AddRenderer( ren1 );
	renWin->SetSize( 300, 300 );*/


	//=============== esfera ===============

	vtkSmartPointer<vtkSphereSource> sphere = vtkSmartPointer<vtkSphereSource>::New();
	sphere->SetCenter(0.0, 0.0, 0.0);
	sphere->SetRadius(5.0);
	
	sphereMapper = vtkPolyDataMapper::New();
	sphereMapper->SetInputConnection(sphere->GetOutputPort());

	sphereActor = vtkActor::New();
	sphereActor->SetMapper( sphereMapper );

	//ren1 = vtkRenderer::New();
	ren1->AddActor( sphereActor );
	ren1->SetBackground( 0.1, 0.2, 0.4 );
	
	// VTK/Qt wedded
	uivtk->qvtkWidget->GetRenderWindow()->Render();
	uivtk->qvtkWidget->GetRenderWindow()->AddRenderer(ren1);
	//uivtk->qvtkWidget->GetRenderWindow()->AddRenderer(ren2);

	

}

void ViewVtk::UpdateCone(Ui::runEdgeCFDClass *uivtk, int id)
{

	switch (id)
	{
		case 0:
			cone->SetHeight( 2.0 );
			cone->SetRadius( 3.0 );
			coneActor->GetProperty()->SetColor(1,0,0); 
			break;

		case 1:
			cone->SetHeight( 4.0 );
			cone->SetRadius( 1.0 );
			coneActor->GetProperty()->SetColor(0,1,0); 
			break;

		case 2:
			cone->SetHeight( 2.0 );
			cone->SetRadius( 3.0 );
			coneActor->GetProperty()->SetColor(255,239,0); 
			break;

		case 3:
			cone->SetHeight( 4.0 );
			cone->SetRadius( 1.0 );
			coneActor->GetProperty()->SetColor(1,1,1);
			break;
	}
	uivtk->qvtkWidget->update();
}

void ViewVtk::ChangeWireframe(bool wf)
{
	if(wf)
	{
		sphereActor->GetProperty()->SetRepresentationToWireframe();
		//sphereActor->GetMapper()->GetInput()->Update();
		//sphereActor->SetMapper(sphereMapper);

	}else
	{
		sphereActor->GetProperty()->SetRepresentationToSurface();
		//sphereActor->SetMapper(sphereMapper);
		
	}
}

//---------- leitura do arquivo ensigth ---------------------
vector<string> ViewVtk::LeituraArquivoEnsigth(const char *casefile, Ui::runEdgeCFDClass *uivtk)
{
	
	actorEnsigth = vtkActor::New();
	actor = vtkActor::New();
	
	//realizando a leitura do arquivo ensight
	vtkSmartPointer<vtkCompositeDataPipeline> cdp = vtkSmartPointer<vtkCompositeDataPipeline>::New();
	this->reader->SetDefaultExecutivePrototype(cdp);
	this->reader->SetCaseFileName(casefile);
	this->reader->SetTimeValue(1);
	this->reader->Update();
	this->numberOfBlocks = this->reader->GetOutput()->GetNumberOfBlocks();

	//Pegar a informação de multiblocos do reader
	this->multiBDS = this->reader->GetOutput();

	vector<string> parts;
	//qDebug() << "GetNumberOfBlocks: " << reader->GetOutput()->GetNumberOfBlocks()  << endl;
	for(int i=0; i < this->numberOfBlocks; i++)
	{
		//Capturando os nomes dos blocos do arquivo case
		const char *c = this->multiBDS->GetMetaData(i)->Get(vtkCompositeDataSet::NAME());
		parts.push_back(c);

		//Selecionando cada bloco separadamente
		vtkExtractBlock *eBlock = vtkExtractBlock::New();
		eBlock->SetInputConnection(reader->GetOutputPort(0));
		eBlock->AddIndex(i+1);
		eBlock->Update();
		blocksCollection->AddItem(eBlock);

		//Extraindo o bloco selecionado pelo vtkExtractBlock
		vtkCompositeDataGeometryFilter *compositeFilter = vtkCompositeDataGeometryFilter::New();
		compositeFilter->SetInputConnection(vtkExtractBlock::SafeDownCast(blocksCollection->GetItemAsObject(i))->GetOutputPort(0));
		compositeFilter->Update();
		compositeCollection->AddItem(compositeFilter);

		//Passando o bloco para mapeamento
		vtkHierarchicalPolyDataMapper *hpdm = vtkHierarchicalPolyDataMapper::New();
		hpdm->SetInputConnection(vtkCompositeDataGeometryFilter::SafeDownCast(compositeCollection->GetItemAsObject(i))->GetOutputPort(0));
		mapperCollection->AddItem(hpdm);
		
		//Passando o mapeamento do bloco para o ator e configurando a sua visualização
		vtkActor *actor = vtkActor::New();
		actor->GetProperty()->SetColor(1,1,1);
		actor->VisibilityOn();
		actor->GetProperty()->SetPointSize(2);
		actor->SetMapper(vtkMapper::SafeDownCast(mapperCollection->GetItemAsObject(i)));
		actorsCollection->AddItem(actor);

		ren1->AddActor(vtkProp::SafeDownCast(actorsCollection->GetItemAsObject(i)));
		//ren1->AddActor(a);
		//uivtk->qvtkWidget->GetRenderWindow()->Render();
		
		//ren1->AddActor(a);
		//bl1->RemoveIndex(i+1);
		//compositeFilter->Delete();		
	}
	//multiBDS->Delete();
	//ren1->RemoveActor(vtkProp::SafeDownCast(actorCollection->GetItemAsObject(0)));
	//ren1->RemoveActor(vtkProp::SafeDownCast(actorCollection->GetItemAsObject(1)));
	//ren1->RemoveActor(vtkProp::SafeDownCast(actorCollection->GetItemAsObject(2)));
	//ren1->RemoveActor(vtkProp::SafeDownCast(actorCollection->GetItemAsObject(3)));
	//ren1->RemoveActor(vtkProp::SafeDownCast(actorCollection->GetItemAsObject(4)));
	////ren1->RemoveActor(vtkProp::SafeDownCast(actorCollection->GetItemAsObject(5)));

	//vtkSmartPointer<vtkGeometryFilter> geo =  vtkSmartPointer<vtkGeometryFilter>::New();
	//geo->SetInputConnection(reader->GetOutputPort());
	
//	mapper1 = vtkHierarchicalPolyDataMapper::New();
//	mapper1->SetInputConnection(compositeFilter->GetOutputPort());
//
//	mapper0 = vtkHierarchicalPolyDataMapper::New();
//  mapper0->SetInputConnection(compositeFilter->GetOutputPort());
    
	//mapper0->SetColorModeToMapScalars();
   // mapper0->SetScalarModeToUsePointFieldData();
    //mapper0->ColorByArrayComponent("pointScalars", 0);
    //mapper0->SetScalarRange(0, 112);
	

	
	//reader->ReadAllVariablesOn();
	//reader->Update();

	// o que devo fazer
	//multiblockDataSet-> ExtractBlock -> CompositeDataGeometryFilter -> Mapper for the N blocs we have extracted -> Actors for the N Mappers -> Renderer

	 // vtkMultiBlockDataSet *multiBDS =vtkMultiBlockDataSet::New ();
	 // multiBDS = reader->GetOutput();

	 // 
	 // //retornando o nome de cada parte do bloco do arquivo geo
	 // 	for(int i=0; i < reader->GetOutput()->GetNumberOfBlocks() ; i++)
		//{
		//	
		//	const char *c = multiBDS->GetMetaData(i)->Get(vtkCompositeDataSet::NAME());
		//	parts.push_back(c);
		//	//qDebug() << "name" << multiBDS->GetMetaData(i)->Get(vtkCompositeDataSet::NAME())  << endl;
		//}

	    

	////mapper de armazenamento do arquivo GEO
	//mapper = vtkSmartPointer<vtkDataSetMapper>::New();
	//mapper->SetInputConnection(geo->GetOutputPort());
	//
	//
	
	//vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();





//	actor->SetMapper( mapper1 );
//	
//	
//	actorEnsigth->SetMapper( mapper0 );
//	actorEnsigth->GetProperty()->SetPointSize(2);
	//
//	ren1->AddActor( actorEnsigth );
//	ren1->AddActor(actor);
		
		//for(int i=0; i < reader->GetOutput()->GetNumberOfBlocks(); i++)
		//{
		//	ren1->AddActor(vtkProp::SafeDownCast(actorCollection->GetItemAsObject(i)));
		//}




	//
	//// VTK/Qt wedded
	uivtk->qvtkWidget->GetRenderWindow()->Render();
	uivtk->qvtkWidget->GetRenderWindow()->AddRenderer(ren1);


	
	return parts;
}


//// metodo para selecionar a parte do arquivo de pontos gerado pelo ANSYS
//void ViewVtk::UpdateModelAnsys(Ui::runEdgeCFDClass *uivtk, int id)
//{
//	vtkActor *a;
//	int visibility;
//	switch (id)
//	{
//		case 0:
//			actorEnsigth->GetProperty()->SetColor(255/255,127/255,36/255);
//			actorEnsigth->VisibilityOff();
////			QMessageBox::critical(uivtk->tab_Setup, "PAINEL ITEM", QString::number(id));
//
//			a = vtkActor::SafeDownCast(actorsCollection->GetItemAsObject(id));
//			visibility = a->GetVisibility();
//			if(visibility)
//			{
//				vtkActor::SafeDownCast(actorsCollection->GetItemAsObject(id))->VisibilityOff();
//			}
//			else
//			{
//				vtkActor::SafeDownCast(actorsCollection->GetItemAsObject(id))->VisibilityOn();
//			}
//
//			break;
//
//		case 1:
//			actor->VisibilityOff();
//			actor->GetProperty()->SetColor(255/255,127/255,36/255);
//			//QMessageBox::critical(uivtk->tab_Setup, "PAINEL ITEM", QString::number(id));
//			a = vtkActor::SafeDownCast(actorsCollection->GetItemAsObject(id));
//			visibility = a->GetVisibility();
//			if(visibility)
//			{
//				vtkActor::SafeDownCast(actorsCollection->GetItemAsObject(id))->VisibilityOff();
//			}
//			else
//			{
//				vtkActor::SafeDownCast(actorsCollection->GetItemAsObject(id))->VisibilityOn();
//			}
//			break;
//
//		case 2:
//			//QMessageBox::critical(uivtk->tab_Setup, "PAINEL ITEM", QString::number(id));
//			a = vtkActor::SafeDownCast(actorsCollection->GetItemAsObject(id));
//			visibility = a->GetVisibility();
//			if(visibility)
//			{
//				vtkActor::SafeDownCast(actorsCollection->GetItemAsObject(id))->VisibilityOff();
//			}
//			else
//			{
//				vtkActor::SafeDownCast(actorsCollection->GetItemAsObject(id))->VisibilityOn();
//			}
//			break;
//
//		case 3:
//			//QMessageBox::critical(uivtk->tab_Setup, "PAINEL ITEM", QString::number(id));
//			a = vtkActor::SafeDownCast(actorsCollection->GetItemAsObject(id));
//			visibility = a->GetVisibility();
//			if(visibility)
//			{
//				vtkActor::SafeDownCast(actorsCollection->GetItemAsObject(id))->VisibilityOff();
//			}
//			else
//			{
//				vtkActor::SafeDownCast(actorsCollection->GetItemAsObject(id))->VisibilityOn();
//			}
//			break;
//	}
//	uivtk->qvtkWidget->update();
//
//}
void ViewVtk::ReconfigureBlocks(Ui::runEdgeCFDClass *uivtk)
{
	////vector<int> indexes;
	//int i = this->reader->GetOutput()->GetNumberOfBlocks();
	//std::vector<int> indexes(i);

	//if(uivtk->checkBox->isChecked())
	//	//indexex.at
	//
	//for(i; i>0; i--)
	//	indexes.at(i)=uivtk->checkBox->setChecked();

}