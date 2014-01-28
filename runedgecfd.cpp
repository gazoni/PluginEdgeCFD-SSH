#include <QFileDialog>
#include "runedgecfd.h"
#include <stdlib.h>

#include "ssh.h"

//================================================================================================

//TROCANDO ATRIBUTO DE ARQUIVOS
BOOL WINAPI SetFileAttributesA(_In_  LPCTSTR lpFileName, _In_  DWORD dwFileAttributes);

//OBJETO DO MENU EXTERNO DE CONFIGURACAO DO ANSYS
configAnsys *menuAnsys;


//================================================================================================


//CONSTRUTOR DA CLASSE
runEdgeCFD::runEdgeCFD(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags), ui(new Ui::runEdgeCFDClass)
{
	//INICIALIZACAO DA JANELA PRINCIPAL
	ui->setupUi(this);
	this->setWindowFlags(Qt::WindowMaximizeButtonHint);
	//QDecoration::Maximize;

    //ALOCANDO O MENU DO ANSYS
     menuAnsys = new configAnsys();


	//realiza todos os connects
	conectar();

	//pasta de origem dos arquivos do edgecfd
	sourceFolder = "./edgecfd";

	// variaveis de controle de elementos da aba SETUP
	linha = 1;
	idMaterial = 1;
	totcampos = 60;
	totcamposMat = 800;

	//Iniciando a aplicacao com a criando um campo para DOF
	//slotNewSetup();
	
	//slotNewMaterial();
	//slotNewMaterial();

	// VERIFICA QUAL VERSAO DE ANSYS EXISTE INSTALADA NA MAQUINA ATUAL e coloca uma string no aba FILEMANEGEMENT
	menuAnsys->VerificaPathsAnsys();
	
	//menubar lendo a versao de trabalho
	loadVersion();

	
	//======== REALIZANDO A CHAMADA DO VTK ================

	view = new ViewVtk(ui);
     //view->ChamadaNavio(ui);

	//========= ALOCACAO DOS METODOS DO SSH ========
	process = new QProcess();

}

//DESTRUTOR DA CLASSE
runEdgeCFD::~runEdgeCFD()
{
	delete ui;
}

void runEdgeCFD::loadMesh()
{
	//===============================================================================================
	//========================== COMENTAR PARA GERAR O INSTALADOR ===================================
	//===============================================================================================

	//parts = view->LeituraArquivoEnsigth("C:\\runEdgeCFD\\teste.case", ui);
	this->parts = view->LeituraArquivoEnsigth(this->pathCase.c_str(), ui);
	//view->LeituraArquivoEnsigth("E:\\SOFTWARES\\VTK\\vtkdata-5.6.0\\Data\\EnSight\\elements.case", ui);
	
	//Set table row count 1 and column count 3
	ui->tableWidget->setRowCount(this->view->numberOfBlocks);
	ui->tableWidget->setColumnCount(2);
	
	ui->tableWidget->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
	
	//Set Header Label Texts Here
	ui->tableWidget->setHorizontalHeaderLabels(QString("Parts").split(";"));
	QStringList list;
	list << "Parts" << "Color";
	ui->tableWidget->setHorizontalHeaderLabels(list);	
	
	srand(0);
	
	//Add Table items here
	for(int i = 0; i < this->view->numberOfBlocks; i++)
	{
		QTableWidgetItem *cBox = new QTableWidgetItem(QString::fromStdString(parts[i]));
		cBox->setCheckState(Qt::Checked);
		cBox->setForeground(QBrush(QColor(0, 0, 0, 255)));
		cBox->setBackground(QBrush(QColor(255, 255, 255, 255)));
		ui->tableWidget->setItem(i,0,cBox);
		QTableWidgetItem *item = new QTableWidgetItem();

		item->setForeground(QBrush(QColor(0, 0, 0, 255)));
		float r = (rand() % 255) + 1;
		float g = (rand() % 255) + 1;
		float b = (rand() % 255) + 1;
		item->setBackgroundColor(QColor(r, g, b, 255));
		ui->tableWidget->setItem(i,1,item);

		vtkActor *a = vtkActor::SafeDownCast(this->view->actorsCollection->GetItemAsObject(i));
		a->GetProperty()->SetColor(item->background().color().redF(), item->background().color().greenF(), item->background().color().blueF());
	}
	//ui->tableWidget->resizeColumnsToContents();
	this->ui->qvtkWidget->GetRenderWindow()->GetRenderers()->GetFirstRenderer()->ResetCamera();
	this->ui->qvtkWidget->GetRenderWindow()->Render();
	
	connect(ui->tableWidget, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(slotBlocksVisibility(QTableWidgetItem*)));
	connect(ui->tableWidget, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), this, SLOT(slotBlocksColors(QTableWidgetItem*)));

	//TRANSFORMANDO A TABELA COMO READ ONLY --------------------------
	ui->tableWidget->setEditTriggers(QTableWidget::NoEditTriggers);
	//----------------------------------------------------------------

	QList<QTableWidgetItem*> selected_rows = ui->tableWidget->selectedItems();
	while( !selected_rows.isEmpty() )
	{
		QTableWidgetItem *itm = selected_rows.at(0);
		ui->tableWidget->removeRow(itm->row());
		selected_rows = ui->tableWidget->selectedItems();
	}


	//HABILITANDO USO DE MOUSE NA TABELA

	//ui->tableWidget->setMouseTracking(true);
 //   ui->tableWidget->viewport()->setMouseTracking(true);
 //   ui->tableWidget->installEventFilter(this);
 //   ui->tableWidget->viewport()->installEventFilter(this);
	
	//----------------------------------------------------------------

	//===============================================================================================
	//====================== FIM DE COMENTAR PARA GERAR O INSTALADOR ================================
	//===============================================================================================
}

//METODO PARA REALIZAR OS CONNECTS DA CLASSE
void runEdgeCFD::conectar()
{

	//connects MENU
	connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(slotOpen()));
	connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(slotSave()));
    
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(slotExit()));
    connect(ui->actionAnsys_Path, SIGNAL(triggered()), this, SLOT(slotConfigAnsys()));
	connect(ui->actionRenderColor, SIGNAL(triggered()), this, SLOT(slotConfigRender()));


	// ABA FILE MANAGEMENT
	connect(ui->pushButton_WorkingDir, SIGNAL(clicked()), this, SLOT(slotChangeDirectory()));
	connect(ui->pushButton_Run, SIGNAL(clicked()), this, SLOT(slotMakeButton()));
	connect(ui->pushButton_dbFile, SIGNAL(clicked()), this, SLOT(slotSelectDBFile()));
	
	//atualiza o nome do JOBNAME na ABA INPUT
	connect(ui->lineEdit_jobName, SIGNAL(textChanged(QString)),this, SLOT(setNameFileInput(QString)));

	//connects da aba SETUP
	connect(ui->pushButton_newDOF, SIGNAL(clicked()), this, SLOT(slotNewSetup()));
	connect(ui->pushButton_delDOF, SIGNAL(clicked()), this, SLOT(slotDeleteSetup()));
    connect(ui->pushButton_RunSetupEdgeCFD, SIGNAL(clicked()), this, SLOT(slotRunEdgeCFDSetup()));
	connect(ui->pushButtonSaveSetupFile, SIGNAL(clicked()), this, SLOT(slotEscreveArquivoSetup()));

	//connect da aba INPUT
	connect(ui->pushButtonSaveInput, SIGNAL(clicked()), this, SLOT(slotEscreveArquivoInput()));
	
	//connect da aba FSI
	connect(ui->pushButtonSaveFSI, SIGNAL(clicked()), this, SLOT(slotEscreveArquivoFSI()));


	//CONNECTS ABA PRE
	connect(ui->pushButton_RunPreEdgeCFD, SIGNAL(clicked()), this, SLOT(slotRunEdgeCFDPRE()));


	//CONNECTS ABA MATERIAL
	connect(ui->pushButton_newMaterial, SIGNAL(clicked()),  this, SLOT(slotNewMaterial()));
	connect(ui->pushButton_delMaterial, SIGNAL(clicked()),  this, SLOT(slotDeleteMaterial()));
	connect(ui->pushButton_saveMaterial, SIGNAL(clicked()), this, SLOT(slotEscreveMaterial()));


	//CONNECT BOTAO EXECUCAO EDGECFD
	connect(ui->pushButton_RunEdgeCFDSolver, SIGNAL(clicked()), this, SLOT(slotRunEdgeCFDSolver()));


	//connect SIGNAL AND SLOTS
	connect(menuAnsys, SIGNAL(updateAnsysVersion(QString)), this, SLOT(slotAtualizaLabelAnsys(QString)));

	//conects para trabalhar com a visualizacao do VTK
	connect(ui->checkBoxWireframe, SIGNAL(toggled(bool)), this, SLOT(slotSetWireframeMode(bool)));

	//connect(ui->treeWidgetMesh, SIGNAL(toggled(bool)), this, SLOT(slotBlocksVisibility(bool)));
	connect(ui->gridLayoutMesh, SIGNAL(toggled(bool)), this, SLOT(slotBlocksColor(bool)));

	//connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(slotTestaCores(int)));

	//SLOT PARA CONEXAO UTILIZANDO O SSH
	connect(ui->commandLinkButton_jobStatus, SIGNAL(clicked()), this, SLOT(slotSSHConnect()));
	connect(ui->pushButtonClearWindow, SIGNAL(clicked()), this, SLOT(slotClearWindowStatus()));

	//SLOT DE COMPACTACAO E COPIA DOS ARQUIVOS DE DADOS COPIA DOS ARQUIVOS
	connect(ui->pushButton_CopySimulationFiles, SIGNAL(clicked()), this, SLOT(slotCopySimulationFiles()));

	//SLOT PARA A GRAVACAO CONFIGURACAO E GRAVACAO DO ARQUIVO PBS NA ABA UNIX
	connect(ui->pushButton_PBSFile, SIGNAL(clicked()), this, SLOT(slotSavePBSFile()));
	
}


//========= CRIANDO EVENTOS DE MOUSE =================

bool runEdgeCFD::eventFilter(QObject *object, QEvent *e)
{
	//if(ui->tabWidget_View->currentIndex() == 6)
	//{
	//	if (object == ui->tableWidget && e->type() == QEvent::MouseButtonPress)
	//	{
	//		QMessageBox::critical(ui->tab_Setup, "mouse", QString::number(ui->tableWidget->currentRow()));		
	//	}
	//}

	if (e->type() == QEvent::MouseButtonDblClick )
	{
		////===========================================================================
		////CODIDO PARA TRAVAR O ITEM E NAO PERMITIR O USUARIO A NAO EDITAR AS PARTES
		////===========================================================================
		//QTableWidgetItem *item = ui->tableWidget->currentItem();
		//ui->tableWidget->item(item->row(),item->column())->setFlags(Qt::NoItemFlags|Qt::ItemIsSelectable|Qt::ItemIsEnabled);
	}
	

 if (e->type() == QEvent::MouseButtonPress )
    {       
		//Aviso de quando se clica com o mouse
        //qDebug()<<"MOUSE BUTTON PRESSED @";
   //     if (  object == ui->tableWidget->viewport() ) // changed here
   //     {   
			////QMessageBox::critical(ui->tab_Setup, "PRESS", QString::number(ui->tableWidget->currentRow()));
			//	
   //     }    
        return QObject::eventFilter(object, e);
    }  

 else if (e->type() == QEvent::MouseButtonRelease )
    {      
        qDebug()<<"MOUSE BUTTON RELEASED @";    
   //     if ( object == ui->tableWidget->viewport() ) // changed here
   //     {        
   //         //QMessageBox::critical(ui->tab_Setup, "SAIDA", QString::number(ui->tableWidget->currentRow()));
			//QTableWidgetItem *item = ui->tableWidget->currentItem();
   //         //qDebug()<<item->row()<<":"<<item->column();

			////Fazendo atualizacao em propriedades do cone caso clique na tabela em seu item especifico
			////view->UpdateCone(ui, item->row());

			//////Fazendo a selecão da parte do arquivo VTK do modelo gerado pelo ANSYS
			////view->UpdateModelAnsys(ui, item->row());


   //     }      
        return QObject::eventFilter(object, e);
    }  
    return false;

}

void runEdgeCFD::mousePressEvent ( QMouseEvent * e )
{
	// store click position
	m_lastPoint = e->pos();
	// set the flag meaning "click begin"
	//m_mouseClick = true;

	//if (ui->tabWidget_View->currentIndex() == 5 )
	//{

	// do something: for example emit Click signal
	//QMessageBox::critical(ui->tab_Setup, "mouse", "press event");
	//emit mouseClickEvent();
	//}
}

//================================================

//void runEdgeCFD::mouseReleaseEvent ( QMouseEvent * e )
//{
//    // check if cursor not moved since click beginning
//	//&& (e->pos() == m_lastPoint)
//	if (ui->tabWidget_View->currentIndex() == 5 )
//    {
//	
//        // do something: for example emit Click signal
//        QMessageBox::critical(ui->tab_Setup, "mouse", "to na aba certa");
//		//emit mouseClickEvent();
//    }
//}

//================================== CARREGAR A VERSAO DO ARQUIVO ==================================
void runEdgeCFD::loadVersion(){

	QString filename = "config.ini";

    FILE *file;
    file = freopen(filename.toAscii(), "r", stdin);
    if(file != NULL)
    {

        std::string linha;
        char buffer[256];
		        
        std::cin.getline(buffer,256);
        linha = buffer;

        if(linha.compare("[Version]") == 0)
        {
            string t1;
            cin.getline(buffer,256);
            linha = buffer;
			QString temp = "runEdgeCFD v. ";
			temp += linha.c_str();
			this->setWindowTitle(temp);
			
        }
		
		fclose(file);
	}
}


//=================================== ABA FILE MANEGEMENT ===========================================

//METODO RESPOSANVEL POR SELECIONAR O ARQUIVO DB
void runEdgeCFD::slotSelectDBFile()
{
	//ABRINDO A JANELA DE SELECAO DO ARQUIVO DB
	
	////definindo um diretorio Home() para que o usario possa selecionar apartir dai.
	//directory = QDir::home();

	//limpando o path selecionado no lineEdit
	ui->lineEdit_dbFile->clear();

	/* select a db file only using file dialog */
	QString path = QFileDialog::getOpenFileName(this, tr("Select db File"), directory.path(), tr("db File (*.db *.DB)"));

	//definindo um diretorio Home() para que o usario possa selecionar apartir dai.
	directory.setPath(QString::fromAscii(path));

	if ( path.isNull() == false )
	{
		directory.setPath(path);
		ui->lineEdit_dbFile->setText(path);
		//definindo o path para o arquivo db
		dbFile.setFileName(path);
	}

	//DEPOIS TERA QUE REALIZAR UMA COPIA DO ARQUIVO DB PARA O DIRETORIO DO USUARIO ASSIM QUE O USUARIO CLICAR NO BOTAO MAKE
	//IR PARA O METODO runEdgeCFD::slotMakeButton()


}


