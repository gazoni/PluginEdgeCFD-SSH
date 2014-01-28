#include <QFileDialog>
#include "io.h"

io::io() 
{
}


io::~io(void)
{
}

bool ordena_por_id(FormOrd A, FormOrd B)
{
	if (A.compDOF_ord < B.compDOF_ord) 
		return true;
	return false;
}


/// METODOS

//REESCREVE O ARQUIVO MAC NA PASTA ANSYS ADEQUANDO O NOME DO ARQUIVO DB ESCOLHIDO
void io::Escreve_OPENMAC(QString pathdb, QDir filePath)
{
	//RECEBENDO O NOME DO ARQUIVO DB SELECIONADO NO lineEdit_DB
	QFileInfo info;
	info.setFile(pathdb);
	
	//retona o nome base do arquivo db
	//qDebug() << info.baseName();

	//ABRINDO O ARQUIVO OPEN.MAC
	QString MACfilename = filePath.absoluteFilePath("OPEN.mac");
	FILE *file;
	file = fopen(MACfilename.toAscii().constData(), "w");//, stdout);
	
	//escrevendo o arquivo MAC
	
	fprintf(file, "! Abrindo " + info.fileName().toAscii() + " DA PASTA: ..\\ANSYS" );
	fprintf(file, "\n\n");
	fprintf(file, "RESUME,'" + info.baseName().toAscii() + "','db','..\\ANSYS',0,0");
	fprintf(file, "\n\n");
	fprintf(file, "! Alterando o diretorio de trabalho para ..\\ANSYS");
	fprintf(file, "\n\n");
	fprintf(file, "/CWD,'..\\ANSYS'");
	fprintf(file, "\n\n");
	fprintf(file, "! Executa a macro: ..\\MACROS\\SETUP_EDGECFD_REV-A");
	fprintf(file, "\n\n");
	fprintf(file, "/INPUT,'SETUP_EDGECFD_REV-A','MAC','..\\MACROS\\',, 0  ");
	fprintf(file, "\n\n");
	fprintf(file, "/CWD,'..\\ANSYS' ");

	//fechando o arquivo
	fclose(file);
	
}

