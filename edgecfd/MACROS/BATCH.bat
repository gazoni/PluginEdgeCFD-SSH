@echo off
rem Gets rid of confirmation "Batch completed" dialog box
rem
set ANS_CONSEC=YES
rem Sets ANSYS 120 environment variables
rem
set ANSYS_DIR=C:\Program Files\ANSYS Inc\v130\ansys\bin\winx64
set ANSYS_EXE=ansys130
set ANSYS_MACRO=open.mac
set JOBNAME=jobname_sample
set OUTPUT=..\ansys\output.txt
rem Change working directory
rem

rem Starts ANSYS in working directory
rem Use -s option to read/noread start55.ans file
rem Use -m and -db options to define memory requirements
rem
"%ANSYS_DIR%\%ANSYS_EXE%" -b -i %ANSYS_MACRO% -j %JOBNAME% -o %OUTPUT%

REM -----------------end input------------------------


rem C:\Users\kadu\Documents\coppe\lixo\teste\ansys\MODEL-001\MODEL-001\MACROS>"C:\Program Files\ANSYS Inc\v120\ansys\bin\winx64\ansys120" -b -i open.mac -j jobname_sample -o ..\ansys\output.txt