// scMult.cpp: implementation of the scMult class.
//
//////////////////////////////////////////////////////////////////////

#include "scMult.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

scMult::scMult(uint32_t i)
{
	cout<<"uncomplete scMult"<<endl;
}

scMult::~scMult()
{

}
const char* scMult::kind_string="Multiply";
const char* scMult::kind()
{
  return kind_string;
}

uint32_t scMult::A()
{

  if(ir.set==1)
  {
	return 0;
  }else 
  {
     return ir.rn;   
  }

 
}

REGS scMult::Rd()
{
  return REGS(ir.rd);
}

bool scMult::is_mult()
{
  return true;
}

uint32_t scMult::B()
{
  return ir.rm;
}

uint32_t scMult::dist()
{
  return ir.rs;
}

bool scMult::is_rs()
{
  return true;
}


OPCODE scMult::op()
{
  return OPCODE(ir.opcode);
}
