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
//  scRAM.h: interface for the scRAM class.
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
#if !defined(SCRAM_H)
#define SCRAM_H
#include<systemc.h>
#include <sc_mslib.h>
#include"scTypes.h"
const int SIZE_OF_MEM=1024*64;
class scRAM  : public sc_module
{
public:
	sc_in<bool>         clock;
	sc_inslave<bool>               nRW;
	sc_inslave<uint32_t>      A;
	sc_inoutmaster<uint32_t>  D;
public: 
	void interrupt();
	void rw();
	void entry();
	void dump(uint32_t);
	bool load_program(char*);
	SC_HAS_PROCESS(scRAM);
	scRAM(sc_module_name name_);
	virtual ~scRAM();

private:
	uint32_t m_data[SIZE_OF_MEM];
	bool m_rw;

private:
	
	void read_data(void);
	void write_data(void);

};
#endif