// scARMInstruction.h: interface for the scARMInstruction class.
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
#if !defined(AFX_SCARMINSTRUCTION_H__9BF2A924_AA7B_11D6_BB1A_000000000000__INCLUDED_)
#define AFX_SCARMINSTRUCTION_H__9BF2A924_AA7B_11D6_BB1A_000000000000__INCLUDED_

#include "scBarrelShifter.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "scTypes.h"
#include "scRegisterFile.h"	// Added by ClassView
#include "scALU.h"	// Added by ClassView
#include "scBarrelShifter.h"
// used to package the different behavoir of the different instruciton.


class scARMInstruction  
{
   
	static const char* kind_string;
public:
	virtual bool up();
	virtual bool is_link();
	virtual bool is_mrt();
	virtual bool set();
	virtual bool is_branch();
	virtual bool is_ls();
	virtual bool is_word();
	virtual REGS Rn();
	virtual bool load();
	virtual bool wb();
	virtual bool pre();
	virtual bool is_shift();
	virtual bool is_mult();
	virtual bool is_rs();
	virtual bool is_imm();
	virtual uint32_t dist(); //return rs
	virtual enum SHIFT shift_type();
	virtual COND cond();
	virtual OPCODE op();
	virtual REGS Rd();
	virtual uint32_t B();//return rn
	virtual uint32_t A();//return rm
	virtual const char* kind();
    scARMInstruction();
	virtual ~scARMInstruction();

};

#endif // !defined(AFX_SCARMINSTRUCTION_H__9BF2A924_AA7B_11D6_BB1A_000000000000__INCLUDED_)
