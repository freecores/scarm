// sc_mem_if.h: interface for the sc_mem_if class.
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
#if !defined(AFX_SC_MEM_IF_H__7BC07E75_A752_11D6_BB12_000000000000__INCLUDED_)
#define AFX_SC_MEM_IF_H__7BC07E75_A752_11D6_BB12_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <systemc.h>
#include "scTypes.h"	// Added by ClassView
class sc_mem_if  : public sc_interface  
{
public:
	virtual bool write_mem(uint32_t addr,uint32_t data);
	virtual uint32_t read_mem(uint32_t addr);
	sc_mem_if();
	virtual ~sc_mem_if();

};

#endif // !defined(AFX_SC_MEM_IF_H__7BC07E75_A752_11D6_BB12_000000000000__INCLUDED_)
