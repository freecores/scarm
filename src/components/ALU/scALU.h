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
//  info   This is a SystemC ARM model,I "stole" some codes from 
//       "swarm" , author Michael Dales (michael@dcs.gla.ac.uk)
//  scALU.h: interface for the scALU class.
//
//////////////////////////////////////////////////////////////////////

#ifndef ALU_H
#define ALU_H
#include"scTypes.h"
#include<systemc.h>
#include<sc_mslib.h>
enum ALU_AI {AI_NORM = 0, AI_HACK, AI_MAGIC, AI_MULT_LO, AI_MULT_HI};
enum ALU_BI {BI_NORM = 0, BI_HACK, BI_NULL, BI_MULT_LO, BI_MULT_HI};
enum COND {C_EQ = 0x0, C_NE = 0x1, C_CS = 0x2, C_CC = 0x3, 
	   C_MI = 0x4, C_PL = 0x5, C_VS = 0x6, C_VC = 0x7, 
	   C_HI = 0x8, C_LS = 0x9, C_GE = 0xA, C_LT = 0xB,
           C_GT = 0xC, C_LE = 0xD, C_AL = 0xE, C_NV = 0xF};
enum OPCODE {OP_AND = 0x00, OP_EOR = 0x01, OP_SUB = 0x02, OP_RSB = 0x03,
	     OP_ADD = 0x04, OP_ADC = 0x05, OP_SBC = 0x06, OP_RSC = 0x07,
	     OP_TST = 0x08, OP_TEQ = 0x09, OP_CMP = 0x0A, OP_CMN = 0x0B,
	     OP_ORR = 0x0C, OP_MOV = 0x0D, OP_BIC = 0x0E, OP_MVN = 0x0F};
class scALU:public sc_module  
{
public://ports
	sc_in<OPCODE>    in_OP;
    sc_in<COND>      in_COND;
	sc_in<uint32_t>  in_n_A;
	sc_in<uint32_t>  in_n_B;
    sc_out<uint32_t> out_n_Out;
	sc_out<uint32_t> out_n_Flag;
public:
	SC_HAS_PROCESS(scALU);
	scALU(sc_module_name name) : sc_module(name)
    {
       SC_METHOD(entry);
	   sensitive<<in_n_B<<in_n_A<<in_OP<<in_COND;
    }
	virtual ~scALU();
private://implementation 
	void entry(void);
 typedef uint32_t alu_fn(uint32_t a, uint32_t b, uint32_t* cont);

	   alu_fn and_op;
	   alu_fn eor_op;
	   alu_fn sub_op;
	   alu_fn rsb_op;
	   alu_fn add_op;
	   alu_fn adc_op;
	   alu_fn sbc_op;
	   alu_fn rsc_op;
	   alu_fn tst_op;
	   alu_fn teq_op;
	   alu_fn cmp_op;
	   alu_fn cmn_op;
	   alu_fn orr_op;
	   alu_fn mov_op;
	   alu_fn bic_op;
	   alu_fn mvn_op;

};
#endif