//METODO QUE SELECIONA ONDE O USARIO DEVERA FAZER A RODADA
void runEdgeCFD::slotChangeDirectory()
{
	//definindo um diretorio Home() para que o usario possa selecionar apartir dai.
	directory = QDir::home();

	//limpando o path selecionado no lineEdit
	ui->lineEdit_WorkingDir->clear();

	/* select a directory using file dialog */
	QString path = QFileDialog::getExistingDirectory (this, tr("Select Folder"), directory.path(), QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);

	if ( path.isNull() == false )
	{
		directory.setPath(path);
		ui->lineEdit_WorkingDir->setText(path);
	}
}

// RESPONSAVEL POR REALIZAR A EXECUCAO DO FRAMEWORK EDGECFD
//BOTAO MAKE DA ABA - FILE MANEGEMENT
void runEdgeCFD::slotMakeButton()
{

	//*********************************************************
	//VERIFICACAO DE ERROS EM TODAS AS ABAS
	//*********************************************************

	bool erro = verificarErros();

	//*********************************************************


	if(erro == false)
	{
		return;
	}
	else
	{
		//*************************************************************
		//METODO PARA COPIAR A ESTRUTURA DE PASTAS PARA O WORKDIR ATUAL
		//*************************************************************
		copyFolder(sourceFolder, ui->lineEdit_WorkingDir->text());

		//*********************************************************


		//*************************************************************
		//METODO PARA COPIAR O ARQUIVO DB PARA O WORKDIR ATUAL
		//*************************************************************
		QFileInfo fileInfo(dbFile.fileName());
		QString destinationFile = ui->lineEdit_WorkingDir->text().toAscii() + "/ANSYS/" + fileInfo.fileName();
		dbFile.copy(dbFile.fileName(), destinationFile);

		//*********************************************************
		

		//*********************************************************
		////SALVAR OS DADOS DO FORMULARIO ARQUIVOS NAS SUAS PASTAS
		//*********************************************************

		ProcessarFormulario();

		//*********************************************************


		//***********************************************************
		// EXECUTA AS MACROS EXISTENTES E CHAMAS O EXE FEITOS EM F90
		//***********************************************************

		// VERIFICANDO SE EXISTE VALORES INSERIDOS NA ABA SETUP MENORES IGUAL A ZERO PARA A
		// COMPONENTE ZERO (0)
		// POIS SE ESTES VALORES FOREM ZERO O EXECUTAVEL SETUP_EDGECFD-REV-C GERA UM ERRO
		
		//PERCORRENDO O VETOR INSERIDO PELO USUARIO
		bool LabelErro = false;
		for (int i= 0; i< form.size(); i++)
		{
			if(form[i].componenteDOF->currentIndex() == 0 && form[i].valorDOF->value() <= 0 )
			{
				LabelErro =  true;
			}
		}

		//CASE EXISTA UM VALOR <= 0 DA COMPONENTE ZERO
		if(LabelErro)
		{
			QMessageBox::critical(ui->tab_Setup, "error", "The Tab SETUP a zero COMPONENT value can not be smaller than or equal to zero");
			return;
		}
		else
		{
			//EXECURANDO A MACRO DO ANSYS
			ExecutaMacros();
		}
		
		//***********************************************************
	}


}

//VERIFICACAO DE ERROS NAS ABAS
bool runEdgeCFD::verificarErros()
{

	//*********************************************************
	//VERIFICACAO DE ERROS NAS ABAS
	//*********************************************************

	//ABA  FILE MANAGEMENT

	//menssagem de erro - usuario nao definiu o WorkDir
	if(ui->lineEdit_WorkingDir->text() == "")
	{
		QMessageBox::critical(this, "error", "Please set Work Directory");
		return false;
	}

	//Menssagem de erro - usuario nao definiu o nome do job name
	if(ui->lineEdit_jobName->text() == "")
	{
		QMessageBox::critical(this, "error", "Please set Job Name");
		return false;
	}

	
	//verificando se o usuario definiu um arquivo db
	if(ui->lineEdit_dbFile->text().isEmpty())
	{
		QMessageBox::critical(this, "error", "Please set db file");
		return false;
	}

	
	//ABA SETUP
	if(form.size() <= 0)
	{
		QMessageBox::critical(this, "error", "There are no items in the SETUP tab");
		return false;
	}

	//ABA PRE

	//ABA INPUT

	//ABA FSI

	//**********************************************************************************
	return true;
}	


//criacao de nos itens para a aba INPUT (condicoes de contorno)
void runEdgeCFD::slotNewSetup()
{

	// REALIZANDO A CRIACAO DOS CAMPOS DINAMICOS DA ABA SETUP
	//#  Nº DA COMPONENTE CC >> "ESPACO" >>  LABEL  <<  VALOR   

	//===================================================================
	// CRIANDO O CAMPO COMPONENTE - COMBOBOX COM NOMES DAS COMPONENTES
	//===================================================================
	form[linha].componenteDOF = new QComboBox(ui->scrollAreaWidgetContents);
	form[linha].componenteDOF->setObjectName(QString::fromUtf8("componente_DOF"));
	form[linha].componenteDOF->setMinimumSize(QSize(100, 22));
	form[linha].componenteDOF->setMaximumSize(QSize(150, 22));
	
	int numeroDeBlocos = this->view->numberOfBlocks;
	QStringList list;
	list << " ";//inserir o indice 0 que é vazio
	for(int i=0; i<numeroDeBlocos; i++)
		list << QApplication::translate("runEdgeCFDClass", QString::fromStdString(parts[i]), 0, QApplication::UnicodeUTF8);
	form[linha].componenteDOF->insertItems(linha, list);

	//spinBox_DOF = new QSpinBox(ui->scrollAreaWidgetContents);
	//spinBox_DOF->setObjectName(QString::fromUtf8("spinBox_DOF"));
	//spinBox_DOF->setMaximumSize(QSize(46, 22));
	//spinBox_DOF->setMinimum(0);
	//spinBox_DOF->setMaximum(999);
	//spinBox_DOF->setValue(0);


	//===================================================================
	//===================================================================

	//===================================================================
	// CRIANDO O CAMPO ESPACAMENTO
	//===================================================================

	//form[linha].espacamentoDOF = new QSpacerItem(35, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);


	//===================================================================
	//===================================================================


	//===================================================================
	// CRIANDO O CAMPO COMPONENTE - COMBOBOX - "VX" "VY" "VZ" "ALE-X" "ALE-Y" "ALE-Z" "P" "HX" "HY" "HZ" "HW"
	//===================================================================

	form[linha].labelDOF = new QComboBox(ui->scrollAreaWidgetContents);
	form[linha].labelDOF->setObjectName(QString::fromUtf8("label_DOF"));
	form[linha].labelDOF->setMinimumSize(QSize(50, 22));
	form[linha].labelDOF->setMaximumSize(QSize(80, 22));
	//form[linha].labelDOF->setGeometry(QRect(320, 80, 73, 22));
	
	//comboBox_DOF = new QComboBox(ui->scrollAreaWidgetContents);
	//comboBox_DOF->setObjectName(QString::fromUtf8("comboBox_DOF"));
	//comboBox_DOF->setMinimumSize(QSize(80, 22));
	//comboBox_DOF->setMaximumSize(QSize(80, 22));
	//comboBox_DOF->setGeometry(QRect(320, 80, 73, 22));

	// ITENS DO COMBOBOX - setcurrentIndex(id)
	form[linha].labelDOF->insertItems(0, QStringList()
		<< QApplication::translate("runEdgeCFDClass", "VX"		,0, QApplication::UnicodeUTF8) //	0
		<< QApplication::translate("runEdgeCFDClass", "VY"		,0, QApplication::UnicodeUTF8) //	1
		<< QApplication::translate("runEdgeCFDClass", "VZ"		,0, QApplication::UnicodeUTF8) //	2
		<< QApplication::translate("runEdgeCFDClass", "ALE-X"	,0, QApplication::UnicodeUTF8) //	3
		<< QApplication::translate("runEdgeCFDClass", "ALE-Y"	,0, QApplication::UnicodeUTF8) //	4
		<< QApplication::translate("runEdgeCFDClass", "ALE-Z"	,0, QApplication::UnicodeUTF8) //	5
		<< QApplication::translate("runEdgeCFDClass", "P "		,0, QApplication::UnicodeUTF8) //	6
		<< QApplication::translate("runEdgeCFDClass", "HX"		,0, QApplication::UnicodeUTF8) //	7
		<< QApplication::translate("runEdgeCFDClass", "HY"		,0, QApplication::UnicodeUTF8) //	8
		<< QApplication::translate("runEdgeCFDClass", "HZ"		,0, QApplication::UnicodeUTF8) //	9
		<< QApplication::translate("runEdgeCFDClass", "HW"		,0, QApplication::UnicodeUTF8) //	10
		);



	//=========================================================================================
	//=========================================================================================

	//===================================================================
	// CRIANDO O CAMPO COMPONENTE - QDoubleSpinBox - VALORDOF
	//===================================================================


	form[linha].valorDOF = new QDoubleSpinBox(ui->scrollAreaWidgetContents);
	form[linha].valorDOF->setObjectName(QString::fromUtf8("valor_DOF"));
	form[linha].valorDOF->setMaximumSize(QSize(80, 22));
	form[linha].valorDOF->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
	form[linha].valorDOF->setDecimals(5);
	form[linha].valorDOF->setMaximum(100000);
	form[linha].valorDOF->setButtonSymbols(QAbstractSpinBox::NoButtons);


	//doubleSpinBox_DOF = new QDoubleSpinBox(ui->scrollAreaWidgetContents);
	//doubleSpinBox_DOF->setObjectName(QString::fromUtf8("doubleSpinBox_DOF"));
	//doubleSpinBox_DOF->setMaximumSize(QSize(70, 22));
	//doubleSpinBox_DOF->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
	//doubleSpinBox_DOF->setDecimals(5);
	//doubleSpinBox_DOF->setMaximum(100000);


	//===================================================================================================
	//===================================================================================================


	//=============================================================
	//INSERINDO OS ITENS NA ESTRUTURA DO QVECTOR
	//=============================================================

	//componenteDOF.push_back(spinBox_DOF);
	//espacamentoDOF.push_back(horizontalSpacer);
	//labelDOF.push_back(comboBox_DOF);
	//valorDOF.push_back(doubleSpinBox_DOF);



	//=============================================================
	//ATUALIZANDO A INTERFACE
	//=============================================================

	//ADICIONANDO O CAMPO DE COMPONENTES DOF A INTERFACE
	//int linha = componenteDOF->size();
	ui->gridLayout_19->addWidget(form[linha].componenteDOF, linha, 0, 1, 1);

	//=============================================================
	//ADICIONANDO O ESPACAMENTO JUNTO A INTERFACE
	//linha = espacamentoDOF->size();
	//ui->gridLayout_19->addItem(form[linha].espacamentoDOF, linha, 1, 1, 1);

	//=============================================================
	//ADICIONANDO O COMBOBOX (label) JUNTO A INTERFACE
	//linha = labelDOF->size();
	ui->gridLayout_19->addWidget(form[linha].labelDOF, linha, 1, 1, 1);

	//==============================================================

	//ADICIONANDO DOUBLESPINBOX (VALOR) JUNTO A INTERFACE
	//linha = valorDOF->size();
	ui->gridLayout_19->addWidget(form[linha].valorDOF, linha, 2, 1, 1);

	//===================================================================

	//INSERINDO UM ESPACAMENTO VERTICAL NO FINAL DOS CAMPOS DO FOMULARIO PARA QUE 
	//OS CAMPOS POSSAM FICAR NO TOPO
	//verticalSpacer_setup = new QSpacerItem(20, 554, QSizePolicy::Minimum, QSizePolicy::Expanding);

	//linha = valorDOF->size();
	//ui->gridLayout_19->addItem(verticalSpacer_setup, totcampos, 1, 1, 1);

	//=============================================================
	//=============================================================

	//atualizando os itens na interface
	ui->gridLayout_19->update();
	//=============================================================

	linha++;
	totcampos++;

}

// deleta itens criados na aba INPUT (condicoes de contorno)
void runEdgeCFD::slotDeleteSetup()
{

	if(linha == 1)
	{
		QMessageBox::critical(this, "Error", "There are no items in the SETUP tab");
		return;
	}
	else
	{
		totcampos--;
		linha--;
		
		form[linha].componenteDOF->deleteLater();
		//form[linha].espacamentoDOF->invalidate();
		form[linha].labelDOF->deleteLater();
		form[linha].valorDOF->deleteLater();

		//componenteDOF.at(linha)->deleteLater();
		//espacamentoDOF.at(linha)->invalidate();
		//labelDOF.at(linha)->deleteLater();
		//valorDOF.at(linha)->deleteLater();


		form.erase(form.find(linha));
		//espacamentoDOF.pop_back();
		//labelDOF.pop_back();
		//valorDOF.pop_back();
		//qDebug() << form.size();
	}


	//atualizando os itens na interface
	ui->gridLayout_19->update();
	//=============================================================

}



//ATUALIZANDO O NOME DO ARQUIVO NA ABA INPUT
void runEdgeCFD::setNameFileInput(QString FileName)
{
	//A MEDIDA QUE O USUARIO ESCREVE O NOME DO JOBNAME ELE E ATUALIZADO AUTOMATIMENTE NA ABA INPUT
	ui->lineEdit_InputFileName->setText(FileName+"_1");

	//DEFININDO O NOME DO JOBNAME NO ARQUIVO PBS
	ui->lineEdit_PBSJobname->setText(FileName);
}

//================================================================================================================
// Metodo responsavel por realizar a escrita do arquivo INPUT.DAT
//================================================================================================================
void runEdgeCFD::slotEscreveArquivoInput()
{
	//realizar o tratamento de erro caso nao ainda nao foi criado este arquivo pelo botao make da aba principal
	QDir WorkPath = ui->lineEdit_WorkingDir->text();
	QString inputFilePath = WorkPath.absolutePath()+"/SOLVER/INPUT.DAT";
	QFile inputFile(inputFilePath);
	
	if( !inputFile.exists() || ui->lineEdit_jobName->text().isEmpty())
	{
		QMessageBox::critical(this, "Error", "The Jobname does not exist or a folder structure is empty. Please set data in file management tab and click on the make button.");
		return;		
	}
	else
	{

		//realizando a chamada nome metodo da classe IO para escrever o arquivo INPUT.DAT
		io::Escreve_INPUTFile(ui->lineEdit_jobName->text(), QDir(ui->lineEdit_WorkingDir->text()+"/SOLVER"), form, ui);
	}
}


