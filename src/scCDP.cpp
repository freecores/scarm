// scCDP.cpp: implementation of the scCDP class.
//
//////////////////////////////////////////////////////////////////////

#include "scCDP.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

scCDP::scCDP(uint32_t)
{
 cout<<"CDP uncomplete"<<endl;
}

scCDP::~scCDP()
{

}
const char* scCDP::kind_string="CDP";

const char* scCDP::kind()
{
  return kind_string;
}

COND scCDP::cond()
{
 return COND(ir.cond);
}

bool scCDP::is_mult()
{
 return false;
}

bool scCDP::is_shift()
{
 return false;
}

bool scCDP::load()
{
 return false;
}

bool scCDP::pre()
{
 return false;
}

uint32_t scCDP::dist()
{
 return 0;
}

REGS scCDP::Rd()
{
 return REGS(0);
}

REGS scCDP::Rn()
{
 return REGS(0);
}

bool scCDP::is_ls()
{
 return false;
}

bool scCDP::is_rs()
{
 return true;
}

bool scCDP::is_branch()
{
 return false;
}

bool scCDP::set()
{
 return false;
}

bool scCDP::wb()
{
 return false;
}

OPCODE scCDP::op()
{
 return OPCODE(0);
}

uint32_t scCDP::A()
{
 return 0;
}

uint32_t scCDP::B()
{
 return 0;
}

SHIFT scCDP::shift_type()
{
 return SHIFT(0);
}

bool scCDP::is_imm()
{
 return true;
}
