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
// scARMMCR.h: interface for the scARMMCR class.
//
//////////////////////////////////////////////////////////////////////

#include "scTypes.h"
/* General register to status register transfer - two formats */
typedef struct MSR1TAG
{
  uint32_t imm   : 8;
  uint32_t rot   : 4;
  uint32_t pad4  : 4;
  uint32_t field : 4;
  uint32_t pad3  : 2;
  uint32_t which : 1;
  uint32_t pad2  : 2;
  uint32_t hash  : 1;
  uint32_t pad   : 2;
  uint32_t cond  : 4;
} MSR1;

typedef struct MSR2TAG
{
  uint32_t rm    : 4;
  uint32_t pad5  : 8;
  uint32_t pad4  : 4;
  uint32_t field : 4;
  uint32_t pad3  : 2;
  uint32_t which : 1;
  uint32_t pad2  : 2;
  uint32_t hash  : 1;
  uint32_t pad   : 2;
  uint32_t cond  : 4;
} MSR2;
#define MSR_MASK    0x0DB0F000
#define MSR_SIG     0x0120F000

class scARMMCR  
{
public:
	scARMMCR();
	virtual ~scARMMCR();

};
