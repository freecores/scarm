// scB.h: interface for the scB class.
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

#if !defined(AFX_SCB_H__FC5E6447_AB29_11D6_BB1E_000000000000__INCLUDED_)
#define AFX_SCB_H__FC5E6447_AB29_11D6_BB1E_000000000000__INCLUDED_

#include "scRegisterFile.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "scARMInstruction.h"
#include "scTypes.h"	// Added by ClassView
#include "scALU.h"	// Added by ClassView
#include "scBarrelShifter.h"	// Added by ClassView
const uint32_t BRANCH_MASK= 0x0E000000;//branch and bl
const uint32_t BRANCH_SIG=  0x0A000000;
class scB  :public scARMInstruction
{
	typedef struct BLTAG
{
  uint32_t offset : 24;
  uint32_t   link   : 1;
  uint32_t pad    : 3;
  uint32_t cond   : 4;
} BRANCH;
	static const char* kind_string_b;
	static const char* kind_string_bl;
	BRANCH ir;
public:
	bool is_link();
	bool set();
	bool is_branch();
	bool load();
	bool pre();
	REGS Rn();
	bool wb();
	bool is_imm();
	COND cond();
	SHIFT shift_type();
	OPCODE op();
	uint32_t dist();
	uint32_t B();
	bool is_rs();
	bool is_mult();
	bool is_word();
	bool is_ls();
	bool is_shift();
	REGS Rd();
	uint32_t A();
	const char* kind();
	scB(uint32_t);
	virtual ~scB();

};

#endif // !defined(AFX_SCB_H__FC5E6447_AB29_11D6_BB1E_000000000000__INCLUDED_)
