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
// scARMBranch1.cpp: implementation of the scARMBranch class.
//
//////////////////////////////////////////////////////////////////////

#include "scARMBranch1.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

scARMBranch::scARMBranch()
{

}

scARMBranch::~scARMBranch()
{

}

uint32_t scARMBranch::get_offset(uint32_t nI)
{
	uint32_t nOffset;
    nOffset=nI&0xffffff;
	return nOffset;
}

bool_t scARMBranch::get_link(uint32_t nI)
{
   bool_t bL;
   bL=(nI>>24)&0x1;
   return bL;
}
