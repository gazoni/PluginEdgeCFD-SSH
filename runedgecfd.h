#ifndef RUNEDGECFD_H
#define RUNEDGECFD_H
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


//includes QT
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

#include "ui_runedgecfd.h"
#include "configansys.h"
#include "io.h"
#include "ViewVtk.h"

// Configure LibSSH
#include "ssh.h"



using namespace std;


class runEdgeCFD : public QMainWindow
{
	Q_OBJECT

public:
	runEdgeCFD(QWidget *parent = 0, Qt::WFlags flags = 0);
	~runEdgeCFD();

	

private:
	
	QProcess *process;
	ViewVtk *view;
	Ui::runEdgeCFDClass *ui;

	QDir directory; 
	QFile dbFile;
	int linha, totcampos, idMaterial, totcamposMat;
	QString sourceFolder; //pasta de origem dos arquivos principais
	io *saida;
	QPoint m_lastPoint;	//GUARDA A ULTIMA POSICAO DO MOUSE

	string workingDir;
	string jobName;
	string pathDb;
	string pathCase;

protected:
	// re-implement processing of mouse events
    //void mouseReleaseEvent ( QMouseEvent * e );
    void mousePressEvent ( QMouseEvent * e );


    bool eventFilter(QObject *object, QEvent *event);

public:
	//========================================================================================
	//CRIANDO METODOS DA CLASSE PRINCIPAL
	//========================================================================================
	void loadVersion();					//carrega um arquivo que referencia a ultima versao
	void conectar();					//METODOS DE CONNECT
	bool verificarErros();				//VERIFICA ERRO NAS ABAS DO PROGRAMA
	void copyFolder(const QString& sourceFolder,const QString& destFolder);		//METODO PARA COPIAR AS PASTAS COM ARQUIVOS PARA O WORKDIR
	void ProcessarFormulario();		// processando os dados do formulario
	void ExecutaMacros();				//executa a macro ANSYS
	void ExecutaSetup();				//executa o arquivo SETUP_EDGECFD-REV-B.exe
	void ExecutaPRE();					//executa o arquivo EdgeCFDPre-dbg-REV-A.exe
	void ExecutaEdgeCFDSolver();		//executa o arquivo EdgeCFD
	void loadMesh();


	 //SALVANDO O ARQUIVO DE DADOS

	 bool VerificaDadosProjeto();	//verifica erros de consistencia nos dados preenchidos (campos vazios)
	 void SalvarDadosProjeto(QString prjFileName);	//salva em arquivo os dados do formulario
	 QString RetornaCondContorno(int id);			//funcao auxiliar para retornar a condicao de contorno

	 //ABRINDO ARQUIVO DE DADOS

	 int RetornaIdCondContorno(string cc);	// Retorna o Id da condicaod e contorno da caixa de selecao

	 //========================================================================================
	
	 QMap<int, Forms> form;			//map para a criacao dos itens do menu SETUP
	 QMap<int, MATERIAL> formMaterial;	//map para a criacao dos itens do menu MATERIAL
	
	 int PREdata[10];

	


	 //Criando os elementos para a aba setup
	 //#  Nº DA COMPONENTE CC  LABEL   VALOR  
	 QVector<QSpinBox*>			componenteDOF;
	 QVector<QSpacerItem*>		espacamentoDOF;
	 QVector<QComboBox*>		labelDOF;
	 QVector<QDoubleSpinBox*>	valorDOF; 
	
	 //QVector<QSpacerItem*>		horizontalSpacer;
	 QSpacerItem		*verticalSpacer_setup;
	 QSpacerItem		*verticalSpacer_mat;

	 QSpinBox *spinBox_DOF;
	 QSpacerItem *horizontalSpacer;
	 QComboBox *comboBox_DOF;
	 QDoubleSpinBox *doubleSpinBox_DOF;

	 
	 std::vector<string> parts;

