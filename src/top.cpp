// top.cpp: implementation of the top class.
//
//////////////////////////////////////////////////////////////////////

#include "top.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

top::top(sc_module_name name_):sc_module(name_)
,CLK("clock1",10,0.1,1,true)
,ram("ram")
,processor("cpu")
,cp("cp")
,cp_ch("cp_ch")
//,mem_ch("mem_ch")
{
	 cp(cp_ch);
     ram(CLK,nRW,l_n_addr,l_n_data);
	 processor(CLK,nRW,l_n_addr,l_n_data);
}

top::~top()
{

}

bool top::init(char *file_name)
{
    ram.load_program(file_name);
	return true;
}
