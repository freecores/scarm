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
// scARM_Branch.cpp: implementation of the scARM_Branch class.
//
//////////////////////////////////////////////////////////////////////
#include"stdio.h"
#include "scARMInstruction.h"
#include "scARM_Branch.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
scARM_Branch::scARM_Branch()
{
 
}
scARM_Branch::scARM_Branch(uint32_t nI)
{
 
}

scARM_Branch::~scARM_Branch()
{

}

scARMInstruction* scARM_Branch::Create(uint32_t nI)
{
    scARMInstruction* pI=NULL;
	return pI;
}
