// scRegisterFile.cpp: implementation of the scRegisterFile class.
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

#include "scRegisterFile.h"
#define DEBUG
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////



scRegisterFile::~scRegisterFile()
{

}

void scRegisterFile::set_mode(enum MODE m)
{
	m_Mode=m;
	r[0]=&m_r0;
    r[1]=&m_r1;
	r[2]=&m_r2;
	r[3]=&m_r3;
	r[4]=&m_r4;
	r[5]=&m_r5;
	r[6]=&m_r6;
	r[7]=&m_r7;
	r[8]=&m_r8;                  
	r[9]=&m_r9;             
	r[10]=&m_r10;           
	r[11]=&m_r11;           
	r[12]=&m_r12;          
	r[13]=&m_r13;         
	r[14]=&m_r14;           
	r[15]=&m_r15; 
	r[16]=&m_cpsr;
	r[17]=&m_spsr;
switch(m_Mode)
{
       
case M_USER:
	{
		//16 general register   
	  //printf("M_USER Mode \n");   
	  break;
	  
    }
case M_FIQ://7 reg for FIQ mode 
	{
	r[8]=&m_r8_fiq; 
	r[9]=&m_r9_fiq;
	r[10]=&m_r10_fiq; 
	r[11]=&m_r11_fiq; 
	r[12]=&m_r12_fiq;    
	r[13]=&m_r13_fiq;
	r[14]=&m_r14_fiq; 
	r[17]=&m_spsr_fiq;
	printf("M_FIQ\n");
	break;
	}
case M_SVC : //2 reg for supervisor mode
	{
	r[13]=&m_r13_svc;
	r[14]=&m_r14_svc;
	//r[17]=&m_spsr_svc;
	m_spsr_svc=m_cpsr;
	break;
	}

case M_ABORT://2 reg for abort mode
	{
	r[13]=&m_r13_abt;
	r[14]=&m_r14_abt;
	r[17]=&m_spsr_abt;
	break;
	}
case M_IRQ://2 m_reg for IRQ mode
	{
		r[13]=&m_r13_irq;
		r[14]=&m_r14_irq;
		r[17]=&m_spsr_irq;
		break;
	}
case M_UNDEF://2 m_reg undefined instruction mode
	{
	r[13]=&m_r13_und;
	r[14]=&m_r14_und;
	r[17]=&m_spsr_und;
	break;
	}
default:
	{
      cout<<"error in Regsiger File"<<endl;	
	}
}//end of switch (m_Mode)

}

void scRegisterFile::entry()
{
	uint32_t i=in_REG;
	#if defined(DEBUG)
	if(i>0x11) {
	 cout<<" error00:try to access register which doesn't exist. "<<endl;
	 sc_stop();
	}
#endif
	if(m_rw==0)
    {  
		inout_n_Data=*(r[i]);
         //cout<<"read port0:"<<"r"<<hex<<i<<"="<<inout_n_Data<<endl;
	}else
	{	//cout<<"port0:"<<"r"<<hex<<i<<"="<<inout_n_Data<<endl;
		(*r[i])=inout_n_Data;
        m_rw=0;
	}
}

void scRegisterFile::change_mode()
{  
   MODE temp;
   temp=in_MODE;
   set_mode(temp);
}

void scRegisterFile::entry1()
{


	uint32_t i=in_REG1;

	#if defined(DEBUG)
	if(i>0x11) {
		cout<<" error01:try to access register which doesn't exist. "<<endl;
	 sc_stop();
	}
#endif
	if(m_rw==0)
    {  
		inout_n_Data1=(*r[i]);
	
	}else
	{
		(*r[i])=inout_n_Data1;
		
	//	cout<<"port1:"<<"r"<<hex<<i<<"="<<inout_n_Data1<<endl;

	    m_rw=0;
	}

}

void scRegisterFile::entry2()
{
  	uint32_t i=in_REG2;
	#if defined(DEBUG)
	if(i>0x11) {
	 cout<<" error02:try to access register which doesn't exist. "<<endl;
	 sc_stop();
	}
#endif
	if(m_rw==0)
    {  
		inout_n_Data2=*r[i];
	//	cout<<(*r[15])<<"read reg"<<endl;
	}else
	{
		(*r[i])=inout_n_Data2;
	//	cout<<"port2:"<<"r"<<hex<<i<<"="<<inout_n_Data2<<endl;
		m_rw=0;
	}
}

void scRegisterFile::entry4()
{
  	uint32_t i=in_REG_PC;
#if defined(DEBUG)
	if(i>0x11) {
	 cout<<" error04:try to access register which doesn't exist. "<<endl;
	 sc_stop();
	}
#endif
	if(m_rw==0)
    {  
		inout_n_Data_PC=*r[i];
	}else
	{
		*r[i]=inout_n_Data_PC;
		//	cout<<"port pc:"<<hex<<(*r[15])<<"="<<hex<<inout_n_Data_PC<<endl;
		m_rw=0;
	}
}

void scRegisterFile::display()
{

  cout<<"		  PC:"<<hex<<m_r15;
  cout<<"   CPSR:";//0100
  // Bit masks for CPSR
    if((m_cpsr&N_FLAG)==N_FLAG) cout<<"N";else cout<<"n"; 
    if((m_cpsr&Z_FLAG)==Z_FLAG) cout<<"Z"; else cout<<"z"; 
    if((m_cpsr&C_FLAG)==C_FLAG) cout<<"C"; else cout<<"c"; 
    if((m_cpsr&V_FLAG)==V_FLAG) cout<<"V"; else cout<<"v"<<endl; 

  cout<<"		 r0="<<hex<<m_r0;
  cout<<" r1="<<hex<<m_r1;
  cout<<" r2="<<hex<<m_r2;
  cout<<" r3="<<hex<<m_r3;
  cout<<" r4="<<hex<<m_r4;
  cout<<" r5="<<hex<<m_r5;
  cout<<" r6="<<hex<<m_r6;
  cout<<" r7="<<hex<<m_r7<<endl;
  cout<<"		 r8="<<hex<<m_r8;
  cout<<" r9="<<hex<<m_r9;
  cout<<" r10="<<hex<<m_r10;
  cout<<" r11="<<hex<<m_r11;
  cout<<" r12="<<hex<<m_r12;
  cout<<" r13="<<hex<<m_r13;
  cout<<"link="<<hex<<m_r14<<endl<<endl;


}

void scRegisterFile::rw()
{
       m_rw=1;
}
void scRegisterFile::rw1()
{
       m_rw=1;
	   
}
void scRegisterFile::rw2()
{
       m_rw=1;
}
void scRegisterFile::rw4()
{
       m_rw=1;
}

void scRegisterFile::show()
{

}
