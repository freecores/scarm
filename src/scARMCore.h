
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
//
//   scARMCore.h: interface for the scARMCore class.
//              
//          
//  Original Author: Allen Tao Zhong,
//  University of Electronic Science and Technology in China
//  email: zhong@opencores.org
//  header n/a
//  info   This is a simple ARM modeling using SystemC.
//               Architecure defined by Allen Tao Zhong. 
//
///////////////////////////////////////////////////////////////////////////////
 
/*****************************************************************************
 
  MODIFICATION LOG - modifiers, enter your name, affiliation, date and
  changes you are making here.
 
      Name, Affiliation, Date:
  Description of Modification:
 
 *****************************************************************************/


#if !defined(CORE_H)
#define CORE_H


#include<systemc.h>
#include"scRegisterFile.h"
#include <sc_mslib.h>

#include"scIF.h"
#include"scID.h"
#include"scEX.h"
#include "scMEM.h"
#include "scWB.h"
#include "scRegisterFile.h"
#include "scNPC.h"



#include"scTypes.h"	// Added by ClassView


//vectors for exceptions
/*
enum VECTOR {V_RESET = 0x00, V_UNDEF = 0x04, V_SWI = 0x08, V_PABORT = 0x0C, 
	     V_DABORT = 0x10, V_IRQ = 0x18, V_FIQ = 0x1C};
		 */



class scARMCore  :public sc_module
{
public://ports
	sc_in<bool>       in_b_Clock; 
    sc_outmaster<bool>     out_b_nRW;         
	sc_outmaster<uint32_t> out_n_Addr;//  address bus
	sc_inoutslave<uint32_t>  inout_n_Data; //Instruction bus
private://internal interconnects
	sc_signal<bool>     s_b_hold;
		 sc_signal<bool>  s_b_is_mrt;
sc_signal<bool>  s_b_is_mrt1;
	sc_signal<bool>  s_b_is_branch;
	sc_signal<bool>  s_b_is_branch1;
	sc_signal<bool> s_interrupt1;
	sc_signal<bool> s_interrupt2;
	sc_signal<COND> s_COND;
	sc_signal<bool>  signal_branch_taken_ID;
	sc_signal<bool> s_b_flush;
	sc_signal<bool> s_b_flush_2;
		sc_signal<bool> s_b_branch_taken;
	sc_signal<uint32_t> s_n_NPC; 
	//IF to ID
    sc_signal<uint32_t> s_n_Instruction;
	sc_signal<uint32_t> s_n_PC;
	
	//ID to Register File
	sc_link_mp<REGS>     l_REG;
	sc_signal<MODE>     s_MODE;
	sc_link_mp<uint32_t> l_n_Data;
	sc_link_mp<bool>        s_b_RW;// 0-Read  1-Write
	sc_link_mp<REGS>     l_REG2;
	sc_link_mp<uint32_t> l_n_Data2;
	sc_link_mp<bool>        s_b_RW2;// 0-Read  1-Write
	//ID to EX
	sc_signal<OPCODE >    s_OP;
    sc_signal<bool>    s_SET;
	sc_signal<uint32_t>       s_A;
	sc_signal<uint32_t>       s_B;
	sc_signal<REGS>           s_Rd1;
	sc_signal<REGS>    s_Rm;//used for forwarding
    sc_signal<REGS>    s_Rs;
    sc_signal<bool>    is_Rm;
	sc_signal<bool>    is_Rs;

	  //conrol of Barrel shifter
	    sc_signal<bool>  s_b_S;
	     sc_signal<SHIFT>  s_SHIFT_TYPE;
	     sc_signal<uint32_t>  s_n_Dist;
		//controls of Mutiplier
		 sc_signal<bool>    s_M;
		 //controls of MEM
     	 sc_signal<bool>   s_b_ls;
	 sc_signal<uint32_t>       s_n_Rd;
     sc_signal<REGS>   s_Rn;

	 sc_signal<bool>   s_b_Pre;
	 sc_signal<bool>   s_b_Load;
     sc_signal<bool>   s_b_WB;
	//EX to MEM
	sc_signal<uint32_t>       s_Result;
	sc_signal<bool>     s_b_write_Rd;
	sc_signal<REGS>           s_Rd2;
	sc_signal<REGS>           s_Rn1;
	sc_signal<uint32_t>       s_n_Rn;
	sc_signal<bool>  s_b_ls1;
	sc_signal<bool>           s_b_Pre1;// alter base reg before?
	sc_signal<bool>           s_b_Load1;// load or store
    sc_signal<bool>           s_b_WB1;  //if i should write back to base reg?
	//MEM to WB

	sc_signal<REGS>           s_Rd3;
	sc_signal<uint32_t>       s_Result1;
	sc_signal<REGS>           s_Rn2;
	sc_signal<uint32_t>       s_n_Rn1;
	sc_signal<bool>           s_b_W_Rd;//if write Rd?
	sc_signal<bool>           s_b_WB2;
    //WB to RegisterFile
	sc_link_mp<REGS>     l_REG1;
	sc_link_mp<uint32_t> l_n_Data1;
	sc_link_mp<bool>        s_b_RW1;// 0-Read  1-Write
	   //branch
	sc_signal<bool>     s_b_B;  //is it a branch?
	sc_signal<uint32_t> s_n_B; //branch address
	//access link  

	
	sc_link_mp<bool>        s_b_RW_PC;// 0-Read  1-Write
	sc_link_mp<REGS>     l_REG_PC;
	sc_link_mp<uint32_t> l_n_Data_PC;

