// scHWT.h: interface for the scHWT class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCHWT_H__8C326338_AB49_11D6_BB1E_000000000000__INCLUDED_)
#define AFX_SCHWT_H__8C326338_AB49_11D6_BB1E_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\SRC\scARMInstruction.h"
#include "scTypes.h"	// Added by ClassView
#include "scRegisterFile.h"	// Added by ClassView
const uint32_t HWT_MASK  =  0x0E000090;
const uint32_t HWT_SIG   =  0x00000090;
class scHWT : public scARMInstruction  
{
	/* Half-word and signed bype transfer - two formats, but use same fields, so
   I've only defined it once. */
typedef struct HWTAG
{
  uint32_t rm    : 4;
  uint32_t pad3  : 1;
  uint32_t h     : 1;
  uint32_t s     : 1;
  uint32_t pad2  : 1;
  uint32_t imm   : 4;
  uint32_t rd    : 4;
  uint32_t rn    : 4;
  uint32_t ls    : 1;
  uint32_t wb    : 1;
  uint32_t hash  : 1;
  uint32_t u     : 1;
  uint32_t p     : 1;
  uint32_t pad   : 3;
  uint32_t cond  : 4;
} HWT;
	HWT ir;
	static const char* kind_string ;
public:
	uint32_t B();
	REGS Rd();
	uint32_t A();
	const char* kind();
	scHWT(uint32_t);
	virtual ~scHWT();

};

#endif // !defined(AFX_SCHWT_H__8C326338_AB49_11D6_BB1E_000000000000__INCLUDED_)
