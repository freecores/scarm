// scSWI.h: interface for the scSWI class.
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
#if !defined(AFX_SCSWI_H__8C326336_AB49_11D6_BB1E_000000000000__INCLUDED_)
#define AFX_SCSWI_H__8C326336_AB49_11D6_BB1E_000000000000__INCLUDED_

#include "scTypes.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\SRC\scARMInstruction.h"
#include "scRegisterFile.h"	// Added by ClassView
#include "scALU.h"	// Added by ClassView
#include "scBarrelShifter.h"	// Added by ClassView
const uint32_t SWI_MASK  =  0x0F000000;
const uint32_t SWI_SIG  =   0x0F000000;
//enum VECTOR {V_RESET = 0x00, V_UNDEF = 0x04, V_SWI = 0x08, V_PABORT = 0x0C, 
//	     V_DABORT = 0x10, V_IRQ = 0x18, V_FIQ = 0x1C};
const uint32_t V_SWI=0x08;
class scSWI : public scARMInstruction  
{
/* Software interrupt */
typedef struct SWITAG
{
  uint32_t val  : 24;
  uint32_t pad  : 4;
  uint32_t cond : 4;
} SWI;

SWI ir;
  static const char* kind_string;
public:
	void function();
	bool wb();
	SHIFT shift_type();
	bool set();
	bool is_mult();
	bool load();
	bool is_set();
	bool is_shift();
	bool is_rs();
	bool is_ls();
	uint32_t dist();
	bool is_branch();
	bool is_imm();
	REGS Rn();
	bool pre();
	COND cond();
	OPCODE op();
	uint32_t B();
	uint32_t A();
	REGS Rd();
	const char* kind();
	scSWI(uint32_t);
	virtual ~scSWI();

};

#endif // !defined(AFX_SCSWI_H__8C326336_AB49_11D6_BB1E_000000000000__INCLUDED_)