//================================================================================================================
// Metodo responsavel por realizar a escrita do arquivo FSI.DAT - 
//================================================================================================================
void runEdgeCFD::slotEscreveArquivoFSI()
{
	//realizar o tratamento de erro caso nao ainda nao foi criado este arquivo pelo botao make da aba principal
	QDir WorkPath = ui->lineEdit_WorkingDir->text();
	QString inputFilePath = WorkPath.absolutePath()+"/SOLVER/FSI.DAT";
	QFile inputFile(inputFilePath);
	
	if( !inputFile.exists() || ui->lineEdit_jobName->text().isEmpty())
	{
		QMessageBox::critical(this, "Error", "The Jobname does not exist or a folder structure is empty. Please set data in file management tab and click on the make button.");
		return;		
	}
	else
	{

		//realizando a chamada nome metodo da classe IO para escrever o arquivo fsi.DAT
		io::Escreve_FSIFile(ui->lineEdit_jobName->text(), QDir(ui->lineEdit_WorkingDir->text()+"/SOLVER"), form, ui);
	}
}



//================================================================================================================
// Metodo responsavel por realizar a escrita do arquivo jobname.SETUP - 
//================================================================================================================
void runEdgeCFD::slotEscreveArquivoSetup()
{
	//realizar o tratamento de erro caso nao ainda nao foi criado este arquivo pelo botao make da aba principal
	QDir WorkPath = ui->lineEdit_WorkingDir->text();
	QString inputFilePath = WorkPath.absolutePath()+"/SETUP/"+ ui->lineEdit_jobName->text() +".SETUP";
	QFile inputFile(inputFilePath);
	
	if( !inputFile.exists() || ui->lineEdit_jobName->text().isEmpty())
	{
		QMessageBox::critical(this, "Error", "The Jobname does not exist or a folder structure is empty. Please set data in file management tab and click on the make button.");
		return;		
	}
	else
	{

		//realizando a chamada nome metodo da classe IO para escrever o arquivo jobname.setup
		io::Escreve_SETUPFile(ui->lineEdit_jobName->text(), QDir(ui->lineEdit_WorkingDir->text()+"/SETUP"), form, ui);
	}
}



//================================================================================================================
// Metodo responsavel pelo fechamento completo do aplicativo
//================================================================================================================
void runEdgeCFD::slotExit(){

	qApp->exit(0);
	exit(0);

}

//================================================================================================================
// Metodo responsavel pelo abertura de um arquivo de dados - MENU PRINCIPAL
//================================================================================================================
void runEdgeCFD::slotOpen()
{


	//CHAMADA PARA O ARQUIVO DE PROJETO .ecfd
	QString filename = QFileDialog::getOpenFileName( 
        this, 
        tr("Open Document"), 
        QDir::currentPath(), 
        tr("Documents (*.ecfd)") );


	QFile f(filename);
	cin.clear();
	
	if (f.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		
		QTextStream in(&f);
		QString line;
		
		//*********** LEITURA DO CABECALHO ***************
		line = in.readLine(256);//1
		line = in.readLine(256);//2
		line = in.readLine(256);//3
		line = in.readLine(256);//4
		

		//######################
		//# ABA FILE MANAGEMENT
		//######################

		line = in.readLine(256);//5
		line = in.readLine(256);//6
		line = in.readLine(256);//7
		line = in.readLine(256);//8
		line = in.readLine(256);//9

		stringstream stream;
		stream << (line.toAscii().constData());

		//atribuindo o WorkDir
		stream >> workingDir;
		ui->lineEdit_WorkingDir->setText(QString::fromStdString(this->workingDir));
		directory.setPath(QString::fromAscii(this->workingDir.c_str()));

		line = in.readLine(256);//10
		line = in.readLine(256);//11
		stream.clear();
		stream << (line.toAscii().constData());

		//atribuindo o jobname
		stream >> this->jobName;
		ui->lineEdit_jobName->setText(QString::fromStdString(this->jobName));

		line = in.readLine(256);//12
		line = in.readLine(256);//13
		stream.clear();
		stream << (line.toAscii().constData());

		QString verificaGeo;
		verificaGeo.append(this->workingDir.c_str());
		verificaGeo.append("/Ansys/") ;
		verificaGeo.append(this->jobName.c_str());
		verificaGeo.append(".geo");

		this->pathCase.append(this->workingDir.c_str());
		this->pathCase.append("/Ansys/") ;
		this->pathCase.append(this->jobName.c_str());
		this->pathCase.append(".case");

		if(!QFile::exists(verificaGeo))
		{
			QMessageBox::critical(this, "Error Read File", "Geometry file not found!");
			ui->lineEdit_WorkingDir->setText("");
			directory.setPath("");
			this->workingDir.clear();
			ui->lineEdit_jobName->setText("");
			this->jobName.clear();
			return;
		}
		else if (!QFile::exists(this->pathCase.c_str()))
		{
			FILE *file;
			file = fopen(this->pathCase.c_str(), "w");
			fprintf(file,"FORMAT\n");
			fprintf(file,"type: ensight\n");
			fprintf(file,"GEOMETRY\n");
			fprintf(file,"model: ");fprintf(file,this->jobName.c_str());fprintf(file,".geo");
		}

		this->loadMesh();

		//atribuindo o pathDB
		stream >> this->pathDb;
		ui->lineEdit_dbFile->setText(QString::fromStdString(this->pathDb));
		dbFile.setFileName(QString::fromAscii(this->pathDb.c_str()));

		//######################
		//# ABA SETUP
		//######################
		
		QString description;
		int totCContorno;
		int idCondContorno;
		string condContorno;
		float valueCContorno;

		line = in.readLine(256);//14
		line = in.readLine(256);//15
		line = in.readLine(256);//16
		line = in.readLine(256);//17
		line = in.readLine(256);//18
		
		//atribuindo a descricao da aba setup
		description = line.toAscii().constData();
		ui->lineEdit_descriptionSetup->setText(description);


		line = in.readLine(256);//19
		
		//atribuindo o numero total de Condicoes de contorno
		totCContorno = line.toInt();

		//verificando se o usuario criou uma lista de Condicoes de contorno e apagando
		int totCC= form.size();
		if(form.size() >= 0)
		{
			for(int i=0;i<totCC;i++)
				slotDeleteSetup();
		}

		//realizando a leitura de cada atributo para a condicao de contorno
		for (int i=1;i<totCContorno+1;i++)
		{

			line = in.readLine(256);
			stream.clear();
			stream<<(line.toAscii().constData());

			stream >> idCondContorno;
			stream >> condContorno;
			stream >> valueCContorno;

			slotNewSetup();

			form[i].componenteDOF->setCurrentIndex(idCondContorno);
			form[i].labelDOF->setCurrentIndex(RetornaIdCondContorno(condContorno));
			form[i].valorDOF->setValue(valueCContorno);
		}

		//######################
		//# ABA PRE
		//######################

		//#JOIN
		//#NP(INT>0) #BLK(INT) #RED(BOOL) #ORD(BOOL) #RCM(BOOL) #KEQ(BOOL) #FMT(BOOL) #ANS(BOOL) #PMV(BOOL) #LDE(BOOL)
		int NP, BLK, RED, ORD, RCM, KEQ, FMT, ANS, PMV, LDE;

		line = in.readLine(256);
		line = in.readLine(256);
		line = in.readLine(256);
		line = in.readLine(256);
		stream.clear();
		stream<<(line.toAscii().constData());

		//realizando a leitura de cada atributo aba pre
			stream >> NP;
			stream >> BLK;
			stream >> RED;
			stream >> ORD;
			stream >> RCM; 
			stream >> KEQ; 
			stream >> FMT;
			stream >> ANS;
			stream >> PMV; 
			stream >> LDE;
			
			//verificando consistencia de dados nos itens da aba PRE
			if(NP <= 0)
			{
				ui->tabWidget_View->setCurrentIndex(2); //indo para aba onde ocorreu um erro
				QMessageBox::critical(this, "Error Read File", "NP File error (PRE TAB)");
				return;
			}else if(RED > 1 || ORD > 1 || RCM > 1 || KEQ > 1 || FMT > 1 || ANS > 1 || PMV > 1 || LDE > 1)
			{
				ui->tabWidget_View->setCurrentIndex(2); //indo para aba onde ocorreu um erro
				QMessageBox::critical(this, "Error Read File", "RED, ORD, RCM, KEQ, FMT, ANS, PMV, LDE (PRE TAB)");
				return;
			}
			else{
			
				//atribuindo os valores a aba pre
				ui->spinBox_NP->setValue(NP);
				ui->spinBox_RED->setValue(RED);
				ui->spinBox_ORD->setValue(ORD);
				ui->spinBox_RCM->setValue(RCM);
				ui->spinBox_KEQ->setValue(KEQ);
				ui->spinBox_FMT->setValue(FMT);
				ui->spinBox_ANS->setValue(ANS);
				ui->spinBox_PMV->setValue(PMV);
				ui->spinBox_LDE->setValue(LDE);
			}

			//######################
			//# ABA INPUT
			//######################

			 int item1, item2, item3;
			 float item4, item5;

			//#ITEM1(INT) #ITEM2(INT) #ITEM3(INT)
			//#ITEM4(FLOAT) #ITEM5(FLOAT)

			line = in.readLine(256);
			line = in.readLine(256);
			line = in.readLine(256);
			line = in.readLine(256);
			stream.clear();
			stream<<(line.toAscii().constData());

			//realizando a leitura de cada atributo aba input

			stream >> item1;
			stream >> item2;
			stream >> item3;

			line = in.readLine(256);
			stream.clear();
			stream<<(line.toAscii().constData());

			stream >> item4;
			stream >> item5;

			//atribuindo os valores a aba input
			ui->spinBox_input1->setValue(item1);
			ui->spinBox_input2->setValue(item2);
			ui->spinBox_input3->setValue(item3);

			ui->doubleSpinBox_input1->setValue(item4);
			ui->doubleSpinBox_input2->setValue(item5);


			//######################
			//# ABA FSI
			//######################

			string FSI;
			float FSI_ALE1, FSI_ALE2;
			float MASS_FSI;
			float CGx, CGy, CGz;
			float CGRx, CGRy, CGRz;
			string x11, x12, x13, x22, x23, x33;
			float Ux, Uy, Uz, ROTx, ROTy, ROTz;
			float vx, vy, vz, Wx, Wy, Wz;
			int nptf_1;
			float nptf_2, nptf_3, nptf_4, nptf_5, nptf_6, nptf_7;

			line = in.readLine(256);
			line = in.readLine(256);
			line = in.readLine(256);
			line = in.readLine(256);
			line = in.readLine(256);
			stream.clear();
			stream<<(line.toAscii().constData());

			//"#SOLVEFSI (BOOL)" //TRUE OR FALSE INDEX
			stream >> FSI;
			(FSI.compare("TRUE") == 0 ? ui->comboBox_FSI->setCurrentIndex(0) : ui->comboBox_FSI->setCurrentIndex(1));

			//#START_ALE1(FLOAT) #START_ALE2(FLOAT)"
			line = in.readLine(256);
			line = in.readLine(256);
			stream.clear();
			stream<<(line.toAscii().constData());

			stream >> FSI_ALE1;
			stream >> FSI_ALE2;

			//#MASSFSI(FLOAT)
			line = in.readLine(256);
			line = in.readLine(256);
			stream.clear();
			stream<<(line.toAscii().constData());

			stream >> MASS_FSI;
			
			//#CGX(FLOAT) #CGY(FLOAT) #CGZ(FLOAT)
			//				0.250     0.100     0.125
			
			line = in.readLine(256);
			line = in.readLine(256);
			stream.clear();
			stream<<(line.toAscii().constData());

			stream >> CGx;
			stream >> CGy;
			stream >> CGz;

			//#CRX(FLOAT) #CRY(FLOAT) #CRZ(FLOAT)
			//				0.250     0.100     0.125
			
			line = in.readLine(256);
			line = in.readLine(256);
			stream.clear();
			stream<<(line.toAscii().constData());

			stream >> CGRx;
			stream >> CGRy;
			stream >> CGRz;

			//#TensorOfInertia
			//				7.000     0.000     0.000         
			//				7.000     0.000         
			//				6.000


			line = in.readLine(256);
			line = in.readLine(256);
			stream.clear();
			stream<<(line.toAscii().constData());

			stream >> x11;
			stream >> x12;
			stream >> x13;

			line = in.readLine(256);
			stream.clear();
			stream<<(line.toAscii().constData());

			stream >> x22;
			stream >> x23;
			
			line = in.readLine(256);
			stream.clear();
			stream<<(line.toAscii().constData());

			stream >> x33;


			//#nglBody
			//				1         1         0         1         1         1
			
			line = in.readLine(256);
			line = in.readLine(256);
			stream.clear();
			stream<<(line.toAscii().constData());

			stream >> Ux;
			stream >> Uy;
			stream >> Uz;
			stream >> ROTx;
			stream >> ROTy;
			stream >> ROTz;
			
			//#Velocity vx vy vz Wx Wy Wz
			//	0.0         0.0         0.0         0.0         0.0         1
			
			line = in.readLine(256);
			line = in.readLine(256);
			stream.clear();
			stream<<(line.toAscii().constData());

			stream >> vx;
			stream >> vy;
			stream >> vz;
			stream >> Wx;
			stream >> Wy;
			stream >> Wz;

			//#NPTF
			//				0				 =	nptf_1
			//				0.000      0.000 =  nptf_2 - nptf_5   
			//				10.000     0.000 =  nptf_3 - nptf_6     
			//				15.000     2.000 =	nptf_4 - nptf_7

			line = in.readLine(256);
			line = in.readLine(256);
			stream.clear();
			stream<<(line.toAscii().constData());

			stream >> nptf_1;

			line = in.readLine(256);
			stream.clear();
			stream<<(line.toAscii().constData());

			stream >> nptf_2;
			stream >> nptf_5;
			
			line = in.readLine(256);
			stream.clear();
			stream<<(line.toAscii().constData());

			stream >> nptf_3;
			stream >> nptf_6;
			
			line = in.readLine(256);
			stream.clear();
			stream<<(line.toAscii().constData());

			stream >> nptf_4;
			stream >> nptf_7;
			
			//atribuindo os dados na aba FSI
			
			//#START_ALE1(FLOAT) #START_ALE2(FLOAT)
			ui->doubleSpinBox_FSI_ALE1->setValue(FSI_ALE1);
			ui->doubleSpinBox_FSI_ALE1->setValue(FSI_ALE2);

			//#MASSFSI(FLOAT)
			ui->doubleSpinBox_MASSFSI->setValue(MASS_FSI);

			//#CGX(FLOAT) #CGY(FLOAT) #CGZ(FLOAT)
			ui->doubleSpinBox_MassCG1->setValue(CGx);
			ui->doubleSpinBox_MassCG2->setValue(CGy);
			ui->doubleSpinBox_MassCG3->setValue(CGz);

			//#CRX(FLOAT) #CRY(FLOAT) #CRZ(FLOAT)
			ui->doubleSpinBox_RotationCG1->setValue(CGRx);
			ui->doubleSpinBox_RotationCG2->setValue(CGRy);
			ui->doubleSpinBox_RotationCG3->setValue(CGRz);

			//#TensorOfInertia
			ui->lineEdit_InertiaX11->setText(x11.c_str());
			ui->lineEdit_InertiaX12->setText(x12.c_str());
			ui->lineEdit_InertiaX13->setText(x13.c_str());
			ui->lineEdit_InertiaX22->setText(x22.c_str());
			ui->lineEdit_InertiaX23->setText(x23.c_str());
			ui->lineEdit_InertiaX33->setText(x33.c_str());

			//#nglBody
			ui->spinBox_Ux->setValue(Ux);
			ui->spinBox_Uy->setValue(Uy);
			ui->spinBox_Uz->setValue(Uz);
			ui->spinBox_ROTx->setValue(ROTx);
			ui->spinBox_ROTy->setValue(ROTy);
			ui->spinBox_ROTz->setValue(ROTz);

			//#Velocity vx vy vz Wx Wy Wz
			ui->doubleSpinBox_VInitial_vx->setValue(vx);
			ui->doubleSpinBox_VInitial_vy->setValue(vy);
			ui->doubleSpinBox_VInitial_vz->setValue(vz);
			ui->doubleSpinBox_VInitial_Wx->setValue(Wx);
			ui->doubleSpinBox_VInitial_Wy->setValue(Wy);
			ui->doubleSpinBox_VInitial_Wz->setValue(Wz);

			//#NPTF
			ui->spinBox_nptf->setValue(nptf_1);
			ui->doubleSpinBox_nptf11->setValue(nptf_2);
			ui->doubleSpinBox_nptf12->setValue(nptf_3);
			ui->doubleSpinBox_nptf21->setValue(nptf_4);
			ui->doubleSpinBox_nptf22->setValue(nptf_5);
			ui->doubleSpinBox_nptf31->setValue(nptf_6);
			ui->doubleSpinBox_nptf32->setValue(nptf_7);
			

			//######################
			//# ABA MATERIAL
			//######################

			//#totMateriais
			//ID(int)	DENS(float)	VISC(float)	PAR3(float)	PAR4(float)	KXX(float)	KYY(float)	KZZ(float)	SPH(float)	NAME(string)

			int  totMaterial, idMat;
			double dens, visc, par3,	par4, kxx,	kyy, kzz, sph;
			string nameMaterial;

			line = in.readLine(256);
			line = in.readLine(256);
			line = in.readLine(256);
			line = in.readLine(256);
			stream.clear();

			//atribuindo o numero total de materiais
			totMaterial = line.toInt();
			
			//verificando se o usuario criou uma lista de materiais e realizar a delecao
			int totMaterialAtual= formMaterial.size();
			if(formMaterial.size() >= 0)
			{
				for(int i=0;i<totMaterialAtual;i++)
					slotDeleteMaterial();
			}

			//realizando a leitura de cada atributo para a condicao de contorno
			for (int i=1;i<=totMaterial;i++)
			{
			
				line = in.readLine(256);
				stream.clear();
				stream<<(line.toAscii().constData());
			
				stream >> idMat;
				stream >> dens;
				stream >> visc;
				stream >> par3;
				stream >> par4;
				stream >> kxx;
				stream >> kyy;
				stream >> kzz;
				stream >> sph;
				stream >> nameMaterial;
				
				//realizando a chamada para a criacao de novos materiais
				slotNewMaterial();
			
				//atribuindo os valores ao material lido do arquivo de dados
				formMaterial[i].id->setValue(idMat);
				formMaterial[i].dens->setValue(dens);
				formMaterial[i].visc->setValue(visc);
				formMaterial[i].par3->setValue(par3);
				formMaterial[i].par4->setValue(par4);
				formMaterial[i].kxx->setValue(kxx);
				formMaterial[i].kyy->setValue(kyy);
				formMaterial[i].kzz->setValue(kzz);
				formMaterial[i].sph->setValue(sph);
				formMaterial[i].name->setText(nameMaterial.c_str());
			}




			//######################
	}
	//caso ocorra um erro na leitura do arquivo de dados
	else
	{}


}


