// scEX.cpp: implementation of the scEX class.
//
//////////////////////////////////////////////////////////////////////

#include "scEX.h"
#define DEBUG


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

scEX::scEX(sc_module_name name_):sc_module(name_)
  ,mult("mutiplier")
  ,bsh("shifter")
  ,alu("alu")
{
	m_last_Rd=REGS(0);
	m_b_last_Load=false;
	m_last_OP=OP_TST;
	 m_is_Rs=false;
	 m_is_Rm=false;
	 m_b_last_excute=false;
	 m_b_last_branch=false;

#if defined(DEBUG)
	flush_number=0;
#endif
	m_Rn=REGS(0);
    SC_METHOD(entry);
	sensitive_pos<<in_b_Clock;
	SC_METHOD(shift_delay);
	SC_METHOD(middle);
	SC_METHOD(out);
	SC_METHOD(out_delay);
	SC_METHOD(alu_delay);
	SC_METHOD(delay1);
	SC_METHOD(delay2);
	SC_METHOD(delay3);
	SC_METHOD(write_lr);

	
	mult(s_A_Mult,s_B_Mult,s_mult_out);
	 
	bsh(s_shift_in,s_shift_type,s_shift_dist,s_shift_out,s_carry,out_b_RW,out_REG,inout_n_Data);

	alu(s_OP,s_A,s_B,s_alu_out,s_n_CPSR);
}

scEX::~scEX()
{
}

void scEX::entry()
{  

        m_predict=in_branch_taken;
		m_b_interrupt=in_interrupt;
        m_b_is_mrt=in_b_is_mrt;
		m_COND=in_COND;
		m_A=in_A;
	    m_B=in_B;
 		m_Rd=in_Rd;
      	m_Rn=in_Rn;
        m_OP=in_OP;
        m_SET=in_SET;
	    m_b_S=in_b_S;
	    m_SHIFT_TYPE=in_SHIFT_TYPE;
	    m_n_Dist=in_n_Dist;
		
	m_b_M=in_b_M;
    m_b_ls=in_b_ls;//is it load/store instruction
    m_Rn=in_Rn; //base adress register
	m_b_Pre=in_b_Pre;// alter base reg before?
	m_b_Load=in_b_Load;// load or store
    m_b_WB=in_b_WB;  //if i should write back to base reg?
	m_is_Rm=is_Rm;
	m_Rm=in_Rm;
	m_is_Rs=is_Rs;
	m_Rs=in_Rs;
	//forwarding
 	m_is_write_Rd=in_is_write_Rd;
	m_Rd_from_mem=in_Rd_from_mem;//target
	m_n_Result_from_mem=in_n_Result_from_mem;
	m_b_WB_from_mem=in_b_WB_from_mem;
	m_Rn_from_mem=in_Rn_from_mem;//write-back register
	m_n_Rn_from_mem=in_n_Rn_from_mem; //write-back data 
	//cout<<"exe0 Rd r="<<in_Rd_from_mem<<":"<<in_n_Result_from_mem<<endl;//target
	//
	//cout<<"stage1a: a="<<m_A<<" b="<<m_B<<" shift="<<m_n_Dist<<endl;
 
    forwarding_pc();

  

	
   //display();

 trigger01_ex.notify(SC_ZERO_TIME);//trigger shift_delay()

}

