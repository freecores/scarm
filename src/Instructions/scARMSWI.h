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
// scARMSWI.h: interface for the scARMSWI class.
//
//////////////////////////////////////////////////////////////////////



#include "scARMInstruction.h"
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

typedef struct SW2TAG
{
  uint32_t rm    : 4;
  uint32_t pad2  : 1;
  uint32_t type  : 2;
  uint32_t shift : 5;
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
} SWT2;
#define  SWT_MASK    0x0C000000
#define  SWT_SIG     0x04000000
/* Software interrupt */
typedef struct SWITAG
{
  uint32_t val  : 24;
  uint32_t pad  : 4;
  uint32_t cond : 4;
} SWI;
#define SWI_MASK    0x0F000000
#define SWI_SIG     0x0F000000

class scARMSWI : public scARMInstruction  
{
public:
	scARMSWI();
	virtual ~scARMSWI();

};