//================================================================================================================
// Metodo responsavel por salvar de um arquivo de dados - MENU PRINCIPAL
//================================================================================================================
void runEdgeCFD::slotSave(){


	//CHAMANDO A CAIXA DE DIALOGO PARA ESCOLHER O NOME DO PROJETO A SER SALVO
	QString filename = QFileDialog::getSaveFileName( 
        this, 
        tr("Save Document"), 
        QDir::currentPath(), 
        tr("Documents (*.ecfd)") );

	//SE O NOME DO ARQUIVO FOI DIGITADO ENTAO REALIZA O PROCESSO DE SALVAR
	if( !filename.isNull() )
	{
		//qDebug( filename.toAscii() );
		SalvarDadosProjeto(filename);
	}
	else
	{
		return;
	}

}

void runEdgeCFD::SalvarDadosProjeto(QString prjFileName)
{
	//recebendo o nome do arquivo de dados
	QFile f( prjFileName );
	QTextStream out(&f);
    
	//get current date
	QDate date = QDate::currentDate();
	QString dateString = date.toString();
	//get current time
	QTime time = QTime::currentTime();
	QString timeString = time.toString();
	// get current date and time
	QDateTime datetime = QDateTime::currentDateTime();
	QString dateTimeString = datetime.toString();
	
	//get username
	QString  user = getenv("USERNAME");

	//VERIFICANDO SE TODAS AS INFORMACOES ESTAO OK

	// ######################
	// # ABA FILE MANAGEMENT
	// ######################
	if( ui->lineEdit_WorkingDir->text().isEmpty())
	{
		QMessageBox::critical(this, "Error", "Working Directory is empty");
		return;		
	}else if(ui->lineEdit_jobName->text().isEmpty())
	{
		QMessageBox::critical(this, "Error", "Job Name is empty");
		return;
	}else if(ui->lineEdit_dbFile->text().isEmpty())
	{
		QMessageBox::critical(this, "Error", "Db File is empty");
		return;
	} 	

	//######################
	//# ABA PRE
	//######################
	if( ui->lineEdit_descriptionSetup->text().isEmpty())
	{
		QMessageBox::critical(this, "Error", "Description is empty");
		return;		
	}


	//SALVANDO O ARQUIVO DE DADOS FORMATO .ecfd
	f.open( QIODevice::WriteOnly );
	
	// store data in f
	//Criando o cabecalho do arquivo de dados
	out << "#ARQUIVO DE DADOS DO EDGECFD PLUGIN" << endl;
	out << "#"+dateTimeString << endl;
	out << "#USER: "+user << endl;
	out << endl;

	out << "######################" << endl;
	out << "# ABA FILE MANAGEMENT"  <<  endl;
	out << "######################" << endl;
	out << "#WORKING DIRECTORY" << endl;
	out << ui->lineEdit_WorkingDir->text() << endl;
	
	out << "#JOB NAME" << endl;
	out << ui->lineEdit_jobName->text() << endl;

	out << "#PATH DB FILE" << endl;
	out << ui->lineEdit_dbFile->text() << endl;

	out << "######################" << endl;
	out << "# ABA SETUP" << endl;
	out << "######################" << endl;
	out << "#DESCRIPTION" << endl; 
	out << ui->lineEdit_descriptionSetup->text() << endl;
	
	//#NUMERO DE DOFS(INT)
	//#COMPONENTE CC(INT) #LABEL(INT) #VALOR (FLOAT)
	out << form.size() << endl;
	
	for (int i=0; i<form.size();i++)
	{
		out << form[i].componenteDOF->currentIndex()  ;
		out.setFieldWidth(10);
		out << RetornaCondContorno(form[i].labelDOF->currentIndex())  ;
		out.setFieldWidth(10);
		out.setRealNumberPrecision(5);
		out << QString::number(form[i].valorDOF->value(), 'f', 3) ;
		out << endl;
		out.reset();
	}

	out << "######################" << endl;
	out << "# ABA PRE" << endl;
	out << "######################" << endl;
	//#JOIN
	//#NP(INT>0) #BLK(INT) #RED(BOOL) #ORD(BOOL) #RCM(BOOL) #KEQ(BOOL) #FMT(BOOL) #ANS(BOOL) #PMV(BOOL) #LDE(BOOL)
	
	out << QString::number(ui->spinBox_NP->value() );
	out.setFieldWidth(10);						   
	out << QString::number(ui->spinBox_BLK->value());
	out << QString::number(ui->spinBox_RED->value());
	out << QString::number(ui->spinBox_ORD->value());
	out << QString::number(ui->spinBox_RCM->value());
	out << QString::number(ui->spinBox_KEQ->value());
	out << QString::number(ui->spinBox_FMT->value());
	out << QString::number(ui->spinBox_ANS->value());
	out << QString::number(ui->spinBox_PMV->value());
	out << QString::number(ui->spinBox_LDE->value());
	out.reset();
	out << endl;

	out << "######################" << endl;
	out << "# ABA INPUT" << endl;
	out << "######################" << endl;
	//#ITEM1(INT) #ITEM2(INT) #ITEM3(INT)
	//#ITEM4(FLOAT) #ITEM5(FLOAT)
	
	out << ui->spinBox_input1->value();
	out.setFieldWidth(10);
	out << ui->spinBox_input2->value();
	out << ui->spinBox_input3->value();
	out << endl;
	out.reset();
	out << ui->doubleSpinBox_input1->value();
	out.setFieldWidth(10);
	out << ui->doubleSpinBox_input2->value();
	out << endl;
	out.reset();

	out << "######################" << endl;
	out << "# ABA FSI" << endl;
	out << "######################" << endl;
	out << "#SOLVEFSI (BOOL)" << endl; //TRUE OR FALSE INDEX
	out << (ui->comboBox_FSI->currentIndex() == 0 ? "TRUE":"FALSE") << endl;

	out << "#START_ALE1(FLOAT) #START_ALE2(FLOAT)" << endl; 
	out << QString::number(ui->doubleSpinBox_FSI_ALE1->value(), 'f', 3);
	out.setFieldWidth(10);
	out << QString::number(ui->doubleSpinBox_FSI_ALE2->value(), 'f', 3); 
	out.reset();
	out << endl;

	out << "#MASSFSI(FLOAT)" << endl;
	out << QString::number(ui->doubleSpinBox_MASSFSI->value(), 'f', 3) << endl;
	
	out << "#CGX(FLOAT) #CGY(FLOAT) #CGZ(FLOAT)" << endl;
	out.setRealNumberPrecision(5);
	out << QString::number(ui->doubleSpinBox_MassCG1->value(), 'f', 3);
	out.setFieldWidth(10);
	out << QString::number(ui->doubleSpinBox_MassCG2->value(), 'f', 3);
	out << QString::number(ui->doubleSpinBox_MassCG3->value(), 'f', 3);
	out.reset();
	out >> endl;

	out << "#CRX(FLOAT) #CRY(FLOAT) #CRZ(FLOAT)" << endl;
	out.setRealNumberPrecision(5);
	out << QString::number(ui->doubleSpinBox_RotationCG1->value(), 'f', 3);
	out.setFieldWidth(10);
	out << QString::number(ui->doubleSpinBox_RotationCG2->value(), 'f', 3);
	out << QString::number(ui->doubleSpinBox_RotationCG3->value(), 'f', 3);
	out.reset();
	out >> endl;

	out << "#TensorOfInertia" << endl;
	//#x11(float) #x12(float) #x13(float)
	//#x22(float) #x23(float)
	//#x33(float)
	out <<  ui->lineEdit_InertiaX11->text().toAscii();
	out.setFieldWidth(10);							 
	out << ui->lineEdit_InertiaX12->text().toAscii() ;
	out << ui->lineEdit_InertiaX13->text().toAscii() ;
	out << endl;									 
	out.setFieldWidth(15);							 
	out << ui->lineEdit_InertiaX22->text().toAscii() ;
	out.setFieldWidth(10);							 
	out << ui->lineEdit_InertiaX23->text().toAscii() ;
	out << endl;									 
	out.setFieldWidth(25);
	out << ui->lineEdit_InertiaX33->text().toAscii();
	out.reset();
	out << endl;
	
	
	out << "#nglBody" << endl;
	//#Ux(int) #Uy(int) #Uz(int) #Rx(int) #Ry(int) #Rz(int)
	out <<  QString::number(ui->spinBox_Ux->value(), 10  );
	out.setFieldWidth(10);							
	out <<  QString::number(ui->spinBox_Uy->value()  );
	out <<  QString::number(ui->spinBox_Uz->value()  );
	out <<  QString::number(ui->spinBox_ROTx->value());
	out <<  QString::number(ui->spinBox_ROTy->value());
	out <<  QString::number(ui->spinBox_ROTz->value());
	out.reset();
	out << endl;
	
	out << "#Velocity vx vy vz Wx Wy Wz" << endl;
	//#vx(double) #vy(double) #vz(double) #Wx(double) #Wy(double) #Wz(double)
	out <<  QString::number(ui->doubleSpinBox_VInitial_vx->value(),'f',3);
	out.setFieldWidth(10);
	out <<  QString::number(ui->doubleSpinBox_VInitial_vy->value(),'f',3);
	out <<  QString::number(ui->doubleSpinBox_VInitial_vz->value(),'f',3);
	out <<  QString::number(ui->doubleSpinBox_VInitial_Wx->value(),'f',3);
	out <<  QString::number(ui->doubleSpinBox_VInitial_Wy->value(),'f',3);
	out <<  QString::number(ui->doubleSpinBox_VInitial_Wz->value(),'f',3);
	out.reset();
	out << endl;
	
	out << "#NPTF" << endl;
	//#nptf11(int)
	//#nptf21(float) #nptf22(float)
	//#nptf31(float) #nptf32(float)
	//#nptf41(float) #nptf42(float)
	out <<  QString::number(ui->spinBox_nptf->value());
	out << endl;
	out <<  QString::number(ui->doubleSpinBox_nptf11->value(), 'f', 3);
	out.setFieldWidth(10);
	out <<  QString::number(ui->doubleSpinBox_nptf12->value(), 'f', 3);
	out << endl;
	out.reset();
	out <<  QString::number(ui->doubleSpinBox_nptf21->value(), 'f', 3);
	out.setFieldWidth(10);
	out <<  QString::number(ui->doubleSpinBox_nptf22->value(), 'f', 3);
	out << endl;
	out.reset();
	out <<  QString::number(ui->doubleSpinBox_nptf31->value(), 'f', 3);
	out.setFieldWidth(10);
	out <<  QString::number(ui->doubleSpinBox_nptf32->value(), 'f', 3);
	out.reset();
	out << endl;


	out << "######################" << endl;
	out << "# ABA MATERIAL"			<< endl;
	out << "######################" << endl;
	//#totMateriais
	//ID(int)	DENS(float)	VISC(float)	PAR3(float)	PAR4(float)	KXX(float)	KYY(float)	KZZ(float)	SPH(float)	NAME(string)
	out << formMaterial.size() <<endl;
	

	for (int i=1; i<=formMaterial.size();i++)
	{
		out.setFieldAlignment(QTextStream::AlignRight);
		out.setFieldWidth(2);
		out << formMaterial[i].id->value();
	   	
		out.setFieldWidth(10);
		out << QString::number(formMaterial[i].dens->value(), 'f', 3);
		out << QString::number(formMaterial[i].visc->value(), 'f', 3);
		out << QString::number(formMaterial[i].par3->value(), 'f', 3);
		out << QString::number(formMaterial[i].par4->value(), 'f', 3);
		out << QString::number(formMaterial[i].kxx->value(), 'f', 3);
		out << QString::number(formMaterial[i].kyy->value(), 'f', 3);
		out << QString::number(formMaterial[i].kzz->value(), 'f', 3);
		out << QString::number(formMaterial[i].sph->value(), 'f', 3);
		
		out << formMaterial[i].name->text();
		out.reset();
		out << endl;
	}


	//fechando o arquivo
	f.close();

}

