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
enum ARI {ARI_ALU, ARI_INC, ARI_REG, ARI_NONE};
class scIF:public sc_module 
{
public: //ports
	sc_in<bool> in_b_Clock;
	
 	sc_outmaster<uint32_t> out_n_Addr;//  address bus
	sc_inoutslave<uint32_t>  inout_n_Data; //Instruction bus
	sc_in<uint32_t>  in_n_PC;
	sc_out<uint32_t> out_n_Instruction;
	sc_out<uint32_t> out_n_NPC;
	sc_in<bool_t>    in_b_Flush;
		
public:
	

	SC_HAS_PROCESS(scIF);
	scIF(const sc_module_name name_):sc_module(name_)
	{
      
       //s_n_IR=0;//nop
	   
	   SC_METHOD(entry);
	   sensitive_pos<<in_b_Clock;
         
       SC_METHOD(increase_pc);
	   sensitive<<s_n_IR;

	}	
	virtual ~scIF();
private:
	sc_signal<uint32_t> s_n_IR;
	sc_signal<uint32_t> s_n_NPC;


private:
	void increase_pc();
	uint32_t  read_mem_data(uint32_t);
	void entry(void);
	
};
