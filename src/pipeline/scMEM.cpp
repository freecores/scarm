// scMEM.cpp: implementation of the scMEM class.
//
//////////////////////////////////////////////////////////////////////

#include "scMEM.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


scMEM::~scMEM()
{

}

void scMEM::entry()
{
  sc_time local_time = sc_time_stamp();
  cout<<"MEMtime="<<local_time<<"--"<<endl;
    out_Rd=in_Rd;
    out_b_Flush=in_b_Branch;
	bool_t temp=in_b_Branch;
    if(in_b_Branch==1)//if 
    {
		out_n_NPC=in_n_ALUOutput;
		out_n_MEMtoWB=0;
	}
	if(temp==0)
	{
		//decide 
        out_n_Addr=in_n_ALUOutput;
		s_n_LMD=inout_n_Data;

	}

}