//funcao auxiliar somente para retornar o nome definido na caixa de combo da aba setup
QString runEdgeCFD::RetornaCondContorno(int id)
{
	QString cc;
	switch(id)
	{
	case 0:
		cc = "VX";
		break;
	case 1:
		cc = "VY";
		break;
	case 2:
		cc = "VZ";
		break;
	case 3 :
		cc = "ALE-X";
		break;
	case 4 :
		cc = "ALE-Y";
		break;
	case 5 :
		cc = "ALE-Z";
		break;
	case 6 :
		cc = "P ";
		break;
	case 7 :
		cc = "HX";
		break;
	case 8 :
		cc = "HY"; 
		break;
	case 9 :
		cc = "HZ";
		break;
	case 10:
		cc = "HW";
		break;
	}

	return cc;

}

//metodo para retornar o id da caixa de combo de selecao da condicao de contorno
int runEdgeCFD::RetornaIdCondContorno(string cc)
{
	int value;

	if(cc.compare("VX") == 0)
		value = 0;
	else if(cc.compare("VY")== 0)
		value = 1;
	else if(cc.compare("VZ")== 0)
		value = 2;
	else if(cc.compare("ALE-X") == 0 || cc.compare("UX") == 0 )
		value = 3;
	else if(cc.compare("ALE-Y")== 0 || cc.compare("UY") == 0 )
		value = 4;
	else if(cc.compare("ALE-Z")== 0 || cc.compare("UZ") == 0 )
		value = 5 ;
	else if(cc.compare("P")== 0)
		value = 6;
	else if(cc.compare("HX")== 0)
		value = 7;
	else if(cc.compare("HY")== 0)
		value = 8 ; 
	else if(cc.compare("HZ")== 0)
		value = 9 ;
	else if(cc.compare("HW")== 0)
		value = 10;


	return value;

}


//================================================================================================================
// Metodo responsavel por copiar as pastas do edgecfd para o workdir
//================================================================================================================

void runEdgeCFD::copyFolder(const QString& sourceFolder,const QString& destFolder)
{
	QQueue< QPair<QString, QString> > queue;

	queue.enqueue(qMakePair(sourceFolder, destFolder));

	while (!queue.isEmpty())
	{
		QPair<QString, QString> pair = queue.dequeue();
		QDir sourceDir(pair.first);
		QDir destDir(pair.second);

		if(!sourceDir.exists())
			continue;

		if(!destDir.exists())
			destDir.mkpath(pair.second);

		QStringList files = sourceDir.entryList(QDir::Files);
		for(int i = 0; i < files.count(); i++)
		{
			QString srcName = pair.first + "/" + files.at(i);
			QString destName = pair.second + "/" + files.at(i);
			QFile::copy(srcName, destName);
		}

		QStringList dirs = sourceDir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot);
		for(int i = 0; i < dirs.count(); i++)
		{
			QString srcName = pair.first + "/" + dirs.at(i);
			QString destName = pair.second + "/" + dirs.at(i);
			queue.enqueue(qMakePair(srcName, destName));
		}
	}
}


//================================================================================================================
// Metodo responsavel por processar os dados do formulario e salvar os dados nas pastas corretas
//================================================================================================================

void runEdgeCFD::ProcessarFormulario()
{
	//./FORMULÁRIO.TXT
	//DESCRIÇÃO: DADOS DE CONTROLE DO USUÁRIO PARA GERAR OS SEGUINTES ARQUIVOS:

	//../SETUP/FILENAME.SETUP
	//../PREPROCESSOR/FILENAME.PRE
	//../SOLVER/INPUT.DAT
	//../SOLVER/FSI.DAT


	//===========================================
	// MODIFICANDO O ARQUIVO DE MACRO PARA ADEQUAR 
	// O NOME DO ARQUIVO DB A MACRO
	//============================================

	io::Escreve_OPENMAC(ui->lineEdit_dbFile->text(), QDir(ui->lineEdit_WorkingDir->text()+"/MACROS"));

	//============================================


	//========================================
	////ESCREVENDO O CONTEUDO DA ABA SETUP
	//========================================

	// CASO O USUARIO NAO ENTRE COM NENHUM VALOR NA ABA SETUP UMA MENSAGEM DE AVISO DEVE OCORRER

	io::Escreve_SETUPFile(ui->lineEdit_jobName->text(), QDir(ui->lineEdit_WorkingDir->text()+"/SETUP"), form, ui);

	//===================================
	//ESCREVENDO O CONTEUDO DA ABA PRE
	//===================================

	io::Escreve_PREFile(ui->lineEdit_jobName->text(), QDir(ui->lineEdit_WorkingDir->text()+"/PREPROCESSOR"), form, ui);

	//=======================================
	////ESCREVENDO O CONTEUDO DA ABA INPUT
	//=======================================

	io::Escreve_INPUTFile(ui->lineEdit_jobName->text(), QDir(ui->lineEdit_WorkingDir->text()+"/SOLVER"), form, ui);

	//=====================================
	////ESCREVENDO O CONTEUDO DA ABA FSI
	//=====================================

	io::Escreve_FSIFile(ui->lineEdit_jobName->text(), QDir(ui->lineEdit_WorkingDir->text()+"/SOLVER"), form, ui);


	//=====================================
	////ESCREVENDO O CONTEUDO DA ABA MATERIAL
	//=====================================

	io::Escreve_MaterialFile(ui->lineEdit_jobName->text(), QDir(ui->lineEdit_WorkingDir->text()+"/SOLVER"), formMaterial, ui);
}

// Realiza a execucao da MACRO ANSYS e Chama os executaveis feitos em F90
void runEdgeCFD::ExecutaMacros()
{
	
	// teste para acham o path do ansys

	//QByteArray value2 = qgetenv("ANSYS130_DIR");
	//qDebug("myvariable=%s", value2.constData());
	
	QString VerAnsys11 = QString::fromLocal8Bit( qgetenv("ANSYS110_DIR").constData() );
	QString VerAnsys12 = QString::fromLocal8Bit( qgetenv("ANSYS120_DIR").constData() );
	QString VerAnsys13 = QString::fromLocal8Bit( qgetenv("ANSYS130_DIR").constData() );
	QString VerAnsys14 = QString::fromLocal8Bit( qgetenv("ANSYS140_DIR").constData() );

	QString VersaoAtual;

	if(!VerAnsys11.isEmpty())
		VersaoAtual = VerAnsys11+"\\bin\\winx64\\ansys110.exe";
	else if(!VerAnsys12.isEmpty())
		VersaoAtual = VerAnsys12+"\\bin\\winx64\\ansys120.exe";
	else if(!VerAnsys13.isEmpty())
		VersaoAtual = VerAnsys13+"\\bin\\winx64\\ansys130.exe" ;
	else if(!VerAnsys14.isEmpty())
		VersaoAtual = VerAnsys14+"\\bin\\winx64\\ansys140.exe" ;

	//*************************************************************************************


	/*======================================================================================
	EXECUCAO DA MACRO DO ANSYS
	========================================================================================

	./ANSYS
	DESCRIÇÃO: GERAÇÃO DA GEOMETRIA, da MALHA E COMPONENTES NODAIS DAS SUPERFÍCIES DE INTERESSE:
	INPUT:
	./FILENAME.DB
	../MACROS/SETUP_EDGECFD_REV-A.MAC

	OUTPUT:
	./FILENAME.IN
	./FILENAME.MSH
	./FILENAME.GEO
	========================================================================================*/

	QDir WorkPath = ui->lineEdit_WorkingDir->text();
	QProcess*   process = new QProcess();
	QString WorkFolder = WorkPath.absolutePath();
	//QString Ansys = "\"C:\\Program Files\\ANSYS Inc\\v130\\ansys\\bin\\winx64\\ansys130.exe \" ";
	QString Ansys = "\""+VersaoAtual+ "\"";
	QStringList parameters;

	parameters.append(" -dir "); 
	parameters.append("\""+ui->lineEdit_WorkingDir->text().toAscii()+"\\MACROS\" ");
	parameters.append("-b ");
	parameters.append("-i "); 
	parameters.append("\""+ui->lineEdit_WorkingDir->text().toAscii()+"\\MACROS\\OPEN.mac\" ");
	parameters.append(" -j "); 
	parameters.append(ui->lineEdit_jobName->text().toAscii());
	parameters.append(" -o ");
	parameters.append( "\""+ui->lineEdit_WorkingDir->text().toAscii()+"\\ANSYS\\OUTPUT.txt \" ");


	//CRIANDO UM ARQUIVO BAT PARA EXECUTAR A MACRO DO ANSYS

	QString filename = WorkFolder+"\\AnsysBatch.bat";
	QFile batchAnsysFile(filename);	

	if(!batchAnsysFile.open(QFile::WriteOnly | QFile::Text))
	{
		qDebug() << "Erro arquivo";
		return;
	}

	QTextStream out(&batchAnsysFile);
	out << "@echo off" << endl;
	out << Ansys 
		<< parameters.at(0).toAscii() 
		<< parameters.at(1).toAscii()
		<< parameters.at(2).toAscii()
		<< parameters.at(3).toAscii()
		<< parameters.at(4).toAscii()
		<< parameters.at(5).toAscii()
		<< parameters.at(6).toAscii()
		<< parameters.at(7).toAscii()
		<< parameters.at(8).toAscii();

	batchAnsysFile.flush();
	batchAnsysFile.close();

	//FIM DA CRIACAO DE UM ARQUIVO DE BAT PARA A EXECUCAO DA MACRO ANSYS

	if (process)
	{
		//EXECUTANDO O ARQUIVO BAT CRIADO USANDO O QPROCESS
		process->start(filename);
		process->waitForFinished();
		//APAGANDO O ARQUIVO BAT CRIADO PARA A EXECUCAO DO ANSYS
		batchAnsysFile.remove(filename);
		delete process;
	}

	//================================================================
	// FIM DA EXECUCAO DA MACRO DO ANSYS
	//================================================================

}



//EXECUCAO DO BOTAO RUN EDGECFD SETUP DA ABA SETUP
// REALIZA A CHAMADA DO EXECUTAVEL SETUP;
// ESTA EXECUCAO DEVERA SALVAR O ARQUIVO DE DADOS DA ABA SETUP CASO O USUARIO FACA QQ MODIFICACAO
void runEdgeCFD::slotRunEdgeCFDSetup()
{
	//DEFININDO O DIRETORIO DO ARQUIVO .SETUP
	QDir WorkPath = ui->lineEdit_WorkingDir->text();
	QString SetupFilePath = WorkPath.absolutePath()+"/SETUP/"+ui->lineEdit_jobName->text()+".SETUP";
	QFile setupFile(SetupFilePath);

	//verificando se o usuario criou um jobname
	if(ui->lineEdit_jobName->text().isEmpty())
	{
		QMessageBox::critical(this, "Error", "Jobname is empty");
		return;
	}
	else if(!setupFile.exists())
	{
		QMessageBox::critical(this, "Error", "Please run MAKE button in File Management tab ");
		return;
	}
	else
	{
		//METODO PARA SALVAR O ARQUIVO .SETUP
		//io::Escreve_SETUPFile(ui->lineEdit_jobName->text(), QDir(ui->lineEdit_WorkingDir->text()+"/SETUP"), form, ui);

		//METODO QUE CRIA UM ARQUIVO DE BATCH E CHAMA O EXECUTAVEL DO SETUP_EDGECFD
		ExecutaSetup();
	}
}	



