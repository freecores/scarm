// scSWP.h: interface for the scSWP class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCSWP_H__8C326336_AB49_11D6_BB1E_000000000000__INCLUDED_)
#define AFX_SCSWP_H__8C326336_AB49_11D6_BB1E_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\SRC\scARMInstruction.h"
#include "scTypes.h"	// Added by ClassView
const uint32_t SWP_MASK  =  0x0FB00FF0;
const uint32_t SWP_SIG  =   0x01000090;

class scSWP : public scARMInstruction  
{
/* Swap memory and register */
typedef struct SWPTAG
{
  uint32_t cond  : 4;
  uint32_t pad   : 5;
  uint32_t byte  : 1;
  uint32_t pad2  : 2;
  uint32_t rn    : 4;
  uint32_t rd    : 4;
  uint32_t pad3  : 8;
  uint32_t rm    : 4;
} SWP;
SWP ir;
  static const char* kind_string;
public:
	uint32_t A();
	const char* kind();
	scSWP(uint32_t);
	virtual ~scSWP();

};

#endif // !defined(AFX_SCSWP_H__8C326336_AB49_11D6_BB1E_000000000000__INCLUDED_)
