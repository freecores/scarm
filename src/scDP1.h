// scDP1.h: interface for the scDP1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCDP1_H__4AB5E1E4_AAD4_11D6_BB1C_000000000000__INCLUDED_)
#define AFX_SCDP1_H__4AB5E1E4_AAD4_11D6_BB1C_000000000000__INCLUDED_

#include "scALU.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\SRC\scARMInstruction.h"
#include "scTypes.h"	// Added by ClassView
#include "scRegisterFile.h"	// Added by ClassView
#include "scBarrelShifter.h"	// Added by ClassView
const uint32_t DP1_MASK=0x0E000000;  //data process
const uint32_t DP1_SIG= 0x02000000;
class scDP1 : public scARMInstruction  
{
 typedef struct DP1TAG
{
  uint32_t imm    : 8;
  uint32_t rot    : 4;
  uint32_t rd     : 4;
  uint32_t rn     : 4;
  uint32_t set    : 1;
  uint32_t opcode : 4;
  uint32_t hash   : 1;
  uint32_t pad    : 2;
  uint32_t cond   : 4;
} DPI1;
private:
	static const char* kind_string ;
	DPI1 ir;
public:
	bool is_branch();
	bool set();
	bool is_mult();
	bool load();
	bool wb();
	bool pre();
	REGS Rn();
	bool is_rs();
	bool is_ls();
	bool is_shift();
	SHIFT shift_type();
	COND cond();
	OPCODE op();
	uint32_t dist();
	bool is_imm();
	REGS Rd();
	uint32_t B();
	uint32_t A();

	const char* kind();
	scDP1(uint32_t);
	virtual ~scDP1();

};

#endif // !defined(AFX_SCDP1_H__4AB5E1E4_AAD4_11D6_BB1C_000000000000__INCLUDED_)