//REALIZA A CHAMADA PARA O EXECUTAVEL DO ARQUIVO - SETUP_EDGECFD-REV-C.exe
// UTILIZA OS ARQUIVOS GERADOS PELA MACRO DO ANSYS E O .SETUP DA PASTA SETUP
void runEdgeCFD::ExecutaSetup()
{

	/*==========================================================================
	EXECUCAO DAS CONDICOES DE CONTORNO - ../EXECUTABLES/SETUP_EDGECFD.EXE
	DESCRIÇÃO: APLICA CONDIÇÕES DE CONTORNO DO MODELO
	==========================================================================

	./SETUP
	DESCRIÇÃO: APLICA CONDIÇÕES DE CONTORNO DO MODELO
	EXECTUTÁVEL:
	../EXECUTABLES/SETUP_EDGECFD.EXE

	INPUT:
	./FILENAME.SETUP
	../ANSYS/FILENAME.IN
	../ANSYS/FILENAME.MSH
	../ANSYS/FILENAME.GEO

	OUTPUT:
	../PREPROCESSOR/FILENAME.IN
	==========================================================================*/

	//criando o path inicial de trabalho
	QDir WorkPath = ui->lineEdit_WorkingDir->text();
	QString WorkFolder = WorkPath.absolutePath();

	//CRIANDO O ARQUIVO INPUT COM O NOME DO JOB PARA VIRAR ENTRADA NO EXECUTAVEL DO SETUP

	QString filenameInput = WorkFolder+"/EXECUTABLES/INPUT.txt";
	QFile batchSetupInputFile(filenameInput);
	
	if(!batchSetupInputFile.open(QFile::WriteOnly | QFile::Text))
	{
		qDebug() << "Erro arquivo";
		return;
	}

	QTextStream outInputFile(&batchSetupInputFile);
	outInputFile << ui->lineEdit_jobName->text().toAscii().constData() << endl;

	//fechando o arquivo de batch do setup	
	batchSetupInputFile.flush();
	batchSetupInputFile.close();

	//****************** FIM ARQUIVO INPUT ********************************

	//CRIANDO O ARQUIVO .BAT PARA FAZER A CHAMADA DO EXECUTAVEL SETUP

	QString filenameExecSetupBatch = WorkFolder+"/SETUP.bat";
	QString filenameSetupBatch = WorkFolder+"/SETUP_EDGECFD.bat";
	
	QFile batchSetupFile(filenameSetupBatch);
	QFile batchSetupEXECFile(filenameExecSetupBatch);
	
	// NOME DO EXECUTAVEL DO SETUP
	QString EXESetup = "SETUP_EDGECFD-REV-C.exe";

	
	//Tratando o nome do arquivo Input.txt
	QString str = batchSetupInputFile.fileName();
	QStringList parts = str.split("/");
	QString inputFile = parts.at(parts.size()-1);

	//===================================================================================

	//ESCREVENDO O BATCH QUE IRA CHAMAR OUTRO BATCH QUE CONTEM O EXECUTAVEL DO SETUP 
	if(!batchSetupEXECFile.open(QFile::WriteOnly | QFile::Text))
	{
		qDebug() << "Erro arquivo batch SETUP.bat";
		return;
	}

	QTextStream outBatchExecFile(&batchSetupEXECFile);
	outBatchExecFile << "@echo off" << endl;
	outBatchExecFile << "CLS " << endl;
	outBatchExecFile << "CD " << endl;
	outBatchExecFile << WorkFolder.at(0) << ":" <<endl;
	outBatchExecFile << "CD " << WorkFolder.toAscii() << "/EXECUTABLES" << endl;
	outBatchExecFile << "REM EXECUTANDO O ARQUIVO SETUP.bat" << endl;
	outBatchExecFile << "@echo on" << endl;
	outBatchExecFile << EXESetup.toAscii() + " < " + inputFile.toAscii() << endl;
	outBatchExecFile << "exit";

	//fechando o arquivo de batch do setup.bat	
	batchSetupEXECFile.flush();
	batchSetupEXECFile.close();
	
	//trocando atributo do arquivo batch
	
	//SetFileAttributesA((LPCWSTR)filenameExecSetupBatch.data(), FILE_ATTRIBUTE_HIDDEN);

	//====================================================================================
	//ESCREVENDO O BATCH QUE IRA CHAMAR OUTRO BATCH QUE CONTEM O EXECUTAVEL DO SETUP 
	if(!batchSetupFile.open(QFile::WriteOnly | QFile::Text))
	{
		qDebug() << "Erro arquivo";
		return;
	}

	QTextStream outBatchFile(&batchSetupFile);
	outBatchFile << "@echo off" << endl;
	outBatchFile << "CLS " << endl;
	outBatchFile << WorkFolder.at(0)  << ":" << endl; 
	outBatchFile << "CD " << WorkFolder.toAscii() << endl; //+"/EXECUTABLES" << endl;
	outBatchFile << "REM EXECUTANDO O ARQUIVO SETUP" << endl;
	outBatchFile << "@echo on" << endl;
	outBatchFile << "start \"Running Edge - SETUP - LAMCE 2013\" /I /HIGH SETUP.bat" << endl;//+ filenameExecSetupBatch.toAscii() << endl;
	//outBatchFile << "start cmd /c SETUP.bat" << endl;//+ filenameExecSetupBatch.toAscii() << endl;
	//outBatchFile << EXESetup.toAscii() + " < " + inputFile.toAscii() << endl;
	outBatchFile << "exit" ;

	//fechando o arquivo de batch do SETUP_EDGECFD.bat	
	batchSetupFile.flush();
	batchSetupFile.close();

	//trocando atributo do arquivo batch
	
	//SetFileAttributesA((LPCWSTR)filenameSetupBatch.data(), FILE_ATTRIBUTE_HIDDEN);

	//************* FIM DA CRIACAO DE UM ARQUIVO SETUP_EDGECFD.bat PARA A EXECUCAO setup.bat *************
	

	//=========================================================================
	
	//Criando o obejeto para executar este processo
	QProcess*   process_setup = new QProcess();
	
	if (process_setup)
	{
		
		//EXECUTANDO O ARQUIVO BAT CRIADO USANDO O QPROCESS
		process_setup->start(filenameSetupBatch);
		process_setup->waitForFinished(); 

		if(process_setup->waitForFinished(5000))
		{		

			//apagando o arquivo de batchs gerados para execucao do setup
			//batchSetupFile.remove();
			//batchSetupEXECFile.remove();

			//desalocando o processo 
			delete process_setup;
		}
	}

	//==========================================================================
	// FIM EXECUCAO DAS CONDICOES DE CONTORNO - ../EXECUTABLES/SETUP_EDGECFD.EXE
	//==========================================================================

}



//EXECUCAO DO BOTAO RUN EDGECFD SETUP DA ABA SETUP
// REALIZA A CHAMADA DO EXECUTAVEL SETUP;
// AO CLICAR NESTE BOTAO O USARIO DEVERA TAMBEM SALVAR O ARQUIVO DE DADOS .PRE
void runEdgeCFD::slotRunEdgeCFDPRE()
{
	//definido o diretorio atual e o caminho do arquivo pre
	QDir WorkPath = ui->lineEdit_WorkingDir->text();
	QString SetupFilePath = WorkPath.absolutePath()+"/PREPROCESSOR/"+ui->lineEdit_jobName->text()+".PRE";
	QFile setupFile(SetupFilePath);

	//verificando se o usuario criou um jobname
	if(ui->lineEdit_jobName->text().isEmpty())
	{
		QMessageBox::critical(this, "Error", "Jobname is empty");
		return;
	}
	else if(!setupFile.exists())
	{
		QMessageBox::critical(this, "Error", "Please run MAKE button in File Management tab ");
		return;
	}
	else
	{
		//CHAMANDO O METODO PARA SALVAR O ARQUIVO .PRE
		io::Escreve_PREFile(ui->lineEdit_jobName->text(), QDir(ui->lineEdit_WorkingDir->text()+"/PREPROCESSOR"), form, ui);
		// CHAMADA PARA O EXECUTAVEL DO PRE PROCESSADOR
		ExecutaPRE();
	}
}




//REALIZA A CHAMADA PARA O EXECUTAVEL DO ARQUIVO - EdgeCFDPre-dbg-REV-A.exe
// PRE PROPROCESSADOR DO EDGECFD
void runEdgeCFD::ExecutaPRE()
{

	/*==========================================================================
	EXECUCAO DO PRE-PROCESSAMENTO - ../EXECUTABLES/EdgeCFDPre-dbg.EXE
	DESCRIÇÃO: GERA PRE-PROCESSAMENTO PARA O EDGECFD
	==========================================================================

	./PREPROCESSOR
	DESCRIÇÃO: GERA PRE-PROCESSAMENTO PARA O EDGECFD
	EXECTUTÁVEL:
	../EXECUTABLES/EdgeCFDPre-dbg.EXE

	INPUT:
	./FILENAME.IN
	./FILENAME.PRE
	../ANSYS/FILENAME.MSH

	OUTPUT:
	../SOLVER/FILENAME_1.PART.IN
	../SOLVER/FILENAME_1.PART.MSH
	../SOLVER/FILENAME_1.PART.EDG
	../SOLVER/FILENAME_1.PART.MAT
	../SOLVER/FILENAME_1.PART.IC

	==========================================================================*/

	//criando o path inicial de trabalho
	QDir WorkPath = ui->lineEdit_WorkingDir->text();
	QString WorkFolder = WorkPath.absolutePath();
	
	//PRIMEIRO PASSO E REALIZAR A COPIA DO ARQUIVO JOBNAME.IN QUE ESTA NA PASTA ANSYS
	// PARA O DIRETORIO PREPROCESSOR 

	/********************************************************************************/
	/******************* NAO E MAIS NECESSARIO **************************************/
	/********************************************************************************/

	/*
	QString filenameInAnsys = WorkFolder+"\\ANSYS\\"+ui->lineEdit_jobName->text()+".in";
	QString filenameInPRE = WorkFolder+"\\PREPROCESSOR\\"+ui->lineEdit_jobName->text()+".in";
	
	QFile inFile(filenameInAnsys);

	//if(!WorkPath.exists(ui->lineEdit_jobName->text().toAscii()+".in"))
	if(inFile.exists())
	{

		inFile.remove(filenameInPRE);
		//copiando o arquivo da pasta ansys para a pasta preprocessador
		inFile.copy(filenameInAnsys,filenameInPRE);
	}
	else
	{
		//arquivo nao existe - ansys nao rodou
		QMessageBox::critical(this, "Error", "Please run make button .in file not exist ");
		return;
	}

	//****************************** FIM COPIA ARQUIVO IN ****************************
	*/

	//CRIANDO O ARQUIVO .BAT PARA FAZER A CHAMADA DO EXECUTAVEL PRE
	QString filenameInput = WorkFolder+"/EXECUTABLES/INPUT.txt";
	QString filenamePREBatch = WorkFolder+"/PRE_EDGECFD.bat";
	QString filenameExecPREBatch = WorkFolder+"/PRE.bat";

	//nome do executavel do PRE
	QString ExecPRE = "EdgeCFDPre-dbg-REV-A";

	//criando os arquivos batch
	QFile batchPREFile(filenamePREBatch);
	QFile batchExecPREFile(filenameExecPREBatch);


	
	// ESCREVENDO O ARQUIVO PRE_EDGECFD.bat
	if(!batchExecPREFile.open(QFile::WriteOnly | QFile::Text))
	{
		qDebug() << "Erro arquivo";
		return;
	}

	QTextStream outExecPREFile(&batchExecPREFile);
	outExecPREFile << "@echo off" << endl;
	outExecPREFile << "CLS " << endl;
	outExecPREFile << "CD " << endl;
	outExecPREFile << WorkFolder.at(0) << ":" << endl;
	outExecPREFile << "CD " << WorkFolder.toAscii() +"/EXECUTABLES" << endl;
	outExecPREFile << "REM EXECUTANDO O ARQUIVO PRE.bat" << endl;
	outExecPREFile << "@echo on" << endl;
	outExecPREFile << ExecPRE.toAscii() + " <" + filenameInput.toAscii() << endl;
	outExecPREFile << "exit" ;

	//fechando o arquivo de batch PRE_EDGECFD.bat	
	//batchExecPREFile.flush();
	//batchExecPREFile.close();


	//trocando atributo do arquivo batch
	
	//SetFileAttributesA((LPCWSTR)filenameExecPREBatch.data(), FILE_ATTRIBUTE_HIDDEN);
	

	//************* FIM DA CRIACAO DE UM ARQUIVO PRE.bat *************


	
	// ESCREVENDO O ARQUIVO PRE_EDGECFD.bat
	if(!batchPREFile.open(QFile::WriteOnly | QFile::Text))
	{
		qDebug() << "Erro arquivo";
		return;
	}

	QTextStream outPREFile(&batchPREFile);
	outPREFile << "@echo off" << endl;
	outPREFile << "CLS " << endl;
	outPREFile << "CD " << endl;
	outPREFile << WorkFolder.at(0) << ":" << endl;
	outPREFile << "CD " << WorkFolder.toAscii() << endl; //+"\\EXECUTABLES" << endl;
	outPREFile << "REM EXECUTANDO O ARQUIVO PRE_EDGECFD.bat" << endl;
	outPREFile << "@echo on" << endl;
	outPREFile << "start \"Running Edge-CFD PRE - LAMCE 2013\" /I /HIGH PRE.bat " << endl;
	//outPREFile << "call PRE.bat " << endl;
	outPREFile << "CD.." ;

	//fechando o arquivo de batch PRE_EDGECFD.bat	
	batchPREFile.flush();
	batchPREFile.close();

	
	//trocando atributo do arquivo batch
	
	//SetFileAttributesA((LPCWSTR)filenamePREBatch.data(), FILE_ATTRIBUTE_HIDDEN);
	
	
	//************* FIM DA CRIACAO DE UM ARQUIVO PRE_EDGECFD.bat PARA A EXECUCAO pre *************



	
	//Criando o objeto para executar este processo do EdgeCFDPre-dbg-REV-A
	QProcess* process_pre = new QProcess();
	
	if (process_pre)
	{
		//EXECUTANDO O ARQUIVO BAT CRIADO USANDO O QPROCESS
		process_pre->start(filenamePREBatch);
		
		if(process_pre->waitForFinished(-1))
		{
			process_pre->deleteLater();
			delete process_pre;

			//apagando o arquivo de batch gerados 
			//batchPREFile.remove();
			//batchExecPREFile.remove();
	
		}
	}

	
	//******************** FIM EXECUCAO DO EXECUTAVEL DO PRE DO EDGECFD ******************/

	

}



//EXECUCAO DO BOTAO RUN EDGECFDSOlver - BOTAO PARTE SUPERIO INTERFACE
// REALIZA A CHAMADA DO metodo  ExecutaEdgeCFDSolver()
void runEdgeCFD::slotRunEdgeCFDSolver()
{

	//definido o diretorio atual e o caminho do arquivo pre
	QDir WorkPath = ui->lineEdit_WorkingDir->text();
	QString SetupFilePath = WorkPath.absolutePath()+"/PREPROCESSOR/"+ui->lineEdit_jobName->text()+".PRE";
	QFile setupFile(SetupFilePath);

	//verificando se o usuario criou um jobname
	if(ui->lineEdit_jobName->text().isEmpty())
	{
		QMessageBox::critical(this, "Error", "Jobname is empty");
		return;
	}
	else if(!setupFile.exists())
	{
		QMessageBox::critical(this, "Error", "Please run MAKE button in File Management tab ");
		return;
	}
	else
	{

		//===========================================================================
		// REALIZANDO A CHAMADA NA CLASSE IO:: ESCREVENDO O CONTEUDO DA ABA MATERIAL
		//===========================================================================

		io::Escreve_MaterialFile(ui->lineEdit_jobName->text(), QDir(ui->lineEdit_WorkingDir->text()+"/SOLVER"), formMaterial, ui);

		// CHAMADA PARA O EXECUTAVEL DO PRE PROCESSADOR
		ExecutaEdgeCFDSolver();
	}

}