void scEX::out(  )
{
 
  next_trigger(trigger4);
    //  cout<<"reslut="<<s_alu_out<<endl;
 if((m_b_excute)||(m_Rd==R_PC))
 {
	 //cout<<"entry"<<endl;
 	uint32_t temp;
     out_Rd=m_Rd;
	
     //branch
	 if(m_Rd==R_PC)
     {
		 	out_REG=R_PC;
			temp=inout_n_Data;
            if(m_b_excute==1)
			{
				out_REG=R_PC;
				temp=inout_n_Data;
				if(m_b_excute==m_predict)
				{
					m_b_branch=1;
				//	cout<<"exe   c w"<<endl;
		            m_n_Result=s_alu_out;     
				}
				else{ 
				//	cout<<"exe  e w"<<endl;
                    m_n_Result=s_alu_out;
					//cout<<"m_n_Result="<<m_n_Result<<endl;
					m_b_branch=1;
					//cout<<"  dont write Pc ex=1"<<endl;
				}
				 if(m_b_WB&&m_b_branch)//bl wirte r14
				 {
				   //read old pc	
					//out_b_RW=0;
						out_REG=R_PC;
						temp=inout_n_Data;
					//write to link reg
					//can not work correctly, should debug
				//	out_b_RW_link=1;
					out_REG_link=R_LR;
					inout_n_Data_link=temp-4;
					trigger_write_lr.notify(SC_ZERO_TIME);
				}
		     
		}else if((m_b_excute==0)&&(m_Rd==R_PC))
		{
		        		//;
			//cout<<"   b dont excute"<<endl;
			out_REG=R_PC;
			temp=inout_n_Data;
		    
			if(m_b_excute==m_predict)
			{
					//cout<<"nexe c w"<<endl;
					m_b_branch=0;
					m_n_Result=s_alu_out;          
				
				
			}
			else{ 
				//	cout<<"nexe e w"<<endl;
					m_b_branch=1;
					if(m_predict==1)
                    { 
					   	///cout<<"predict=1";
						//cout<<" write Pc ex=0"<<endl;
						m_n_Result=temp-4;
					}else
					{
					  //  cout<<"predict=0";
					   	//cout<<" write Pc ex=0"<<endl;
						m_n_Result=s_alu_out;
					}
			}

		}
	
        	m_b_last_branch=m_b_branch;
            out_b_hold=m_b_hold;
	 }else 
	 {
		 //cout<<"branch=0"<<endl;
		m_n_Result=s_alu_out;
	    m_b_branch=0;
		m_b_last_branch=0;
		m_b_hold=0;
		
	 } 
	  out_b_hold=m_b_hold;
	 
	out_n_Result=m_n_Result;
    out_b_Branch=m_b_branch;
     out_b_excute=m_b_excute;	  
	 out_b_ls=m_b_ls;
      out_Rn=m_Rn; //base adress register
	 
     out_n_Rn=m_A;//content of base addr reg
    
     out_b_Pre=m_b_Pre;// alter base reg before?
	 out_b_Load=m_b_Load;// load or store
     out_b_WB= m_b_WB;  //if i should write back to base reg?
      out_is_mrt=m_b_is_mrt;
	 out_interrupt=m_b_interrupt&&m_b_excute;
 

	// out_b_write_Rd=(m_Rd!=R_PC)&&(m_b_ls)&&(m_OP!=OP_TEQ)&&(m_OP!=OP_TST)&&(m_OP!=OP_CMP)&&(m_OP!=OP_CMN);
	
  out_b_write_Rd=(m_OP!=OP_TEQ)&&(m_OP!=OP_TST)&&(m_OP!=OP_CMP)&&(m_OP!=OP_CMN);
  

	 //save for forwarding()
     
	 m_last_Result=s_alu_out;
	 m_b_last_ls=m_b_ls;
	 m_last_Rd=m_Rd;
	 m_last_Rn=m_Rn;
	 m_b_last_WB=m_b_WB;
	 m_b_last_is_Rs=m_is_Rs;
	 m_b_last_is_Rm=m_is_Rm;
	 m_last_OP=m_OP;
	 m_b_last_Load=m_b_Load;
	 m_b_last_excute=m_b_excute;
	 //cout<<"stage3:result"<<s_alu_out<<endl;

	 	  //set CPSR
	 if((m_SET==1)&&(m_Rd!=R_PC)){
       //s_carry
		 /*The logical
operations (AND, EOR, TST, TEQ, ORR, MOV, BIC, MVN) perform the logical action
on all corresponding bits of the operand or operands to produce the result.
If the S bit is set (and Rd is not R15, see below) the V flag in the CPSR will be unaffected, the C
flag will be set to the carry out from the barrel shifter (or preserved when the shift
operation is LSL #0), the Z flag will be set if and only if the result is all zeros, and the
N flag will be set to the logical value of bit 31 of the result.
		*/
	
		 if((m_OP==OP_AND)||(m_OP==OP_EOR)||(m_OP==OP_TST)||(m_OP==OP_TEQ)||(m_OP==OP_ORR)||(m_OP==OP_BIC)||(m_OP==OP_MVN)||(m_OP==OP_MOV))
		 {
			 //cout<<"logic op "<<hex<<m_n_CPSR<<endl;
			 //logic op
			if(!((m_SHIFT_TYPE==S_LSL)&&(m_n_Dist==0)))
			{
		     if(s_carry==1)
			 {
				 m_n_CPSR=m_n_CPSR|C_FLAG;
			 };
			 if(s_alu_out==0) 
			 {
				 m_n_CPSR=m_n_CPSR|Z_FLAG;
			 };
			 uint32_t temp=s_n_CPSR;
			 temp=temp>>31;
			 m_n_CPSR=temp?(m_n_CPSR|N_FLAG):(m_n_CPSR);
			}
             
		 }else
		 {
			 //arithmetic operations (SUB, RSB, ADD, ADC, SBC, RSC, CMP, CMN)
			 
		      m_n_CPSR=s_n_CPSR;
			
		 }

	
		inout_n_Data=m_n_CPSR;
		 //cout<<"CPSddR "<<hex<<m_n_CPSR<<endl;
		  trigger5.notify(SC_ZERO_TIME);
	
	 }

	 if(m_b_ls)//If is it a load/store instruction?
	 { 
		
		if(!m_b_Load)//store Rd to memory
		{
			//out_b_RW=0;
			out_REG=m_Rd;
			out_n_Rd=inout_n_Data;
		 }
	}
 }else
 {
    	 out_b_Branch=0; 
		out_b_excute=0;
        //cout<<endl;
    
 }//is excute;

}

