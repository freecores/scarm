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
// scEX.h: interface for the scEX class.
//
//////////////////////////////////////////////////////////////////////

#include<systemc.h>
#include"scTypes.h"
#include".\components\alu\scALU.h"
#include".\components\barrelshifter\scBarrelShifter.h"

//enum ARI {ARI_ALU, ARI_INC, ARI_REG, ARI_NONE};

class scEX :public sc_module
{
public: //ports

	sc_in<bool> in_b_Clock;
	sc_in<uint32_t> in_n_NPC;
	sc_in<bool_t> in_b_Branch;
	sc_out<bool_t> out_b_Flush;
	sc_in<bool_t>  in_b_MEM;
	sc_out<bool_t> out_b_MEM;

//A Bus
	sc_in<OPCODE>   in_OP;
	sc_in<COND>     in_COND;
 	sc_in<uint32_t> in_n_A;	

//B bus
	sc_in<SHIFT>    in_SHIFT;
	sc_in<uint32_t> in_n_Dist;
    sc_in<uint32_t> in_n_B;

//ALU Bus
	sc_out<uint32_t> out_n_ALUOutput;
	sc_in<REGS>     in_Rd;
	sc_out<REGS>    out_Rd;
//	sc_out<uint32_t> out_n_Flag;

		//regs file
	sc_outmaster<REGS>   out_REG;    
	sc_inoutslave<uint32_t> in_n_RegData;
private:
	sc_signal<OPCODE>   s_OP;
	sc_signal<COND>     s_COND;
	sc_signal<uint32_t> s_n_A;
	sc_signal<SHIFT>    s_SHIFT;
	sc_signal<uint32_t> s_n_Dist;
	sc_signal<uint32_t> s_n_B;
	//should update flag
	sc_signal<uint32_t> s_n_Flag;


private:
	scALU inst_ALU;
	scBarrelShifter inst_BarrelShifter;

	sc_signal<uint32_t> s_n_B1;
    sc_signal<uint32_t> s_n_ALUOutput;
public:
    
	SC_HAS_PROCESS(scEX);
	scEX(const sc_module_name name_):sc_module(name_),
		inst_ALU("alu"),
	    inst_BarrelShifter("barrel_shifter")
	{
	   SC_METHOD(entry);
	   sensitive_pos<<in_b_Clock;
	   SC_METHOD(output);
	   sensitive<<s_n_ALUOutput;
	   //internal links
	   //A bus is directly linked
	   
	   //The barrelshifter is inserted before the ALU in B bus
	   //For ARM6, there is a Booth Mutiplier which is inserted in A Bus
	   inst_BarrelShifter(s_n_B,s_SHIFT,s_n_Dist,s_n_B1,
		   out_REG,in_n_RegData);

	   inst_ALU(s_OP,s_COND,s_n_A,s_n_B1,s_n_ALUOutput,s_n_Flag);
	}	
	virtual ~scEX();

private:
	void entry(void);
private:
	void output();

	uint32_t m_n_ALUOutput;
	uint32_t m_nIR;
	uint32_t m_nCond;//Control signals
};
