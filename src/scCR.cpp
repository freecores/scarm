// scCR.cpp: implementation of the scCR class.
//
//////////////////////////////////////////////////////////////////////

#include "scCR.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

scCR::scCR(uint32_t i)
{
	cout<<"uncomplete scCR "<<endl;
}

scCR::~scCR()
{

}
const char* scCR::kind_string="CR";
const char* scCR::kind()
{
  return kind_string;
}

bool scCR::is_mult()
{
  return false;
}

bool scCR::is_shift()
{
 return false;
}

REGS scCR::Rd()
{
  return REGS(0);
}

bool scCR::is_ls()
{
  return false;
}

bool scCR::is_rs()
{
 return false;
}

REGS scCR::Rn()
{
 return REGS(0);
}

COND scCR::cond()
{
 return COND(0);
}

bool scCR::wb()
{
 return false;
}

bool scCR::pre()
{
 return false;
}

bool scCR::is_imm()
{
 return false;
}

uint32_t scCR::A()
{
 return 0;
}

uint32_t scCR::B()
{
 return 0;
}