void scEX::middle()
{
 
next_trigger(trigger2);
 // cout<<"middle:";
if(m_b_excute||(m_Rd==R_PC))
{
        //CPSR
		//out_b_RW=0;
		out_REG=R_CPSR;
		m_n_CPSR=inout_n_Data;
		s_n_CPSR=m_n_CPSR;
      //controls of ALU		
		s_OP=m_OP;
	if(m_b_M)
	{	
		s_A=s_mult_out;
      
	}else {
		s_A=m_A;
      
	}

	if(m_b_S)
    { 
		s_B=s_shift_out;
		//cout<<"stage2: shifted value="<<s_shift_out<<endl;

	}else
	{

	   s_B=m_B;
	  
	}
}
	
  
   trigger3.notify(SC_ZERO_TIME);//trigger alu_delay();
  
}

void scEX::shift_delay()
{
  next_trigger(trigger1);
  trigger2.notify(SC_ZERO_TIME);//trigger middle();
}

void scEX::alu_delay()
{
  next_trigger(trigger3);
  trigger4.notify(SC_ZERO_TIME);//trigger out()
  
}
bool scEX::is_excute(COND cond,uint32_t flag)
{
   switch (cond)
    {
    case C_EQ: return ((flag & Z_FLAG) ? TRUE : FALSE); break;
    case C_NE: return ((flag & Z_FLAG) ? FALSE : TRUE); break;
    case C_CS: return ((flag & C_FLAG) ? TRUE : FALSE); break;
    case C_CC: return ((flag & C_FLAG) ? FALSE : TRUE); break;
    case C_MI: return ((flag & N_FLAG) ? TRUE : FALSE); break;
    case C_PL: return ((flag & N_FLAG) ? FALSE : TRUE); break;
    case C_VS: return ((flag & V_FLAG) ? TRUE : FALSE); break;
    case C_VC: return ((flag & V_FLAG) ? FALSE : TRUE); break;
    case C_HI: return ((flag & CZ_FLAGS) == C_FLAG); break;
    case C_LS: return ((flag & C_FLAG) == 0) ||
		 ((flag & Z_FLAG) == Z_FLAG); break;
    case C_GE: return (((flag & NV_FLAGS) == 0) || 
                     ((flag & NV_FLAGS) == NV_FLAGS)); break;
    case C_LT: return (((flag & NV_FLAGS) == V_FLAG) ||
                     ((flag & NV_FLAGS) == N_FLAG)); break;
    case C_GT: return (((flag & Z_FLAG) == 0) && 
                     (((flag & NV_FLAGS) == NV_FLAGS) || 
                      ((flag & NV_FLAGS) == 0))); break;
    case C_LE: return (((flag & Z_FLAG) == Z_FLAG) || 
                     (((flag & NV_FLAGS) == V_FLAG) || 
                      ((flag & NV_FLAGS) == N_FLAG))); break;
    case C_AL: return TRUE; break;
    case C_NV: return FALSE; break;
    default:
       cout<<"error:"<<endl;
	// Should never reach here
	   sc_stop();
  }
    	// Should never reach here
	return TRUE;
}


