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

#include "scID.h"
#include "scDP1.h"
#include "scDP2.h"
#include "scDP3.h"
#include "scB.h"
#include "scSW1.h"
#include "scSW2.h"
#include "scUNDEF.h"
#include "scSWI.h"
#include "scSWP.h"
#include "scMULT.h"
#include "scHWT.h"
#include "scMRT.h"
#include "scMRS.h"
#include "scCD.h"
#include "scCR.h"
#include "scCDP.h"
#include "scNOOP.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////





scID::~scID()
{

}

void  scID::entry()
{
  m_pc=in_n_PC;
 
  m_ir=in_n_Instruction;

  trigger0.notify(SC_ZERO_TIME);
}




// use little endian

scARMInstruction* scID::create_instru(uint32_t i)
{
  scARMInstruction* p;
  if((i&BRANCH_MASK)==BRANCH_SIG) p=new scB(i);
  else if((i & DP1_MASK) == DP1_SIG) p=new scDP1(i);
  else if((i & DP2_MASK) == DP2_SIG) p=new scDP2(i);
  else if((i & DP3_MASK) == DP3_SIG) p=new scDP3(i);
  else if((i & SWT1_MASK) == SWT1_SIG) p=new scSW1(i);
  else if((i & SWT2_MASK) == SWT2_SIG) p=new scSW2(i);

  else if((i & SWI_MASK)  == SWI_SIG) {  p=new scSWI(i);}

  else if((i & HWT_MASK)  == HWT_SIG)  p=new scHWT(i); 
  else if((i & SWP_MASK)  == SWP_SIG)  p=new scSWP(i);
  else if((i & MULT_MASK)  == MULT_SIG)  p=new scMult(i);
  else if((i & MRT_MASK)  == MRT_SIG)  p=new scMRT(i);
  else if((i & MRS_MASK)  == MRS_SIG)  p=new scMRS(i);
  else if((i & CDT_MASK)  == CDT_SIG)  p=new scCD(i);
  else if((i & CRT_MASK)  == CRT_SIG)  p=new scCR(i);
  else if((i & CDP_MASK)  == CDP_SIG)  p=new scCDP(i);
  else if((i & NOP_MASK)  == NOP_SIG)  p=new scNOOP(i);
  else
	  p=new scUNDEF(i);
  
  
  return p;
}


void scID::display()
{
	  s_is_mrt=m_b_is_mrt;
	 s_reg_in_list=m_reg_in_list-1;
  s_b_flush_debug=save_flush;
  if(s_b_flush_debug==1)
  {
	  flush_number=2;
	  s_b_flush_debug=0;
  }
  s_pc_debug=m_last_pc;
  s_ir_debug=m_last_ir;
  uint32_t temp=s_ir_debug;
  s_A_debug=m_A;
  s_dist_debug=m_Dist;
  s_B_debug=m_B;
  
  if(flush_number==0)
  {

  cout<<s_pc_debug<<":"<<s_ir_debug<<" ";

  scARMInstruction* j=create_instru(temp);

  if(((j->kind())=="DP1")||((j->kind())=="DP2")||((j->kind())=="DP3"))
  {
   switch(j->op())
   {
      case 0:  cout<<"AND"; break;     case 1:  cout<<"EOR"; break;
      case 2:  cout<<"SUB"; break;     case 3:  cout<<"RSB"; break;
      case 4:  cout<<"ADD"; break;     case 5:  cout<<"ADC"; break;
      case 6:  cout<<"SBC"; break;     case 7:  cout<<"RSC"; break;
      case 8:  cout<<"TST"; break;     case 9:  cout<<"TEQ"; break;
      case 10:  cout<<"CMP"; break;     case 11:  cout<<"CMN"; break;
      case 12:  cout<<"ORR"; break;     case 13:  cout<<"MOV"; break;
      case 14:  cout<<"BIC"; break;     case 15:  cout<<"MVN"; break;
      default: cout<<"unknow op"<<endl;
   }
  }
  else  cout<<j->kind();

  switch(j->cond())
  {
	case 0x0: cout<<"eq";break;  case 0x1:cout<<"ne";break;
	case 0x2: cout<<"cs";break;  case 0x3:cout<<"cc";break;
	case 0x4: cout<<"mi";break;  case 0x5:cout<<"pl";break;
	case 0x6: cout<<"vs";break;  case 0x7:cout<<"vc";break;
	case 0x8: cout<<"hi";break;  case 0x9:cout<<"ls";break;
	case 0xa: cout<<"ge";break;  case 0xb:cout<<"lt";break;
	case 0xc: cout<<"gt";break;  case 0xd:cout<<"le";break;
	case 0xe: cout<<"al";break;  case 0xf:cout<<"nv";break;
    default: cout<<"unknow condition"<<endl;
  }
      
  if(j->Rd()==R_PC)
	  {
		  cout<<" pc";
 }else{
		  if(s_is_mrt){
			  cout<<" r"<<s_reg_in_list;
		  }else
	   cout<<" r"<<(j->Rd());
  }


		   cout<<",[";
  
   if(j->A()==R_PC)
   {
      cout<<"pc ="<<hex<<(s_pc_debug+8)<<",";
   }else

     cout<<"r"<<(j->A())<<"="<<hex<<s_A_debug<<",";

	  
   if(j->is_imm())	cout<<"#0x";  else  cout<<"r"<<hex<<(j->B())<<"=";

  
   cout<<hex<<s_B_debug;

   if(j->is_shift()){
      
	   cout<<" shift "<<s_dist_debug;
   }

   cout<<"] "<<endl;
   delete j;
  }else
  {
	flush_number--;

    //cout<<"flush";
  }

}

