# Microsoft Developer Studio Project File - Name="scARM" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=scARM - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "scARM.mak".
!MESSAGE 
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

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "scARM - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "scARM - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GR /GX /ZI /Od /I "c:\systemc2.0\systemc-2.0\src" /I "c:\systemc2.0\systemc-2.0-MS2.0b3\src" /I "f:\cdrom1\scarm\src" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x809 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# SUBTRACT BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386
# SUBTRACT LINK32 /profile

!ENDIF 

# Begin Target

# Name "scARM - Win32 Release"
# Name "scARM - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\src\main.cpp
# End Source File
# Begin Source File

SOURCE=..\src\components\Registers\scAddressRegister.cpp
# End Source File
# Begin Source File

SOURCE=..\src\components\ALU\scALU.cpp
# End Source File
# Begin Source File

SOURCE=..\src\Instructions\scARMBranch.cpp
# End Source File
# Begin Source File

SOURCE=..\src\core\scARMCore.cpp
# End Source File
# Begin Source File

SOURCE=..\src\Instructions\scARMDPI.cpp
# End Source File
# Begin Source File

SOURCE=..\src\Instructions\scARMInstruction.cpp
# End Source File
# Begin Source File

SOURCE=..\src\Instructions\scARMLSI.cpp
# End Source File
# Begin Source File

SOURCE=..\src\Instructions\scARMMCR.cpp
# End Source File
# Begin Source File

SOURCE=..\src\Instructions\scARMMult.cpp
# End Source File
# Begin Source File

SOURCE=..\src\SoC\scARMSoC.cpp
# End Source File
# Begin Source File

SOURCE=..\src\Instructions\scARMSWP.cpp
# End Source File
# Begin Source File

SOURCE=..\src\components\barrelshifter\scBarrelShifter.cpp
# End Source File
# Begin Source File

SOURCE=..\src\components\booth\scBooth.cpp
# End Source File
# Begin Source File

SOURCE=..\src\components\cache\scCache.cpp
# End Source File
# Begin Source File

SOURCE=..\src\Instructions\scCPInstruction.cpp
# End Source File
# Begin Source File

SOURCE=..\src\components\decoder\scDecoder.cpp
# End Source File
# Begin Source File

SOURCE=..\src\pipeline\scEX.cpp
# End Source File
# Begin Source File

SOURCE=..\src\scException.cpp
# End Source File
# Begin Source File

SOURCE=..\src\pipeline\scID.cpp
# End Source File
# Begin Source File

SOURCE=..\src\pipeline\scIF.cpp
# End Source File
# Begin Source File

SOURCE=..\src\Instructions\scMCR.cpp
# End Source File
# Begin Source File

SOURCE=..\src\pipeline\scMEM.cpp
# End Source File
# Begin Source File

SOURCE=..\src\SoC\Mem\scMemory.cpp
# End Source File
# Begin Source File

SOURCE=..\src\components\mux\scPCMux.cpp
# End Source File
# Begin Source File

SOURCE=..\src\components\Registers\scRegisterFile.cpp
# End Source File
# Begin Source File

SOURCE=..\src\Instructions\scUnUsedInstruction.cpp
# End Source File
# Begin Source File

SOURCE=..\src\pipeline\scWB.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\src\main.h
# End Source File
# Begin Source File

SOURCE=..\src\components\Registers\scAddressRegister.h
# End Source File
# Begin Source File

SOURCE=..\src\components\ALU\scALU.h
# End Source File
# Begin Source File

SOURCE=..\src\Instructions\scARMBranch.h
# End Source File
# Begin Source File

SOURCE=..\src\core\scARMCore.h
# End Source File
# Begin Source File

SOURCE=..\src\Instructions\scARMDPI.h
# End Source File
# Begin Source File

SOURCE=..\src\Instructions\scARMInstruction.h
# End Source File
# Begin Source File

SOURCE=..\src\Instructions\scARMLSI.h
# End Source File
# Begin Source File

SOURCE=..\src\Instructions\scARMMCR.h
# End Source File
# Begin Source File

SOURCE=..\src\Instructions\scARMMult.h
# End Source File
# Begin Source File

SOURCE=..\src\SoC\scARMSoC.h
# End Source File
# Begin Source File

SOURCE=..\src\Instructions\scARMSWI.h
# End Source File
# Begin Source File

SOURCE=..\src\Instructions\scARMSWP.h
# End Source File
# Begin Source File

SOURCE=..\src\components\barrelshifter\scBarrelShifter.h
# End Source File
# Begin Source File

SOURCE=..\src\components\booth\scBooth.h
# End Source File
# Begin Source File

SOURCE=..\src\components\cache\scCache.h
# End Source File
# Begin Source File

SOURCE=..\src\Instructions\scCPInstruction.h
# End Source File
# Begin Source File

SOURCE=..\src\components\decoder\scDecoder.h
# End Source File
# Begin Source File

SOURCE=..\src\pipeline\scEX.h
# End Source File
# Begin Source File

SOURCE=..\src\scException.h
# End Source File
# Begin Source File

SOURCE=..\src\pipeline\scID.h
# End Source File
# Begin Source File

SOURCE=..\src\pipeline\scIF.h
# End Source File
# Begin Source File

SOURCE=..\src\Instructions\scMCR.h
# End Source File
# Begin Source File

SOURCE=..\src\pipeline\scMEM.h
# End Source File
# Begin Source File

SOURCE=..\src\SoC\Mem\scMemory.h
# End Source File
# Begin Source File

SOURCE=..\src\components\mux\scPCMux.h
# End Source File
# Begin Source File

SOURCE=..\src\components\Registers\scRegisterFile.h
# End Source File
# Begin Source File

SOURCE=..\src\scTypes.h
# End Source File
# Begin Source File

SOURCE=..\src\Instructions\scUnUsedInstruction.h
# End Source File
# Begin Source File

SOURCE=..\src\pipeline\scWB.h
# End Source File
# Begin Source File

SOURCE=..\src\core\Vectors.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Source File

SOURCE="C:\SystemC2.0\systemc-2.0\msvc60\systemc\Debug\systemc.lib"
# End Source File
# Begin Source File

SOURCE="C:\SystemC2.0\systemc-2.0-MS2.0b3\msvc60\sc_ms\Debug\sc_ms.lib"
# End Source File
# End Target
# End Project
