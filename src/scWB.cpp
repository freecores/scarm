// scWB.cpp: implementation of the scWB class.
/*                            -------------------
    begin                : Oct 2 2002
    copyright            : (C) 2002 UESTC 
    author               : Zhong Tao
    email                : zhong@opencores.org
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#include "scWB.h"
//#define DEBUG
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

scWB::scWB(sc_module_name name_):sc_module(name_)
{
	m_Rn=REGS(13);
	m_Rd=REGS(13);
	m_n_Rn=0;
	m_n_Rd=0;
	m_b_excute=false;
	m_b_write=false;
	m_b_wb=false;
    SC_METHOD(entry);
	sensitive_pos<<in_b_Clock;
	SC_METHOD(out_delay);
	SC_METHOD(delay1);
}

scWB::~scWB()
{

}

void scWB::entry()
{

	m_Rd=in_Rd;
	m_Rn=in_Rn;
	m_n_Rd=in_n_Result;
	m_n_Rn=in_n_Rn;
    m_b_excute=in_b_excute;
	m_b_write=in_b_W_Rd;
	m_b_wb=in_b_WB;
if(m_b_excute)
{
	

  if((m_Rd!=R_PC)&&m_b_write)
  {

    inout_n_Data1=m_n_Rd;
  }
 
     if(m_b_wb)//write back
  {
 
    inout_n_Data2=m_n_Rn;
  }
  //regs();
  
}//if excute
trigger_wb1.notify(SC_ZERO_TIME);
}


void scWB::regs()
{
		//read CPSR
      uint32_t R=0;
	  	//	out_b_RW=0;
		out_REG1=R_PC;
		R=inout_n_Data1;
	  cout<<"	PC:"<<R;//0100
		//out_b_RW=0;
		out_REG1=R_CPSR;
		R=inout_n_Data1;
	  cout<<" CPSR:";//0100
  // Bit masks for CPSR
    if((R&N_FLAG)==N_FLAG) cout<<"N";else cout<<"n"; 
    if((R&Z_FLAG)==Z_FLAG) cout<<"Z"; else cout<<"z"; 
    if((R&C_FLAG)==C_FLAG) cout<<"C"; else cout<<"c"; 
    if((R&V_FLAG)==V_FLAG) cout<<"V"; else cout<<"v";
	cout<<"  "<<endl;
	//cout<<"WB"<<endl;
	
  	 cout<<"	";
		for(int i=0;i<15;i++)
		{
			
		     //out_b_RW1=0;
		     out_REG1=REGS(i);
		     R=inout_n_Data1;
			 cout<<"r"<<i<<"="<<R<<" ";		
			 if((i==4)||(i==9)) cout<<endl<<"	";
		}
		cout<<endl;
}

void scWB::out_delay()
{
  next_trigger(trigger_wb1);
  if(m_b_excute)
{
  
   if((m_Rd!=R_PC)&&m_b_write)
   {   
	  
      //cout<<"R"<<m_Rd<<"="<<m_n_Rd<<endl;
	  out_b_RW1=1;
      out_REG1=m_Rd;
	  inout_n_Data1=m_n_Rd;
   }

     if(m_b_wb)//write back
  {
       out_b_RW2=1;
	   out_REG2=m_Rn;
	   //cout<<"m_n_Rn="<<m_n_Rn<<endl;
       inout_n_Data2=m_n_Rn;
	 }
}
 //regs();
  //trigger_wb2.notify(SC_ZERO_TIME);

}

void scWB::delay1()
{
  next_trigger(trigger_wb2);
	 out_REG2=REGS(0);
  uint32_t temp=inout_n_Data2; 
  cout<<"	wb r0="<<temp;
    out_REG2=REGS(1);
   temp=inout_n_Data2; 
  cout<<" wb r1="<<temp;
      out_REG2=REGS(2);
   temp=inout_n_Data2; 
  cout<<" wb r2="<<temp;
    out_REG2=REGS(3);
   temp=inout_n_Data2; 
  cout<<" wb r3="<<temp<<endl;
}