//REALIZA A CHAMADA PARA O EXECUTAVEL DO ARQUIVO - EdgeCFDSolver-vof-rel-x64
// EXECUCAO DO PROGRAMA DO EdgeCFDSolver-vof-rel-x64
void runEdgeCFD::ExecutaEdgeCFDSolver()
{

	/*==========================================================================
	EXECUCAO DO EDGECFD - ../EXECUTABLES/EdgeCFDSolver-vof-rel-x64
	DESCRIÇÃO: EXECUTA A ANÁLISE
	==========================================================================

	./SOLVER
	DESCRIÇÃO: EXECUTA A ANÁLISE
	EXECTUTÁVEL:
	../EXECUTABLES/EdgeCFDSolver-vof-rel-x64.EXE

	INPUT:
	./FILENAME_1.PART.IN;       ./FILENAME_1.PART.MSH;     ./FILENAME_1.PART.EDG; ./FILENAME_1.PART.MAT;   ./FILENAME_1.PART.IN

	./INPUT.DAT
	./FSI.DAT

	OUTPUT:
	./RESULTS/ FILENAME_1.000.CASE
	./RESULTS/ FILENAME_1_pres_XXXX.SCL000;  ./RESULTS/ FILENAME_1_velo_XXXX.VEC000; 

	//============================================================================================================================*/


	//criando o path inicial de trabalho
	QDir WorkPath = ui->lineEdit_WorkingDir->text();
	QString WorkFolder = WorkPath.absolutePath();

	// **************** REALIZANDO A CHAMADA DO EXECUTAVEL *****************************/

	//verificando se os arquivos foram criados pelo setup

	//===================================================================================
	//realizando a chamada do executavel
	//A CRIACAO DE UM ARQUIVO .BAT PARA FAZER A CHAMADA DO EXECUTAVEL EDGECFDSOLVER()
	// PARA SUA EXECUCAO TEMOS QUE COPIAR O EXECUTAVEL PARA A PASTA SOLVER
	//===================================================================================
	
	//CRIANDO UM COPIA DO EXECUTAVEL NO DIRETORIO SOLVER
	QString SolverExeFile = "EdgeCFDSolver-vof-rel-x64.exe";
	QString PathExeSolver = WorkFolder+"/EXECUTABLES";
	QString PathSolverFolder = WorkFolder+"/SOLVER";

	QFile Sfile(PathExeSolver+"/"+SolverExeFile);
	if(!Sfile.exists())
	{
		QMessageBox::critical(this, "Error", "The file "+SolverExeFile+ " not exist!");
		return;
	}else
	{
		Sfile.copy(PathExeSolver+"/"+SolverExeFile,PathSolverFolder+"/"+SolverExeFile);	
	}


	//INCIANDO A CRIACAO DE UM ARQUIVO DE BATCH PARA EXECUTAR O SOLVER
	QString filenameSolverBatch = WorkFolder+"/SOLVER_EDGECFD.bat";
	QFile batchSolverFile(filenameSolverBatch);
	if(!batchSolverFile.open(QFile::WriteOnly | QFile::Text))
	{
		qDebug() << "Erro arquivo";
		return;
	}

	QTextStream outSolverFile(&batchSolverFile);
	outSolverFile << "@echo off" << endl;
	outSolverFile << "CLS " << endl;
	outSolverFile << "CD " << endl;
	outSolverFile << WorkFolder.at(0) << ":" << endl;
	outSolverFile << "CD " << WorkFolder+"/EXECUTABLES" << endl;
	outSolverFile << "REM REALIZANDO UMA COPIA DO EXECUTAVEL DO EDGECFD" << endl;
	outSolverFile << "copy " + SolverExeFile.toAscii() + " ../SOLVER/" << endl;
	outSolverFile << "CD " << WorkFolder+"/SOLVER" << endl;
	outSolverFile << "REM EXECUTANDO O ARQUIVO SETUP" << endl;
	outSolverFile << "@echo on" << endl;
	outSolverFile << "start \"Running Edge-CFD Solver - LAMCE 2013\" /I /HIGH " + SolverExeFile.toAscii() << endl;
	outSolverFile << "REM REMOVENDO A COPIA DO EXECUTAVEL DO EDGECFD" << endl; 
	outSolverFile << "del "+SolverExeFile.toAscii() << endl;
	outSolverFile << "CD.." ;

	//fechando o arquivo de batch do setup	
	batchSolverFile.flush();
	batchSolverFile.close();

	//************* FIM DA CRIACAO DE UM ARQUIVO DE BAT PARA A EXECUCAO SOLVER *************/


	//Criando o objeto para executar este processo do EdgeCFDPre-dbg-REV-A
	QProcess* process_solver = new QProcess();

	if (process_solver)
	{
		//EXECUTANDO O ARQUIVO BAT CRIADO USANDO O QPROCESS
		process_solver->start(filenameSolverBatch);

		if(process_solver->waitForFinished())
		{
			//apagando o arquivo de batch gerado 
			batchSolverFile.remove();
			delete process_solver;
		}
	}

	
	//******************** FIM EXECUCAO DO EXECUTAVEL DO PRE DO EDGECFD ******************/



}


// CHAMADA PARA A CRIACAO DE UMA LISTA DE MATERIAIS NA ABA MATERIAL
void runEdgeCFD::slotNewMaterial()
{

	//===================================================================
	// CRIANDO O CAMPO ID - SPINBOX [VALOR MAXIMO 999]
	//===================================================================

	formMaterial[idMaterial].id = new QSpinBox(ui->scrollAreaWidgetContents_2);
	formMaterial[idMaterial].id->setObjectName(QString::fromUtf8("spinBox_mat_ID"));
	formMaterial[idMaterial].id->setMaximumSize(QSize(46, 22));
	formMaterial[idMaterial].id->setMinimum(0);
	formMaterial[idMaterial].id->setMaximum(999);
	formMaterial[idMaterial].id->setValue(idMaterial);

	//ADICIONANDO O CAMPO ID A INTERFACE
	//int linha = componenteDOF->size();
	ui->gridLayout_2->addWidget(formMaterial[idMaterial].id, idMaterial, 0, 1, 1);

	//---------------------------------

	formMaterial[idMaterial].dens = new QDoubleSpinBox(ui->scrollAreaWidgetContents_2);
	formMaterial[idMaterial].dens->setObjectName(QString::fromUtf8("doubleSpinBox_mat_DENS"));
	formMaterial[idMaterial].dens->setMaximumSize(QSize(80, 22));
	formMaterial[idMaterial].dens->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
	formMaterial[idMaterial].dens->setDecimals(4);
	formMaterial[idMaterial].dens->setMinimum(0.0);
	formMaterial[idMaterial].dens->setMaximum(9999);
	formMaterial[idMaterial].dens->setValue(1);
	formMaterial[idMaterial].dens->setToolTip(QString::fromUtf8("Massa Especifica"));


	//ADICIONANDO O CAMPO ID A INTERFACE
	//int linha = componenteDOF->size();
	ui->gridLayout_2->addWidget(formMaterial[idMaterial].dens, idMaterial, 1, 1, 1);

	//---------------------------------
	
	formMaterial[idMaterial].visc = new QDoubleSpinBox(ui->scrollAreaWidgetContents_2);
	formMaterial[idMaterial].visc->setObjectName(QString::fromUtf8("doubleSpinBox_mat_VISC"));
	formMaterial[idMaterial].visc->setMaximumSize(QSize(80, 22));
	formMaterial[idMaterial].visc->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
	formMaterial[idMaterial].visc->setDecimals(4);
	formMaterial[idMaterial].visc->setMinimum(0.0);
	formMaterial[idMaterial].visc->setMaximum(9999);
	formMaterial[idMaterial].visc->setValue(0.1);
	

	//ADICIONANDO O CAMPO ID A INTERFACE
	//int linha = componenteDOF->size();
	ui->gridLayout_2->addWidget(formMaterial[idMaterial].visc, idMaterial, 2, 1, 1);
	
	//---------------------------------
	
	formMaterial[idMaterial].par3 = new QDoubleSpinBox(ui->scrollAreaWidgetContents_2);
	formMaterial[idMaterial].par3->setObjectName(QString::fromUtf8("doubleSpinBox_mat_PAR3"));
	formMaterial[idMaterial].par3->setMaximumSize(QSize(80, 22));
	formMaterial[idMaterial].par3->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
	formMaterial[idMaterial].par3->setDecimals(4);
	formMaterial[idMaterial].par3->setMinimum(0.0);
	formMaterial[idMaterial].par3->setMaximum(9999);
	formMaterial[idMaterial].par3->setValue(0.1);

	//ADICIONANDO O CAMPO ID A INTERFACE
	//int linha = componenteDOF->size();
	ui->gridLayout_2->addWidget(formMaterial[idMaterial].par3, idMaterial, 3, 1, 1);
	
	//---------------------------------


		
	formMaterial[idMaterial].par4 = new QDoubleSpinBox(ui->scrollAreaWidgetContents_2);
	formMaterial[idMaterial].par4->setObjectName(QString::fromUtf8("doubleSpinBox_mat_PAR3"));
	formMaterial[idMaterial].par4->setMaximumSize(QSize(80, 22));
	formMaterial[idMaterial].par4->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
	formMaterial[idMaterial].par4->setDecimals(4);
	formMaterial[idMaterial].par4->setMinimum(0.0);
	formMaterial[idMaterial].par4->setMaximum(9999);
	formMaterial[idMaterial].par4->setValue(0.1);

	//ADICIONANDO O CAMPO ID A INTERFACE
	//int linha = componenteDOF->size();
	ui->gridLayout_2->addWidget(formMaterial[idMaterial].par4, idMaterial, 4, 1, 1);
	
	//---------------------------------

	formMaterial[idMaterial].kxx = new QDoubleSpinBox(ui->scrollAreaWidgetContents_2);
	formMaterial[idMaterial].kxx->setObjectName(QString::fromUtf8("doubleSpinBox_mat_KXX"));
	formMaterial[idMaterial].kxx->setMaximumSize(QSize(80, 22));
	formMaterial[idMaterial].kxx->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
	formMaterial[idMaterial].kxx->setDecimals(4);
	formMaterial[idMaterial].kxx->setMinimum(0.0);
	formMaterial[idMaterial].kxx->setMaximum(9999);
	formMaterial[idMaterial].kxx->setValue(0.1);

	//ADICIONANDO O CAMPO ID A INTERFACE
	//int linha = componenteDOF->size();
	ui->gridLayout_2->addWidget(formMaterial[idMaterial].kxx, idMaterial, 5, 1, 1);
	
	//---------------------------------

	formMaterial[idMaterial].kyy = new QDoubleSpinBox(ui->scrollAreaWidgetContents_2);
	formMaterial[idMaterial].kyy->setObjectName(QString::fromUtf8("doubleSpinBox_mat_KYY"));
	formMaterial[idMaterial].kyy->setMaximumSize(QSize(80, 22));
	formMaterial[idMaterial].kyy->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
	formMaterial[idMaterial].kyy->setDecimals(4);
	formMaterial[idMaterial].kyy->setMinimum(0.0);
	formMaterial[idMaterial].kyy->setMaximum(9999);
	formMaterial[idMaterial].kyy->setValue(0.1);

	//ADICIONANDO O CAMPO ID A INTERFACE
	//int linha = componenteDOF->size();
	ui->gridLayout_2->addWidget(formMaterial[idMaterial].kyy, idMaterial, 6, 1, 1);
	
	//---------------------------------

	formMaterial[idMaterial].kzz = new QDoubleSpinBox(ui->scrollAreaWidgetContents_2);
	formMaterial[idMaterial].kzz->setObjectName(QString::fromUtf8("doubleSpinBox_mat_KZZ"));
	formMaterial[idMaterial].kzz->setMaximumSize(QSize(80, 22));
	formMaterial[idMaterial].kzz->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
	formMaterial[idMaterial].kzz->setDecimals(4);
	formMaterial[idMaterial].kzz->setMinimum(0.0);
	formMaterial[idMaterial].kzz->setMaximum(9999);
	formMaterial[idMaterial].kzz->setValue(0.1);

	//ADICIONANDO O CAMPO ID A INTERFACE
	//int linha = componenteDOF->size();
	ui->gridLayout_2->addWidget(formMaterial[idMaterial].kzz, idMaterial, 7, 1, 1);
	
	//---------------------------------

	
	formMaterial[idMaterial].sph = new QDoubleSpinBox(ui->scrollAreaWidgetContents_2);
	formMaterial[idMaterial].sph->setObjectName(QString::fromUtf8("doubleSpinBox_mat_SPH"));
	formMaterial[idMaterial].sph->setMaximumSize(QSize(80, 22));
	formMaterial[idMaterial].sph->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
	formMaterial[idMaterial].sph->setDecimals(4);
	formMaterial[idMaterial].sph->setMinimum(0.0);
	formMaterial[idMaterial].sph->setMaximum(9999);
	formMaterial[idMaterial].sph->setValue(0.1);

	//ADICIONANDO O CAMPO ID A INTERFACE
	//int linha = componenteDOF->size();
	ui->gridLayout_2->addWidget(formMaterial[idMaterial].sph, idMaterial, 8, 1, 1);
	
	//---------------------------------
	

	formMaterial[idMaterial].name = new QLineEdit(ui->scrollAreaWidgetContents_2);
	formMaterial[idMaterial].name->setObjectName(QString::fromUtf8("lineEdit_mat_NAME"));
	formMaterial[idMaterial].name->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
	formMaterial[idMaterial].name->setGeometry(QRect(630, 10, 61, 22));
	formMaterial[idMaterial].name->setText("MAT"+QString::number(idMaterial));
	

	//ADICIONANDO O CAMPO ID A INTERFACE
	//int linha = componenteDOF->size();
	ui->gridLayout_2->addWidget(formMaterial[idMaterial].name, idMaterial, 9, 1, 1);
	
	//---------------------------------



	//=======================================================================================
	//INSERINDO UM ESPACAMENTO VERTICAL NO FINAL DOS CAMPOS DO FOMULARIO PARA QUE 
	//OS CAMPOS POSSAM FICAR NO TOPO
	verticalSpacer_mat = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

	//linha = valorDOF->size();
	ui->gridLayout->addItem(verticalSpacer_mat, totcamposMat, 1, 1, 1);

	//=============================================================
	//=============================================================

	//atualizando os itens na interface
	ui->gridLayout->update();
	//=============================================================

	idMaterial++;
	totcamposMat++;


}

// CHAMADA PARA A DELECAO DE UM ITEM DA LISTA DE MATERIAIS NA ABA MATERIAL
void runEdgeCFD::slotDeleteMaterial()
{

	if(idMaterial == 1)
	{
		QMessageBox::critical(this, "Error", "There are no items in the MATERIAL tab");
		return;
	}
	else
	{
		idMaterial--;
		totcamposMat--;

		formMaterial[idMaterial].id->deleteLater();
		formMaterial[idMaterial].dens->deleteLater();
		formMaterial[idMaterial].visc->deleteLater();
		formMaterial[idMaterial].par3->deleteLater();
		formMaterial[idMaterial].par4->deleteLater();
		formMaterial[idMaterial].kxx->deleteLater();
		formMaterial[idMaterial].kyy->deleteLater();
		formMaterial[idMaterial].kzz->deleteLater();
		formMaterial[idMaterial].sph->deleteLater();
		formMaterial[idMaterial].name->deleteLater();

		formMaterial.erase(formMaterial.find(idMaterial));
	}


	//atualizando os itens na interface
	ui->gridLayout->update();
	//=============================================================

}	