//ESCREVE O ARQUIVO DE DADOS CORRESPONDENTE A ABA SETUP
void io::Escreve_SETUPFile(QString jobname, QDir filePath, QMap<int, Forms> form,  Ui::runEdgeCFDClass *ui)
{
	
	
	//Criando um Vector com o conteudo do formulario
	//setup para postriormente chamar uma funcao de ordenacao
	vector<FormOrd> FormOrd(form.size());


	//PERCORRENDO OS ELEMENTOS DO FORM PARA CRIAR UM MAP ORDENADO
	for(int i=0; i<form.size(); i++)
	{
		//ATRIBUINDO OS VALORES DO FORMULARIO A VARIAVEIS LOCAIS
		int comp		= form[i].componenteDOF->currentIndex();
		QString label	= form[i].labelDOF->currentText();
		int indexlabel  = form[i].labelDOF->currentIndex();
		float valor		= form[i].valorDOF->value();
		
		//IMPRIMINDO OS VALORES DO FORMULARIO SETUP
		//qDebug() << comp << label << valor;
 

		//ATRIBUINDO OS VALORES ESCOLHIDOS PELO USUARIO PARA UM VETOR A SER ORDENADO
		FormOrd[i].compDOF_ord	= comp;
		FormOrd[i].labelDOF_ord = label.toAscii();
		FormOrd[i].valorDOF_ord = valor;
		
		
	}

	
	//ORDENANDO OS CAMPOS DE DOF SELECIONADOS PELO USUARIO.**************
	sort(FormOrd.begin(), FormOrd.end(), ordena_por_id);
	//*******************************************************************	
	

	//***********************************************************************************************
	//******************** INICIO DA ESCRITA DO ARQUIVO ../SETUP/FILENAME.SETUP *********************
	//***********************************************************************************************
	QString filename = filePath.absoluteFilePath(jobname+".SETUP");
	FILE *file;
	file = fopen(filename.toAscii().constData(), "w");//, stdout);

	//# TITULO DA MODELAGEM (CHARACTER 80)
	//fprintf(file, "DESCRIPTION\n" );
	//fprintf(file, "%s\n", ui->lineEdit_descriptionSetup->text().toAscii().constData());
	//fprintf(file, "\n");

	//fprintf(file,"#  BEGIN FILENAME.SETUP\n"); 
	for (int i= 0; i< FormOrd.size() ; i++)
	{
		if (FormOrd[i].compDOF_ord > 0)
		{
			fprintf(file,"#  Nº DA COMPONENTE CC  LABEL   VALOR\n");
			break;
		}
	}
	//PERCORENDO O VETOR ORDENADO PARA GRAVAR NO ARQUIVO
	QString label;
	//int idTemp;

	//ESCREVENDO OS VALORES DIFERENTES DE ZERO DO CAMPO compDOF_ord
	for (int i= 0; i< FormOrd.size() ; i++)
	{
		if (FormOrd[i].compDOF_ord != 0)
		{
			if(FormOrd[i].labelDOF_ord.compare("ALE-X") == 0)
				label = "UX";
			else if(FormOrd[i].labelDOF_ord.compare("ALE-Y") == 0)
				label = "UY";
			else if (FormOrd[i].labelDOF_ord.compare("ALE-Z") == 0)
				label = "UZ";
			else
				label = FormOrd[i].labelDOF_ord.data();


			fprintf(file, "%8d %17s %12.5f\n", FormOrd[i].compDOF_ord, 
				label.toAscii().constData(), FormOrd[i].valorDOF_ord );

			if(i < (FormOrd.size()-1))
			{
				if(FormOrd[i+1].compDOF_ord > FormOrd[i].compDOF_ord)
					fprintf(file,"\n#  Nº DA COMPONENTE CC  LABEL   VALOR\n"); 
			}
		}
	}

	//ESCREVENDO NO FINAL DO ARQUIVO OS VALORES DE FormOrd[i].compDOF_ord QUE SAO IGUAIS A ZERO
	
	for (int i= 0; i< FormOrd.size() ; i++)
	{
		if (FormOrd[i].compDOF_ord == 0)
		{
		
			fprintf(file,"\n#  Nº DA COMPONENTE CC  LABEL   VALOR\n"); 
		
			if(FormOrd[i].labelDOF_ord.compare("ALE-X") == 0)
				label = "UX";
			else if(FormOrd[i].labelDOF_ord.compare("ALE-Y") == 0)
				label = "UY";
			else if (FormOrd[i].labelDOF_ord.compare("ALE-Z") == 0)
				label = "UZ";
			else
				label = FormOrd[i].labelDOF_ord.data();


			fprintf(file, "%8d %17s %12.5f\n", FormOrd[i].compDOF_ord, 
				label.toAscii().constData(), FormOrd[i].valorDOF_ord  );

		}
	}
	fprintf(file, "\n");
	fprintf(file, "end");
	fprintf(file, "\n");

	//FICOU UMA DUVIDA'SOBRE O ARQUIVO É SE OS VALORES DE ZERO TEM QUE FICAR NO FINAL DO ARQUIVO
	
	//FECHANDO O ARQUIVO DE DADOS INPUT
	fclose(file);

	//***********************************************************************************************

}

