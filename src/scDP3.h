// scDP3.h: interface for the scDP3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCDP3_H__FC5E6446_AB29_11D6_BB1E_000000000000__INCLUDED_)
#define AFX_SCDP3_H__FC5E6446_AB29_11D6_BB1E_000000000000__INCLUDED_

#include "scBarrelShifter.h"	// Added by ClassView
#include "scRegisterFile.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\SRC\scARMInstruction.h"
#include "scTypes.h"	// Added by ClassView
#include "scALU.h"	// Added by ClassView
const uint32_t DP3_MASK=0x0E000010;    
const uint32_t DP3_SIG= 0x00000010;
class scDP3 : public scARMInstruction  
{
	typedef struct DP3TAG
{
  uint32_t rm     : 4;
  uint32_t pad3   : 1;
  uint32_t type   : 2;
  uint32_t pad2   : 1;
  uint32_t rs     : 4;
  uint32_t rd     : 4;
  uint32_t rn     : 4;
  bool_t   set    : 1;
  uint32_t opcode : 4;
  uint32_t hash   : 1;
  uint32_t pad    : 2;
  uint32_t cond   : 4;
} DPI3;
	DPI3 ir;
	static const char* kind_string ;
public:
	bool is_branch();
	bool set();
	bool wb();
	bool is_wb();
	bool load();
	bool pre();
	REGS Rn();
	bool is_mult();
	uint32_t dist();
	bool is_ls();
	uint32_t B();
	bool is_shift();
	SHIFT shift_type();
	COND cond();
	OPCODE op();
	bool is_rs();
	bool is_imm();
	REGS Rd();
	uint32_t A();
	const char* kind();
	scDP3(uint32_t);
	virtual ~scDP3();

};

#endif // !defined(AFX_SCDP3_H__FC5E6446_AB29_11D6_BB1E_000000000000__INCLUDED_)
