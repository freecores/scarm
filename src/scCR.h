// scCR.h: interface for the scCR class.
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
#if !defined(AFX_SCCR_H__7F1E5937_AE4E_11D6_BB28_000000000000__INCLUDED_)
#define AFX_SCCR_H__7F1E5937_AE4E_11D6_BB28_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\SRC\scARMInstruction.h"
#include "scRegisterFile.h"	// Added by ClassView
#include "scALU.h"	// Added by ClassView
#include "scTypes.h"	// Added by ClassView
const uint32_t CRT_MASK  =  0x0F000010;
const uint32_t CRT_SIG  =   0x0E000010;
class scCR : public scARMInstruction  
{
/* Coprocessor register transfers */
typedef struct CRTAG
{
  uint32_t crm   : 4;
  uint32_t pad2  : 1;
  uint32_t cop2  : 3;
  uint32_t cpn   : 4;
  uint32_t rd    : 4;
  uint32_t crn   : 4;
  uint32_t ls    : 1;
  uint32_t cop1  : 3;
  uint32_t pad   : 4;
  uint32_t cond  : 4;
} CRT;
 CRT ir;
 static const char* kind_string;
public:
	uint32_t B();
	uint32_t A();
	bool is_imm();
	bool pre();
	bool wb();
	COND cond();
	REGS Rn();
	bool is_rs();
	bool is_ls();
	REGS Rd();
	bool is_shift();
	bool is_mult();
	const char* kind();
	scCR(uint32_t);
	virtual ~scCR();

};

#endif // !defined(AFX_SCCR_H__7F1E5937_AE4E_11D6_BB28_000000000000__INCLUDED_)