void scID::regs()
{

	uint32_t R=0;
  	 cout<<"	";
		for(int i=0;i<15;i++)
		{
			
		     //out_b_RW=0;
		     out_REG=REGS(i);
		     R=inout_n_Data;
			 cout<<"r"<<i<<"="<<R<<" ";		
			 if((i==4)||(i==9)) cout<<endl<<"	";
		}
		cout<<endl;
}

void scID::delay1()
{
	next_trigger(trigger1	);
 
 	trigger2.notify(SC_ZERO_TIME);
}

void scID::delay2()
{
  next_trigger(trigger2);
	  scARMInstruction* i;
 if(in_b_hold==0){

	  i=create_instru(m_ir);
	  m_last_ir=m_ir;
	  m_last_pc=m_pc;
  }else
  {
     	  i=create_instru(m_last_ir);
	//	  cout<<"m_last_ir="<<m_last_ir<<endl;
  
  }

  //i=create_instru(m_ir);
  m_b_predict=predict();
  m_COND=i->cond();
  m_b_S=i->is_shift();
  m_b_ls=i->is_ls();
  m_Rn=i->Rn();
  m_Rd=i->Rd();
  m_b_Pre=i->pre();
  m_b_up=i->up();
  m_b_is_mrt=i->is_mrt();
  m_b_Load=i->load();
  m_b_WB=i->wb(); 
  m_SET=i->set();
  m_OP=i->op(); 
  m_SHIFT_TYPE=i->shift_type();
  if(m_b_is_mrt&&m_b_ls)
  {
	  
     m_Dist=0;
	 m_n_list=i->dist();
	 for(int i=0;i<=15;i++)
	 {
	   if((m_n_list&(0x1<<i))==(0x1<<i))
	   {
	       m_index++;
		 
	   }
	 }

	 for(m_reg_in_list;m_reg_in_list<=15;m_reg_in_list++)
	 {
		if((m_n_list&(0x1<<m_reg_in_list))==(0x1<<m_reg_in_list))
		{
     		m_Rd=REGS(m_reg_in_list);     
			m_order++;
			//cout<<"order="<<m_order<<endl;
			m_reg_in_list++;
            
			break;
		}
		
	 }
	 if(m_reg_in_list>15){
	    m_b_is_mrt=0;
	 }
	 if(m_reg_in_list>15)
	 {
	    m_reg_in_list=0;
		m_order=0;
			m_index=0;
	 }

	 
  }else
  {
     m_Dist=i->dist();      
     	m_Rd=i->Rd();  
			m_order=0;
			m_index=0;
  }
  m_b_M=i->is_mult();
  if(m_Rd==R_PC){
	//m_b_flush=i->is_branch();
	m_b_flush=1;
  }else
  {
   m_b_flush=0;
  }

  m_A=i->A();
  m_B=i->B();
  m_Rm=REGS(i->B());
  m_Rs=REGS(i->dist());
  is_Rm=(i->is_imm())?0:1;
  m_b_is_Rm=!(i->is_imm());
  m_b_is_Rs=i->is_rs();
 
  m_b_interrupt=0;
 
 delete i;
trigger2_1.notify(SC_ZERO_TIME);
 
}

