// scSW2.cpp: implementation of the scSW1 class.
/*                            -------------------
    begin                : Oct 2 2002
    copyright            : (C) 2002 UESTC 
    author               : Zhong Tao
    email                : zhong@opencores.org
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#include "scSW2.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

scSW2::scSW2(uint32_t i)
{
  ir.rm=i;
  ir.pad2=i>>4;
  ir.type=i>>5;
  ir.shift=i>>7;
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

scSW2::~scSW2()
{

}
const char* scSW2::kind_string_l = "LDR";
const char* scSW2::kind_string_s = "STR";
const char* scSW2::kind()
{ 
	if(ir.ls)
         return kind_string_l;
	else 
		 return kind_string_s;
}

uint32_t scSW2::A()
{
  return ir.rn;
}

REGS scSW2::Rd()
{
 return REGS(ir.rd);
}

bool scSW2::is_imm()
{
 return ir.hash;
}

uint32_t scSW2::B()
{
  return ir.rm;
}

SHIFT scSW2::shift_type()
{
  return SHIFT(ir.type);
}

COND scSW2::cond()
{
  return COND(ir.cond);
}

bool scSW2::is_shift()
{
  return true;
}

bool scSW2::is_rs()
{
  return true;
}

uint32_t scSW2::dist()
{
  return ir.shift;
}

bool scSW2::pre()
{
 return ir.p;
}

bool scSW2::wb()
{
 return ir.wb;
}

bool scSW2::load()
{
  return ir.ls;
}

REGS scSW2::Rn()
{
 return REGS(ir.rn);
}

bool scSW2::is_ls()
{
  return true;
}

bool scSW2::is_word()
{
  return !(ir.b);//byte or word
}

OPCODE scSW2::op()
{
	if(ir.u==0)
	{
        return OP_SUB;
	}else
		return OP_ADD;

}

bool scSW2::is_branch()
{
  return false;
}

bool scSW2::is_mult()
{
  return false;
}

bool scSW2::set()
{
  return false;
}
