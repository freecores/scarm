///////////////////////////////////////////////////////////////////////////////
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////              
//          
//  Original Author: Allen Tao Zhong,
//  University of Electronic Science and Technology in China
//  email: zhong@opencores.org
//  info   This is a SystemC ARM model
// scSW1.cpp: implementation of the scSW1 class.
//
//////////////////////////////////////////////////////////////////////

#include "scSW1.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

scSW1::scSW1(uint32_t i)
{
   
	ir.imm=i;
	ir.rd=i>>12;
	ir.rn=i>>16;
    ir.ls=i>>20;
	ir.wb=i>>21;
  ir.b=i>>22;
  ir.u=i>>23;
  ir.p=i>>24;
  ir.hash=i>>25;
  ir.pad=i>>26;
  ir.cond=i>>28;
 
}

scSW1::~scSW1()
{

}
const char* scSW1::kind_string_l = "LDR";
const char* scSW1::kind_string_s = "STR";
const char* scSW1::kind()
{ 
	if(ir.ls)
         return kind_string_l;
	else 
		 return kind_string_s;
}

uint32_t scSW1::A()
{

   return ir.rn;
}

REGS scSW1::Rd()
{
 return REGS(ir.rd);
}

uint32_t scSW1::B()
{
   return ir.imm;	

}

bool scSW1::is_imm()
{
 return true;
}

OPCODE scSW1::op()
{
   if(ir.u==0)
        return OP_SUB;
   else
        return OP_ADD;
}

COND scSW1::cond()
{
  return COND(ir.cond);
}

SHIFT scSW1::shift_type()
{
 return SHIFT(0);
}

uint32_t scSW1::dist()
{
 return 0;
}

bool scSW1::is_shift()
{
  return false;
}

bool scSW1::pre()
{
 return ir.p;
}

bool scSW1::load()
{
 return ir.ls;
}

bool scSW1::wb()
{
  return ir.wb;
}

REGS scSW1::Rn()
{
  return REGS(ir.rn);
}

bool scSW1::is_mult()
{
  return false;
}


bool scSW1::is_ls()
{
  return true;
}

bool scSW1::is_rs()
{
  return false;
}

bool scSW1::is_branch()
{
 return false;
}

bool scSW1::set()
{
 return false;
}
