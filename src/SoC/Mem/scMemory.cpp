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
//  info   This is a SystemC ARM model,
// scMemory.cpp: implementation of the scMemory class.
//
//////////////////////////////////////////////////////////////////////

#include "scMemory.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


scMemory::~scMemory()
{

}



void scMemory::write_data()
{   
	sc_time temptime=sc_time_stamp();
  
 	if(in_b_nRW==1){
	   m_data[in_n_Addr]=inout_n_Data;
	   cout << "write time: " << temptime << endl;
	}  
}

void scMemory::read_data()
{
	//	if(in_b_nRW==0){
	   uint32_t addr=in_n_Addr;
	   addr=addr/4;
	   inout_n_Data=m_data[addr];

//
}