//REALIZA A CHAMADA NO METODO DE IO PARA A ESCRITA DO ARQUIVO DE MATERIAL

void runEdgeCFD::slotEscreveMaterial()
{
	//===========================================================================
	// REALIZANDO A CHAMADA NA CLASSE IO:: ESCREVENDO O CONTEUDO DA ABA MATERIAL
	//===========================================================================

	io::Escreve_MaterialFile(ui->lineEdit_jobName->text(), QDir(ui->lineEdit_WorkingDir->text()+"/SOLVER"), formMaterial, ui);
}


//MENU DE CONFIGURACAO DO ANSYS
void runEdgeCFD::slotConfigAnsys()
{
    menuAnsys->show();
}



//SIGNALS AND SLOTS - VISUALIZANDO A VERSAO DO ANSYS ESCOLHIDA NA INTERFACE PRINCIPAL
void runEdgeCFD::slotAtualizaLabelAnsys(QString VersaoAtual)
{
	QFile f(VersaoAtual);
	QFileInfo fileInfo(f.fileName());
	QString AnsysAtual(fileInfo.fileName());

	//setando o cor do label 
	QPalette sample_palette;
	sample_palette.setColor(QPalette::Window, Qt::red);
	ui->label_AnsysVersion->setPalette(sample_palette);
	ui->label_AnsysVersion->setText("<font color='red'> Ansys version Selected: " + AnsysAtual + "</font>");
}


//slot de visualizacao do VTK
void runEdgeCFD::slotSetWireframeMode(bool wf)
{
	//view->ChangeWireframe(wf);
	//ui->qvtkWidget->update();
}

//Manipular a visibilidade dos blocos
void runEdgeCFD::slotBlocksVisibility(QTableWidgetItem *item)
{
	//qDebug() << "runEdgeCFD::slotBlocksVisibility(" << item->row() << ", " << item->column() << ")";

	QPalette palette;
	palette = this->ui->tableWidget->palette();
	QColor color;
	color = item->background().color();
	//qDebug() << "Background Color->R: " << color.red() << " G: " << color.green() << " B: " << color.blue() << " A: " << color.alpha();	

	palette.setColor(QPalette::Active, QPalette::Highlight, color);
	palette.setColor(QPalette::Inactive, QPalette::Highlight, color);
	
	color = item->foreground().color();
	//qDebug() << "Foreground Color->R: " << color.red() << " G: " << color.green() << " B: " << color.blue() << " A: " << color.alpha();

	palette.setColor(QPalette::Active, QPalette::HighlightedText, color);
	palette.setColor(QPalette::Inactive, QPalette::HighlightedText, color);
	//palette.setColor(QPalette::, QPalette::HighlightedText, color);
	
	this->ui->tableWidget->setPalette(palette);
	this->ui->tableWidget->viewport()->update();
	
	if(item->column() == 0)
	{
		vtkActor *a = vtkActor::SafeDownCast(this->view->actorsCollection->GetItemAsObject(item->row()));
		a->SetVisibility(item->checkState());
		this->ui->qvtkWidget->GetRenderWindow()->Render();
	}
}

//Manipular a coloração dos blocos
void runEdgeCFD::slotBlocksColors(QTableWidgetItem *item)
{
	//qDebug() << "runEdgeCFD::slotBlocksVisibility(" << item->row() << ", " << item->column() << ")";
	if(item->column() == 1)
	{
		QColor color = QColorDialog::getColor();
		if(color.isValid())
		{
			item->setBackgroundColor(color);
			vtkActor *a = vtkActor::SafeDownCast(this->view->actorsCollection->GetItemAsObject(item->row()));
			a->GetProperty()->SetColor(color.redF(), color.greenF(), color.blueF());
			this->ui->qvtkWidget->GetRenderWindow()->Render();
		}
	}
}

//void runEdgeCFD::slotTestaCores(int seed)
//{
//	srand(seed);
//
//	for(int i = 0; i < this->view->numberOfBlocks; i++)
//	{
//		float r = (rand() % 255) + 1;
//		float g = (rand() % 255) + 1;
//		float b = (rand() % 255) + 1;
//		QTableWidgetItem *item;
//		item = ui->tableWidget->item(i, 1);
//		item->setBackgroundColor(QColor(r, g, b));
//		ui->tableWidget->update();
//		ui->tableWidget->viewport()->update();
//
//		vtkActor *a = vtkActor::SafeDownCast(this->view->actorsCollection->GetItemAsObject(i));
//		a->GetProperty()->SetColor(item->background().color().redF(), item->background().color().greenF(), item->background().color().blueF());
//		this->ui->qvtkWidget->GetRenderWindow()->Render();
//	}
//}



void runEdgeCFD::slotConfigRender()
{
	QColor color = QColorDialog::getColor();
	if(color.isValid())
	{
		//qDebug() << "Color.red(): " << color.red() << " Color.green(): " << color.green() << " Color.green(): " << color.black();
		//qDebug() << "Color.redF(): " << color.redF() << " Color.greenF(): " << color.greenF() << " Color.greenF(): " << color.blackF();
		this->view->ren1->SetBackground(color.red(), color.green(), color.blueF());
		this->view->ren1->Render();
	}
}

//########################################################################################
//CHAMADA PARA A EXECUCAO DE UM COMANDO SSH PARA SUBMETER UM ARQUIVO
//########################################################################################
void runEdgeCFD::slotSSHConnect()
{
	//ssh_session my_ssh_session = ssh_new();
	//CallSSH *ssh ;
	//ssh =  new CallSSH(ui);
	//ssh->WrapCallSSH(ui->lineEdit_host->text(), ui->lineEdit_user->text(), ui->lineEdit_port->text().toInt(), ui->lineEdit_passwd->text(), "who", ui);


	// DEFININDO O NOME DO EXECUTAVEL QUE IRA FAZER A CONEXAO DO SSH
	//QString program = "sshCFD.exe -host=uranus.nacad.ufrj.br -user=gazoni -pw=xlxtybl1 -port=22 -cmd=\"" + ui->lineEdit_comandoSSH->text()+"\"";
	
	// DEFININDO O NOME DO EXECUTAVEL QUE IRA FAZER A CONEXAO DO SSH
	QString SSH = "sshCFD.exe";
	QString host = ui->lineEdit_host->text();
	QString user = ui->lineEdit_user->text();
	int port = ui->lineEdit_port->text().toInt();
	QString passwd = ui->lineEdit_passwd->text();
	QString cmd = ui->lineEdit_comandoSSH->text();

	QString SSHRun = SSH +  
		" -host=" + host +  
	    " -user=" + user +
		" -pw=" + passwd +
		" -port=" + QString::number(port) +
		" -cmd=\"" + cmd +"\"";


	// CRIANDO O PROCESSO PARA A EXECUCAO
	process = new QProcess(this);
	process->setWorkingDirectory("./");
	process->setReadChannel(QProcess::StandardOutput);
    process->setReadChannelMode(QProcess::MergedChannels);
	//process->setStandardOutputFile("testesaida2.txt");
	
	process->start(SSHRun);



	//CONECT PARA ESCREVER O CONTEUDO EM UMA JANELA DE SAIDA
	connect(process, SIGNAL(readyReadStandardOutput ()), this, SLOT(outlog()));
	//===========================================================================


	
}

//FUNCAO PARA GERAR UM ARQUIVO RAR COMPACTADO PARA COPIAR PARA MAQUINA LINUX ONDE SERA RODADA A SIMULACAO 
QString runEdgeCFD::slotRARSimulationFiles()
{
	
	//PARA QUE ESTA FUNCAO SEJA REALIZADA E NECESSARIO QUE EXISTA UM DIRETORIO DE CONFIGURACAO DO PROJETO E O 
	//USUARIO JA TENHA EXECUTADO OS PASSOS DE SETUP E O PRE
	//E NECESSARIO QUE A PASTA SOLVER EXISTAM TODOS OS ARQUIVOS NECESSARIOS ALEM DO EXECUTAVEL DA MAQUINA LINUX JA COMPILADO




	// NOME DO ARQUIVO .RAR QUE IRA SER COPIADO PARA A URANUS OU OUTRA MAQUINA LINUX
	// COLOQUEI O MESMO NOME DA PASTA
	QString FileRAR = "solver.rar";

	// DEFININDO O NOME DO EXECUTAVEL QUE IRA FAZER COMPACTACAO
	QString RAR = "Rar.exe";
	RAR.append(" a ");
	RAR.append(FileRAR);
	RAR.append(" \"");
	RAR.append(ui->lineEdit_WorkingDir->text());
	RAR.append("\\SOLVER\\");
	RAR.append("\" > nul");

	// CRIANDO O PROCESSO PARA A EXECUCAO DO ARQUIVO RAR
	process = new QProcess(this);
	process->setWorkingDirectory("./");
	process->setReadChannel(QProcess::StandardOutput);
    process->setReadChannelMode(QProcess::MergedChannels);
	process->start(RAR);
	process->waitForFinished();

	//CONECT PARA ESCREVER O CONTEUDO EM UMA JANELA DE SAIDA
	connect(process, SIGNAL(readyReadStandardOutput ()), this, SLOT(outlog()));
	//===========================================================================

	//retornando o nome do arquivo e local onde foi compactado
	return FileRAR; 
}


//FUNCAO PARA COPIAR O ARQUIVO COMPACTADO PARA A MAQUINA LINUX ONDE SERA RODADA A SIMULACAO 
void runEdgeCFD::slotCopySimulationFiles()
{
	//TESTE PARA CHAMAR O EXECUTAVEL DO RAR
	QString FileRAR = slotRARSimulationFiles();

	
	// DEFININDO O NOME DO EXECUTAVEL QUE IRA FAZER A COPIA DO ARQUIVO COMPACTADO
	QString SSH = "scp.exe";
	QString host = ui->lineEdit_host->text();
	QString user = ui->lineEdit_user->text();
	int port = ui->lineEdit_port->text().toInt();
	QString passwd = ui->lineEdit_passwd->text();
	QString cmd = ui->lineEdit_comandoSSH->text();
	
	QString SCPRun = SSH +  
		" -l=" + user +  
	   	" -pw=" + passwd +
		" -P=" + QString::number(port) +
		" " + FileRAR +
		" " + user+"@"+host+":"+
		FileRAR;
	
	
	// CRIANDO O PROCESSO PARA A EXECUCAO
	process = new QProcess(this);
	process->setWorkingDirectory("./");
	process->setReadChannel(QProcess::StandardOutput);
    process->setReadChannelMode(QProcess::MergedChannels);
	//process->setStandardOutputFile("testesaida2.txt");
	process->start(SCPRun);
	
	//CONECT PARA ESCREVER O CONTEUDO EM UMA JANELA DE SAIDA
	connect(process, SIGNAL(readyReadStandardOutput ()), this, SLOT(outlog()));
	//===========================================================================

}	



//LIMPAR A JANELA DE STATUS DO SSH
void runEdgeCFD::slotClearWindowStatus()
{
	ui->textEdit_ssh->clear();
}



// SIGNAL PARA ESCREVER A SAIDA DO SSH EM UMA JANELA DE SAIDA
void runEdgeCFD::outlog() {

	QString abc = process->readAllStandardOutput();
	emit outlogtext(abc);
	ui->textEdit_ssh->append(abc);
	//SEPARADOR DE LINHA ENTRE MENSAGENS
	ui->textEdit_ssh->append(QString(QChar(0x2028)));
}


//SLOTS DA ABA PBS
//SALVAR O ARQUIVO PBS E VISUALIZAR NA TELA
void runEdgeCFD::slotSavePBSFile()
{
	
	//CRIANDO O NOME DO ARQUIVO DO JOB NA PASTA SOLVER
	QString JobFile;
	JobFile.append(ui->lineEdit_WorkingDir->text());
	JobFile.append("\\SOLVER\\");
	
	//VERIFICANDO SE O DIRETORIO EXISTE
	QDir tmp(JobFile);
	tmp.makeAbsolute();
	if(tmp.exists())
		QMessageBox(this,"merda");

	JobFile.append(ui->lineEdit_PBSJobname->text()+".job");
	
	QFile PBSFile(JobFile);

	//ABRINDO O ARQUIVO PARA ESCRITA
	if (PBSFile.open(QIODevice::WriteOnly| QIODevice::Text))
	{

		QTextStream out(&PBSFile);
		
		//ESCREVENDO NO ARQUIVO
		out << "# Configuration file - Portable Batch System" << endl;
		
		//ESCREVENDO AS INFORMACOES DE PROCESSADORES E CORES
		out << "#PBS -l nodes="+QString::number(ui->spinBox_PBSnPROCS->value())+":ppn="+QString::number(ui->spinBox_PBSNumCores->value()) << endl;                   
		//ESCREVENDO TEMPO DE PAREDE
		out << "#PBS -l walltime="+ui->lineEdit_PBSWalltime->text() << endl;
		//ESCREVENDO O NOME DO JOBNAME PARA IR PARA FILA
		out << "#PBS -N "+ ui->lineEdit_PBSJobname->text() << endl;
		//PARAMETROS INTERNOS DO PBS
		out << "#PBS -j oe" << endl;
		out << "#PBS -V" << endl;
		out << "# PBS -m ae" << endl;
		//DEFININDO UM EMAIL PARA ONDE IRA A RESPOSTA DO JOB TERMINADO
		out << "# PBS -M "+ ui->lineEdit_PBSEmail->text() << endl;
		
		//ENTRANDO NO DIRETORIO ONDE ESTA O EXECUTAVEL A SER PROCESSADO
		out << endl;
		out << "#change directory" << endl;
		out << "cd ${PBS_O_WORKDIR}" << endl;

		// LENDO AS VARIAVEIS DO PBS PARA SUBMETER PROC E CORES
		out << endl;
		out << "# get the number of processors and nodes" << endl;
		out << "NUM_PROC=`cat ${PBS_NODEFILE} | wc -l`" << endl;

		// CHAMADA PARA O EXECUTAVEL DA APLICACAO 
		//OBS: O EXECUTAVEL NESTE CASO DEVE ESTAR NA MESMA PASTA SOLVER, ONDE ESTARA O ARQUIVO DE JOB
		out << endl;
		out << "# run on all nodes" << endl;
		out << "mpirun -n ${NUM_PROC} edgecfdsolver-mpi-vof" << endl;

		
		//FECHANDO O ARQUIVO DO PBS
		PBSFile.close();
	}

	//VISUALIZANDO O CONTEUDO DO ARQUIVO NO TEXT_EDIT
}