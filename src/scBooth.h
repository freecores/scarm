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
// scBooth.h: interface for the scBooth class.
//
//////////////////////////////////////////////////////////////////////


#include<systemc.h>
#include"scTypes.h"
enum MUL_OP {M_MUL = 0x0, M_MLA = 0x1, M_UMULL = 0x4, M_UMLAL = 0x5,
	     M_SMULL = 0x6, M_SMLAL = 0x7};
class scBooth  :public sc_module
{
public:
	sc_in<uint32_t> a;
    sc_in<uint32_t> b;
	sc_out<uint32_t> out;

public:
	void entry();
	SC_HAS_PROCESS(scBooth);//
	scBooth(sc_module_name name) : sc_module(name)
    {
          SC_METHOD(entry);
		  sensitive<<a<<b;
    }
	virtual ~scBooth();
private:
	void carry_save_adder_32(uint32_t a, uint32_t b, uint32_t cin, 
			 uint32_t *res, uint32_t *cout);
	void four_stage_booth(uint32_t* part_sum_hi, uint32_t* part_sum_lo, 
		      uint32_t* part_carry_hi, uint32_t* part_carry_lo,
		      uint32_t mult, uint32_t N, bool_t* carry,
		      uint32_t* multiplier, bool_t bSign);
	void booth_one_stage(uint32_t* part_sum_hi, uint32_t* part_sum_lo, 
		     uint32_t* part_carry_hi, uint32_t* part_carry_lo, 
		     uint32_t mult, uint32_t N, bool_t* carry,
		     uint32_t multiplier, bool_t bSign);
};
