// scWB.h: interface for the scWB class.
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
#if !defined(AFX_SCWB_H__D38D2415_AB4A_11D6_BB1E_000000000000__INCLUDED_)
#define AFX_SCWB_H__D38D2415_AB4A_11D6_BB1E_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <systemc.h>
#include "scRegisterFile.h"
class scWB : public sc_module   
{
	public:
	sc_in<bool>         in_b_Clock;
	sc_in<bool>         in_b_excute;
	sc_in<REGS>         in_Rd;
	sc_in<uint32_t>     in_n_Result;
	sc_in<REGS>         in_Rn;
	sc_in<uint32_t>     in_n_Rn;
	sc_in<bool>        in_b_W_Rd;//if write Rd?
	sc_in<bool>         in_b_WB;
	//regs
	sc_outmaster	<bool> out_b_RW1;// 0-Read  1-Write
	sc_outmaster<REGS>     out_REG1;
	sc_inoutslave<uint32_t> inout_n_Data1;
	sc_outmaster	<bool> out_b_RW2;// 0-Read  1-Write
	sc_outmaster<REGS>     out_REG2;
	sc_inoutslave<uint32_t> inout_n_Data2;


public:
	void delay1();
	void out_delay();
	void regs();

	void entry();
	SC_HAS_PROCESS(scWB);
	scWB(sc_module_name);
	virtual ~scWB();
private:
	sc_event trigger_wb1,trigger_wb2;
	REGS m_Rn;
	REGS m_Rd;
	uint32_t m_n_Rn;
	uint32_t m_n_Rd;
	bool m_b_excute;
	bool m_b_write;
	bool m_b_wb;

};

#endif // !defined(AFX_SCWB_H__D38D2415_AB4A_11D6_BB1E_000000000000__INCLUDED_)
