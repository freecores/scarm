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
// scID.cpp: implementation of the scID class.
//
//////////////////////////////////////////////////////////////////////

#include "..\pipeline\scID.h"
#include "..\instructions\scARMInstruction.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////




scID::~scID()
{

}

void  scID::entry()
{
//if branch is taken
  if(s_b_Branch==0)
  {
	s_n_IR=in_n_Instruction;
  } else
  {
    s_n_IR=0;
  }
}



void scID::output()
{
  out_b_MEM=s_b_MEM;
  out_Rd=s_Rd;
  out_OP=s_OP;
  out_COND=s_COND;
sc_time local_time = sc_time_stamp();
cout<<"ID time="<<local_time<<"--"<<endl;
  
  //Is the excutive order  important?
  out_SHIFT=s_SHIFT_TYPE;
  out_n_Dist=s_ShiftDist;
//choose the suitable output;
  cout<<"  OPCODE="<<s_OP;
  cout<<"  SHIFT="<<s_SHIFT_TYPE<<" Dist="<<s_ShiftDist;
  cout<<"  Rd="<<s_Rd;
  //A Bus
  if(1)
  {
  out_REG=s_Rn;
  out_n_A=in_n_RegData;
  cout<<"  R"<<s_Rn<<"="<<in_n_RegData;
  }else
  {
    cout<<"  Branch="<<in_n_NPC<<endl;
	out_n_A=in_n_NPC;
	;// Rn=PC
  }

  //B bus
  bool_t bSet=s_Set;
  if(bSet==0)   
  {
	  out_REG=s_Rm;
      out_n_B=in_n_RegData;
	  cout<<"  R"<<s_Rm<<"="<<in_n_RegData<<endl;
  }
  else if(bSet==1)
  {
	  out_n_B=s_n_Imm;
	  cout<<"  Imm"<<"="<<s_n_Imm<<endl;
  }
  

}
