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
// scNOOP.h: interface for the scNOOP class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCNOOP_H__5BF0CC54_B170_11D6_BB2F_000000000000__INCLUDED_)
#define AFX_SCNOOP_H__5BF0CC54_B170_11D6_BB2F_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "scARMInstruction.h"
#include "scALU.h"	// Added by ClassView
#include "scRegisterFile.h"	// Added by ClassView
#include "scTypes.h"	// Added by ClassView
#include "scBarrelShifter.h"	// Added by ClassView
const uint32_t NOP_MASK =   0xe1a00000;
const uint32_t NOP_SIG  =   0xe1a00000;
class scNOOP : public scARMInstruction  
{
		typedef struct DP2TAG
{
  uint32_t rm     : 4;
  uint32_t pad2   : 1;
  uint32_t type   : 2;
  uint32_t shift  : 5;
  uint32_t rd     : 4;
  uint32_t rn     : 4;
  bool_t   set    : 1;
  uint32_t opcode : 4;
  uint32_t hash   : 1;
  uint32_t pad    : 2;
  uint32_t cond   : 4;
} DPI2;
		DPI2 ir;
public:
	bool set();
	bool is_branch();
	bool is_rs();
	bool is_imm();
	SHIFT shift_type();
	COND cond();
	bool wb();
	bool load();
	bool pre();
	uint32_t B();
	uint32_t A();
	uint32_t dist();
	bool is_ls();
	REGS Rn();
	REGS Rd();
	OPCODE op();
	bool is_shift();
	bool is_mult();
	const char* kind();
	static const char* kind_string;
	scNOOP();
	scNOOP(uint32_t);
	virtual ~scNOOP();
private:


};

#endif // !defined(AFX_SCNOOP_H__5BF0CC54_B170_11D6_BB2F_000000000000__INCLUDED_)
