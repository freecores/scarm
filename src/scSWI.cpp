// scSWI.cpp: implementation of the scSWI class.
//
//////////////////////////////////////////////////////////////////////

#include "scSWI.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

scSWI::scSWI(uint32_t i)
{
  ir.val=i;
  ir.pad=i>>24;
  ir.cond=i>>28;
}

scSWI::~scSWI()
{

}
const char* scSWI::kind_string="SWI";
const char* scSWI::kind(){
  return kind_string;
}

REGS scSWI::Rd()
{
  return REGS(0);
}

uint32_t scSWI::A()
{
  return 0;
}

uint32_t scSWI::B()
{
 return V_SWI;
}

OPCODE scSWI::op()
{
 return OP_CMP;
}

COND scSWI::cond()
{
 //return COND(ir.cond);
 return COND(0xf);
}

bool scSWI::pre()
{
 return false;
}

REGS scSWI::Rn()
{
  return REGS(0);
}

bool scSWI::is_imm()
{
  return true;
}

bool scSWI::is_branch()
{
 return false;
}

uint32_t scSWI::dist()
{
 return 0;
}

bool scSWI::is_ls()
{
 return false;
}

bool scSWI::is_rs()
{
 return false;
}

bool scSWI::is_shift()
{
  return false;
}

bool scSWI::is_set()
{
 return false;
}

bool scSWI::load()
{
 return false;
}

bool scSWI::is_mult()
{
 return false;
}

bool scSWI::set()
{
  return false;
}

SHIFT scSWI::shift_type()
{
 return SHIFT(0);
}

bool scSWI::wb()
{
 return false;
}

void scSWI::function()
{
   
}
