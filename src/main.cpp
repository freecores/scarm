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
//  main.cpp -- This is a simple ARM core modeling with SystemC.
//               Architecure defined by Allen Tao Zhong.
//          
//  Original Author: Allen Tao Zhong,
//  University of Electronic Science and Technology in China
//  email: zhong@opencores.org
//  header main.h
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
#include "main.h"
#include  <stdlib.h>
#include "scTypes.h"
#include ".\SOC\scARMSoC.h"
#include ".\SOC\Mem\scMemory.h"
int sc_main(int ac, char *av[])
{
    // First check the args
  if (ac <= 1)
    {
      cout<< "Usage: scARM  sim_time  \n";
      exit (0);
    }
    int time=atoi(av[1]);

    sc_clock CLK("clock1",10,0.5,1,true);
    sc_link_mp<uint32_t> l_n_addr;
	sc_link_mp<uint32_t> l_n_data;
	
    scMemory ram("ram");
    scARMSoC processor("processor");
   
     ram(CLK,l_n_addr,l_n_data);
	 processor(CLK,l_n_addr,l_n_data);

  //start simulation

   sc_start(time);

 
 return (0);
}
// EOF