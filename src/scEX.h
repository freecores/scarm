// scEX.h: interface for the scEX class.
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

#if !defined(AFX_SCEX_H__8C326337_AB49_11D6_BB1E_000000000000__INCLUDED_)
#define AFX_SCEX_H__8C326337_AB49_11D6_BB1E_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <systemc.h>
#include "scTypes.h"
#include "scALU.h"
#include "scRegisterFile.h"
#include "scBarrelShifter.h"
#include "scBooth.h"
#define DEBUG  
class scEX:  public sc_module   
{  
public:   
	sc_out<bool>     out_b_hold;
	sc_outmaster<bool>  out_b_nRW_mem;
 	sc_outmaster<uint32_t> out_n_Addr_mem;//  address bus
	sc_inoutslave<uint32_t>  inout_n_Data_mem; //Instruction bus
	sc_in<bool> in_b_Clock;
	sc_in<bool>  in_b_is_branch;
	sc_out<bool>  out_b_is_branch;
	sc_in<bool> in_interrupt;
	sc_out<bool> out_interrupt;
	sc_in<COND> in_COND;
	sc_in<bool>  in_branch_taken;
	sc_out<bool> out_b_flush_2;
		//branch
	sc_out<bool> out_b_branch_taken;
	sc_out<bool> out_b_Branch;
	//access link  
	sc_outmaster<bool> out_b_RW_link;
	sc_outmaster<REGS> out_REG_link;
	sc_inoutslave<uint32_t> inout_n_Data_link;	

	//access CPSR  
	sc_outmaster<bool> out_b_RW;
	sc_outmaster<REGS> out_REG;
	sc_inoutslave<uint32_t> inout_n_Data;

	//target reg
	sc_in<REGS> in_Rd;
	sc_out<REGS> in_Rm;//used for forwarding
    sc_out<REGS> in_Rs;
    sc_in<bool>    is_Rm;
	sc_in<bool>    is_Rs;
   // sc_out<bool>    out_is_Rm;
	//sc_out<bool>    out_is_Rs;
	sc_out<REGS> out_Rd;
	//
	sc_in<uint32_t> in_A;
	sc_in<uint32_t> in_B; 

	// ALU controls
	sc_in<OPCODE >    in_OP;
    sc_in<bool>    in_SET;
	// controls of shifter
	sc_in<bool>   in_b_S;
	sc_in<SHIFT>  in_SHIFT_TYPE;
		 sc_in<bool>  in_b_is_mrt;
		 	sc_out<bool>   out_is_mrt;
	sc_in<uint32_t>  in_n_Dist;
	//controls of booth mutiplier
	sc_in<bool>  in_b_M;

	//controls of MEM
	 sc_in<bool>  in_b_ls;//is it load/store instruction
	 sc_in<REGS>   in_Rn; //base adress register
	 sc_in<bool>   in_b_Pre;// alter base reg before?
	 sc_in<bool>   in_b_Load;// load or store
     sc_in<bool>   in_b_WB;  //if i should write back to base reg?
    // EX to MEM
	 sc_out<bool>  out_b_ls;//is it load/store instruction
	 sc_out<REGS> out_Rn; //base adress register
	 sc_out<bool> out_b_Pre;// alter base reg before?
	 sc_out<bool> out_b_Load;// load or store
     sc_out<bool> out_b_WB;  //if i should write back to base reg?
     sc_out<uint32_t>  out_n_Rn;
	sc_out<uint32_t> out_n_Result;
	sc_out<bool>     out_b_write_Rd;

	//  if store instruction, load Rd 
	sc_out<uint32_t> out_n_Rd;
	sc_out<bool>  out_b_excute; 
	//forwarding
	sc_in<bool>         in_is_write_Rd;
	sc_in<REGS>         in_Rd_from_mem;//target
	sc_in<uint32_t>     in_n_Result_from_mem;
	sc_in<bool>         in_b_WB_from_mem;
	sc_in<REGS>         in_Rn_from_mem;//write-back register
	sc_in<uint32_t>     in_n_Rn_from_mem; //write-back data (value in memory rather than Rn) 
private:

	bool m_b_branch;
	bool m_b_hold;
	uint32_t m_n_CPSR;
	bool m_b_flush;
	bool m_b_excute;
	//target reg
	REGS m_Rd;
    uint32_t m_A;
	uint32_t m_B;

	// ALU controls
	COND m_COND;
	OPCODE   m_OP;
    bool     m_SET;
	// controls of shifter
	bool     m_b_S;
	SHIFT  m_SHIFT_TYPE;
	uint32_t  m_n_Dist;
	//controls of booth mutiplier
	bool  m_b_M;
	//controls of MEM
	 bool  m_b_ls;//is it load/store instruction
	 REGS   m_Rn; //base adress register
	 bool   m_b_Pre;// alter base reg before?
	 bool   m_b_Load;// load or store
     bool   m_b_WB;  //if i should write back to base reg?
	 bool  m_is_Rs;
	 bool  m_is_Rm;
	 bool  m_predict;
	 uint32_t m_n_Result;
	//forwarding
	bool         m_is_write_Rd;
	REGS         m_Rd_from_mem;//target
	uint32_t     m_n_Result_from_mem;
	bool         m_b_WB_from_mem;
	REGS         m_Rn_from_mem;//write-back register
	uint32_t     m_n_Rn_from_mem; //write-back data 
     
private:
	sc_event trigger1,trigger2,trigger3,trigger4,trigger5;
	sc_event trigger01_ex,trigger02_ex, trigger03_ex;
	sc_event trigger_write_lr;
	sc_signal<uint32_t> s_A;
	sc_signal<uint32_t> s_B; 
	//multiplier
	sc_signal<uint32_t> s_A_Mult;
	sc_signal<uint32_t> s_B_Mult;
	sc_signal<uint32_t> s_mult_out;
	//shifter
	sc_signal<uint32_t> s_shift_in;
	sc_signal<uint32_t> s_shift_out;
	sc_signal<SHIFT>   s_shift_type;
	sc_signal<uint32_t> s_shift_dist;
	sc_signal<bool>     s_carry;
	//
	sc_signal<uint32_t> s_alu_out;
	sc_signal<uint32_t> s_n_CPSR;
	sc_signal<COND>     s_COND;
	sc_signal<OPCODE>   s_OP;

public:
	void write_lr();
	void last_half();
	void delay0();
	void forwarding_pc();
	void delay3();
	void delay2();
	void delay1();
	void forwarding1();
	void out_delay();
	void regs();
	void forwarding();
	void display();
	void alu_delay();
	bool is_excute(COND cond,uint32_t flag);
	void shift_delay();
	void middle();
	void out();
	void entry();
	SC_HAS_PROCESS(scEX);
	scEX(sc_module_name);
	virtual ~scEX();
private:
	scBooth    mult;
	scBarrelShifter bsh;
	scALU alu;
private:
	 //save for forwarding
	REGS m_last_Rd;
	
	REGS m_last_Rn;
    OPCODE m_last_OP;
	bool m_b_last_Load;
	bool m_b_last_ls;
    REGS m_Rm,m_Rs;
	uint32_t m_last_Result;
	bool m_b_last_WB;
	bool m_b_last_is_Rm;
	bool m_b_last_is_Rs;
	bool m_b_last_excute;
	bool m_b_last_branch;
	bool m_b_interrupt;
	uint32_t m_n_list;
	bool m_b_is_mrt;

#if defined(DEBUG)
int flush_number;
#endif

};



#endif // !defined(AFX_SCEX_H__8C326337_AB49_11D6_BB1E_000000000000__INCLUDED_)
