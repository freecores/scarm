// scDP2.h: interface for the scDP2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCDP2_H__FC5E6444_AB29_11D6_BB1E_000000000000__INCLUDED_)
#define AFX_SCDP2_H__FC5E6444_AB29_11D6_BB1E_000000000000__INCLUDED_

#include "scBarrelShifter.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\SRC\scARMInstruction.h"
#include "scTypes.h"	// Added by ClassView
#include "scRegisterFile.h"	// Added by ClassView
#include "scALU.h"	// Added by ClassView
const uint32_t DP2_MASK=0x0E000010;
const uint32_t DP2_SIG= 0x00000000;
class scDP2 : public scARMInstruction  
{
	typedef struct DP2TAG
{
  uint32_t rm     : 4;
  uint32_t pad2   : 1;
  uint32_t type   : 2;
  uint32_t shift  : 5;
  uint32_t rd     : 4;
  uint32_t rn     : 4;
  bool_t   set    : 1;
  uint32_t opcode : 4;
  uint32_t hash   : 1;
  uint32_t pad    : 2;
  uint32_t cond   : 4;
} DPI2;
private:
	DPI2 ir;
	static const char* kind_string ;
public:
	bool set();
	bool is_branch();
	bool pre();
	bool wb();
	bool load();
	bool is_mult();
	bool is_ls();
	REGS Rn();
	bool is_shift();
	SHIFT shift_type();
	COND cond();
	OPCODE op();
	bool is_rs();
	uint32_t dist();
	bool is_imm();
	REGS Rd();
	uint32_t B();
	uint32_t A();
	const char* kind();
	scDP2(uint32_t);
	virtual ~scDP2();

};

#endif // !defined(AFX_SCDP2_H__FC5E6444_AB29_11D6_BB1E_000000000000__INCLUDED_)
