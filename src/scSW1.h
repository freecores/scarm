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
// scSW1.h: interface for the scSW1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCSW1_H__8C326334_AB49_11D6_BB1E_000000000000__INCLUDED_)
#define AFX_SCSW1_H__8C326334_AB49_11D6_BB1E_000000000000__INCLUDED_

#include "scBarrelShifter.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\SRC\scARMInstruction.h"
#include "scTypes.h"	// Added by ClassView
#include "scRegisterFile.h"	// Added by ClassView
#include "scALU.h"	// Added by ClassView
const uint32_t SWT1_MASK =   0x0E000000;
const uint32_t SWT1_SIG  =   0x04000000;
class scSW1 : public scARMInstruction  
{

/* Single word and unsigned byte transfer - again, two formats*/
typedef struct SW1TAG
{
  uint32_t imm   : 12;
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
} SWT1;

	SWT1 ir;
	static const char* kind_string_l ;
	static const char* kind_string_s ;
public:
	bool set();
	bool is_branch();
	bool is_rs();
	bool is_ls();

	bool is_mult();
	REGS Rn();
	bool wb();
	bool load();
	bool pre();
	bool is_shift();
	uint32_t dist();
	SHIFT shift_type();
	COND cond();
	OPCODE op();
	bool is_imm();
	uint32_t B();
	REGS Rd();
	uint32_t A();
	const char* kind();
	scSW1(uint32_t);
	virtual ~scSW1();

};

#endif // !defined(AFX_SCSW1_H__8C326334_AB49_11D6_BB1E_000000000000__INCLUDED_)
