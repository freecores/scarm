# Microsoft Developer Studio Generated NMAKE File, Based on scARM.dsp
!IF "$(CFG)" == ""
CFG=scARM - Win32 Debug
!MESSAGE No configuration specified. Defaulting to scARM - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "scARM - Win32 Release" && "$(CFG)" != "scARM - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "scARM.mak" CFG="scARM - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "scARM - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "scARM - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "scARM - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\scARM.exe"


CLEAN :
	-@erase "$(INTDIR)\main.obj"
	-@erase "$(INTDIR)\scAddressRegister.obj"
	-@erase "$(INTDIR)\scALU.obj"
	-@erase "$(INTDIR)\scARMBranch.obj"
	-@erase "$(INTDIR)\scARMCore.obj"
	-@erase "$(INTDIR)\scARMDPI.obj"
	-@erase "$(INTDIR)\scARMInstruction.obj"
	-@erase "$(INTDIR)\scARMLSI.obj"
	-@erase "$(INTDIR)\scARMMCR.obj"
	-@erase "$(INTDIR)\scARMMult.obj"
	-@erase "$(INTDIR)\scARMSoC.obj"
	-@erase "$(INTDIR)\scARMSWP.obj"
	-@erase "$(INTDIR)\scBarrelShifter.obj"
	-@erase "$(INTDIR)\scBooth.obj"
	-@erase "$(INTDIR)\scCache.obj"
	-@erase "$(INTDIR)\scCPInstruction.obj"
	-@erase "$(INTDIR)\scDecoder.obj"
	-@erase "$(INTDIR)\scEX.obj"
	-@erase "$(INTDIR)\scException.obj"
	-@erase "$(INTDIR)\scID.obj"
	-@erase "$(INTDIR)\scIF.obj"
	-@erase "$(INTDIR)\scMCR.obj"
	-@erase "$(INTDIR)\scMEM.obj"
	-@erase "$(INTDIR)\scMemory.obj"
	-@erase "$(INTDIR)\scPCMux.obj"
	-@erase "$(INTDIR)\scRegisterFile.obj"
	-@erase "$(INTDIR)\scUnUsedInstruction.obj"
	-@erase "$(INTDIR)\scWB.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\scARM.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\scARM.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\scARM.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\scARM.pdb" /machine:I386 /out:"$(OUTDIR)\scARM.exe" 
LINK32_OBJS= \
	"$(INTDIR)\main.obj" \
	"$(INTDIR)\scAddressRegister.obj" \
	"$(INTDIR)\scALU.obj" \
	"$(INTDIR)\scARMBranch.obj" \
	"$(INTDIR)\scARMCore.obj" \
	"$(INTDIR)\scARMDPI.obj" \
	"$(INTDIR)\scARMInstruction.obj" \
	"$(INTDIR)\scARMLSI.obj" \
	"$(INTDIR)\scARMMCR.obj" \
	"$(INTDIR)\scARMMult.obj" \
	"$(INTDIR)\scARMSoC.obj" \
	"$(INTDIR)\scARMSWP.obj" \
	"$(INTDIR)\scBarrelShifter.obj" \
	"$(INTDIR)\scBooth.obj" \
	"$(INTDIR)\scCache.obj" \
	"$(INTDIR)\scCPInstruction.obj" \
	"$(INTDIR)\scDecoder.obj" \
	"$(INTDIR)\scEX.obj" \
	"$(INTDIR)\scException.obj" \
	"$(INTDIR)\scID.obj" \
	"$(INTDIR)\scIF.obj" \
	"$(INTDIR)\scMCR.obj" \
	"$(INTDIR)\scMEM.obj" \
	"$(INTDIR)\scMemory.obj" \
	"$(INTDIR)\scPCMux.obj" \
	"$(INTDIR)\scRegisterFile.obj" \
	"$(INTDIR)\scUnUsedInstruction.obj" \
	"$(INTDIR)\scWB.obj" \
	"C:\SystemC2.0\systemc-2.0\msvc60\systemc\Debug\systemc.lib" \
	"C:\SystemC2.0\systemc-2.0-MS2.0b3\msvc60\sc_ms\Debug\sc_ms.lib"

"$(OUTDIR)\scARM.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "scARM - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\scARM.exe"


CLEAN :
	-@erase "$(INTDIR)\main.obj"
	-@erase "$(INTDIR)\scAddressRegister.obj"
	-@erase "$(INTDIR)\scALU.obj"
	-@erase "$(INTDIR)\scARMBranch.obj"
	-@erase "$(INTDIR)\scARMCore.obj"
	-@erase "$(INTDIR)\scARMDPI.obj"
	-@erase "$(INTDIR)\scARMInstruction.obj"
	-@erase "$(INTDIR)\scARMLSI.obj"
	-@erase "$(INTDIR)\scARMMCR.obj"
	-@erase "$(INTDIR)\scARMMult.obj"
	-@erase "$(INTDIR)\scARMSoC.obj"
	-@erase "$(INTDIR)\scARMSWP.obj"
	-@erase "$(INTDIR)\scBarrelShifter.obj"
	-@erase "$(INTDIR)\scBooth.obj"
	-@erase "$(INTDIR)\scCache.obj"
	-@erase "$(INTDIR)\scCPInstruction.obj"
	-@erase "$(INTDIR)\scDecoder.obj"
	-@erase "$(INTDIR)\scEX.obj"
	-@erase "$(INTDIR)\scException.obj"
	-@erase "$(INTDIR)\scID.obj"
	-@erase "$(INTDIR)\scIF.obj"
	-@erase "$(INTDIR)\scMCR.obj"
	-@erase "$(INTDIR)\scMEM.obj"
	-@erase "$(INTDIR)\scMemory.obj"
	-@erase "$(INTDIR)\scPCMux.obj"
	-@erase "$(INTDIR)\scRegisterFile.obj"
	-@erase "$(INTDIR)\scUnUsedInstruction.obj"
	-@erase "$(INTDIR)\scWB.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\scARM.exe"
	-@erase "$(OUTDIR)\scARM.ilk"
	-@erase "$(OUTDIR)\scARM.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MLd /W3 /Gm /GR /GX /ZI /Od /I "c:\systemc2.0\systemc-2.0\src" /I "c:\systemc2.0\systemc-2.0-MS2.0b3\src" /I "f:\cdrom1\scarm\src" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\scARM.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/o"$(OUTDIR)\scARM.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\scARM.pdb" /debug /machine:I386 /out:"$(OUTDIR)\scARM.exe" 
