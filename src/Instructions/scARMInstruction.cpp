// scARMInstruction.cpp: implementation of the scARMInstruction class.
//
//////////////////////////////////////////////////////////////////////

#include "scARMInstruction.h"
#include "scException.h"
#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

scARMInstruction::scARMInstruction()
{

}

scARMInstruction::~scARMInstruction()
{

}



scARMInstruction* scARMInstruction::Create(uint32_t nI)
{
    scARMInstruction* pI=NULL;
	
  /*

  
  if ((nI & BRANCH_MASK) == BRANCH_SIG)
    {

//      pI=scARM_Branch(nI);
	  printf("create str\n");
    }

  else if ((i & SWI_MASK) == SWI_SIG)
    {
      decode_swi(i, str);
    }
  else if ((i & MULT_MASK) == MULT_SIG)
    {
      decode_mult(i, str);
    }
  else if ((i & DPI_MASK) == DPI_SIG)
    {
      decode_dpi(i, str);
    }
  else if ((i & SWT_MASK) == SWT_SIG)
    {
      decode_swt(i, str);
    }
#if 0
  else if ((i & HWT_MASK) == HWT_SIG)
    {
      decode_hwt(i, str);
    }
#endif
  else if ((i & MRT_MASK) == MRT_SIG)
    {
      decode_mrt(i, str);
    }
  return;
#if 0

  else if ((i & SWP_MASK) == SWP_SIG)
    {
      decode_swp(i, str);
    }
  else if ((i & MRS_MASK) == MRS_SIG)
    {
      decode_sgr(i, str);
    }
  else if ((i & MSR_MASK) == MSR_SIG)
    {
      decode_gsr(i, str);
    }
  else if ((i & CDO_MASK) == CDO_SIG)
    {
      decode_cdo(i, str);
    }
  else if ((i & CDT_MASK) == CDT_SIG)
    {
      decode_cdt(i, str);
    }
  else if ((i & CRT_MASK) == CRT_SIG)
    {
      decode_crt(i, str);
    }
  else if ((i & UAI_MASK) == UAI_SIG)
    {
      sprintf(str, "Unused arithmetic op\n");
    }
  else if ((i & UCI1_MASK) == UCI1_SIG)
    {
      sprintf(str, "Unused control 1\n");
    }
  else if ((i & UCI2_MASK) == UCI2_SIG)
    {
      sprintf(str, "Unused control 2\n");
    }
  else if ((i & UCI3_MASK) == UCI3_SIG)
    {
      sprintf(str, "Unused control 3\n");
    }
  else if ((i & ULSI_MASK) == ULSI_SIG)
    {
      sprintf(str, "Unused load/store\n");
    }
  else if ((i & UCPI_MASK) == UCPI_SIG)
    {
      sprintf(str, "Unused CoPro\n");
    }
  else if ((i & UNDEF_MASK) == UNDEF_SIG)
    {
      sprintf(str, "Undefined\n");
    }
  else
    {
      sprintf(str, "Rubbish");
    }
#endif
	*/
     return pI;
}

void scARMInstruction::Decode(uint32_t inst)
{
  uint32_t i = inst;
/*
  if (str == NULL)
    {
      throw scException();
    }

  if ((i & BRANCH_MASK) == BRANCH_SIG)
    {
      decode_branch(i, str);
    }
  else if ((i & SWI_MASK) == SWI_SIG)
    {
      decode_swi(i, str);
    }
  else if ((i & MULT_MASK) == MULT_SIG)
    {
      decode_mult(i, str);
    }
  else if ((i & DPI_MASK) == DPI_SIG)
    {
      decode_dpi(i, str);
    }
  else if ((i & SWT_MASK) == SWT_SIG)
    {
      decode_swt(i, str);
    }
#if 0
  else if ((i & HWT_MASK) == HWT_SIG)
    {
      decode_hwt(i, str);
    }
#endif
  else if ((i & MRT_MASK) == MRT_SIG)
    {
      decode_mrt(i, str);
    }
  return;
#if 0

  else if ((i & SWP_MASK) == SWP_SIG)
    {
      decode_swp(i, str);
    }
  else if ((i & MRS_MASK) == MRS_SIG)
    {
      decode_sgr(i, str);
    }
  else if ((i & MSR_MASK) == MSR_SIG)
    {
      decode_gsr(i, str);
    }
  else if ((i & CDO_MASK) == CDO_SIG)
    {
      decode_cdo(i, str);
    }
  else if ((i & CDT_MASK) == CDT_SIG)
    {
      decode_cdt(i, str);
    }
  else if ((i & CRT_MASK) == CRT_SIG)
    {
      decode_crt(i, str);
    }
  else if ((i & UAI_MASK) == UAI_SIG)
    {
      sprintf(str, "Unused arithmetic op\n");
    }
  else if ((i & UCI1_MASK) == UCI1_SIG)
    {
      sprintf(str, "Unused control 1\n");
    }
  else if ((i & UCI2_MASK) == UCI2_SIG)
    {
      sprintf(str, "Unused control 2\n");
    }
  else if ((i & UCI3_MASK) == UCI3_SIG)
    {
      sprintf(str, "Unused control 3\n");
    }
  else if ((i & ULSI_MASK) == ULSI_SIG)
    {
      sprintf(str, "Unused load/store\n");
    }
  else if ((i & UCPI_MASK) == UCPI_SIG)
    {
      sprintf(str, "Unused CoPro\n");
    }
  else if ((i & UNDEF_MASK) == UNDEF_SIG)
    {
      sprintf(str, "Undefined\n");
    }
  else
    {
      sprintf(str, "Rubbish");
    }
#endif
	*/
}
/*
enum COND {C_EQ = 0x0, C_NE = 0x1, C_CS = 0x2, C_CC = 0x3, 
	   C_MI = 0x4, C_PL = 0x5, C_VS = 0x6, C_VC = 0x7, 
	   C_HI = 0x8, C_LS = 0x9, C_GE = 0xA, C_LT = 0xB,
           C_GT = 0xC, C_LE = 0xD, C_AL = 0xE, C_NV = 0xF};
*/
COND scARMInstruction::get_cond(uint32_t nI)
{
	uint32_t nCOND=nI>>27;
	COND c;
	switch(nCOND)
    {
	case 0x00: { c=C_EQ; break;}
	case 0x01: { c=C_NE; break;}	
	case 0x02: { c=C_CS; break;}
	case 0x03: { c=C_CC; break;}
	case 0x04: { c=C_MI; break;}
	case 0x05: { c=C_PL; break;}
	case 0x06: { c=C_VS; break;}
	case 0x07: { c=C_VC; break;}
	case 0x08: { c=C_HI; break;}
	case 0x09: { c=C_LS; break;}
	case 0x0a: { c=C_GE; break;}
	case 0x0b: { c=C_LT; break;}
	case 0x0c: { c=C_GT; break;}
	case 0x0d: { c=C_LE; break;}
	case 0x0e: { c=C_AL; break;}
	case 0x0f: { c=C_NV; break;}
	}
     
	return c;
}
