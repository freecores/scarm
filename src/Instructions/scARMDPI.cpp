// scARMDPI.cpp: implementation of the scARMDPI class.
//
//////////////////////////////////////////////////////////////////////

#include "scARMDPI.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

scARMDPI::scARMDPI()
{

}

scARMDPI::~scARMDPI()
{

}

void scARMDPI::Decode(uint32_t)
{


}


REGS scARMDPI::get_Rn(uint32_t nI)
{
	REGS r;
   uint32_t nR;
   //0000,0001,1110,0000,0000,0000,0000,0000
   //
   nR=((nI>>16)&0x0000000f);

   switch(nR)
   {
   case 0x0:{r=R_R0;break;}
   case 0x1:{r=R_R1;break;}
   case 0x2:{r=R_R2;break;}
   case 0x3:{r=R_R3;break;}
   case 0x4:{r=R_R4;break;}
   case 0x5:{r=R_R5;break;}
   case 0x6:{r=R_R6;break;}
   case 0x7:{r=R_R7;break;}
   case 0x8:{r=R_R8;break;}
   case 0x9:{r=R_R9;break;}
   case 0xa:{r=R_R10;break;}
   case 0xb:{r=R_FP;break;}
   case 0xc:{r=R_IP;break;}
   case 0xd:{r=R_SP;break;}
   case 0xe:{r=R_LR;break;}
   case 0xf:{r=R_PC;break;}
   default: {cout<<"can not access the Rn"<<endl;}
   }
   return r;
}

REGS scARMDPI::get_Rm(uint32_t nI)
{
	REGS r;
   uint32_t nR;
  //0000,0000,0000,0000,0000,0000,0000,0000
   nR=(nI&0x0000000f);
   switch(nR)
   {
   case 0x0:{r=R_R0;break;}
   case 0x1:{r=R_R1;break;}
   case 0x2:{r=R_R2;break;}
   case 0x3:{r=R_R3;break;}
   case 0x4:{r=R_R4;break;}
   case 0x5:{r=R_R5;break;}
   case 0x6:{r=R_R6;break;}
   case 0x7:{r=R_R7;break;}
   case 0x8:{r=R_R8;break;}
   case 0x9:{r=R_R9;break;}
   case 0x10:{r=R_R10;break;}
   case 0x11:{r=R_FP;break;}
   case 0x12:{r=R_IP;break;}
   case 0x13:{r=R_SP;break;}
   case 0x14:{r=R_LR;break;}
   case 0x15:{r=R_PC;break;}
  default: {cout<<"can not access Rm"<<endl;}
   }
   return r;
}

uint32_t scARMDPI::get_Imm(uint32_t nI)
{
	uint32_t i;
	i=nI&0xffff;
	//signed extended
	if(((nI>>15)&0x1)==1)
	{i=0xffff0000+i;}
    return i;
}

SHIFT scARMDPI::get_shift(uint32_t nI)
{
   SHIFT s;
   //
   uint32_t nS;
  //0000,0000,0000,0000,0000,0000,0000,0000
   nS=(nI>>5)&0x3;
   switch(nS)
   {
   case 0x0:{s=S_LSL;break;}
   case 0x1:{s=S_LSR;break;}
   case 0x2:{s=S_ASR;break;}
   case 0x3:{s=S_ROR;break;}
   case 0x4:{s=S_RRX;break;}
   case 0x5:{s=S_ASL;break;}

  default: {cout<<"SHIFT Type error"<<endl;}
   }
   return s;
}



OPCODE scARMDPI::get_opcode(uint32_t nI)
{
  OPCODE op;
  // DPI_MASK    0x0C000000
  uint32_t nOp=(nI>>21)&0xf;
  switch(nOp)
  {
	case 0x00: { op=OP_AND; break;}
	case 0x01: { op=OP_EOR; break;}	
	case 0x02: { op=OP_SUB; break;}
	case 0x03: { op=OP_RSB; break;}
	case 0x04: { op=OP_ADD; break;}
	case 0x05: { op=OP_ADC; break;}
	case 0x06: { op=OP_SBC; break;}
	case 0x07: { op=OP_RSC; break;}
	case 0x08: { op=OP_TST; break;}
	case 0x09: { op=OP_TEQ; break;}
	case 0x0a: { op=OP_CMP; break;}
	case 0x0b: { op=OP_CMN; break;}
	case 0x0c: { op=OP_ORR; break;}
	case 0x0d: { op=OP_MOV; break;}
	case 0x0e: { op=OP_BIC; break;}
	case 0x0f: { op=OP_MVN ; break;}
	default:{cout<<"unknown opcode"<<endl;}
  }
  return op;
}



REGS scARMDPI::get_Rd(uint32_t nI)
{
	REGS r;
   uint32_t nR;
  //0000,0000,0000,0000,0000,0000,0000,0000
   nR=(nI>>12)&0xf;
   switch(nR)
   {
   case 0x0:{r=R_R0;break;}
   case 0x1:{r=R_R1;break;}
   case 0x2:{r=R_R2;break;}
   case 0x3:{r=R_R3;break;}
   case 0x4:{r=R_R4;break;}
   case 0x5:{r=R_R5;break;}
   case 0x6:{r=R_R6;break;}
   case 0x7:{r=R_R7;break;}
   case 0x8:{r=R_R8;break;}
   case 0x9:{r=R_R9;break;}
   case 0xa:{r=R_R10;break;}
   case 0xb:{r=R_FP;break;}
   case 0xc:{r=R_IP;break;}
   case 0xd:{r=R_SP;break;}
   case 0xe:{r=R_LR;break;}
   case 0xf:{r=R_PC;break;}

   }
   return r;
}

uint32_t scARMDPI::get_shift_dist(uint32_t nI)
{
  uint32_t dist;
  dist=(nI>>7)&0x1f;
  return dist;
}

uint32_t scARMDPI::get_Rot(uint32_t nI)
{ 
	uint32_t rot;
	rot=(nI>>8)&0xf;
	return rot;
	
}

bool_t scARMDPI::get_Set(uint32_t nI)
{
  bool_t bit;
  bit=(nI>>20)&0x1;
  return bit;
}

REGS scARMDPI::get_Rs(uint32_t nI)
{
   REGS r;
   //
   uint32_t nS=nI;
   nS=(nI>>8)&0xf;
   switch(nS)
   {
   case 0x0:{r=R_R0;break;}
   case 0x1:{r=R_R1;break;}
   case 0x2:{r=R_R2;break;}
   case 0x3:{r=R_R3;break;}
   case 0x4:{r=R_R4;break;}
   case 0x5:{r=R_R5;break;}
   case 0x6:{r=R_R6;break;}
   case 0x7:{r=R_R7;break;}
   case 0x8:{r=R_R8;break;}
   case 0x9:{r=R_R9;break;}
   case 0xa:{r=R_R10;break;}
   case 0xb:{r=R_FP;break;}
   case 0xc:{r=R_IP;break;}
   case 0xd:{r=R_SP;break;}
   case 0xe:{r=R_LR;break;}
   default:{cout<<"error of shift register"<<endl;}
   }
   return r;
}
