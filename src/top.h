// top.h: interface for the top class.
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
#if !defined(AFX_TOP_H__14DB71C4_A9A3_11D6_BB19_000000000000__INCLUDED_)
#define AFX_TOP_H__14DB71C4_A9A3_11D6_BB19_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <systemc.h>
#include "scARMSoC.h"
#include "scRAM.h"
#include "scCoprocessor.h"
#include "sc_cp_ch.h"
#include "sc_mem_ch.h"
class top : public sc_module  
{
private:
    sc_clock CLK;
	sc_link_mp<bool> nRW;
    sc_link_mp<uint32_t> l_n_addr;
	sc_link_mp<uint32_t> l_n_data;
	sc_cp_ch   cp_ch;
	//sc_mem_ch  mem_ch;
private:
	scCoprocessor cp;
    scRAM ram;
    scARMSoC processor;
   

public:
	bool init(char * file_name);
	top(sc_module_name);
	virtual ~top();

};

#endif // !defined(AFX_TOP_H__14DB71C4_A9A3_11D6_BB19_000000000000__INCLUDED_)
