// scMEM.cpp: implementation of the scMEM class.
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
#include "scMEM.h"
#include "scRAM.h"
#include "global.h"
#define DEBUG

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

scMEM::scMEM(sc_module_name name_):sc_module(name_)
{
	m_interrupt=0;
	m_b_is_mrt=0;
  
    SC_METHOD(entry);
	sensitive_pos<<in_b_Clock;
	SC_METHOD(delta_delay1);
	SC_METHOD(write_mem);
}

scMEM::~scMEM()
{

}

void scMEM::entry()
{

 m_Rd=in_Rd;
 m_n_Rd=in_n_Rd;
 m_Rn=in_Rn;
 m_b_W_Rd=in_b_write_Rd;
 m_b_WB=in_b_WB;
 m_n_Result=in_n_Result;
 m_b_excute=in_b_excute;
 m_b_ls=in_b_ls;
 m_b_Load=in_b_Load;
 m_b_is_mrt=in_is_mrt;
 

if((m_b_excute)||(m_Rd==R_PC))
{

  if(m_Rd==R_PC)
  {
	  if((m_b_excute)){
	    //cout<<"BRANCHXXXXXXXXXXXXXX"<<endl;
             
	    m_b_W_Rd=false;
        m_b_WB=false;
      	
		m_n_Result=in_n_Result;
        
		//cout<<"mem  excute b="<<in_n_Result<<endl;
	  }
	   else
	   {
		  // cout<<"mem dont exc b="<<in_n_Result<<endl;
	      m_b_WB=false; 
		  m_b_W_Rd=false;
	      m_n_Result=in_n_Result;
		  
	   }
	
	    m_b_excute=0;
		m_b_W_Rd=0;
		//out_n_Rn=in_n_Result;//change base address

  }else
  {

	    if(m_b_ls==true)
		{  

			cout<<"addr="<<in_n_Result<<endl;
			if(m_b_is_mrt==0)
			{
              	if(in_b_Pre==1)
				{
         
                   //	m_b_WB=in_b_WB;  
				    if(m_b_WB==1) 

						m_n_Rn=m_n_Result;
					else  
						m_n_Rn=m_n_Rn;

                     m_n_Addr=m_n_Result;
					//cout<<"m_n_Rn="<<m_n_Rn<<endl;

		          
				
				}else
				{ 
					m_b_WB=1;
					/*
				    if(m_b_WB==1) 
						m_n_Rn=m_n_Result;
					else  
						m_n_Rn=m_n_Rn;
						*/
					//add to Rn after transfer
                       //always
					m_n_Addr=m_n_Rn;// post
                    
					m_n_Rn=m_n_Result;
					
                      	//cout<<"after"<<endl;  			
				}
               //read meory
				if(m_b_Load==1)
				{
					
					out_n_Addr=m_n_Addr;//pre
				}else
				{
				    out_n_Addr=m_n_Addr;
		           //write memory
			        inout_n_Data=m_n_Rd;
				}
			}else
			{
			     out_n_Addr=m_n_Result;
			
			}
	

		  //	cout<<"ex out"<<in_n_Result<<endl;
		  
		}else///load/store
		{
		   m_n_Result=in_n_Result;
		    m_b_W_Rd=in_b_write_Rd;
		   m_n_Rn=in_n_Rn;

		   m_b_W_Rd=(m_b_W_Rd)&&(m_b_excute);
		
		}
	
  }//if Branch

}//if excute 
else
{
  m_b_W_Rd=false;
  m_b_WB=false;
}
 trigger.notify(SC_ZERO_TIME);
}

void scMEM::dump(uint32_t addr)
{
  
}


void scMEM::delta_delay1()
{
	next_trigger(trigger);
/*
    if(m_interrupt==1)
  {

		m_b_excute=0;
    g_interrupt=1;
	g_count++;
	if(g_count>1) sc_stop();
  }else
  {
    g_interrupt=0;
  }
  */
  	//transfer data between memory and register
	       
		if((m_b_Load==1)&&(m_b_ls==1))
			{
			    //read from memory;
			    m_b_W_Rd=(m_b_W_Rd)&&(m_b_excute);
				out_n_Addr=m_n_Addr;
				m_n_Result=inout_n_Data;

				               
		}else
		if((m_b_Load==0)&&(m_b_ls==1))
		{
					
		//store data

		    out_n_Addr_reg=m_Rd;
		    m_n_Rd=inout_n_Data_reg;
			//cout<<"r"<<m_Rd<<"="<<m_n_Rd<<endl;
			//cout<<"store "<<endl;
			//out_b_nRW=1;
			out_n_Addr=m_n_Addr;
			inout_n_Data=m_n_Rd;
			//cout<<"store r"<<m_Rd<<":"<<m_n_Rd<<" to "<<m_n_Result<<endl;
	         m_b_W_Rd=0;
			 //m_b_WB=1;
	
				//write to memory;
			trigger_mem.notify(SC_ZERO_TIME);
		}else
		{
		  
		}
  		
		/*
			if(m_interrupt==1)
			{
   			
				if(m_n_Addr=0xec0)m_n_Result=0x40000000;
				if(m_n_Addr=0xec4)m_n_Result=0x70000000;
				if(m_n_Addr=0xec8)m_n_Result=0x80000000;
				if(m_n_Addr=0xecc)m_n_Result=0x70000000;
			}         
			*/
 out_Rd=m_Rd;
 //cout<<"mem Rd: r"<<m_Rd<<"="<<m_n_Result<<endl;
 
 out_Rn=m_Rn;
 out_n_Rn=m_n_Rn;
 out_b_W_Rd=(m_b_W_Rd)&&m_b_excute;
 //cout<<"ddd"<<m_b_W_Rd<<endl;
 out_b_WB=m_b_WB&&m_b_excute;
 out_n_Result=m_n_Result;
 out_b_excute=m_b_excute;
  

}

void scMEM::write_mem()
{
	next_trigger(trigger_mem);
    out_b_nRW=1;
	out_n_Addr=m_n_Result;
    inout_n_Data=m_n_Rd;//write to memory;
     
    //cout<<"write to mem:"<<m_n_Result<<endl;
	//out_n_Addr=m_n_Result;
	//uint32_t temp=inout_n_Data;
	//cout<<"  read from mem"<<temp<<endl;
	//cout<<"mem write reg="<<endl;
}