//ESCREVE O ARQUIVO DE DADOS CORRESPONDENTE A ABA PRE
void io::Escreve_PREFile(QString jobname, QDir filePath, QMap<int, Forms>, Ui::runEdgeCFDClass *ui)
{

	//***********************************************************************************************
	//******************** INICIO DA ESCRITA DO ARQUIVO ../PREPROCESSOR/FILENAME.PRE ****************
	//***********************************************************************************************
	QString filename = filePath.absoluteFilePath(jobname+".PRE");
	FILE *file;
	file = fopen(filename.toAscii().constData(), "w");//, stdout);

	

	fprintf(file, "JOIN\n" );
	fprintf(file, "$============================================================$\n");
	fprintf(file, "$  NP   BLK   RED   ORD   RCM   KEQ   FMT   ANS   PMV   LDE  $\n");
	fprintf(file, "$============================================================$\n");

	fprintf(file, "%5d %5d %5d %5d %5d %5d %5d %5d %5d %5d", 
		ui->spinBox_NP->value(), 
		ui->spinBox_BLK->value(),
		ui->spinBox_RED->value(),
		ui->spinBox_ORD->value(),
		ui->spinBox_RCM->value(),
		ui->spinBox_KEQ->value(),
		ui->spinBox_FMT->value(),
		ui->spinBox_ANS->value(),
		ui->spinBox_PMV->value(),
		ui->spinBox_LDE->value());
	

	fprintf(file,"\n$============================================================$\n");
	fprintf(file,"$                                                            $\n");
	fprintf(file,"$ GENERAL RULES:                                             $\n");
	fprintf(file,"$ ======= =====                                              $\n");
	fprintf(file,"$                                                            $\n");
	fprintf(file,"$ - Do not skip lines or the program will produce an error   $\n");
	fprintf(file,"$ - Lines started with $ are considered as comment lines     $\n");
	fprintf(file,"$                                                            $\n");
	fprintf(file,"$ INPUT PARAMETERS:                                          $\n");
	fprintf(file,"$ ===== ==========                                           $\n");
	fprintf(file,"$                                                            $\n");
	fprintf(file,"$                                                            $\n");
	fprintf(file,"$ NP     : integer > 0                                       $\n");
	fprintf(file,"$          number of processes to be generated               $\n");
	fprintf(file,"$                                                            $\n");
	fprintf(file,"$ BLK   : integer                                            $\n");
	fprintf(file,"$         Controls the use of mesh coloring algorithm for    $\n");
	fprintf(file,"$         vectorization purposes as following:               $\n");
	fprintf(file,"$         n < 0: Group blocks in chunks                      $\n");
	fprintf(file,"$         n = 0: Do not perform mesh coloring                $\n");
	fprintf(file,"$         n > 0: Group colored blocks (VECTORIZATION)        $\n");
	fprintf(file,"$         where 'n' is the size of the block                 $\n");
	fprintf(file,"$                                                            $\n");
	fprintf(file,"$ RED   : integer (0 or 1)                                   $\n");
	fprintf(file,"$         0: Keep the original mesh                          $\n");
	fprintf(file,"$         1: Perform Lohner data reordering to build reduced $\n");
	fprintf(file,"$            edge structure                                  $\n");
	fprintf(file,"$                                                            $\n");
	fprintf(file,"$ ORD   : integer (0 or 1)                                   $\n");
	fprintf(file,"$         Controls if element ordering according to edges    $\n");
	fprintf(file,"$         will be performed or not                           $\n");
	fprintf(file,"$         0: Do not perform element reordering               $\n");
	fprintf(file,"$         1: Perform element reordering                      $\n");
	fprintf(file,"$                                                            $\n");
	fprintf(file,"$ RCM   : integer (0 or 1)                                   $\n");
	fprintf(file,"$         0: Keep original mesh                              $\n");
	fprintf(file,"$         1: Perform Reverse Cuthill Mckee data reordering   $\n");
	fprintf(file,"$            to reduce matrix bandwidth                      $\n");
	fprintf(file,"$                                                            $\n");
	fprintf(file,"$ KEQ   : integer (0 or 1)                                   $\n");
	fprintf(file,"$         Equation numbering schemes                         $\n");
	fprintf(file,"$         0: Fully coupled                                   $\n");
	fprintf(file,"$         1: u-p segregated                                  $\n");
	fprintf(file,"$                                                            $\n");
	fprintf(file,"$ FMT   : integer (0 or 1)                                   $\n");
	fprintf(file,"$         0: Output data in binary format                    $\n");
	fprintf(file,"$         1: Output data in ASCII format                     $\n");
	fprintf(file,"$                                                            $\n");
	fprintf(file,"$ ANS   : integer (0 or 1)                                   $\n");
	fprintf(file,"$         0: Do not write Ansys macro file                   $\n");
	fprintf(file,"$         1: Writes Ansys macro file                         $\n");
	fprintf(file,"$                                                            $\n");
	fprintf(file,"$ PMV   : integer (0 or 1)                                   $\n");
	fprintf(file,"$         0: Do not write PMVis                              $\n");
	fprintf(file,"$         1: Writes PMVis file                               $\n");
	fprintf(file,"$                                                            $\n");
	fprintf(file,"$ LDE   : integer (0 or 1)                                   $\n");
	fprintf(file,"$         apply edge reordering to prescribed edges          $\n");
	fprintf(file,"$         0: Do not perform edge reordering                  $\n");
	fprintf(file,"$         1: Performs edge reordering                        $\n");
	fprintf(file,"$============================================================$\n"); 
	
	
	fclose(file);
}

