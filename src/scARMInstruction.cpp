// scARMInstruction.cpp: implementation of the scARMInstruction class.
//
//////////////////////////////////////////////////////////////////////
#include <systemc.h>
#include "scARMInstruction.h"
//#ilcude "scRegisterFile.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

scARMInstruction::scARMInstruction()
{
   
}

scARMInstruction::~scARMInstruction()
{

}
const char* scARMInstruction::kind_string="ARMInstruction" ;
const char* scARMInstruction::kind()
{
   return kind_string;
}

uint32_t scARMInstruction::A()
{
	//return Rn
   cout<<"you should re-design your A() in sub class."<<endl;
   return 0;
}
   
uint32_t scARMInstruction::B()
{
	//return Rm
   cout<<"you should re-design your B() in sub class."<<endl;
   return 0;
}

REGS scARMInstruction::Rd()
{
   cout<<"you should re-design your Rd() in sub class."<<endl;
   return REGS(0);
}

OPCODE scARMInstruction::op()
{
    cout<<"you should re-design your op() in sub class."<<endl;
	return OPCODE(4);
}

COND scARMInstruction::cond()
{
     cout<<"you should re-design your cond() in sub class."<<endl;
	return C_AL;
}

SHIFT scARMInstruction::shift_type()
{
    cout<<"you should re-design your shift_type() in sub class."<<endl;
	return SHIFT(0);
}

uint32_t scARMInstruction::dist()
{
	//return rs
    cout<<"you should re-design your dist() in sub class."<<endl;
	return 0;
}

bool scARMInstruction::is_imm()
{
    cout<<"you should re-design your is_imm() in sub class."<<endl;
	return true;

}

bool scARMInstruction::is_rs()
{
	 cout<<"you should re-design your is_rs() in sub class."<<endl;
   return false;
}

bool scARMInstruction::is_mult()
{
	 cout<<"you should re-design your is_mult() in sub class."<<endl;
   return false;
}

bool scARMInstruction::is_shift()
{
	 cout<<"you should re-design your is_shift() in sub class."<<endl;
  return false;
}

bool scARMInstruction::pre()
{
	   cout<<"you should re-design your pre() in sub class."<<endl;
  return 0;
}

bool scARMInstruction::wb()
{
	   cout<<"you should re-design your wb() in sub class."<<endl;
  return true;
}

bool scARMInstruction::load()
{
	   cout<<"you should re-design your load() in sub class."<<endl;
  return 0;
}

REGS scARMInstruction::Rn()
{
		   cout<<"you should re-design your Rn() in sub class."<<endl;
  return REGS(0);
}

bool scARMInstruction::is_word()
{
		   cout<<"you should re-design your is_word() in sub class."<<endl;
  return true;
}

bool scARMInstruction::is_ls()
{
 cout<<"you should re-design your is_ls() load/store in sub class."<<endl;
   return false;
}

bool scARMInstruction::is_branch()
{
 cout<<"you should re-design your is_branch() in sub class."<<endl;
   return false;
}

bool scARMInstruction::set()
{
	 cout<<"you should re-design your set() in sub class."<<endl;
  return false;
}

bool scARMInstruction::is_link()
{
   return false;
}
bool scARMInstruction::is_mrt()
{

  return false;
}

bool scARMInstruction::up()
{
 return 1;
}
