// scMult.h: interface for the scMult class.
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

#if !defined(AFX_SCMULT_H__8C326335_AB49_11D6_BB1E_000000000000__INCLUDED_)
#define AFX_SCMULT_H__8C326335_AB49_11D6_BB1E_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\SRC\scARMInstruction.h"
#include "scTypes.h"	// Added by ClassView
#include "scRegisterFile.h"	// Added by ClassView
#include "scALU.h"	// Added by ClassView
const uint32_t  MULT_MASK=   0x0F0000F0;
const uint32_t  MULT_SIG =   0x00000090;

class scMult : public scARMInstruction  
{
	/* Multiply instruction */
typedef struct MTAG
{
  uint32_t rm     : 4;
  uint32_t pad2   : 4;
  uint32_t rs     : 4;
  uint32_t rn     : 4;
  uint32_t rd     : 4;
  uint32_t set    : 1;
  uint32_t opcode : 3;
  uint32_t pad    : 4;
  uint32_t cond   : 4;

} MULT;
	MULT ir;
	static const char* kind_string ;
public:
	OPCODE op();
	bool is_rs();
	uint32_t dist();
	uint32_t B();
	bool is_mult();
	REGS Rd();
	uint32_t A();
	const char* kind();
	scMult(uint32_t);
	virtual ~scMult();

};

#endif // !defined(AFX_SCMULT_H__8C326335_AB49_11D6_BB1E_000000000000__INCLUDED_)