//ESCREVE O ARQUIVO DE DADOS CORRESPONDENTE A ABA INPUT
void io::Escreve_INPUTFile(QString jobname, QDir filePath, QMap<int, Forms>, Ui::runEdgeCFDClass *ui)
{
	//***********************************************************************************************
	//******************** INICIO DA ESCRITA DO ARQUIVO ../SOLVER/INPUT.DAT ****************
	//***********************************************************************************************
	QString filename = filePath.absoluteFilePath("INPUT.DAT");
	FILE *file;
	file = fopen(filename.toAscii().constData(), "w");//, stdout);

	//fprintf(file, "# BEGIN INPUT.DAT \n" );
	fprintf(file, "%s%s", jobname.toAscii().constData(),"_1\n" );

	fprintf(file, "%d\n", ui->spinBox_input1->value());
	fprintf(file, "%d\n", ui->spinBox_input2->value());
	fprintf(file, "%d\n", ui->spinBox_input3->value());
	fprintf(file, "%8.4f %7.4f\n", ui->doubleSpinBox_input1->value(),  ui->doubleSpinBox_input2->value());

	//fprintf(file, "# END  INPUT.DAT"); 

	fclose(file);

}

//ESCREVE O ARQUIVO DE DADOS CORRESPONDENTE A ABA FSI
void io::Escreve_FSIFile(QString jobname, QDir filePath, QMap<int, Forms>,  Ui::runEdgeCFDClass *ui)
{
	//***********************************************************************************************
	//******************** INICIO DA ESCRITA DO ARQUIVO ../SOLVER/FSI.DAT ****************
	//***********************************************************************************************
	QString filename = filePath.absoluteFilePath("FSI.DAT");
	FILE *file = NULL;
	file = fopen(filename.toAscii().constData(), "w");//, stdout);

	//fprintf(file, "# BEGIN FSI.DAT \n" );
	fprintf(file, "$ Arquivo de Dados FSI: FPSO Section: roll\n\n"); 

	fprintf(file, "$  SolveFSI  (.TRUE. OR .FALSE.)\n");

	fprintf(file, "%8s\n\n", ui->comboBox_FSI->currentText().toAscii().constData());

	fprintf(file, "$  Instante de tempo de inicio do movimento da malha ALE :  START_ALE ( 1 REAL*8 )\n");
	fprintf(file, "%8.2f %8.2f\n\n", ui->doubleSpinBox_FSI_ALE1->value(),   ui->doubleSpinBox_FSI_ALE2->value());         

	fprintf(file, "$  Mass of the body  : MASSFSI ( 1 REAL*8 )      [M]\n");
	fprintf(file, "%8.2f\n\n", ui->doubleSpinBox_MASSFSI->value() ); 

	fprintf(file, "$  Center of mass : CG ( 3 REAL*8 )      [M]\n");
	fprintf(file, "%8.2f %8.2f %8.2f\n\n", 
		ui->doubleSpinBox_MassCG1->value(),
		ui->doubleSpinBox_MassCG2->value(),
		ui->doubleSpinBox_MassCG3->value());

	fprintf(file, "$  Center of rotation : CG ( 3 REAL*8 )      [M]\n");
	fprintf(file, "%8.2f %8.2f %8.2f\n\n", 
		ui->doubleSpinBox_RotationCG1->value(),
		ui->doubleSpinBox_RotationCG2->value(),
		ui->doubleSpinBox_RotationCG3->value());

	_set_output_format(_TWO_DIGIT_EXPONENT);
	fprintf(file, "$  Tensor of Inertia : X11 X12 X13 X22 X23 X33 ( 6 REAL*8 ) [M][L2]\n");
	fprintf(file, "%s %s %s %s %s %s \n\n", 
		ui->lineEdit_InertiaX11->text().toAscii().constData(),
		ui->lineEdit_InertiaX12->text().toAscii().constData(),
		ui->lineEdit_InertiaX13->text().toAscii().constData(),
		ui->lineEdit_InertiaX22->text().toAscii().constData(),
		ui->lineEdit_InertiaX23->text().toAscii().constData(),
		ui->lineEdit_InertiaX33->text().toAscii().constData());

	fprintf(file, "$  Movimentos prescritos: ngl_body(1:6) Ux Uy Uz ROTx ROTy ROTz\n"); 
	fprintf(file, "%8i %8i %8i %8i %8i %8i \n\n", 
		ui->spinBox_Ux->value(),   
		ui->spinBox_Uy->value(),
		ui->spinBox_Uz->value(),
		ui->spinBox_ROTx->value(),
		ui->spinBox_ROTy->value(),
		ui->spinBox_ROTz->value());

	fprintf(file, "$  Velocidade inicial prescritos: vx vy vz Wx Wy Wz [L/T] [1/T]\n");
	fprintf(file, "%8.2f %8.2f %8.2f %8.2f %8.2f %8.2f \n\n", 
		ui->doubleSpinBox_VInitial_vx->value(),   
		ui->doubleSpinBox_VInitial_vy->value(),
		ui->doubleSpinBox_VInitial_vz->value(),
		ui->doubleSpinBox_VInitial_Wx->value(),
		ui->doubleSpinBox_VInitial_Wy->value(),
		ui->doubleSpinBox_VInitial_Wx->value());

	fprintf(file, "$  Função prescrita: nptf < 11 [L] ou [grau]\n");
	fprintf(file, "%8i\n", ui->spinBox_nptf->value());
	fprintf(file, "%8.2f %5.2f \n", ui->doubleSpinBox_nptf11->value(),  ui->doubleSpinBox_nptf12->value());
	fprintf(file, "%8.2f %5.2f \n", ui->doubleSpinBox_nptf21->value(),  ui->doubleSpinBox_nptf22->value());
	fprintf(file, "%8.2f %5.2f \n", ui->doubleSpinBox_nptf31->value(),  ui->doubleSpinBox_nptf32->value());

	//COMENTARIO INCLUSO NO FINAL DO ARQUIVO
	fprintf(file, "\n\n$ README\n");

	fprintf(file, "NGL_BODY =  0 LIVRE PARA DESLOCAR\n");
	fprintf(file, "NGL_BODY =  1 PRESO\n");
	fprintf(file, "NGL_BODY = -1 DESLOCAMENTO PRESCRITO, EXIGE NPTF > 0\n");

	fprintf(file, "\nNPTF = PONTOS DA FUNÇÃO TEMPORAL DE DESCOLAMENTO PRESCRITO, SÓ É PERMITIDA UMA FUNÇÃO\n");
	fprintf(file, "\nNptf < 11, Só permite até 10 pares de pontos para a função ( tempo e valor )");

	//fprintf(file, "\n# END FSI.DAT"); 


	fclose(file);
}


