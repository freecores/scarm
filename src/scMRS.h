///////////////////////////////////////////////////////////////////////////////
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////              
//          
//  Original Author: Allen Tao Zhong,
//  University of Electronic Science and Technology in China
//  email: zhong@opencores.org
//  info   This is a SystemC ARM model
// scMRS.h: interface for the scMRS class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCMRS_H__7F1E5935_AE4E_11D6_BB28_000000000000__INCLUDED_)
#define AFX_SCMRS_H__7F1E5935_AE4E_11D6_BB28_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\SRC\scARMInstruction.h"
const uint32_t MRS_MASK=0x0FBF0FFF;
const uint32_t MRS_SIG=0x010F0000;
class scMRS : public scARMInstruction  
{
	/* Status register to general register transfer */
typedef struct MRSTAG
{
  uint32_t cond  : 4;
  uint32_t pad   : 5;
  uint32_t which : 1;
  uint32_t pad2  : 6;
  uint32_t rd    : 4;
  uint32_t pad3  : 12;
} MRS;

  MRS ir;
  static const char* kind_string;
public:
	const char* kind();
	scMRS(uint32_t);
	virtual ~scMRS();

};

#endif // !defined(AFX_SCMRS_H__7F1E5935_AE4E_11D6_BB28_000000000000__INCLUDED_)
