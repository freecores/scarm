// scIF.cpp: implementation of the scIF class.
//
//////////////////////////////////////////////////////////////////////

#include "scIF.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////



scIF::~scIF()
{

}

void scIF::entry()
{   
  uint32_t addr=in_n_PC;
 
  s_n_IR=read_mem_data(addr);
  out_n_Instruction=s_n_IR;//output instruction
 
sc_time local_time = sc_time_stamp();
cout<<"IF time="<<local_time<<" Addr="<<addr<<" CurrentIR="<<hex<<s_n_IR<<endl;
    
}



uint32_t  scIF::read_mem_data(uint32_t addr)
{ 

  out_n_Addr=addr;
  uint32_t temp;
  temp=inout_n_Data;
  return temp;
}

void scIF::increase_pc()
{
 
   out_n_NPC=in_n_PC+4;
 
}
