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
//  info   This is a SystemC ARM model,I "stole" some codes from 
//       "swarm" , author Michael Dales (michael@dcs.gla.ac.uk)
// scARMDPI.h: interface for the scARMDPI class.
//
//////////////////////////////////////////////////////////////////////

#include ".\instructions\scARMInstruction.h"
#include ".\components\registers\scRegisterFile.h"	// Added by ClassView
#include "scTypes.h"	// Added by ClassView


/* Data processing instruction - there are 3 types (see Furber book) */
typedef struct DP1TAG
{
  uint32_t imm    : 8;
  uint32_t rot    : 4;
  uint32_t rd     : 4;
  uint32_t rn     : 4;
  uint32_t set    : 1;
  uint32_t opcode : 4;
  uint32_t hash   : 1;
  uint32_t pad    : 2;
  uint32_t cond   : 4;
} DPI1;

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

typedef struct DP3TAG
{
  uint32_t rm     : 4;
  uint32_t pad3   : 1;
  uint32_t type   : 2;
  uint32_t pad2   : 1;
  uint32_t rs     : 4;
  uint32_t rd     : 4;
  uint32_t rn     : 4;
  bool_t   set    : 1;
  uint32_t opcode : 4;
  uint32_t hash   : 1;
  uint32_t pad    : 2;
  uint32_t cond   : 4;
} DPI3;
#define  DPI_MASK    0x0C000000
#define  DPI_SIG     0x00000000

class scARMDPI : public scARMInstruction  
{
	friend class scDecoder;
public:
	scARMDPI();
	virtual ~scARMDPI();




private:
	REGS get_Rs(uint32_t);
	bool_t get_Set(uint32_t nI);
	uint32_t get_Rot(uint32_t);
	void Decode(uint32_t);
	OPCODE   get_opcode(uint32_t nI);
	SHIFT    get_shift(uint32_t nI);
    REGS     get_Rn(uint32_t nI); 
	REGS     get_Rm(uint32_t nI);
	uint32_t get_Imm(uint32_t nI);
	REGS     get_Rd(uint32_t nI);
	uint32_t get_shift_dist(uint32_t nI);

};
