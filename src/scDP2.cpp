// scDP2.cpp: implementation of the scDP2 class.
//
//////////////////////////////////////////////////////////////////////

#include "scDP2.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

scDP2::scDP2(uint32_t i)
{
  ir.rm=i;
  ir.pad2=(i>>4);
  ir.type=(i>>5);
  ir.shift=(i>>7);
  ir.rd=(i>>12);
  ir.rn=(i>>16);
  ir.set=(i>>20);
  ir.opcode=(i>>21);
  ir.hash=(i>>25);
  ir.pad=(i>>26);
  ir.cond=(i>>28);

}

scDP2::~scDP2()
{

}
const char* scDP2::kind_string = "DP2";
const char* scDP2::kind()
{
  return kind_string;
}

uint32_t scDP2::A()
{
  return ir.rn;
}

uint32_t scDP2::B()
{
  return ir.rm;
}

REGS scDP2::Rd()
{
   return REGS(ir.rd);
}

bool scDP2::is_imm()
{
  return false;
}

uint32_t scDP2::dist()
{
  return ir.shift;
}

bool scDP2::is_rs()
{
  return false;
}

OPCODE scDP2::op()
{

	uint32_t m=ir.opcode;
	
  return OPCODE(ir.opcode);

}

COND scDP2::cond()
{

  return COND(ir.cond);
}

SHIFT scDP2::shift_type()
{
  return SHIFT(ir.type);
}

bool scDP2::is_shift()
{
 return true;
}

REGS scDP2::Rn()
{
 return REGS(ir.rn);
}

bool scDP2::is_ls()
{
 return false;
}

bool scDP2::is_mult()
{
 return false;
}

bool scDP2::load()
{
 return false;
}

bool scDP2::wb()
{
 return false;
}

bool scDP2::pre()
{
  return false;
}

bool scDP2::is_branch()
{
 return false;
}

bool scDP2::set()
{
 return ir.set;
}
