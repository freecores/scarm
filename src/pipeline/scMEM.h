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
// scMEM.h: interface for the scMEM class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(MEM_H)
#define MEM_H


#include<systemc.h>
#include<sc_mslib.h>
#include "scTypes.h"	// Added by ClassView

#include "..\components\registers\scRegisterFile.h"

class scMEM :public sc_module 
{
public: //ports
	sc_in<bool>         in_b_Clock;
	sc_in<uint32_t>     in_n_ALUOutput;
	sc_in<bool_t>       in_b_Branch;
	sc_out<bool_t>      out_b_Flush;
	sc_in<bool_t>       in_b_MEM;
	sc_out<uint32_t>    out_n_NPC;
	sc_in<REGS>         in_Rd;
    sc_out<REGS>        out_Rd;
	sc_out<uint32_t>    out_n_MEMtoWB;
 	sc_outmaster<uint32_t> out_n_Addr;//  address bus
	sc_inoutslave<uint32_t>  inout_n_Data; //Instruction bu
	sc_out<bool_t>        out_b_RW;     //R/W
public:
	void entry(void);

public:

 
	SC_HAS_PROCESS(scMEM);
	scMEM(const sc_module_name name_):sc_module(name_)
	{
       b_AccessMem=false;
	   SC_METHOD(entry);
	   sensitive_pos<<in_b_Clock;
	
	}	
	virtual ~scMEM();


private:
	sc_signal<uint32_t> s_n_LMD;
	bool b_AccessMem;
	
};

#endif // !defined(AFX_SCMEM_H__3D36E4D9_3B3D_11D6_B9E2_000000000000__INCLUDED_)
