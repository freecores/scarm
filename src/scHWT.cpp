// scHWT.cpp: implementation of the scHWT class.
//
//////////////////////////////////////////////////////////////////////

#include "scHWT.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

scHWT::scHWT(uint32_t i)
{
	cout<<"uncomplete scHWT"<<endl;
}

scHWT::~scHWT()
{

}
const char* scHWT::kind_string = "HWT";
const char* scHWT::kind()
{
  return kind_string;
}

uint32_t scHWT::A()
{
  return ir.rn;
}

REGS scHWT::Rd()
{
  return REGS(ir.rd);
}

uint32_t scHWT::B()
{
  return ir.rm;
}
