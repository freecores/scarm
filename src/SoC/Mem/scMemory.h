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
//  scMemory.h: interface for the scMemory class.
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

#include<systemc.h>
#include <sc_mslib.h>
#include"scTypes.h"
class scMemory  :public sc_module
{
public:
	//sc_in<bool>          in_b_clock;
	sc_in<bool>          in_b_nRW;
	sc_inslave<uint32_t>      in_n_Addr;
	sc_inoutmaster<uint32_t>   inout_n_Data;
public:
	SC_HAS_PROCESS(scMemory);
	scMemory(sc_module_name name_):sc_module(name_)
	{
	  // 
		for(int i=0;i<=1024-1;i++)
		{
			m_data[i]=0xe1884aa3;//add ;
			
		}

		m_data[1]=0xe0805184;
		m_data[2]=0xe1530001;
		m_data[3]=0x401370a3;//cmp
		m_data[4]=0xe1884aa3;
		m_data[5]=0xe59f0024;
		m_data[6]=0xeb000002;
     //  SC_METHOD(entry);    	
	 //  sensitive_pos<<in_b_clock;

	   SC_SLAVE(read_data,in_n_Addr);
	 
	 //  SC_METHOD(write_data)
	 //  sensitive<<inout_n_Data;

	};
	virtual ~scMemory();

private:
	uint32_t m_data[1024];

private:
	
	void read_data(void);
	void write_data(void);

};
