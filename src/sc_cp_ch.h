// sc_cp_ch.h: interface for the sc_cp_ch class.
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
#if !defined(AFX_SC_CP_CH_H__7BC07E78_A752_11D6_BB12_000000000000__INCLUDED_)
#define AFX_SC_CP_CH_H__7BC07E78_A752_11D6_BB12_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\SRC\sc_cp_if.h"
class sc_cp_ch : 
	public sc_channel, 
	public sc_cp_if  
{
public:

public:
	sc_cp_ch(sc_module_name);
	virtual ~sc_cp_ch();

};

#endif // !defined(AFX_SC_CP_CH_H__7BC07E78_A752_11D6_BB12_000000000000__INCLUDED_)
