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
// scUnUsedInstruction.h: interface for the scUnUsedInstruction class.
//
//////////////////////////////////////////////////////////////////////
#include "scTypes.h"
/* Unused arithmetic instruction */
typedef struct UAITAG
{
  uint32_t rm    : 4;
  uint32_t pad2  : 4;
  uint32_t rs    : 4;
  uint32_t rd    : 4;
  uint32_t rn    : 4;
  uint32_t op    : 2;
  uint32_t pad   : 6;
  uint32_t cond  : 4;
} UAI;
#define UAI_MASK    0x0FC000F0
#define UAI_SIG     0x00700090


/* Unused control instructions - there are 3 of these */
typedef struct UC1TAG
{
  uint32_t rm    : 4;
  uint32_t pad3  : 1;
  uint32_t op2   : 3;
  uint32_t rs    : 4;
  uint32_t rd    : 4;
  uint32_t rn    : 4;
  uint32_t pad2  : 1;
  uint32_t op    : 2;
  uint32_t pad   : 5;
  uint32_t cond  : 4;
} UCI1;
#define UCI1_MASK    0x0F900010
#define UCI1_SIG     0x01000000

typedef struct UC2TAG
{
  uint32_t rm    : 4;
  uint32_t pad4  : 1;
  uint32_t op2   : 2;
  uint32_t pad3  : 1;
  uint32_t rs    : 4;
  uint32_t rd    : 4;
  uint32_t rn    : 4;
  uint32_t pad2  : 1;
  uint32_t op    : 2;
  uint32_t pad   : 5;
  uint32_t cond  : 4;
} UCI2;
#define UCI2_MASK    0x0F900090
#define UCI2_SIG     0x01000010

typedef struct UC3TAG
{
  uint32_t imm   : 8;
  uint32_t rot   : 4;
  uint32_t rd    : 4;
  uint32_t rn    : 4;
  uint32_t pad2  : 1;
  uint32_t op    : 2;
  uint32_t pad   : 5;
  uint32_t cond  : 4;
} UCI3;
#define UCI3_MASK    0x0F900000
#define UCI3_SIG     0x03000000


/* Unused Load/Store Instruction */
typedef struct ULSTAG
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
} ULSI;
#define ULSI_MASK    0x0E000090
#define ULSI_SIG     0x00000090


/* Unused Coprocessor Instruction */
typedef struct UCPITAG
{
  uint32_t offset : 8;
  uint32_t cpn    : 4;
  uint32_t crd    : 4;
  uint32_t rn     : 4;
  uint32_t x      : 1;
  uint32_t pad2   : 1;
  uint32_t op     : 2;
  uint32_t pad    : 4;
  uint32_t cond   : 4;
} UCPI;
#define UCPI_MASK    0x0F200000
#define UCPI_SIG     0x0C000000


/* Undefined instruction space */
typedef struct UDTAG
{
  uint32_t raw2 : 4;
  uint32_t pad2 : 1;
  uint32_t raw  : 20;
  uint32_t pad  : 3;
  uint32_t cond : 4;
} UNDEF;
#define UNDEF_MASK   0x0E000010
#define UNDEF_SIG    0x06000010

class scUnUsedInstruction  
{
public:
	scUnUsedInstruction();
	virtual ~scUnUsedInstruction();

};