	sc_signal<bool>  s_b_excute;
	sc_signal<bool>  s_b_excute1;
	//forwarding
	sc_signal<REGS>         s_Rd_from_mem;//target
	sc_signal<uint32_t>     s_n_Result_from_mem;
	sc_signal<REGS>         s_Rn_from_mem;//write-back register
	sc_signal<uint32_t>     s_n_Rn_from_mem; //write-back data  


private:
	scNPC   inst_NPC;
	scIF inst_IFStage;
	scID inst_IDStage;	
	scRegisterFile inst_Regs;
	scEX inst_EXStage;
	scMEM inst_MEMStage;
	scWB inst_WBStage;

public:
	SC_HAS_PROCESS(scARMCore);
	scARMCore(sc_module_name name_):sc_module(name_),

		inst_Regs("regs"),
		inst_NPC("npc"),
		inst_IFStage("if"),
		inst_IDStage("id"),
		inst_EXStage("ex"),
		inst_MEMStage("mem"),
		inst_WBStage("wb")

	{
	   		//registers
		s_MODE=M_USER;
	inst_Regs(in_b_Clock,s_MODE,s_b_RW,l_REG,l_n_Data,s_b_RW1,l_REG1,l_n_Data1,s_b_RW2,l_REG2,l_n_Data2,s_b_RW_PC,l_REG_PC,l_n_Data_PC);

       	//internal structure of the pineline
		inst_NPC(s_b_hold,in_b_Clock,s_b_flush,s_n_PC,s_b_B,s_Result,s_n_NPC,s_b_RW_PC,l_REG_PC,l_n_Data_PC);
 		inst_IFStage(s_b_hold,in_b_Clock,s_b_flush,s_b_flush_2,s_n_NPC,
			         s_b_RW_PC,l_REG_PC,l_n_Data_PC,
			         // read memory
			         out_b_nRW,out_n_Addr,inout_n_Data,
					 //out to ID
			         s_n_Instruction,
					 s_n_PC
					 
					 );

		inst_IDStage(s_b_hold,in_b_Clock,s_b_is_branch,s_interrupt1,s_COND,signal_branch_taken_ID,s_b_flush_2,s_b_flush,
			         //input from IF
			         s_n_Instruction,  
					 s_n_PC,
					 //access register file
					 s_b_RW, l_REG,l_n_Data,
					 //ID to EX
					 s_A, s_B,
				     s_OP,s_SET,	      //controls of ALU
					 s_b_S,s_SHIFT_TYPE,s_b_is_mrt,s_n_Dist,        //controls of shifter
					 s_M,             //controls of multiplier
					 s_b_ls,s_Rn,s_b_Pre,s_b_Load,s_b_WB,//controls of MEM
					 s_Rd1,s_Rm,s_Rs,is_Rm,is_Rs
			         ); 
		inst_EXStage(s_b_hold,
						 out_b_nRW,out_n_Addr,inout_n_Data,
			in_b_Clock,s_b_is_branch,s_b_is_branch1,s_interrupt1,s_interrupt2,s_COND,signal_branch_taken_ID,s_b_flush_2,s_b_branch_taken,
			         s_b_B,//branch
					 s_b_RW1,l_REG1,l_n_Data1,
			         //access register file
					 s_b_RW2,l_REG2, l_n_Data2,
                      //A bus and B bus
			        s_Rd1,s_Rm,s_Rs,is_Rm,is_Rs,
					s_Rd2,
					s_A,s_B,s_OP,s_SET,
					s_b_S,s_SHIFT_TYPE,s_b_is_mrt,s_b_is_mrt1,s_n_Dist,
					s_M,//controls of multiplier
					s_b_ls,s_Rn,s_b_Pre,s_b_Load,s_b_WB,
					s_b_ls1,s_Rn1,//
                     
					s_b_Pre1,// alter base reg before?
					s_b_Load1,// load or store
					s_b_WB1,  //if i should write back to base reg?
                    s_n_Rn,
					s_Result,	s_b_write_Rd,s_n_Rd,
					s_b_excute,
					s_b_W_Rd,s_Rd3,s_Result1,s_b_WB2,s_Rn2,s_n_Rn1  
					);

		inst_MEMStage(in_b_Clock,s_interrupt2,s_b_branch_taken,s_b_excute,s_b_excute1,
			            
			//read/write meme
			 out_b_nRW,out_n_Addr,inout_n_Data,
            // 
            s_b_RW,l_REG,l_n_Data,
			s_Rd2,s_b_write_Rd,s_Rn1,s_n_Rn,
			s_b_ls1,s_b_is_mrt1,s_b_Pre1,s_b_Load1,s_b_WB1,
			s_Result,s_n_Rd,s_b_W_Rd,s_b_WB2,
			s_Rd3,s_Result1,s_Rn2,s_n_Rn1
			
			
			);
			inst_WBStage(in_b_Clock,s_b_excute1,
			s_Rd3,s_Result1,s_Rn2,s_n_Rn1,s_b_W_Rd,s_b_WB2,s_b_RW,l_REG,l_n_Data,s_b_RW2,l_REG2,l_n_Data2);	

	

	};
	virtual ~scARMCore();

private:

		void entry(void);
};

#endif // !defined(AFX_SCARMCORE_H__3D36E4DC_3B3D_11D6_B9E2_000000000000__INCLUDED_)
