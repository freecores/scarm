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
//  info   This is a SystemC ARM model,
// scRAM.cpp: implementation of the scRAM class.
//
//////////////////////////////////////////////////////////////////////
#include "scRAM.h"
#include  "global.h"
//#define DEBUG
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


scRAM::~scRAM()
{

}



bool scRAM::load_program(char * file_name)
{
		FILE * program=NULL;
        uint32_t data;
          program = fopen(file_name, "rb");
			if(program!=NULL)
			{
                if( fseek(program, 0, SEEK_SET) != 0)
				{
				    cout<<"seek error"<<endl;
				}else
				{
                 //for
				 int i=0;
#if defined(DEBUG)
        //cout<<"loading program..."<<endl;
#endif 				
				 while( !feof( program) )
				 {
					fread(&data,sizeof(uint32_t),1,program);
   				
					  if( ferror( program ) )      {
						 perror( "Read error" );
						 break;
					  }

					//fseek(program,4,SEEK_CUR);
					//cout<<hex<<data<<endl;
					m_data[i]=data;
					i++;
					if(i>=SIZE_OF_MEM){ 
						cout<<"The memory is full."<<endl;
						break;}
                 
				 }
                  	m_data[i]=0x12345678;
				}
				
			     cout<<"ram swi"<<endl;
uint32_t addr=0xec0;
	   addr=addr/4;
	   m_data[addr]=0x40000000;
addr=0xec4;
	   addr=addr/4;
	   m_data[addr]=0x70000000;
addr=0xec8;
	   addr=addr/4;
	   m_data[addr]=0x80000000;
addr=0xecc;
	   addr=addr/4;
	   m_data[addr]=0x70000000;				
				fclose(program);
			}else{
			  cout<<"can not find file."<<endl; 
		cout<<"  usage : scARM <file name> <args...>"<<endl;
		cout<<"  file name : a program to execute"<<endl;
		cout<<"  Note:Program should be plain bianery format."<<endl;
		cout<<"  args : arguments to the file"<<endl;
			  sc_stop();
			}

  return true;
}

void scRAM::dump(uint32_t addr)
{
   cout<<hex<<addr<<":"<<m_data[addr]<<endl;
}
void scRAM::entry()
{
	
	   uint32_t addr=A;
	   addr=addr/4;

	  if(addr>SIZE_OF_MEM)
      {
		  cout<<"read access out of mem in scRAM"<<endl;
		  //sc_stop();
	  }else
	  {
			if(m_rw==0){
	  
			  D=m_data[addr];
         //cout<<"read ram "<<hex<<A<<":"<<(m_data[addr])<<endl;    
			}
			else {
      // cout<<"write ram "<<hex<<A<<":"<<D<<endl;
			  m_data[addr]=D;
			 m_rw=0;
			}
	  }

  
}
void scRAM::rw()
{
  m_rw=1;
}
scRAM::scRAM(sc_module_name name_):sc_module(name_)
	{
       m_rw=0;
	  // SC_METHOD(interrupt);
	  // sensitive_pos<<clock;
	   SC_SLAVE(rw,nRW);
	   SC_SLAVE(entry,A);
	  

	};

void scRAM::interrupt()
{
  if(g_interrupt==1)
  {
     cout<<"ram swi"<<endl;
uint32_t addr=0xec0;
	   addr=addr/4;
	   m_data[addr]=0x40000000;
addr=0xec4;
	   addr=addr/4;
	   m_data[addr]=0x70000000;
addr=0xec8;
	   addr=addr/4;
	   m_data[addr]=0x80000000;
addr=0xecc;
	   addr=addr/4;
	   m_data[addr]=0x70000000;
  }
}
