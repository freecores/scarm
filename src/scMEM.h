// scMEM.h: interface for the scMEM class.
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
#if !defined(AFX_SCMEM_H__D38D2414_AB4A_11D6_BB1E_000000000000__INCLUDED_)
#define AFX_SCMEM_H__D38D2414_AB4A_11D6_BB1E_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <systemc.h>
#include "scTypes.h"

#include "scRegisterFile.h"
class scMEM : public sc_module  
{
	public:
	sc_in<bool> in_b_Clock;
	sc_in<bool> in_interrupt;
	sc_in<bool> in_b_branch_taken;
    sc_in<bool> in_b_excute;
	sc_out<bool> out_b_excute;
	//sc_out<bool> out_b_flush;
	//access memory
	sc_outmaster<bool>  out_b_nRW;
 	sc_outmaster<uint32_t> out_n_Addr;//  address bus
	sc_inoutslave<uint32_t>  inout_n_Data; //Instruction bus
	//access regs
	sc_outmaster<bool>  out_b_nRW_reg;
 	sc_outmaster<REGS> out_n_Addr_reg;//  address bus
	sc_inoutslave<uint32_t>  inout_n_Data_reg; //Instruction bus
	//EX to MEM
	sc_in<REGS>   in_Rd;
	sc_in<bool>   in_b_write_Rd;
	sc_in<REGS>   in_Rn;    //Reg
	sc_in<uint32_t> in_n_Rn;//data
	sc_in<bool>   in_b_ls;
	sc_in<bool>   in_is_mrt;
    sc_in<bool>   in_b_Pre;// alter base reg before?
    sc_in<bool>  in_b_Load;// load or store
    sc_in<bool>  in_b_WB;  //if i should write back to base reg?
	sc_in<uint32_t> in_n_Result;//result
	sc_in<uint32_t> in_n_Rd;//write to memory from source Rd
	//MEM to WB
	sc_out<bool>         out_b_W_Rd;
	sc_out<bool>         out_b_WB;
	sc_out<REGS>         out_Rd;//target
	sc_out<uint32_t>     out_n_Result;
	sc_out<REGS>         out_Rn;//write-back register
	sc_out<uint32_t>     out_n_Rn; //write-back data  

public:
	void write_mem();
	void delta_delay1();

	void dump(uint32_t);
	void entry();
	SC_HAS_PROCESS(scMEM);
	scMEM(sc_module_name);
	virtual ~scMEM();
private:
   sc_event trigger,trigger_mem;
 REGS m_Rd;
 REGS m_Rn;
 bool m_b_W_Rd,m_b_WB,m_interrupt,m_b_is_mrt;

 uint32_t m_n_Result,m_n_Rn,m_n_Rd,m_n_Addr;
 bool m_b_excute,m_b_ls,m_b_Load;
};

#endif // !defined(AFX_SCMEM_H__D38D2414_AB4A_11D6_BB1E_000000000000__INCLUDED_)