void scEX::display()
{

  if(m_last_Rd==R_PC){
    flush_number=2;
	m_last_Rd=R_R0;
  }
  if(flush_number<=0)
  {
	//read CPSR
      uint32_t R=0;
	  	//	out_b_RW=0;
		out_REG=R_PC;
		R=inout_n_Data;
	  cout<<"	PC:"<<R;//0100
		//out_b_RW=0;
		out_REG=R_CPSR;
		R=inout_n_Data;
	  cout<<" CPSR:";//0100
  // Bit masks for CPSR
    if((R&N_FLAG)==N_FLAG) cout<<"N";else cout<<"n"; 
    if((R&Z_FLAG)==Z_FLAG) cout<<"Z"; else cout<<"z"; 
    if((R&C_FLAG)==C_FLAG) cout<<"C"; else cout<<"c"; 
    if((R&V_FLAG)==V_FLAG) cout<<"V"; else cout<<"v";
	cout<<"  ";
   cout<<(is_excute(in_COND,R)?"yes":" nop")<<endl;

  }else{
    
	flush_number--; 

  }
	
}

void scEX::forwarding()
{

if((m_b_last_excute==1))
{

	
	//if writing Rd,forwarding from EX out
	//TEQ, TST, CMP & CMN
	 if((m_b_last_ls!=1)&&((m_last_OP!=OP_TEQ)&&(m_last_OP!=OP_TST)&&(m_last_OP!=OP_CMP)&&(m_last_OP!=OP_CMN)))
	{
	      //Rn
	       if((m_Rn!=R_PC)&&(m_Rn==m_last_Rd))
		   {
               //cout<<"forwarding0 Rn r"<<m_Rn<<"="<<m_last_Result<<endl;
		       m_A=m_last_Result;
		   }
       	//Rm
			if((m_Rm!=R_PC)&&(m_is_Rm)&&(m_Rm==m_last_Rd)&&(m_b_last_is_Rm))
			{
			   m_B=m_last_Result;
	
			}
    	//Rs
			if((m_Rs!=R_PC)&&(m_is_Rs)&&(m_Rs==m_last_Rd)&&(m_b_last_is_Rs))
			{
			  m_n_Dist=m_last_Result;
			}
	}
     if(m_b_last_WB==1)
	 {
	      //Rn
	       if((m_Rn!=R_PC)&&(m_Rn==m_last_Rn))
		   {
		       m_A=m_last_Result;
		   }
       	//Rm
			if((m_Rm!=R_PC)&&(m_is_Rm)&&(m_Rm==m_last_Rn)&&m_b_last_is_Rm)
			{
			   m_B=m_last_Result;
			
			}
    	//Rs
			if((m_Rs!=R_PC)&&(m_is_Rs)&&(m_Rs==m_last_Rn)&&m_b_last_is_Rs)
			{
			  m_n_Dist=m_last_Result;
			}
   
	 }
	 
  
 
    
}//is excute?

	    
}

void scEX::regs()
{
	 cout<<"EX"<<endl;
	uint32_t R=0;
  	 cout<<"	";
		for(int i=0;i<16;i++)
		{
			
		     //out_b_RW=0;
		     out_REG=REGS(i);
		     R=inout_n_Data;
			 cout<<"r"<<i<<"="<<R<<" ";		
			 if((i==4)||(i==9)) cout<<endl<<"	";
		}
		//cout<<endl;
 
   
}

void scEX::out_delay( )
{
	next_trigger(trigger5);

     if((m_SET==1)&&(m_Rd!=R_PC)){
		out_b_RW=1;
	    out_REG=R_CPSR;
		inout_n_Data=m_n_CPSR;
	 }
	
}

