// scB.cpp: implementation of the scB class.
//
//////////////////////////////////////////////////////////////////////

#include "scB.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

scB::scB(uint32_t i)
{
  ir.offset=i;
  ir.link=(i>>24);
  ir.pad =(i>>25);
  ir.cond=(i>>28);
}

scB::~scB()
{

}
const char * scB::kind_string_b="B";
const char * scB::kind_string_bl="BL";
const char * scB::kind()
{
	if(ir.link==1)
	{
		return kind_string_bl;
		cout<<"link"<<endl;
	}
	else 
		return kind_string_b;
}

uint32_t scB::A()
{  

  return R_PC;
}

REGS scB::Rd()
{
  return R_PC;
}

bool scB::is_shift()
{
  return true;
}

bool scB::is_ls()
{
  return false;
}

bool scB::is_word()
{
  return true;
}

bool scB::is_mult()
{
  return false;
}

bool scB::is_rs()
{
  return false;
}

uint32_t scB::B()
{
  //24bit  offset Sign extension
  uint32_t temp=ir.offset;
  if((temp&(0x00800000))!=0)
  {
     temp=(temp|0xFF000000);
  }
  return temp;
}

uint32_t scB::dist()
{
  return 2;
}

OPCODE scB::op()
{
  return OP_ADD;
}

SHIFT scB::shift_type()
{
  return S_LSL;
}

COND scB::cond()
{
  return COND(ir.cond);
}

bool scB::is_imm()
{
  return true;
}

bool scB::wb()
{
 return ir.link;
}

REGS scB::Rn()
{
  return R_PC;
}

bool scB::pre()
{
  return 0;
}

bool scB::load()
{
  return false;
}

bool scB::is_branch()
{
 return true;
}

bool scB::set( )
{
 return false;
}

bool scB::is_link()
{
  return ir.link;
}
