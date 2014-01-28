#include "configansys.h"
#include "ui_configansys.h"

configAnsys::configAnsys(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::configAnsys)
{
    ui->setupUi(this);

	// definie o label dos botoes de radio e verifica qual versao de ansys existe instalda na maquina atual
	VerificaPathsAnsys();

	
	

	// CONECTS ==============================================================================
	connect(ui->pushButtonQuitMenuAnsys, SIGNAL(clicked()),  this, SLOT(slotcloseWindow()));
	connect(ui->pushButtonSaveAnsys, SIGNAL(clicked()),  this, SLOT(slotSetAnsysVersion()));

}

configAnsys::~configAnsys()
{
    delete ui;
}

//====================== INICIO DOS METODOS =====================

void configAnsys::VerificaPathsAnsys()
{
		
	//DEfinindo os Labels dos botoes de radio
	ui->radioButton_ansys11->setText("ANSYS 11");
	ui->radioButton_ansys12->setText("ANSYS 12");
	ui->radioButton_ansys13->setText("ANSYS 13");
	ui->radioButton_ansys14->setText("ANSYS 14"); 
	

	// verificando quais versoes de ansys existem no computador
	// assumindo que a isntalacao e padrao

	// verificando se existe versoes de ansys instaladas - autoexec paths
	VerAnsys11 = QString::fromLocal8Bit( qgetenv("ANSYS110_DIR").constData() );
	VerAnsys12 = QString::fromLocal8Bit( qgetenv("ANSYS120_DIR").constData() );
	VerAnsys13 = QString::fromLocal8Bit( qgetenv("ANSYS130_DIR").constData() );
	VerAnsys14 = QString::fromLocal8Bit( qgetenv("ANSYS140_DIR").constData() );

	// verifiando a versao ANSYS 11
	if(!VerAnsys11.isEmpty())
	{
		VersaoAtual = VerAnsys11+"\\bin\\winx64\\ansys110.exe";
		ui->radioButton_ansys11->setChecked(true);
	}else
		ui->radioButton_ansys11->setDisabled(true);
	
	// verifiando a versao ANSYS 12
	if(!VerAnsys12.isEmpty())
	{
		VersaoAtual = VerAnsys12+"\\bin\\winx64\\ansys120.exe";
		ui->radioButton_ansys12->setChecked(true);
	}else
		ui->radioButton_ansys12->setDisabled(true);

	// verifiando a versao ANSYS 13
	if(!VerAnsys13.isEmpty())
	{
		VersaoAtual = VerAnsys13+"\\bin\\winx64\\ansys130.exe";
		ui->radioButton_ansys13->setChecked(true);
	}else
		ui->radioButton_ansys13->setDisabled(true);
	
	// verifiando a versao ANSYS 14
	if(!VerAnsys14.isEmpty())
	{
		VersaoAtual = VerAnsys14+"\\bin\\winx64\\ansys140.exe" ;
		ui->radioButton_ansys14->setChecked(true);
	}else
		ui->radioButton_ansys14->setDisabled(true);

	//enviando um sinal para atualizar a interface
	emit this->updateAnsysVersion(VersaoAtual);
}

void configAnsys::slotSetAnsysVersion()
{

	if(ui->radioButton_ansys11->isChecked())
		VersaoAtual = VerAnsys11+"\\bin\\winx64\\ansys110.exe";

	if(ui->radioButton_ansys12->isChecked())
		VersaoAtual = VerAnsys13+"\\bin\\winx64\\ansys120.exe";
	
	if(ui->radioButton_ansys13->isChecked())
		VersaoAtual = VerAnsys13+"\\bin\\winx64\\ansys130.exe";

	if(ui->radioButton_ansys14->isChecked())
		VersaoAtual = VerAnsys14+"\\bin\\winx64\\ansys140.exe" ;

	//enviando um sinal para atualizar a interface
	emit this->updateAnsysVersion(VersaoAtual);

}

void  configAnsys::slotcloseWindow()
{
	close();
}