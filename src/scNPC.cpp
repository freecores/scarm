// scNPC.cpp: implementation of the scNPC class.
//
//////////////////////////////////////////////////////////////////////

#include "scNPC.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

scNPC::scNPC(sc_module_name name_):sc_module(name_)
{
       m_b_start=1;
	   m_b_branch=0;
	   m_nNPC=0;
   	   SC_METHOD(next_pc);
	      sensitive<<in_b_Clock;
	   SC_METHOD(write_pc);
	   SC_METHOD(delay1);
	   SC_METHOD(delay2);
	   SC_METHOD(delay3);
}

scNPC::~scNPC()
{

}

void scNPC::next_pc()
{
   m_b_B=in_b_B;
   m_n_B=in_n_B;
   m_PC=in_PC;

      trigger1_npc.notify(SC_ZERO_TIME);
 
 
}

void scNPC::write_pc()
{
	next_trigger(trigger);

	out_b_RW_PC=1;// 0-Read  1-Write
    out_REG_PC=R_PC;
   	out_n_NPC=m_nNPC;
}

void scNPC::delay1 ()
{
	next_trigger(trigger1_npc);

    trigger2_npc.notify(SC_ZERO_TIME);
}

void scNPC::delay2()
{
	next_trigger(trigger2_npc);

   trigger3_npc.notify(SC_ZERO_TIME);
}

void scNPC::delay3()
{
	next_trigger(trigger3_npc);
if(in_b_hold==0)
{
 	if(m_b_B==0){
	
		m_nNPC=m_PC+4;
	}
	else	
	{
		m_nNPC=m_n_B;
		
	}

 
	//cout<<"bengin write pc"<<endl;

	inout_n_Data_PC=m_nNPC;

       trigger.notify(SC_ZERO_TIME);
	//cout<<"endl write pc"<<endl;
}

}
