// scUNDEF.h: interface for the scUNDEF class.
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

#if !defined(AFX_SCUNDEF_H__FC5E6445_AB29_11D6_BB1E_000000000000__INCLUDED_)
#define AFX_SCUNDEF_H__FC5E6445_AB29_11D6_BB1E_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\SRC\scARMInstruction.h"
#include "scTypes.h"	// Added by ClassView

class scUNDEF : public scARMInstruction  
{
		static const char* kind_string ;
public:
	uint32_t A();
		const char* kind();
	scUNDEF(uint32_t);
	virtual ~scUNDEF();

};

#endif // !defined(AFX_SCUNDEF_H__FC5E6445_AB29_11D6_BB1E_000000000000__INCLUDED_)
