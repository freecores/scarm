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
// scARMLSI.h: interface for the scARMLSI class.
//
//////////////////////////////////////////////////////////////////////


#include "..\instructions\scARMInstruction.h"
#include "..\components\registers\scRegisterFile.h"	// Added by ClassView
/* Unused Load/Store Instruction */
typedef struct LSTAG
{
  uint32_t rm    : 4;
  uint32_t pad4  : 1;
  uint32_t op2   : 2;
  uint32_t pad3  : 1;
  uint32_t rs    : 4;
  uint32_t rd    : 4;
  uint32_t rn    : 4;
  uint32_t ls    : 1;
  uint32_t wb    : 1;
  uint32_t b     : 1;
  uint32_t u     : 1;
  uint32_t p     : 1;
  uint32_t pad   : 3;
  uint32_t cond  : 4;
} LSI;
#define LSI_MASK    0x0c000000
#define LSI_SIG     0x04000000

class scARMLSI : public scARMInstruction  
{
public:
	scARMLSI();
	virtual ~scARMLSI();

private:
	REGS get_Rs(uint32_t);
	bool_t get_Set(uint32_t nI);
	uint32_t get_Rot(uint32_t);

	OPCODE   get_opcode(uint32_t nI);
	SHIFT    get_shift(uint32_t nI);
    REGS     get_Rn(uint32_t nI); 
	REGS     get_Rm(uint32_t nI);
	uint32_t get_Imm(uint32_t nI);
	REGS     get_Rd(uint32_t nI);
	uint32_t get_shift_dist(uint32_t nI);
};
