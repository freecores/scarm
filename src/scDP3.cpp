// scDP3.cpp: implementation of the scDP3 class.
//
//////////////////////////////////////////////////////////////////////

#include "scDP3.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

scDP3::scDP3(uint32_t i)
{
  ir.rm=i;
  ir.pad3=i>>4;
  ir.type=i>>5;
  ir.pad2=i>>7;
  ir.rs=i>>8;
  ir.rd=i>>12;
  ir.rn=i>>16;
  ir.set=i>>20;
  ir.opcode=i>>21;
  ir.hash=i>>25;
  ir.pad=i>>26;
  ir.cond=i>>28;
  
}

scDP3::~scDP3()
{

}
const char* scDP3::kind_string = "DP3";
const char* scDP3::kind()
{
  return kind_string;
}

uint32_t scDP3::A()
{
  return ir.rn;
}

REGS scDP3::Rd()
{
  return REGS(ir.rd);
}

bool scDP3::is_imm()
{
  return false;
}

bool scDP3::is_rs()
{
  return true;
}

OPCODE scDP3::op()
{
  return OPCODE(ir.opcode);
}

COND scDP3::cond()
{
  return COND(ir.cond);
}

SHIFT scDP3::shift_type()
{
 return SHIFT(ir.type);
}

bool scDP3::is_shift()
{
 return true;
}

uint32_t scDP3::B()
{
  return ir.rm;
}

bool scDP3::is_ls()
{
 return false;
}

uint32_t scDP3::dist()
{
 return ir.rs;
}

bool scDP3::is_mult()
{
return false;
}

REGS scDP3::Rn()
{
 return REGS(ir.rn);
}

bool scDP3::pre()
{
return 0;
}

bool scDP3::load()
{
 return false;
}

bool scDP3::is_wb()
{
 return true;
}

bool scDP3::wb()
{
  return false;
}

bool scDP3::set()
{
 return ir.set;
}

bool scDP3::is_branch()
{
  return false;
}
