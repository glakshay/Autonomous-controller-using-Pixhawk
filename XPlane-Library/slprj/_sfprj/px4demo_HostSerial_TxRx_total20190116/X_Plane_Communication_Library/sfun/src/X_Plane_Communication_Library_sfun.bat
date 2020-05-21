@echo off
set COMPILER=gcc
				set COMPFLAGS=-c -fexceptions -fno-omit-frame-pointer -m64 -DMATLAB_MEX_FILE  -DMATLAB_MEX_FILE  
				set OPTIMFLAGS=-O -DNDEBUG 
				set DEBUGFLAGS=-g 
				set LINKER=gcc 
				set LINKFLAGS=-m64 -Wl,--no-undefined -shared -L"C:\Program Files\MATLAB\R2016b\extern\lib\win64\mingw64" -llibmx -llibmex -llibmat -lm -llibmwlapack -llibmwblas -Wl,"C:\Program Files\MATLAB\R2016b/extern/lib/win64/mingw64/mexFunction.def" 
				set LINKDEBUGFLAGS=-g
				set NAME_OUTPUT=-o "%OUTDIR%%MEX_NAME%%MEX_EXT%"
set PATH=C:\ProgramData\MATLAB\SupportPackages\R2016b\3P.instrset\mingw_492.instrset\bin;C:\Program Files\MATLAB\R2016b\extern\include\win64;C:\Program Files\MATLAB\R2016b\extern\include;C:\Program Files\MATLAB\R2016b\simulink\include;C:\Program Files\MATLAB\R2016b\lib\win64;%MATLAB_BIN%;%PATH%
set INCLUDE=C:\ProgramData\MATLAB\SupportPackages\R2016b\3P.instrset\mingw_492.instrset\include;;%INCLUDE%
set LIB=C:\ProgramData\MATLAB\SupportPackages\R2016b\3P.instrset\mingw_492.instrset\lib;;%LIB%
set LIBPATH=C:\Program Files\MATLAB\R2016b\extern\lib\win64;%LIBPATH%

gmake SHELL="cmd" -f X_Plane_Communication_Library_sfun.gmk
