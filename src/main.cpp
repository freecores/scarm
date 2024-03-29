/***************************************************************************
                          main.cpp  -  description
                             -------------------
    begin                : Oct 2 2002
    copyright            : (C) 2002 UESTC 
    author               : Zhong Tao
    email                : zhong@opencores.org
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#include <systemc.h>
#include "top.h"

int sc_main(int argc,char* argv[])
{
    cout<<"********************************************"<<endl;
	cout<<"*    scARM:A GNU SystemC ARM Simulator!    *"<<endl;
	cout<<"*         author:Zhong Tao                 *"<<endl;
	cout<<"*       email	zhong@opencores.org       *"<<endl;
    cout<<"********************************************"<<endl;

	char *prog_name = NULL;
    top  board("board");

	for(int i = 1; i < argc; i++)
	{
	
			prog_name = argv[i];
 
	}
	
	if(prog_name)
	{

        board.init(prog_name);//load program
		sc_start(-1);


	}
	else
	{
		cout<<"  usage : scARM <file name> <args...>"<<endl;
		cout<<"  file name : a program to execute"<<endl;
		cout<<"  Note:Program should be plain bianery format."<<endl;
		cout<<"  args : arguments to the file"<<endl;
	}
	return 0;

}