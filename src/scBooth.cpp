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
// scBooth.cpp: implementation of the scBooth class.
//
//////////////////////////////////////////////////////////////////////

#include "scBooth.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////



scBooth::~scBooth()
{

}
///////////////////////////////////////////////////////////////////////////////
// carry_save_adder_32 - 32 bit carry save adder (well, what did you expect?).
//
void scBooth::carry_save_adder_32(uint32_t a, uint32_t b, uint32_t cin, 
			 uint32_t *res, uint32_t *cout)
{
  uint32_t ps, t1, t2;

  ps = a ^ b;
  *res = ps ^ cin;

  t1 = b & ~ps;
  t2 = cin & ps;
  *cout = t1 | t2;

  /*fprintf(stdout, "0x%08x 0x%08x 0x%08x 0x%08x 0x%08x\n", 
    a, b, cin, *res, *cout); 
    fflush(stdout);*/
}


#define SHIFT_LEFT(_x,_y)  ((_y >= 32) ? 0 : _x << _y)
#define SHIFT_RIGHT(_x,_y) ((_y >= 32) ? 0 : _x >> _y)
#define SIGNED_SHIFT_RIGHT(_x,_y) ((_y >= 32) ? ((_x >> 31) * 0xFFFFFFFF) : ((int32_t)_x) >> _y)

///////////////////////////////////////////////////////////////////////////////
// booth_stage_one - Does a single round of booths multiply algorithm. Note
//                   this works on 64 bits.
//
void scBooth::booth_one_stage(uint32_t* part_sum_hi, uint32_t* part_sum_lo, 
		     uint32_t* part_carry_hi, uint32_t* part_carry_lo, 
		     uint32_t mult, uint32_t N, bool_t* carry,
		     uint32_t multiplier, bool_t bSign)
{
  uint32_t temp;
  uint32_t srt;

  temp = multiplier & 0x3;
  temp |= (*carry == 1) ? 4 : 0;

  switch (temp)
    {
    case 0:
      carry_save_adder_32(*part_sum_lo, 0, *part_carry_lo,
			  part_sum_lo, part_carry_lo);
      carry_save_adder_32(*part_sum_hi, 0, *part_carry_hi,
			  part_sum_hi, part_carry_hi);
      break;
    case 1:
      carry_save_adder_32(*part_sum_lo, SHIFT_LEFT(mult,(2 * N)), 
			  *part_carry_lo,
			  part_sum_lo, part_carry_lo);
      srt = bSign == 0 ? SHIFT_RIGHT(mult,(32 - (2 * N))) :
	SIGNED_SHIFT_RIGHT(mult,(32 - (2 * N)));
      carry_save_adder_32(*part_sum_hi, srt, *part_carry_hi,
			  part_sum_hi, part_carry_hi);
      break;
    case 2:
      carry_save_adder_32(*part_sum_lo, ~(SHIFT_LEFT(mult,((2 * N) + 1))), 
			  (*part_carry_lo) | 0x1 , part_sum_lo, part_carry_lo);
      srt = bSign == 0 ? SHIFT_RIGHT(mult,(32 - ((2 * N) + 1))) :
	SIGNED_SHIFT_RIGHT(mult,(32 - ((2 * N) + 1)));
      carry_save_adder_32(*part_sum_hi, ~(srt), 
			  *part_carry_hi, part_sum_hi, part_carry_hi);
      break;
    case 3:
      carry_save_adder_32(*part_sum_lo, ~(SHIFT_LEFT(mult, (2 * N))), 
			  (*part_carry_lo) | 0x1 , part_sum_lo, part_carry_lo);
      srt = bSign == 0 ? SHIFT_RIGHT(mult, (32 - (2 * N))) : 
	SIGNED_SHIFT_RIGHT(mult, (32 - (2 * N)));
      carry_save_adder_32(*part_sum_hi, ~(srt), 
			  *part_carry_hi, part_sum_hi, part_carry_hi);
      break;
    case 4:
      carry_save_adder_32(*part_sum_lo, SHIFT_LEFT(mult, (2 * N)), 
			  *part_carry_lo,
			  part_sum_lo, part_carry_lo);
      srt = bSign == 0 ? SHIFT_RIGHT(mult, (32 - (2 * N))) :
	SIGNED_SHIFT_RIGHT(mult, (32 - (2 * N)));
      carry_save_adder_32(*part_sum_hi, srt, 
			  *part_carry_hi,
			  part_sum_hi, part_carry_hi);
      break;
    case 5:
      carry_save_adder_32(*part_sum_lo, SHIFT_LEFT(mult, ((2 * N) + 1)), 
			  *part_carry_lo,
			  part_sum_lo, part_carry_lo);
      srt = bSign == 0 ? SHIFT_RIGHT(mult, (32 - ((2 * N) + 1))) : 
	SIGNED_SHIFT_RIGHT(mult, (32 - ((2 * N) + 1)));
      carry_save_adder_32(*part_sum_hi, 
			  srt, 
			  *part_carry_hi, part_sum_hi, part_carry_hi);
      break;
    case 6:
      carry_save_adder_32(*part_sum_lo, ~(SHIFT_LEFT(mult,(2 * N))), 
			  (*part_carry_lo) | 0x1 , part_sum_lo, part_carry_lo);
      srt = bSign == 0 ? SHIFT_RIGHT(mult,(32 - (2 * N))) : 
	SIGNED_SHIFT_RIGHT(mult,(32 - (2 * N)));
      carry_save_adder_32(*part_sum_hi, 
			  ~(srt), 
			  *part_carry_hi, part_sum_hi, part_carry_hi);
      break;
    case 7:
      carry_save_adder_32(*part_sum_lo, 0, *part_carry_lo,
			  part_sum_lo, part_carry_lo);
      carry_save_adder_32(*part_sum_hi, 0, *part_carry_hi,
			  part_sum_hi, part_carry_hi);
      break;
    }

#if 0
  if (N < 15)
    *carry = (temp >> 1) & 0x1;
  else
    *carry = 0;
#else
    *carry = (temp >> 1) & 0x1;
#endif
}


///////////////////////////////////////////////////////////////////////////////
// four_stage_booth - Does four rounds of booths alg at once
//
void scBooth::four_stage_booth(uint32_t* part_sum_hi, uint32_t* part_sum_lo, 
		      uint32_t* part_carry_hi, uint32_t* part_carry_lo,
		      uint32_t mult, uint32_t N, bool_t* carry,
		      uint32_t* multiplier, bool_t bSign)
{
  for (int i = 0; i < 4; i++)
    {
      booth_one_stage(part_sum_hi, part_sum_lo, 
		      part_carry_hi, part_carry_lo,
		      mult, (N * 4) + i, 
		      carry, *multiplier, bSign);

      *part_carry_hi = (*part_carry_hi << 1) | (*part_carry_lo >> 31);
      *part_carry_lo = *part_carry_lo << 1;
      *multiplier = *multiplier >> 2;
    }
}



void scBooth::entry()
{
  out=a*b;
}
