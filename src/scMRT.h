// scMRT.h: interface for the scMRT class.
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
#if !defined(AFX_SCMRT_H__E3CD9FD4_AD93_11D6_BB24_000000000000__INCLUDED_)
#define AFX_SCMRT_H__E3CD9FD4_AD93_11D6_BB24_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "scARMInstruction.h"
#include "scTypes.h"	// Added by ClassView
#include "scALU.h"	// Added by ClassView
#include "scBarrelShifter.h"	// Added by ClassView
#include "scRegisterFile.h"	// Added by ClassView
const uint32_t MRT_MASK =    0x0E000000;
const uint32_t MRT_SIG  =    0x08000000;
class scMRT  :public scARMInstruction
{
/* Multiple register transfer */
typedef struct MRTAG
{  
  uint32_t list  : 16;
  uint32_t rn    : 4;
  uint32_t ls    : 1;
  uint32_t wb    : 1;
  uint32_t s     : 1;
  uint32_t u     : 1;
  uint32_t p     : 1;
  uint32_t pad   : 3;
  uint32_t cond  : 4;
} MRT;
  
  MRT ir;
  static const char* kind_string_l ;
  static const char* kind_string_s ;
public:
	bool up();
	bool set();
	bool is_mrt();
	bool is_branch();
	REGS Rn();
	bool load();
	uint32_t dist();
	REGS Rd();
	SHIFT shift_type();
	bool is_imm();
	bool wb();
	OPCODE op();
	bool pre();
	COND cond();
	uint32_t B();
	uint32_t A();
	bool is_shift();
	bool is_word();
	bool is_rs();
	bool is_mult();
	bool is_ls();
	const char* kind();
	scMRT(uint32_t i);
	virtual ~scMRT();

};

#endif // !defined(AFX_SCMRT_H__E3CD9FD4_AD93_11D6_BB24_000000000000__INCLUDED_)