void scID::delay3()
{
	 next_trigger(trigger3);
 
     if((save_flush==0)&&(in_b_flush_2==0))
	{
    out_n_A=m_A;
	out_n_B=m_B;
	//cout<<"A"<<m_A<<"B="<<m_B<<endl;
	//shift
	out_b_S=m_b_S;
	
	//cout<<endl<<(m_b_S?"shitf":"dont shift");
	out_n_Dist=m_Dist;
	//cout<<"ID; a="<<m_A<<" b="<<m_B<<" shift="<<m_Dist<<endl;
	out_SHIFT_TYPE=m_SHIFT_TYPE;
	//base and target
	out_Rn=m_Rn;
	out_Rd=m_Rd;
	//operator
	out_OP=m_OP;
    out_COND=m_COND;
    out_branch_taken=m_b_predict;
	out_b_flush=m_b_flush;
	out_b_ls=m_b_ls;
	out_b_Pre=m_b_Pre;
	out_b_Load=m_b_Load;
	out_b_WB=m_b_WB;
	//cout<<"WB?"<<(m_b_WB?"yes":"no")<<endl;
	out_SET=m_SET; 
    out_Rm=m_Rm;
	out_Rs=m_Rs;
	out_interrupt=m_b_interrupt;

    is_Rm=m_b_is_Rm;
	is_Rs=m_b_is_Rs;
	out_b_is_mrt=m_b_is_mrt;

	}else
	{
       out_b_is_mrt=0;
	out_n_A=0;
	out_n_B=0;
	out_n_Dist=0;
	out_Rn=R_R0;
	out_Rd=R_R0;
	out_OP=OP_CMP;
    out_COND=C_NV;
	out_SHIFT_TYPE=SHIFT(0);
	out_b_flush=0;
	out_b_ls=0;
	out_b_Pre=0;
	out_b_Load=0;
	out_b_WB=0;
	out_SET=0;  
	out_b_S=0;
	is_Rm=0;
	is_Rs=0;
	out_branch_taken=0;
	out_interrupt=0;
	} 
   save_flush=m_b_flush;
}

void scID::delay0()
{
	next_trigger(trigger0);


 	trigger0_1.notify(SC_ZERO_TIME);
}

void scID::delay0_1()
{ 
	next_trigger(trigger0_1);

 	trigger1.notify(SC_ZERO_TIME);
}

bool scID::predict()
{
  return 1;
}

void scID::delay2_1()
{
	next_trigger(trigger2_1);


    //read A
  if(m_b_flush)
  {
	  //
  	//out_b_RW=0;
	  //don't care, this value will be changed because of forwarding
	//out_REG=R_PC;
	//m_A=inout_n_Data;
	//cout<<"current pc="<<m_A<<endl;
	m_A=in_n_PC+8;
	m_b_flush=1;
	
  }else
  {

	//out_b_RW=0;
	 if(m_b_is_mrt==0)
	 {
		out_REG=REGS(m_A);
		m_A=inout_n_Data;
	 }else
	 {
		 //base
		 	out_REG=REGS(m_A);
			m_A=inout_n_Data;
		 //
	    if((m_b_Pre==0)&&(m_b_up==1))
		{
              m_A=m_A+(m_order-1)*4;

		}else if((m_b_Pre==1)&&(m_b_up==1))
		{ 
			m_A=m_A+(m_order-1+1)*4;
             
		}else if((m_b_Pre==0)&&(m_b_up==0))
		{
		
			m_A=m_A-m_index*4+(m_order-1)*4;
		}
		else if((m_b_Pre==1)&&(m_b_up==0))
		{
		   m_A=m_A-(m_index+1)*4+(m_order-1)*4;
		}
	 }
	//don't flush 
	m_b_flush=0;
	
  }
    if(m_b_is_Rm!=1)
  {
     
	m_B=m_B;
  }else
  {
    //out_b_RW=0;
	out_REG=REGS(m_B);
	m_B=inout_n_Data;

  }
     //RS or imm shift
  if(!(m_b_is_Rs))
  {


  }
  else 
  {
	//out_b_RW=0;
    out_REG=REGS(m_Dist);
	m_Dist=inout_n_Data;
	
	
  }
    if(m_b_ls)
  {
		 if(!(m_b_Load))
		 {
			 //out_b_RW=0;
			 out_REG=m_Rd;
			 //when is store, use out_b_Dist transfer data
             m_Dist=inout_n_Data;
			 m_b_is_Rs=false;
		 }


  }
	
	#if defined(DEBUG)
   
   display();
   //regs();
   	//out_REG=REGS(15);
	//uint32_t temp=inout_n_Data;
	//cout<<"pc:="<<temp<<endl;
#endif

   trigger3.notify(SC_ZERO_TIME);
}
