// sc_mem_if.cpp: implementation of the sc_mem_if class.
//
//////////////////////////////////////////////////////////////////////

#include "sc_mem_if.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

sc_mem_if::sc_mem_if()
{

}

sc_mem_if::~sc_mem_if()
{

}

uint32_t sc_mem_if::read_mem(uint32_t addr)
{
   uint32_t d=0;
   cout<<"pls design channel "<<endl;
   return d;
}

bool sc_mem_if::write_mem(uint32_t addr,uint32_t data)
{
	cout<<"pls design channel "<<endl;
	return true;

}