void scEX::forwarding1()
{ 

  // cout<<" forwarding1 Rd_from_mem"<<m_Rd_from_mem<<endl;
   
if(m_Rd_from_mem!=R_PC)
{
   //  cout<<"in_Rd_from_mem=PC"<<in_Rd_from_mem<<endl;

	 if(m_is_write_Rd==1)
	{
           
      if((m_Rn!=R_PC)&&(m_Rn==m_Rd_from_mem))
		   {
		       
		       m_A=m_n_Result_from_mem;
		
		   }
       	//Rm     
	 		if(((m_Rm!=R_PC)&&m_is_Rm)&&(m_Rm==m_Rd_from_mem))
			{
                    
			   m_B=m_n_Result_from_mem;
			  
			}
    	//Rs
			if(((m_Rs!=R_PC)&&m_is_Rs)&&(m_Rs==m_Rd_from_mem))
			{
			  m_n_Dist=m_n_Result_from_mem;
			}
	}
     if( m_b_WB_from_mem==1)
	 {
	 
		  //cout<<" Rn:r"<<in_Rn_from_mem<<"="<<in_n_Rn_from_mem<<endl;
		 //Rn
	       if(((m_Rn!=R_PC))&&(m_Rn==m_Rn_from_mem))
		   {
		       m_A=m_n_Result_from_mem;;
		   }
       	//Rm
			if(((m_Rm!=R_PC)&&m_is_Rm)&&(m_Rm==m_Rn_from_mem))
			{
			   m_B=m_n_Result_from_mem;;
			
			}
    	//Rs
			if(((m_Rs!=R_PC)&&m_is_Rs)&&(m_Rs==m_Rn_from_mem))
			{
			  m_n_Dist=m_n_Result_from_mem;;
			}
   
	 }
}//dont forward pc	     

}

void scEX::delay1( )
{
	next_trigger(trigger01_ex);
	//forwarding
 
   

  trigger02_ex.notify(SC_ZERO_TIME);

}

void scEX::delay2()
{
	next_trigger(trigger02_ex);
	//read CPSR
	//out_b_RW=0;
/*
 out_REG=REGS(0);
  uint32_t temp=inout_n_Data; 
  cout<<"	ex r0="<<temp;
    out_REG=REGS(1);
   temp=inout_n_Data; 
  cout<<" ex r1="<<temp;
      out_REG=REGS(2);
   temp=inout_n_Data; 
  cout<<" ex r2="<<temp;
    out_REG=REGS(3);
   temp=inout_n_Data; 
  cout<<" ex r3="<<temp<<endl;
  */
	//last_half();
   //forwarding_pc();

  last_half();
       forwarding();
     forwarding1();
  
	out_REG=R_CPSR;
	m_n_CPSR=inout_n_Data;
    m_b_excute=is_excute(m_COND,m_n_CPSR);

    out_b_excute=m_b_excute;

	//m_b_interrupt=m_b_interrupt;
	m_b_excute=m_b_excute&&(!m_b_interrupt);
	if((m_b_is_mrt==1)&&(m_b_excute==1))
	{
		m_b_hold=1;
	    out_b_hold=1;
	
	}else
	{
	    m_b_hold=0;
		out_b_hold=0;
	
	}
    trigger03_ex.notify(SC_ZERO_TIME);

}

void scEX::delay3()
{
	next_trigger(trigger03_ex);



//cout<<"stage1b: op="<<m_OP<<" m_A="<<m_A<<" b="<<m_B<<" shift="<<m_n_Dist<<endl;
 
//	cout<<(m_b_excute?"yes":"nop")<<endl;
	
	#if defined(DEBUG)
//		display();
    #endif    
if(m_b_excute||(m_Rd==R_PC))
{
    

    //cout<<(m_b_excute?"m_b_excute=1":"m_b_excute=0");

  if(m_b_M)//is it multi instruction
  {
      s_A_Mult=m_n_Dist;  //use dist signal to transfer rs
	  s_B_Mult=m_A;       //Rm
  }
  if(m_b_S) //Does it need to be shifted?
  {
		s_shift_type=m_SHIFT_TYPE;
		s_shift_dist=m_n_Dist;
		s_shift_in=m_B; //input to shifter
       // cout<<" shift excuted"<<m_n_Dist<<endl;
		
        
  }
  	//trigger1.notify(SC_ZERO_TIME);//trigger shift_delay()
 }
 else
 {
  out_b_Branch=0;
  out_n_Result=0;
  //out_b_RW=0;
  out_b_WB=0;
  out_b_excute=m_b_excute;

  //trigger4.notify(SC_ZERO_TIME);
 }//is excute?
trigger1.notify(SC_ZERO_TIME);//trigger shift_delay()
}

