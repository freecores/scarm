// scDP1.cpp: implementation of the scDP1 class.
//
//////////////////////////////////////////////////////////////////////

#include "scDP1.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

scDP1::scDP1(uint32_t i)
{
  ir.imm=i;
  ir.rot=(i>>8);
  ir.rd=(i>>12);
  ir.rn=(i>>16);
  ir.set=(i>>20);
  ir.opcode=(i>>21);
  ir.hash=(i>>25);
  ir.pad=(i>>26);
  ir.cond=(i>>28);
}

scDP1::~scDP1()
{

}
const char* scDP1::kind_string = "DP1";
const char* scDP1::kind()
{
  return kind_string;
}



uint32_t scDP1::A()
{
  return ir.rn;
}

uint32_t scDP1::B()
{
  return ir.imm;
}

REGS scDP1::Rd()
{
  return (REGS)ir.rd;
}

bool scDP1::is_imm()
{
  return true;
}

uint32_t scDP1::dist()
{
  return ir.rot;
}

OPCODE scDP1::op()
{
  return OPCODE(ir.opcode);
}

COND scDP1::cond()
{
  return COND(ir.cond);
}

SHIFT scDP1::shift_type()
{
  return S_ROR;
}

bool scDP1::is_shift()
{
 return true;
}

bool scDP1::is_ls()
{
 return false;
}

bool scDP1::is_rs()
{
 return false;
}

REGS scDP1::Rn()
{
 return REGS(ir.rn);
}

bool scDP1::pre()
{
 return 0;
}

bool scDP1::wb()
{
 return false;
}

bool scDP1::load()
{
 return false;
}

bool scDP1::is_mult()
{
 return false;
}

bool scDP1::set()
{
  return ir.set;
}

bool scDP1::is_branch()
{
 return false;
}
