// scRegisterFile.cpp: implementation of the scRegisterFile class.
//
//////////////////////////////////////////////////////////////////////

#include "scRegisterFile.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////



scRegisterFile::~scRegisterFile()
{

}

void scRegisterFile::set_mode(MODE m)
{
	m_Mode=m;
	r[0]=m_r0=0;
    r[1]=m_r1=0x11;
	r[2]=m_r2=0x22;
	r[3]=m_r3=0x33;
	r[4]=m_r4=0x44;
	r[5]=m_r5=5;
	r[6]=m_r6=6;
	r[7]=m_r7=7;
	r[8]=m_r8=8;                  
	r[9]=m_r9=9;             
	r[10]=m_r10=10;           
	r[11]=m_r11;           
	r[12]=m_r12;          
	r[13]=m_r13;         
	r[14]=m_r14;           
	r[15]=m_r15;   
switch(m_Mode)
{
       
case M_USER:
	{
		//16 general register   
	  printf("M_USER Mode \n");   
	  break;
	  
    }
case M_FIQ://7 reg for FIQ mode 
	{
	r[8]=m_r8_fiq; 
	r[9]=m_r9_fiq;
	r[10]=m_r10_fiq; 
	r[11]=m_r11_fiq; 
	r[12]=m_r12_fiq;    
	r[13]=m_r13_fiq;
	r[14]=m_r14_fiq; 
	r[17]=m_spsr_fiq;
	printf("M_FIQ\n");
	break;
	}
case M_SVC : //2 reg for supervisor mode
	{
	r[13]=m_r13_svc;
	r[14]=m_r14_svc;
	r[17]=m_spsr_svc;
	break;
	}

case M_ABORT://2 reg for abort mode
	{
	r[13]=m_r13_abt;
	r[14]=m_r14_abt;
	r[17]=m_spsr_abt;
	break;
	}
case M_IRQ://2 m_reg for IRQ mode
	{
		r[13]=m_r13_irq;
		r[14]=m_r14_irq;
		r[17]=m_spsr_irq;
		break;
	}
case M_UNDEF://2 m_reg undefined instruction mode
	{
	r[13]=m_r13_und;
	r[14]=m_r14_und;
	r[17]=m_spsr_und;
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
	if(in_b_RW==0)
    {  
		inout_n_Data=r[i];
	}else
	{
		r[i]=inout_n_Data;
	}
}

void scRegisterFile::change_mode()
{  
   MODE temp;
   temp=in_MODE;
   set_mode(temp);
}
