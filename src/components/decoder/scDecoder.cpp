// scDecoder.cpp: implementation of the scDecoder class.
//
//////////////////////////////////////////////////////////////////////

#include "scDecoder.h"
#include "..\..\instructions\scARMInstruction.h"
#include "..\..\instructions\scARMDPI.h"
#include "..\..\instructions\scARMBranch.h"
#include "..\..\instructions\scARMLSI.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////



scDecoder::~scDecoder()
{

}

void scDecoder::entry()
{  
    uint32_t nI;
    nI=in_n_Instruction;

	Decode(nI);
}



uint32_t scDecoder::get_RegData(REGS reg)
{
	 uint32_t temp;
	 out_REG=reg;
     temp=inout_n_RegData;
	 return temp;
}


void scDecoder::Decode(uint32_t nI)
{

  // First see if the condition code is valid
  if ((nI & 0xF0000000) == 0xF0000000)
    {
     // create_vector(M_UNDEF, VEC_UNDEF, m_ctrlListNext);
	   cout<<"undef instruction"<<endl;
      return;
    }

  if (nI == 0)
    {
       insert_noop();
    }
   else if ((nI & DPI_MASK) == DPI_SIG)
    {
	   scARMDPI* pI;
	   pI=new scARMDPI();
       COND temp=pI->get_cond(nI);              
       bool_t test=CondTest(temp);
	   if(test==1)
	   {
	   out_COND=temp;
	   pI=new scARMDPI();
       out_OP=pI->get_opcode(nI);
	  
	   out_Rn=pI->get_Rn(nI);
	   out_Rm=pI->get_Rm(nI);
	   out_SHIFT_TYPE=pI->get_shift(nI);
	   out_Rd=pI->get_Rd(nI);
	   out_ShiftDist=pI->get_shift_dist(nI);
	   out_Set=pI->get_Set(nI);
	   out_n_Imm=pI->get_Imm(nI);
	   }else
	   {
	     insert_noop();
	   }
	   delete pI;
   }
   else if ((nI & BRANCH_MASK) == BRANCH_SIG)
   { 
	    scARMBranch * pI;
		pI=new scARMBranch();
	   COND temp=pI->get_cond(nI);              
       bool_t test=CondTest(temp);
	   if(test==1)
	   {
	//ALUOut<-NPC+Imm
	//Cond<-(A op 0)
	     out_OP=OP_ADD;
		 out_COND=pI->get_cond(nI);
         out_SHIFT_TYPE= S_LSL;
         out_ShiftDist= 2;
		 out_Rn=R_PC;
         out_Rm= R_LR;
		 out_Rd =R_LR;
		 out_Set=true;
		 out_n_Imm=pI->get_offset(nI);
		 out_b_Branch=true;
	   }else
	   {
         out_b_Branch=false;
	     insert_noop();
	   }
          delete pI;
       
    }
      else if ((nI & LSI_MASK) == LSI_SIG)
   { 
               //
		 scARMLSI * pI=new scARMLSI();
		 out_COND=pI->get_cond(nI);

		  cout<<"load/store instruciton"<<endl;
	 }
   /*
  else if ((nI & MSR_MASK) == MSR_SIG)
    {
        //DecodeMSR();
    }
  else if ((nI & MRS_MASK) == MRS_SIG)
    {
        //DecodeMRS();
    }

  else if ((nI & MULT_MASK) == MULT_SIG)
    {
       //DecodeMult();
    }
  else if ((nI & HWT_MASK) == HWT_SIG)
    {
       //DecodeHWT();
    }

  else if ((nI & SWT_MASK) == SWT_SIG)
    {
      //DecodeSWT();
    }
  else if ((nI & MRT_MASK) == MRT_SIG)
    {
      //DecodeMRT();
    }
  else if ((nI & SWI_MASK) == SWI_SIG)
    {
       //DecodeSWI();
    }
  else if ((nI & CDO_MASK) == CDO_SIG)
    {
      //DecodeCDO();
    }
  else if ((nI & CRT_MASK) == CRT_SIG)
    {
       //DecodeCRT();
    }
  else if ((nI & CDT_MASK) == CDT_SIG)
    {
      //DecodeCWT();
    }
	*/
  else
    {
      // Failed to decode it - generate an undefined instruction trap
      //GenerateUDT();
    }
}

bool_t scDecoder::CondTest(enum COND cond)
{
  uint32_t codes = get_RegData(R_CPSR);

  switch (cond)
    {
    case C_EQ: return ((codes & Z_FLAG) ? TRUE : FALSE); break;
    case C_NE: return ((codes & Z_FLAG) ? FALSE : TRUE); break;
    case C_CS: return ((codes & C_FLAG) ? TRUE : FALSE); break;
    case C_CC: return ((codes & C_FLAG) ? FALSE : TRUE); break;
    case C_MI: return ((codes & N_FLAG) ? TRUE : FALSE); break;
    case C_PL: return ((codes & N_FLAG) ? FALSE : TRUE); break;
    case C_VS: return ((codes & V_FLAG) ? TRUE : FALSE); break;
    case C_VC: return ((codes & V_FLAG) ? FALSE : TRUE); break;
    case C_HI: return ((codes & CZ_FLAGS) == C_FLAG); break;
    case C_LS: return ((codes & C_FLAG) == 0) ||
		 ((codes & Z_FLAG) == Z_FLAG); break;
    case C_GE: return (((codes & NV_FLAGS) == 0) || 
                     ((codes & NV_FLAGS) == NV_FLAGS)); break;
    case C_LT: return (((codes & NV_FLAGS) == V_FLAG) ||
                     ((codes & NV_FLAGS) == N_FLAG)); break;
    case C_GT: return (((codes & Z_FLAG) == 0) && 
                     (((codes & NV_FLAGS) == NV_FLAGS) || 
                      ((codes & NV_FLAGS) == 0))); break;
    case C_LE: return (((codes & Z_FLAG) == Z_FLAG) || 
                     (((codes & NV_FLAGS) == V_FLAG) || 
                      ((codes & NV_FLAGS) == N_FLAG))); break;
    case C_AL: return TRUE; break;
    case C_NV: return FALSE; break;
    }

	// Should never reach here
	return TRUE;
}



void scDecoder::insert_noop()
{
	  //insert noop
      out_OP=OP_MOV;
	  out_Rd=R_R0;
	  out_Rn=R_R0;
	  out_Rm=R_R0;
	  out_COND=C_AL;
	  out_SHIFT_TYPE=S_LSL;
	  out_ShiftDist=0;
	  out_Set=0;
	  out_n_Imm=0;
}
