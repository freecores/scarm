// scCDP.h: interface for the scCDP class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCCDP_H__D6B3B664_B347_11D6_BB34_000000000000__INCLUDED_)
#define AFX_SCCDP_H__D6B3B664_B347_11D6_BB34_000000000000__INCLUDED_

#include "scALU.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\SRC\scARMInstruction.h"
#include "scTypes.h"	// Added by ClassView
#include "scRegisterFile.h"	// Added by ClassView
#include "scBarrelShifter.h"	// Added by ClassView
const uint32_t CDP_MASK  =  0x0F000010;
const uint32_t CDP_SIG   =  0x0E000000;

class scCDP : public scARMInstruction  
{
	typedef struct CDPTAG
{
  uint32_t crm   : 4;
  uint32_t pad2  : 1;
  uint32_t cop2  : 3;
  uint32_t cpn   : 4;
  uint32_t crd   : 4;
  uint32_t crn   : 4;
  uint32_t cop1  : 4;
  uint32_t pad   : 4;
  uint32_t cond  : 4;
} CDP;
	CDP ir;

 static const char* kind_string;
public:
	bool is_imm();
	SHIFT shift_type();
	uint32_t B();
	uint32_t A();
	OPCODE op();
	bool wb();
	bool set();
	bool is_branch();
	bool is_rs();
	bool is_ls();
	REGS Rn();
	REGS Rd();
	uint32_t dist();
	bool pre();
	bool load();
	bool is_shift();
	bool is_mult();
	COND cond();
	const char* kind();
	scCDP(uint32_t);
	virtual ~scCDP();

};

#endif // !defined(AFX_SCCDP_H__D6B3B664_B347_11D6_BB34_000000000000__INCLUDED_)
