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
// scIF.h: interface for the scIF class.
//
//////////////////////////////////////////////////////////////////////


#include<systemc.h>
#include <sc_mslib.h>
#include "scTypes.h"
#include "scRegisterFile.h"
enum ARI {ARI_ALU, ARI_INC, ARI_REG, ARI_NONE};
class scIF:public sc_module 
{
public: //ports
	sc_in<bool>     in_b_hold;
	sc_in<bool> in_b_Clock;
	sc_in<bool> in_b_flush;
	sc_in<bool> in_b_flush_2;
	sc_in<uint32_t>  in_n_PC;
		//regs
	sc_outmaster<bool>        out_b_RW_pc;// 0-Read  1-Write
	sc_outmaster<REGS>     out_REG_pc;
	sc_inoutslave<uint32_t> inout_n_Data_pc;
	//Get Instruction
	sc_outmaster<bool>  out_b_nRW;
 	sc_outmaster<uint32_t> out_n_Addr;//  address bus
	sc_inoutslave<uint32_t>  inout_n_Data; //Instruction bus

	sc_out<uint32_t> out_n_Instruction;
	sc_out<uint32_t> out_n_PC;


public:
	void delay3( );
	void delay2();
	void delay1();
	void regs();
//	void out();
	SC_HAS_PROCESS(scIF);
	scIF(const sc_module_name name_):sc_module(name_)
	{
       m_b_start=true;     
	   m_nIR=0;
	   m_nPC=0;

       SC_METHOD(entry);
	   sensitive_pos<<in_b_Clock;
	   SC_METHOD(delay1);
	   SC_METHOD(delay2);
	   SC_METHOD(delay3);


 	}	
	virtual ~scIF();
private:
	uint32_t m_nPC;
	uint32_t m_nIR;

private:
  
	bool   m_b_flush;
	bool   m_b_start;
    sc_event trigger;
	sc_event trigger1_if,trigger2_if,trigger3_if;
private:
	
	uint32_t  read_mem_data(uint32_t);
	void entry(void);
	
};
