// scBDT.h: interface for the scBDT class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCBDT_H__8C326336_AB49_11D6_BB1E_000000000000__INCLUDED_)
#define AFX_SCBDT_H__8C326336_AB49_11D6_BB1E_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\SRC\scARMInstruction.h"
#include "scTypes.h"	
const uint32_t BDT_MASK  =  0x0E000000;
const uint32_t BDT_SIG  =   0x08000000;

class scBDT : public scARMInstruction  
{

typedef struct BDTTAG
{
 uint32_t list:16;// one bit vs. one register
 uint32_t rn: 4;
 uint32_t l:1;
 uint32_t w:1;
 uint32_t s:1;
 uint32_t u:1;
 uint32_t p:1;
 uint32_t pad:3;
 uint32_t cond:4;
} BDT;
BDT ir;
  static const char* kind_string;
public:
	uint32_t A();
	const char* kind();
	scBDT(uint32_t);
	virtual ~scBDT();

};

#endif // !defined(AFX_SCBDT_H__8C326336_AB49_11D6_BB1E_000000000000__INCLUDED_)
