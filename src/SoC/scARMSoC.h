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
 
/*****************************************************************************
 
  MODIFICATION LOG - modifiers, enter your name, affiliation, date and
  changes you are making here.
 
      Name, Affiliation, Date:
  Description of Modification:
 
 *****************************************************************************/
// scARMSoC.h: interface for the scARMSoC class.
//
//////////////////////////////////////////////////////////////////////


#include<systemc.h>
#include <sc_mslib.h>
#include "scTypes.h"
//components
#include ".\core\scARMCore.h"

class scARMSoC:public sc_module
{
public://ports

	//sc_in<bool_t>        in_b_nRESET;
	sc_in<bool>          in_b_Clock;
	//link with memory 
	//sc_out<bool>        out_b_nRW;
	sc_outmaster<uint32_t>     out_n_A;
	sc_inoutslave<uint32_t>   inout_n_D;
 //***********************************
 //  port unused	
 //********************************
//	sc_in<bool_t>        in_b_nIRQ;
//	sc_in<bool_t>        in_b_nFIQ;
	
//	sc_in<bool_t>        in_b_nBW;

public:
	SC_HAS_PROCESS(scARMSoC);
	scARMSoC(sc_module_name name_):sc_module(name_),
		m_ARMCore("core")
	{
      // SC_METHOD(write_addr);
	  // sensitive<<in_b_Clock;
       //SC_SLAVE(read_data,inout_n_D);    	
	   //internal links
	   m_ARMCore(in_b_Clock,out_n_A,inout_n_D);
	};

	virtual ~scARMSoC();

private:
	scARMCore m_ARMCore;

};
