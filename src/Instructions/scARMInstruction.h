// scARMInstruction.h: interface for the scARMInstruction class.
//
//////////////////////////////////////////////////////////////////////
#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include"scTypes.h"
#include ".\components\Registers\scRegisterFile.h"
#include ".\components\BarrelShifter\scBarrelShifter.h"
#include ".\components\ALU\scALU.h"
// used to package the different behavoir of the different instruciton.
const uint32_t V_FLAG=0x10000000;
const uint32_t C_FLAG=0x20000000;
const uint32_t Z_FLAG=0x40000000;
const uint32_t N_FLAG=0x80000000;

const uint32_t CZ_FLAGS=0x60000000;
const uint32_t NV_FLAGS=0x90000000;



///////////////////////////////
// Defines the types for ARM instructions. For each instruction I've 
// defined the bitfield typedef and a mask/signiture for testing if 
// an instruction is of that type.
/////////////////////////////////

/* General instruction */
typedef union ITAG
{
  uint32_t raw;
 //  BRANCH   branch;
} INST;


class scARMInstruction  
{

private:
	virtual void Decode(uint32_t nI);
	// used in stages of EX, MEM  and WB
	//virtual void exe();
	//virtual void mem();
	//virtual void wb();
public:
	virtual scARMInstruction* Create(uint32_t);
	scARMInstruction();

	virtual ~scARMInstruction();

public:
COND get_cond(uint32_t nI);

};
#endif