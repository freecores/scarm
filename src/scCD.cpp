// scCD.cpp: implementation of the scCD class.
//
//////////////////////////////////////////////////////////////////////

#include "scCD.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

scCD::scCD(uint32_t)
{
	cout<<"uncomplete scCD ";

}

scCD::~scCD()
{

}
const char* scCD::kind_string="CD";
const char* scCD::kind()
{
  return kind_string;
}

SHIFT scCD::shift_type()
{
  return SHIFT(0);
}

bool scCD::is_mult()
{
  return false;
}

bool scCD::is_shift()
{
 return false;

}

bool scCD::is_imm()
{
 return false;
}

uint32_t scCD::A()
{
 return 0;
}

uint32_t scCD::B()
{
 return 0;
}

bool scCD::pre()
{
 return false;
}

bool scCD::is_branch()
{
 return false;
}

REGS scCD::Rd()
{
 return REGS(0);
}

REGS scCD::Rn()
{
 return REGS(0);
}

bool scCD::is_ls()
{
 return false;
}

uint32_t scCD::dist()
{
 return 0;
}

COND scCD::cond()
{
 return COND(0);
}

bool scCD::wb()
{
return false;
}

bool scCD::load()
{
 return false;
}

OPCODE scCD::op()
{
 return OPCODE(0);
}

bool scCD::is_rs()
{
 return true;
}

bool scCD::set()
{
 return false;
}
