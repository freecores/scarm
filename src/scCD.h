// scCD.h: interface for the scCD class.
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
#if !defined(AFX_SCCD_H__7F1E5936_AE4E_11D6_BB28_000000000000__INCLUDED_)
#define AFX_SCCD_H__7F1E5936_AE4E_11D6_BB28_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\SRC\scARMInstruction.h"
#include "scBarrelShifter.h"	// Added by ClassView
#include "scTypes.h"	// Added by ClassView
#include "scRegisterFile.h"	// Added by ClassView
#include "scALU.h"	// Added by ClassView

const uint32_t CDT_MASK=     0x0E000000;
const uint32_t CDT_SIG  =    0x0C000000;
class scCD : public scARMInstruction  
{
	/* Coprocessor data transfers */
typedef struct CDTAG
{
  uint32_t offset : 8;
  uint32_t cpn    : 4;
  uint32_t crd    : 4;
  uint32_t rn     : 4;
  uint32_t ls     : 1;
  uint32_t wb     : 1;
  uint32_t n      : 1;
  uint32_t u      : 1;
  uint32_t p      : 1;
  uint32_t pad    : 3;
  uint32_t cond   : 4;
} CDT;
  CDT ir;
  static const char* kind_string;
public:
	bool set();
	bool is_rs();
	OPCODE op();
	bool load();
	bool wb();
	COND cond();
	uint32_t dist();
	bool is_ls();
	REGS Rn();
	REGS Rd();
	bool is_branch();
	bool pre();
	uint32_t B();
	uint32_t A();
	bool is_imm();
	bool is_shift();
	bool is_mult();
	SHIFT shift_type();
	const char* kind();
	scCD(uint32_t);
	virtual ~scCD();

};

#endif // !defined(AFX_SCCD_H__7F1E5936_AE4E_11D6_BB28_000000000000__INCLUDED_)
