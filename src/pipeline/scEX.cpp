// scEX.cpp: implementation of the scEX class.
//
//////////////////////////////////////////////////////////////////////

#include "scEX.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////



scEX::~scEX()
{

}

void scEX::entry()
{

s_OP=in_OP;
s_COND=in_COND;
s_n_A=in_n_A;
s_SHIFT=in_SHIFT;
s_n_Dist=in_n_Dist;
s_n_B=in_n_B;
}



void scEX::output()
{
 sc_time time=sc_time_stamp();
 cout<<"EX:time="<<time<<"----"<<endl;
 out_n_ALUOutput=s_n_ALUOutput;
 out_b_Flush=in_b_Branch;
 out_b_MEM=in_b_MEM;
 out_Rd=in_Rd;
}
  

