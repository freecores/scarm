// scIF.cpp: implementation of the scIF class.
//
//////////////////////////////////////////////////////////////////////

#include "scIF.h"
#include "scRAM.h"
#define DEBUG
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////



scIF::~scIF()
{

}

void scIF::entry()
{
	
	    //regs();
    m_nPC=in_n_PC;


    trigger1_if.notify(SC_ZERO_TIME);
}



uint32_t  scIF::read_mem_data(uint32_t addr)
{ 
  //out_b_nRW=0;
  out_n_Addr=addr;
  return inout_n_Data;
}




void scIF::regs()
{

}

void scIF::delay1()
{
	next_trigger(trigger1_if);

	trigger2_if.notify(SC_ZERO_TIME);
}

void scIF::delay2()
{
   next_trigger(trigger2_if);

   trigger3_if.notify(SC_ZERO_TIME);
}

void scIF::delay3( )
{

	next_trigger(trigger3_if);
	
if(in_b_hold==0)
{

	if(m_nPC==0) cout<<"start..."<<endl;
  	m_nIR=read_mem_data(m_nPC);

     out_n_PC=m_nPC; 		 	
		//stop machine
		if(m_nIR==(0x12345678)) sc_stop();
    if((in_b_flush==0)&&(in_b_flush_2==0))
	{
			out_n_Instruction=m_nIR;
		     
	}else
	{
		    out_n_Instruction=0xf1500000;
	}   	

}//hold

}
