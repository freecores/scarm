// sc_mem_ch.h: interface for the sc_mem_ch class.
/*                             -------------------
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

#if !defined(AFX_SC_MEM_CH_H__7BC07E77_A752_11D6_BB12_000000000000__INCLUDED_)
#define AFX_SC_MEM_CH_H__7BC07E77_A752_11D6_BB12_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "scTypes.h"
#include <systemc.h>
#include "sc_mem_if.h"
#include <sc_mslib.h>

class sc_mem_ch : public sc_channel,public sc_mem_if
{
public:
	bool write_mem(uint32_t addr,uint32_t data);
	uint32_t read_mem(uint32_t addr);
public:
	sc_out<bool>             nRW;
	sc_outmaster<uint32_t>     A;
	sc_inoutslave<uint32_t>    D;
public:
	uint32_t data;
	void read();

	SC_HAS_PROCESS(sc_mem_ch);
	sc_mem_ch(sc_module_name);
	virtual ~sc_mem_ch();

};

#endif // !defined(AFX_SC_MEM_CH_H__7BC07E77_A752_11D6_BB12_000000000000__INCLUDED_)
