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
// scARMMult.h: interface for the scARMMult class.
//
//////////////////////////////////////////////////////////////////////
#ifndef MULTINSTRUCT_H
#define MULTINSTRUCT_H
#include "scARMInstruction.h"
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
#define MRT_MASK     0x0E000000
#define MRT_SIG      0x08000000

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
#define  MULT_MASK   0x0F0000F0
#define  MULT_SIG    0x00000090


class scARMMult : public scARMInstruction  
{
public:
	scARMMult();
	virtual ~scARMMult();

};
#endif