	 //QList<QCheckBox> *lCheckBox;
	 //QList<QLineEdit> *lLineEdit;

public slots:

	 //MENU PRINCIPAL
	void slotOpen();					//OPCAO DE ABERTURA DO ARQUIVO DE DADOS DO MODELO
	void slotSave();					//OPCAO DE SALVAR UM ARQUIVO DE DADOS DO MODELO
	void slotExit();					//SAIR DA APLICACAO
	void slotConfigAnsys();				//SLOT PARA A CONFIGURACAO DO ANSYS (JANELA EXTERNA)
	void slotConfigRender();

	//ABA FILE MANAGEMENT
	void slotChangeDirectory();		//SELECIONA O DIRETORIO ONDE DEVERA SER A RODADA
	void slotMakeButton();				//RESPONSAVEL POR REALIZAR INICIAL E CHAMADA DO MACRO ANSYS
	void slotSelectDBFile();			//RESPONSAVEL POR SELECIONAR O ARQUIVO DB

	//ABA SETUP
	void slotNewSetup();				//CRIA UM NOVO ITEM NO MENU SETUP
	void slotDeleteSetup();			//APAGA UM ITEM CRIADO NO MENU SETUP
	void slotRunEdgeCFDSetup();		// REALIZA A CHAMADA DO EXECUTAVEL SETUP
	void slotEscreveArquivoSetup();	//REALIZA A ESCRITA DO ARQUIVO DE SETUP APOS CLIQUE BOTAO SAVE SETUP FILE

	//ABA PRE
	void slotRunEdgeCFDPRE();			// REALIZA A CHAMADA DO EXECUTAVEL SETUP

	//aba INPUT
	void setNameFileInput(QString FileName);
	void slotEscreveArquivoInput();
	
	//ABA FSI
	void slotEscreveArquivoFSI();		//CHAMA O METODO PARA ESCREVER O ARQUIVO FSI
	//void slotValidacao(QString);		//VALIDA O CAMPOS DA ABA FSI
	
	//ABA MATERIAL
	void slotNewMaterial();			//CRIA UM NOVO ITEM NA ABA MATERIAL
	void slotDeleteMaterial();			//APAGA UM ITEM CRIADO NA ABA MATERIAL
	void slotEscreveMaterial();		//REALIZA A CHAMADA ESCREVER ARQUIVOD E MATERIAL EM IO::ESCREVEMATERIAL
	
	//botao RunEdgeCFDSolver - execucao
	void slotRunEdgeCFDSolver();		//REALIZA A EXECUCAO DO EDGECFDSOLVER
	
	
	//signals
	void slotAtualizaLabelAnsys(QString VersaoAtual);	//SLOT PARA EXIBIR A VERSAO ATUAL DO ANSYS;

	//chamadas para a visualizacao VTK
	void slotSetWireframeMode(bool);

	//Manipula visualizacao de blocos
	void slotBlocksVisibility(QTableWidgetItem *item);

	//Manipula coloração dos blocos
	void slotBlocksColors(QTableWidgetItem *item);

	////Ttesta Cores para automatização das cores iniciais
	//void slotTestaCores(int);


	//SLOT DA ABA SSH - CONEXAO E COPIA DE ARQUIVOS
	void slotSSHConnect();				//executa teste de conexao ssh
	void slotClearWindowStatus();		//limpa a janela de status de conexao e verificacao
	void outlog();						//funcao para imprimir a saida do ssh em uma janela do QT
	void slotCopySimulationFiles();		//funcao para copiar a pasta onde sera rodada a simulacao 
	void slotSavePBSFile();				//funcao para salvar o arquivo PBS.
	QString slotRARSimulationFiles();		//funcao para compactar a pasta solver a fim de copia-la para uma maquina linux.

signals:
	void mouseClickEvent();
	void outlogtext(QString ver);		// emissao de um sinal para imprimir o conteudo de um processo em uma janela do QT

	
};

#endif // RUNEDGECFD_H
