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
// scPCMux.h: interface for the scPCMux class.
//
//////////////////////////////////////////////////////////////////////


#include <systemc.h>
#include "scTypes.h"

class scPCMux : public sc_module  
{
public:
    sc_out<uint32_t> out_n_PC;
	sc_in<bool_t>    in_b_Branch;
	sc_in<uint32_t>  in_n_NPC;
	sc_in<uint32_t>  in_n_ALUOut;


private:
	sc_signal<uint32_t> s_n_PC;

public:
	SC_HAS_PROCESS(scPCMux);
	scPCMux(const sc_module_name name_):sc_module(name_)
	{
       SC_METHOD(entry);
	   sensitive<<in_n_NPC<<in_n_ALUOut;
	}
	virtual ~scPCMux();
private:

	void entry(void);
};