LINK32_OBJS= \
	"$(INTDIR)\main.obj" \
	"$(INTDIR)\scAddressRegister.obj" \
	"$(INTDIR)\scALU.obj" \
	"$(INTDIR)\scARMBranch.obj" \
	"$(INTDIR)\scARMCore.obj" \
	"$(INTDIR)\scARMDPI.obj" \
	"$(INTDIR)\scARMInstruction.obj" \
	"$(INTDIR)\scARMLSI.obj" \
	"$(INTDIR)\scARMMCR.obj" \
	"$(INTDIR)\scARMMult.obj" \
	"$(INTDIR)\scARMSoC.obj" \
	"$(INTDIR)\scARMSWP.obj" \
	"$(INTDIR)\scBarrelShifter.obj" \
	"$(INTDIR)\scBooth.obj" \
	"$(INTDIR)\scCache.obj" \
	"$(INTDIR)\scCPInstruction.obj" \
	"$(INTDIR)\scDecoder.obj" \
	"$(INTDIR)\scEX.obj" \
	"$(INTDIR)\scException.obj" \
	"$(INTDIR)\scID.obj" \
	"$(INTDIR)\scIF.obj" \
	"$(INTDIR)\scMCR.obj" \
	"$(INTDIR)\scMEM.obj" \
	"$(INTDIR)\scMemory.obj" \
	"$(INTDIR)\scPCMux.obj" \
	"$(INTDIR)\scRegisterFile.obj" \
	"$(INTDIR)\scUnUsedInstruction.obj" \
	"$(INTDIR)\scWB.obj" \
	"C:\SystemC2.0\systemc-2.0\msvc60\systemc\Debug\systemc.lib" \
	"C:\SystemC2.0\systemc-2.0-MS2.0b3\msvc60\sc_ms\Debug\sc_ms.lib"

"$(OUTDIR)\scARM.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("scARM.dep")
!INCLUDE "scARM.dep"
!ELSE 
!MESSAGE Warning: cannot find "scARM.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "scARM - Win32 Release" || "$(CFG)" == "scARM - Win32 Debug"
SOURCE=..\src\main.cpp

"$(INTDIR)\main.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\src\components\Registers\scAddressRegister.cpp

"$(INTDIR)\scAddressRegister.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\src\components\ALU\scALU.cpp

"$(INTDIR)\scALU.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\src\Instructions\scARMBranch.cpp

"$(INTDIR)\scARMBranch.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\src\core\scARMCore.cpp

"$(INTDIR)\scARMCore.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\src\Instructions\scARMDPI.cpp

"$(INTDIR)\scARMDPI.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\src\Instructions\scARMInstruction.cpp

"$(INTDIR)\scARMInstruction.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\src\Instructions\scARMLSI.cpp

"$(INTDIR)\scARMLSI.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\src\Instructions\scARMMCR.cpp

"$(INTDIR)\scARMMCR.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\src\Instructions\scARMMult.cpp

"$(INTDIR)\scARMMult.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\src\SoC\scARMSoC.cpp

"$(INTDIR)\scARMSoC.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\src\Instructions\scARMSWP.cpp

"$(INTDIR)\scARMSWP.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\src\components\barrelshifter\scBarrelShifter.cpp

"$(INTDIR)\scBarrelShifter.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\src\components\booth\scBooth.cpp

"$(INTDIR)\scBooth.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\src\components\cache\scCache.cpp

"$(INTDIR)\scCache.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\src\Instructions\scCPInstruction.cpp

"$(INTDIR)\scCPInstruction.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\src\components\decoder\scDecoder.cpp

"$(INTDIR)\scDecoder.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\src\pipeline\scEX.cpp

"$(INTDIR)\scEX.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\src\scException.cpp

"$(INTDIR)\scException.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\src\pipeline\scID.cpp

"$(INTDIR)\scID.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\src\pipeline\scIF.cpp

"$(INTDIR)\scIF.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\src\Instructions\scMCR.cpp

"$(INTDIR)\scMCR.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\src\pipeline\scMEM.cpp

"$(INTDIR)\scMEM.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\src\SoC\Mem\scMemory.cpp

"$(INTDIR)\scMemory.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\src\components\mux\scPCMux.cpp

"$(INTDIR)\scPCMux.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\src\components\Registers\scRegisterFile.cpp

"$(INTDIR)\scRegisterFile.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\src\Instructions\scUnUsedInstruction.cpp

"$(INTDIR)\scUnUsedInstruction.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\src\pipeline\scWB.cpp

"$(INTDIR)\scWB.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)



!ENDIF 

