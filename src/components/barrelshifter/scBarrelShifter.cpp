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
//   
//
///////////////////////////////////////////////////////////////////////////////

/*****************************************************************************
 
  scBarrelShifter.cpp -- a barrel shifter
 
  Original Author: Allen Tao Zhong, University of Electronic Science and 
                   Technology in China
 
 *****************************************************************************/

// scBarrelShifter.cpp: implementation of the scBarrelShifter class.
//
//////////////////////////////////////////////////////////////////////

#include "scBarrelShifter.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

#define SHIFT_LEFT(_x,_y)  ((_y >= 32) ? 0 : _x << _y)
#define SHIFT_RIGHT(_x,_y) ((_y >= 32) ? 0 : _x >> _y)
#define SIGNED_SHIFT_RIGHT(_x,_y) ((_y >= 32) ? ((_x >> 31) * 0xFFFFFFFF) : ((int32_t)_x) >> _y)

///////////////////////////////////////////////////////////////////////////////
//
//
uint32_t scBarrelShifter::Shift(uint32_t nVal,  SHIFT type, int nDist)
{
	uint32_t nCPSR=inout_n_Flag;
  switch (type)
    {
      ////////////////////////////////////////////////////////////////
      case S_LSL: case S_ASL:
      {
		 if (nDist == 0)
		 {
			m_nShiftCarryBit = (nCPSR & C_FLAG) ? 1 : 0;
			return nVal;
		 }
		 else if (nDist == 32)
		 {
			m_nShiftCarryBit = nVal & 0x1;
			return 0;
		 }
	     else if (nDist > 32)
		 {
			m_nShiftCarryBit = 0;
			return 0;
		 }
		 else
		 {
			m_nShiftCarryBit = SHIFT_RIGHT(nVal, (32 - nDist)) & 0x1;
			return (nVal << nDist); break;
		 }
      }
      break;
      ////////////////////////////////////////////////////////////////
    case S_LSR:
      {
	if (nDist == 0)
	  {
	    m_nShiftCarryBit = (nCPSR & C_FLAG) ? 1 : 0;
	    return nVal;
	  }
	else if (nDist == 32)
	  {
	    m_nShiftCarryBit = (nVal >> 31);
	    return 0;
	  }
	else if (nDist > 32)
	  {
	    m_nShiftCarryBit = 0;
	    return 0;
	  }
	else
	  {
	    m_nShiftCarryBit = (nVal >> (nDist - 1)) & 0x1;
	    return (nVal >> nDist); 
	  }
      }
      break;
      ////////////////////////////////////////////////////////////////
    case S_ASR:
      {
	if (nDist == 0)
	  {
	    m_nShiftCarryBit = (nCPSR & C_FLAG) ? 1 : 0;
	    return nVal;
	  }
	else if (nDist >= 32)
	  {
	    if (nVal & 0x80000000)
	      {
		m_nShiftCarryBit = 1;
		return 0xFFFFFFFF;
	      }
	    else
	      {
		m_nShiftCarryBit = 0;
		return 0;
	      }
	  }
	else
	  {
	    uint32_t temp = 0xFFFFFFFF;	
	    m_nShiftCarryBit = (nVal >> (nDist - 1)) & 0x1;		
	    if ((nVal & 0x80000000) != 0)
	      nVal = (nVal >> nDist) | (~(temp >> (nDist /* - 1 */)));
	    else
	      nVal = (nVal >> nDist);
	    
	    return nVal;
	  }
      }
      break;
      ////////////////////////////////////////////////////////////////
    case S_ROR:
      {
	if (nDist == 0)
	  {
	    m_nShiftCarryBit = (nCPSR & C_FLAG) ? 1 : 0;
	    return nVal;
	  }
	else if ((nDist & 0x1F) == 0)
	  {
	    m_nShiftCarryBit = nVal >> 31;
	    return nVal;
	  }
	else
	  {
	    nDist &= 0x1F;
	    m_nShiftCarryBit = SHIFT_RIGHT(nVal, (nDist - 1)) & 0x1;
	    return (nVal >> nDist) | (nVal << (32 - nDist));
	  }
      }
      break;
      ////////////////////////////////////////////////////////////////
    case S_RRX:
      {
	    m_nShiftCarryBit = nVal & 0x1;
	
        uint32_t temp = nVal & 0x1;
        nVal = nVal >> 1;
        if (nCPSR & C_FLAG)
          nVal |= 0x80000000;

        return nVal;
      }
      break;
    default :
	{
          cout<<"error in scBarrelShifter.Shift\n";
		  return 0;
		 
	}
   }//end of switch(type)
}

void scBarrelShifter::entry()
{  

 
   uint32_t val,dist,new_val;
   val=in_n_Val;
   dist=in_n_Dist;
   new_val=Shift(val, in_SHIFT_TYPE, dist);
   out_n_NewVal=new_val;
   cout<<"   Value="<<hex<<in_n_Val<<"  ShitfDist="<<in_n_Dist<<" shifted_value="<<hex<<new_val<<endl;
}

