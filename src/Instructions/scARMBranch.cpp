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
// scARMBranch.cpp: implementation of the scARMBranch class.
//
//////////////////////////////////////////////////////////////////////

#include "scARMBranch.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

scARMBranch::scARMBranch()
{

}

scARMBranch::~scARMBranch()
{

}
/******************************************************************************
 * decode_branch - Decodes a branch instruction.
 */
void scARMBranch::decode_branch(uint32_t i, char* str)
{
  INST inst;
  inst.raw = i;
 // char temp[10];

 // sprintf(str, "b", i);  
  
 // if (inst.branch.link != 0)
 //   {
 //     strcat(str, "l");
 //   }

 // sprintf(temp, "%s\t%x", cond[inst.branch.cond], inst.branch.offset);
 // strcat(str, temp);
}

uint32_t scARMBranch::get_offset(uint32_t i)
{
   uint32_t offset=0;
   return  offset;
}
