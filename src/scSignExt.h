// scSignExt.h: interface for the scSignExt class.
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

#if !defined(AFX_SCSIGNEXT_H__BA0C4704_AF29_11D6_BB2A_000000000000__INCLUDED_)
#define AFX_SCSIGNEXT_H__BA0C4704_AF29_11D6_BB2A_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <systemc.h>
#include "scTypes.h"
class scSignExt : public sc_module  
{
public:
	sc_in<uint32_t> in_Data;
	sc_out<uint32_t> out_Data;
public:
	void entry();
    SC_HAS_PROCESS(scSignExt);
	scSignExt(sc_module_name);
	virtual ~scSignExt();

};

#endif // !defined(AFX_SCSIGNEXT_H__BA0C4704_AF29_11D6_BB2A_000000000000__INCLUDED_)
