// scCoprocessor.h: interface for the scCoprocessor class.
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
#if !defined(AFX_SCCOPROCESSOR_H__7BC07E76_A752_11D6_BB12_000000000000__INCLUDED_)
#define AFX_SCCOPROCESSOR_H__7BC07E76_A752_11D6_BB12_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <systemc.h>
#include "sc_cp_if.h"
class scCoprocessor : public sc_module  
{
public:
   sc_port<sc_cp_if> ports;
public:
	scCoprocessor(sc_module_name);
	virtual ~scCoprocessor();
public:


};

#endif // !defined(AFX_SCCOPROCESSOR_H__7BC07E76_A752_11D6_BB12_000000000000__INCLUDED_)
