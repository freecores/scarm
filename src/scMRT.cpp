// scMRT.cpp: implementation of the scMRT class.
//
//////////////////////////////////////////////////////////////////////

#include "scMRT.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

scMRT::scMRT(uint32_t i)
{
  ir.list=i;
  ir.rn=i>>16;
  ir.ls=i>>20;
  ir.wb=i>>21;
  ir.s=i>>22;
  ir.u=i>>23;
  ir.p=i>>24;
  ir.pad=i>>25;
  ir.cond=i>>28;
}

scMRT::~scMRT()
{

}
const char* scMRT::kind_string_l="LDM";
const char* scMRT::kind_string_s="STM";
const char* scMRT::kind()
{ 
  if(ir.ls==0)
  return kind_string_s;
  else   return kind_string_l;
}

bool scMRT::is_ls()
{
  return true;
}

bool scMRT::is_mult()
{
 return false;
}

bool scMRT::is_rs()
{
 return false;
}

bool scMRT::is_word()
{
 return true;
}

bool scMRT::is_shift()
{
 return false;
}

uint32_t scMRT::A()
{
 return ir.rn;
}

uint32_t scMRT::B()
{
 return 0;
}

COND scMRT::cond()
{
 return COND(ir.cond);
	
}

bool scMRT::pre()
{
  return ir.p;
}

OPCODE scMRT::op()
{

 	return OP_ADD;
   
}

bool scMRT::wb()
{
  return ir.wb;
}

bool scMRT::is_imm()
{
 return true;
}

SHIFT scMRT::shift_type()
{
  return SHIFT(0);
}

REGS scMRT::Rd()
{
  return REGS(0);
}

uint32_t scMRT::dist()
{
  return ir.list;
}

bool scMRT::load()
{
  return ir.ls;
}

REGS scMRT::Rn()
{
  return REGS(ir.rn);
}

bool scMRT::is_branch()
{
 return false;
}

bool scMRT::set()
{
  return ir.s;
}
bool scMRT::is_mrt()
{
  return true;
}

bool scMRT::up()
{
  return ir.u;
}
