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
// scID.h: interface for the scID class.
//
//////////////////////////////////////////////////////////////////////

#include<systemc.h>
#include<sc_mslib.h>
#include "scTypes.h"
#include ".\components\decoder\scDecoder.h"
#include ".\components\registers\scRegisterFile.h"
enum B_DRIVE {B_REG, B_IMM1, B_IMM2, B_DIN, B_CPSR, B_SPSR}; 
class scID :public sc_module 
{
public: //ports
	sc_in<bool> in_b_Clock;  
	sc_in<uint32_t> in_n_NPC;
	sc_out<uint32_t> out_n_NPC;
    sc_in<uint32_t> in_n_Instruction;
    sc_out<bool_t>  out_b_Branch;
	sc_out<bool_t>  out_b_MEM;

	sc_out<OPCODE>   out_OP;
	sc_out<COND>     out_COND;
	sc_out<uint32_t> out_n_A;
	
	sc_out<SHIFT>    out_SHIFT;
	sc_out<uint32_t> out_n_Dist;
	sc_out<uint32_t> out_n_B;
	
    sc_out<REGS>   out_Rd;
	//regs file
	sc_outmaster<REGS>   out_REG;    
	sc_inoutslave<uint32_t> in_n_RegData;

//	sc_in<uint32_t> in_n_NPC;
private:
	scDecoder  inst_Decoder;



private:
	//input
	sc_signal<uint32_t>  s_n_IR;
    //links

	//output
	sc_signal<bool_t>    s_b_Branch;
	sc_signal<bool_t>    s_b_MEM;
	sc_signal<REGS>      s_Rn;
	sc_signal<REGS>      s_Rm;
	sc_signal<REGS>      s_Rd;
	sc_signal<OPCODE>    s_OP;
	sc_signal<COND>      s_COND;
	sc_signal<uint32_t>  s_n_Rn;
	sc_signal<SHIFT>     s_SHIFT_TYPE;
	sc_signal<bool_t>    s_Set;
	sc_signal<uint32_t>  s_ShiftDist;
    sc_signal<uint32_t>  s_n_Rm;
    sc_signal<uint32_t>  s_n_Imm;
 public:

	SC_HAS_PROCESS(scID);
	scID(const sc_module_name name_):sc_module(name_),
		inst_Decoder("decoder")
	{
	   //s_b_MEM=false;
	   //s_OP=OP_ADD;
	   SC_METHOD(entry);
	   sensitive_pos<<in_b_Clock;
	   SC_METHOD(output);
	   sensitive<<s_n_IR;
	   //internal links
	   inst_Decoder(s_n_IR,
		   s_b_Branch,
		   s_OP,s_COND,
		   s_Rd,s_Rn,
		   s_SHIFT_TYPE,s_Set,s_ShiftDist,s_Rm,s_n_Imm,
		   out_REG/*CPSR*/,in_n_RegData);
   
	}	
	virtual ~scID();



private:
	void output();
//use the fixed field technique

	void entry();
};
