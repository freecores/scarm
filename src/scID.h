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
#if !defined(SCID_H)
#define SCID_H
#include<systemc.h>
#include<sc_mslib.h>
#include "scTypes.h"
#include "scARMInstruction.h"
#include "scRegisterFile.h"
#include "scBarrelShifter.h"
#include "scSignExt.h"
#define DEBUG
//#include "Bus.h"
#include "scALU.h"
class scID : public sc_module 
{ 
 
//	friend class scARMInstruction;
public: //ports
	sc_in<bool>     in_b_hold;
	sc_in<bool> in_b_Clock; 
	sc_out<bool>  out_b_is_branch;
	sc_out<bool>  out_interrupt;
	sc_out<COND> out_COND;
	sc_out<bool> out_branch_taken;
	sc_in<bool> in_b_flush_2;
	sc_out<bool> out_b_flush;

	//IF to ID
   	sc_in<uint32_t> in_n_Instruction;
	sc_in<uint32_t> in_n_PC;
	//regs
	sc_outmaster<bool>        out_b_RW;// 0-Read  1-Write
	sc_outmaster<REGS>     out_REG;
	sc_inoutslave<uint32_t> inout_n_Data;
//ID to EX
    //ABus 
	sc_out<uint32_t>   out_n_A;
    //BBus
	sc_out<uint32_t>   out_n_B;
    //controls of ALU
	sc_out<OPCODE>    out_OP;
    sc_out<bool>    out_SET;
	//controls of Barrel Shifter
	 sc_out<bool>   out_b_S;
	 sc_out<SHIFT>  out_SHIFT_TYPE;
	  sc_out<bool>  out_b_is_mrt;
	 sc_out<uint32_t>  out_n_Dist;
	 //controls of Booth Multiplier
	 sc_out<bool>   out_b_M;
	 //controls to MEM
	 sc_out<bool>   out_b_ls;
	 sc_out<REGS>   out_Rn;
	 sc_out<bool>   out_b_Pre;
	 sc_out<bool>    out_b_Load;
     sc_out<bool>   out_b_WB;
	// target reg
    sc_out<REGS>    out_Rd;
    sc_out<REGS>    out_Rm;//used for forwarding
    sc_out<REGS>    out_Rs;
    sc_out<bool>    is_Rm;
	sc_out<bool>    is_Rs;




public:
	void delay2_1();
	bool predict();
	void delay0_1();
	void delay0();
	void delay3();
	void delay2();
	void delay1();
	void regs();
	void display();
	virtual  scARMInstruction* create_instru(uint32_t i);
	SC_HAS_PROCESS(scID);
	scID(const sc_module_name name_):sc_module(name_)
	//	,	inst_SignExt("signext")
	{
       flush_number=0;
       save_flush=0;
	   m_b_is_mrt=0;
	   m_n_list=0;
	   m_reg_in_list=0;
	   m_order=0;
	   m_index=0;
	   
	   SC_METHOD(entry);
	   sensitive_pos<<in_b_Clock;
	   SC_METHOD(delay0);
	   SC_METHOD(delay0_1);
	   SC_METHOD(delay1);

	   SC_METHOD(delay2);
	   SC_METHOD(delay2_1);
	   SC_METHOD(delay3);

	  // inst_SignExt(s_n_Dist,out_n_Dist);
   
	}	
	virtual ~scID();



private:
	
//use the fixed field technique

	void entry();
private:
 bool save_flush;
  bool m_b_interrupt,m_b_is_mrt,m_b_up;
  uint32_t m_ir,m_pc,m_last_ir,m_last_pc,m_n_list,m_reg_in_list,m_index,m_order;
  sc_event trigger,trigger0,trigger0_1,trigger1,trigger2,trigger2_1,trigger3;
  uint32_t m_A,m_B,m_Dist;
  REGS     m_Rn,m_Rd,m_Rm,m_Rs;
  OPCODE   m_OP;
  COND     m_COND;
  SHIFT    m_SHIFT_TYPE; 
  bool     m_b_predict,m_b_flush,m_b_S,m_b_ls,m_b_M,m_b_Pre,m_b_Load,m_b_WB,m_SET;
  bool     m_b_is_Rm,m_b_is_Rs;
private:

	//	scSignExt inst_SignExt;
	#if defined(DEBUG)
   sc_signal<uint32_t> s_reg_in_list;
  sc_signal<bool>     s_is_mrt; 
  sc_signal<uint32_t> s_pc_debug;
  sc_signal <uint32_t>s_ir_debug;
  sc_signal <uint32_t>s_A_debug;
  sc_signal <uint32_t>s_B_debug;
  sc_signal <uint32_t>s_dist_debug;
  int flush_number;
  sc_signal<bool> s_b_flush_debug;
#endif

};
#endif