void scEX::forwarding_pc()
{
	//if read pc
	if((m_Rn==R_PC))
	{
		 out_REG=R_PC;
		 
		//cout<<"forwarding rn="<<in_Rn<<":"<<inout_n_Data<<endl;
		if((m_b_last_branch==1)||(m_last_Rd==R_PC))
		{
		 out_REG=R_PC;
		 m_A=inout_n_Data;
		}else
		{
		 out_REG=R_PC;
		 m_A=inout_n_Data;
		}
		// cout<<"m_A="<<endl;

	}
	if((m_Rm==R_PC)&&(m_is_Rm))
	{
	//	cout<<"Rm"<<in_Rm<<endl;
		if( (m_b_last_branch==1)||(m_last_Rd==R_PC))
		{
		      out_REG=R_PC;
		      m_B=inout_n_Data;
		    //m_B=m_last_Result;
		}else
		{
	     out_REG=R_PC;
		 m_B=inout_n_Data;
		// cout<<"m_B="<<endl;
		}
	}
	if((m_Rs==R_PC)&&(m_is_Rs))
	{
		//cout<<"Rs"<<in_Rs<<endl;
		if( (m_b_last_branch==1)||(m_last_Rd==R_PC))
		{
		     	 out_REG=R_PC;
		 m_n_Dist=inout_n_Data;
		   // m_n_Dist=m_last_Result;
		}else
		{
		out_REG=R_PC;
		m_n_Dist=inout_n_Data;
		//cout<<"m_DIST="<<endl;
		}
	}
}

void scEX::delay0()
{

}

void scEX::last_half()
{
   //cout<<" last half"<<m_Rd_from_mem<<endl;
   
if(in_Rd_from_mem!=R_PC)
{
   //  cout<<"in_Rd_from_mem=PC"<<in_Rd_from_mem<<endl;

	 if(in_is_write_Rd==1)
	{
		
	        //cout<<"forwarding ..."<<endl;
		 //cout<<m_is_Rm<<" in_Rn="<<m_Rn<<" in_Rm="<<m_Rm<<"  forwarding1 Rd:r"<<m_Rd_from_mem<<"="<<m_n_Result_from_mem<<endl;   
            
      if((m_Rn!=R_PC)&&(m_Rn==in_Rd_from_mem))
		   {
		       
		       m_A=in_n_Result_from_mem;
	   //cout<<"last half m_A="<<m_A<<endl;
		   }
       	//Rm     
	 		if(((m_Rm!=R_PC)&&m_is_Rm)&&(m_Rm==in_Rd_from_mem))
			{
                    
			   m_B=in_n_Result_from_mem;
	//		   cout<<"last half m_B="<<m_B<<endl;
			}
    	//Rs
			if(((m_Rs!=R_PC)&&m_is_Rs)&&(m_Rs==in_Rd_from_mem))
			{
			  m_n_Dist=in_n_Result_from_mem;
			}
	}
     if( in_b_WB_from_mem==1)
	 {
	 
		  //cout<<" Rn:r"<<in_Rn_from_mem<<"="<<in_n_Rn_from_mem<<endl;
		 //Rn
	       if(((m_Rn!=R_PC))&&(m_Rn==in_Rn_from_mem))
		   {
		       m_A=in_n_Result_from_mem;;
		   }
       	//Rm
			if(((m_Rm!=R_PC)&&m_is_Rm)&&(m_Rm==in_Rn_from_mem))
			{
			   m_B=in_n_Result_from_mem;;
			
			}
    	//Rs
			if(((m_Rs!=R_PC)&&m_is_Rs)&&(m_Rs==in_Rn_from_mem))
			{
			  m_n_Dist=in_n_Result_from_mem;;
			}
   
	 }
}//dont forward pc	     
}

void scEX::write_lr()
{
  next_trigger(trigger_write_lr);
		out_b_RW_link=1;
		out_REG_link=R_LR;
	//	inout_n_Data=temp-4;
}
