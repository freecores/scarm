// scSW2.h: interface for the scSW2 class.
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
#if !defined(AFX_SCSW2_H__8C326334_AB49_11D6_BB1E_000000000000__INCLUDED_)
#define AFX_SCSW2_H__8C326334_AB49_11D6_BB1E_000000000000__INCLUDED_

#include "scALU.h"	// Added by ClassView
#include "scBarrelShifter.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\SRC\scARMInstruction.h"
#include "scTypes.h"	// Added by ClassView
#include "scRegisterFile.h"	// Added by ClassView
const uint32_t SWT2_MASK =   0x0E000000;
const uint32_t SWT2_SIG  =   0x06000000;
class scSW2 : public scARMInstruction  
{

/* Single word and unsigned byte transfer - again, two formats*/
typedef struct SW2TAG
{
  uint32_t rm    : 4;
  uint32_t pad2  : 1;
  uint32_t type  : 2;
  uint32_t shift : 5;
  uint32_t rd    : 4;
  uint32_t rn    : 4;
  uint32_t ls    : 1;
  uint32_t wb    : 1; 
  uint32_t b     : 1;
  uint32_t u     : 1;
  uint32_t p     : 1;
  uint32_t hash  : 1;
  uint32_t pad   : 2;
  uint32_t cond  : 4;
} SWT2;

	SWT2 ir;
static const char* scSW2::kind_string_l ;
static const char* scSW2::kind_string_s ;
public:
	bool set();
	bool is_mult();
	bool is_branch();
	OPCODE op();
	bool is_word();
	bool is_ls();
	REGS Rn();
	bool load();
	bool wb();
	bool pre();
	uint32_t dist();
	bool is_rs();
	bool is_shift();
	COND cond();
	SHIFT shift_type();
	uint32_t B();
	bool is_imm();
	REGS Rd();
	uint32_t A();
	const char* kind();
	scSW2(uint32_t);
	virtual ~scSW2();

};

#endif // !defined(AFX_SCSW2_H__8C326334_AB49_11D6_BB1E_000000000000__INCLUDED_)
