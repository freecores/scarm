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
// scNOOP.cpp: implementation of the scNOOP class.
//
//////////////////////////////////////////////////////////////////////

#include "scNOOP.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

scNOOP::scNOOP()
{
  scNOOP(0xe1a00000);
}
scNOOP::scNOOP(uint32_t i)
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
const char* scNOOP::kind_string = "NOP";
scNOOP::~scNOOP()
{

}

const char* scNOOP::kind()
{
  return kind_string;
}

bool scNOOP::is_mult()
{
 return false;
}

bool scNOOP::is_shift()
{
 return false;
}

OPCODE scNOOP::op()
{
 return OP_MOV;
}

REGS scNOOP::Rd()
{
  return REGS(0);
}

REGS scNOOP::Rn()
{
 return REGS(0);
}

bool scNOOP::is_ls()
{
  return false;
}

uint32_t scNOOP::dist()
{
 return 0;
}

uint32_t scNOOP::A()
{
  return 0;
}

uint32_t scNOOP::B()
{
  return 0;
}

bool scNOOP::pre()
{
  return false;
}

bool scNOOP::load()
{
 return false;
}

bool scNOOP::wb()
{
 return false;
}

COND scNOOP::cond()
{
  return C_AL;
}

SHIFT scNOOP::shift_type()
{
 return SHIFT(0);
}

bool scNOOP::is_imm()
{
 return false;
}

bool scNOOP::is_rs()
{
 return false;
}

bool scNOOP::is_branch()
{
 return false;
}

bool scNOOP::set()
{
  return false;
}