//ESCREVE O ARQUIVO DE DADOS CORRESPENDENTE A ABA MATERIAL
void io::Escreve_MaterialFile(QString jobname, QDir filePath, QMap<int, MATERIAL> formMaterial, Ui::runEdgeCFDClass *ui)
{
	//***********************************************************************************************
	//******************** INICIO DA ESCRITA DO ARQUIVO ../SOLVER/JOBNAME_1.part.mat ****************
	//***********************************************************************************************

	if (filePath.exists())
	{

		QString filename = filePath.absoluteFilePath(jobname.toAscii() +"_1.part.mat");

		FILE *file;
		file = fopen(filename.toAscii().constData(), "w");//, stdout);

		//CABECALHO DA MENSAGEM
		//$ID    DENS   VISC      PAR3     PAR4      KXX      KYY      KZZ      SPH   NAME
		//$===============================================================================

		fprintf(file,"\n");
		fprintf(file,"$ID    DENS   VISC      PAR3     PAR4      KXX      KYY      KZZ      SPH   NAME\n");
		fprintf(file,"$===============================================================================\n");

		//PERCORENDO O VETOR MAP PARA GRAVAR NO ARQUIVO
		QString label;
		//int idTemp;



		//ESCREVENDO OS VALORES DIFERENTES DE ZERO DO CAMPO compDOF_ord
		for (int i=1; i <= formMaterial.size() ; i++)
		{
			fprintf(file, "%3d %.4f %.4f %.4f %.4f %.4f %.4f %.4f %.4f %5s \n", 
				formMaterial[i].id->value(),
				formMaterial[i].dens->value(),
				formMaterial[i].visc->value(),
				formMaterial[i].par3->value(),
				formMaterial[i].par4->value(),
				formMaterial[i].kxx->value(),
				formMaterial[i].kyy->value(),
				formMaterial[i].kzz->value(),
				formMaterial[i].sph->value(),
				formMaterial[i].name->text().toAscii().constData());


		}


		fprintf(file, "\n");

		//FECHANDO O ARQUIVO DE DADOS DE MATERIAL
		fclose(file);
	}
	else
	{
		return;
	}
	//***********************************************************************************************


}
