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
// scARMBranch1.h: interface for the scARMBranch class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCARMBRANCH1_H__06407AB3_411D_11D6_B9ED_000000000000__INCLUDED_)
#define AFX_SCARMBRANCH1_H__06407AB3_411D_11D6_B9ED_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "scARMInstruction.h"
#include "scTypes.h"	// Added by ClassView
/* Branch/Link encoding */
typedef struct BLTAG
{
  uint32_t offset : 24;
  bool_t   link   : 1;
  uint32_t pad    : 3;
  uint32_t cond   : 4;
} BRANCH;
const BRANCH_MASK= 0x0E000000;
const BRANCH_SIG=0x0A000000;
class scARMBranch : public scARMInstruction  
{ 
	friend class scDecoder;
public:
	scARMBranch();
	virtual ~scARMBranch();

private:
	bool_t get_link(uint32_t nI);
	uint32_t get_offset(uint32_t);
};

#endif // !defined(AFX_SCARMBRANCH1_H__06407AB3_411D_11D6_B9ED_000000000000__INCLUDED_)
