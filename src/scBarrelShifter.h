////////////////////////////////////////////////////////////////////////////////
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
 
  scBarrelShifter.h: interface for the scBarrelShifter class.
 
  Original Author: Allen Tao Zhong, University of Electronic Science and 
                   Technology in China
 
 *****************************************************************************/
#ifndef scBarrelShifter_H
#define scBarrelShifter_H


#include"scTypes.h"
#include<systemc.h>
#include<sc_mslib.h>
#include "scRegisterFile.h"
#include"scARMInstruction.h"
//////////////////////////////////////
//
//  parameters of barrelshifter
//
////////////////////////////////////////

 enum SHIFT {S_LSL = 0, S_LSR = 1, S_ASR = 2, S_ROR, S_RRX, S_ASL} ;
//control signals for barrel shifter



//////////////////////////////
//the interface of barrelshifter
//////////////////////////////

class scBarrelShifter:public sc_module
{
public://ports
	
     sc_in<uint32_t> in_n_Val;
	 sc_in<SHIFT>  in_SHIFT_TYPE;
	 sc_in<uint32_t>  in_n_Dist;
	 sc_out<uint32_t> out_n_NewVal;
	 sc_out<bool>     out_b_Carry;
	 sc_outmaster<bool>      out_b_RW;
	 sc_outmaster<REGS>    out_CPSR;
	 sc_inoutslave<uint32_t>  inout_n_Flag;   

public:
	SC_HAS_PROCESS(scBarrelShifter);//
	scBarrelShifter(sc_module_name name) : sc_module(name)
    {

        SC_METHOD(entry);
		sensitive<<in_n_Val<<in_SHIFT_TYPE<<in_n_Dist;
		
    }
private://data
	uint32_t m_nShiftCarryBit;
	
	        
	uint32_t m_nShiftType;
	uint32_t m_nShiftDist;
private:

	void entry(void);

uint32_t Shift(uint32_t nVal, enum SHIFT type, int nDist);// behavoir implementation

};


#endif