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
//   
//
///////////////////////////////////////////////////////////////////////////////
// scRegisterFile.h: interface for the scm_registerFile class.
//
//////////////////////////////////////////////////////////////////////

#ifndef REGISTERS_H
#define REGISTERS_H

#include <systemc.h>
#include <sc_mslib.h>
#include"scTypes.h"
// mode of processor
enum MODE {M_PREV = 0x00, M_USER = 0x10, M_FIQ = 0x11, M_IRQ = 0x12, 
	   M_SVC = 0x13, M_ABORT = 0x17, M_UNDEF = 0x1B, M_SYSTEM = 0x1F};
//registers in core
enum REGS {R_R0 = 0x00, R_R1 = 0x01, R_R2 = 0x02, R_R3 = 0x03,
	   R_R4 = 0x04, R_R5 = 0x05, R_R6 = 0x06, R_R7 = 0x07,
	   R_R8 = 0x08, R_R9 = 0x09, R_R10 = 0x0A, R_FP = 0x0B,
	   R_IP = 0x0C, R_SP = 0x0D, R_LR = 0x0E, R_PC = 0x0F,
	   R_CPSR = 0x10,R_SPSR=0x11};
// Bit masks for CPSR
const uint32_t  V_FLAG= 0x10000000;
const uint32_t  C_FLAG= 0x20000000;
const uint32_t  Z_FLAG= 0x40000000;
const uint32_t  N_FLAG= 0x80000000;

const uint32_t  CZ_FLAGS= 0x60000000;
const uint32_t  NV_FLAGS= 0x90000000;

class scRegisterFile:public sc_module
{
	friend class scARMCore;
public:
	sc_in<bool>        in_Clock;
	sc_in<MODE>        in_MODE;
	sc_inslave<bool>        in_b_RW;// 0-Read  1-Write
	sc_inslave<REGS>     in_REG;
	sc_inoutmaster<uint32_t> inout_n_Data;
	sc_inslave<bool>        in_b_RW1;// 0-Read  1-Write
	sc_inslave<REGS>     in_REG1;
	sc_inoutmaster<uint32_t> inout_n_Data1;	
	sc_inslave<bool>        in_b_RW2;// 0-Read  1-Write
	sc_inslave<REGS>     in_REG2;
	sc_inoutmaster<uint32_t> inout_n_Data2;	
	sc_inslave<bool>        in_b_RW_PC;// 0-Read  1-Write
	sc_inslave<REGS>     in_REG_PC;
	sc_inoutmaster<uint32_t> inout_n_Data_PC;

public:
	void show();
	void rw();
	void rw1();
	void rw2();
	void rw4();
	void display();

	void entry4();
	void entry2();
	void entry1();

	SC_HAS_PROCESS(scRegisterFile);
	scRegisterFile(const sc_module_name name_):sc_module(name_)
	{
  //according mode to set the visualabiliy of the registers
	   set_mode(M_USER);
	   m_rw=0;
	 
  m_r0=0;
  m_r1=0;
  m_r2=0;
  m_r3=0;
  m_r4=0;
  m_r5=0;
  m_r6=0;
  m_r7=0;
  m_r8=0;                  
  m_r9=0;             
  m_r10=0;           
  m_r11=0;           
  m_r12=0;          
  m_r13=0;         
  m_r14=0;           
  m_r15=0;
  m_cpsr=0;
  m_spsr=0;

    //port0
       SC_SLAVE(rw,in_b_RW);
	   SC_SLAVE(entry,in_REG);
    //port1  
	   SC_SLAVE(rw1,in_b_RW1);
	   SC_SLAVE(entry1,in_REG1);

       SC_SLAVE(rw2,in_b_RW2);
	   SC_SLAVE(entry2,in_REG2);

       SC_SLAVE(rw4,in_b_RW_PC);
	   SC_SLAVE(entry4,in_REG_PC);
	   SC_METHOD(change_mode);
	   sensitive<<in_MODE;
	  // SC_METHOD(display);
	  // sensitive_pos<<in_Clock;

	}
	virtual ~scRegisterFile();
private:
	enum MODE m_Mode;
	uint32_t* r[18];
	bool m_rw;

private:
	void set_mode(MODE);
	void change_mode();
	void entry(void);

//////////////////////////////////////////////////
//////////////////////////////////////////////////
//		memom_ry for m_registers		//
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//16 general register   
uint32_t  m_r0;
uint32_t  m_r1;
uint32_t  m_r2;
uint32_t  m_r3;
uint32_t  m_r4;
uint32_t  m_r5;
uint32_t  m_r6;
uint32_t  m_r7;
uint32_t  m_r8;                  
uint32_t  m_r9;             
uint32_t  m_r10;           
uint32_t  m_r11;           
uint32_t  m_r12;          
uint32_t  m_r13;         
uint32_t  m_r14;           
uint32_t  m_r15;    
uint32_t  m_cpsr;
uint32_t  m_spsr;     

//7 reg for FIQ mode 
uint32_t  m_r8_fiq; 
uint32_t  m_r9_fiq;
uint32_t  m_r10_fiq; 
uint32_t  m_r11_fiq; 
uint32_t  m_r12_fiq;    
uint32_t  m_r13_fiq;
uint32_t  m_r14_fiq;
uint32_t  m_spsr_fiq;

 //2 reg for supervisor mode
uint32_t  m_r13_svc;
uint32_t  m_r14_svc;
uint32_t  m_spsr_svc;

//2 reg for abort mode
uint32_t  m_r13_abt;
uint32_t  m_r14_abt;
uint32_t  m_spsr_abt;

//2 m_reg for IRQ mode
uint32_t  m_r13_irq;
uint32_t  m_r14_irq;
uint32_t  m_spsr_irq;

//2 m_reg undefined instruction mode
uint32_t  m_r13_und;
uint32_t  m_r14_und;
uint32_t  m_spsr_und;
//


};
#endif