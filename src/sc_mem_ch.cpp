// sc_mem_ch.cpp: implementation of the sc_mem_ch class.
//
//////////////////////////////////////////////////////////////////////

#include "sc_mem_ch.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
bool sc_mem_ch::write_mem(uint32_t addr,uint32_t data)
{
    nRW=1;
    A=addr;
	D=data;
 return true;

}
uint32_t sc_mem_ch::read_mem(uint32_t addr)
{

    nRW=0;
	cout<<"read & mem"<<endl;
    A=addr;
	cout<<"return data"<<endl;
	return data;

}
sc_mem_ch::sc_mem_ch(sc_module_name name_):sc_module(name_)
{

         SC_SLAVE(read,D);
	
}

sc_mem_ch::~sc_mem_ch()
{

}



void sc_mem_ch::read()
{
	cout<<"data deliver"<<endl;
       data=D;
}
