// scDecoder.h: interface for the scDecoder class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(SCDECODER_H)
#define SCDECODER_H


#include<systemc.h>
#include<sc_mslib.h>
#include  "scTypes.h"
//#include  "scARMCore.h"
#include "..\Registers\scRegisterFile.h"
#include "..\..\instructions\scARMInstruction.h"
#include "..\barrelshifter\scBarrelShifter.h"

class scDecoder :public sc_module 
{
	friend class scID;
public://ports
	sc_in<uint32_t> in_n_Instruction;
    sc_out<bool_t>  out_b_Branch;
	sc_out<OPCODE>  out_OP;
	sc_out<COND>    out_COND;

    sc_out<REGS>   out_Rd;
	sc_out<REGS>    out_Rn;

	sc_out<SHIFT>   out_SHIFT_TYPE;
	sc_out<bool_t>  out_Set;
	sc_out<uint32_t> out_ShiftDist;
    sc_out<REGS>    out_Rm;
	sc_out<uint32_t> out_n_Imm;
	sc_outmaster<REGS> out_REG;
	sc_inoutslave<uint32_t> inout_n_RegData;
	//sc_out<uint32_t> 
public:
	SC_HAS_PROCESS(scDecoder);
	scDecoder(const sc_module_name name_):sc_module(name_)
	{

	  SC_METHOD(entry);
	  sensitive<<in_n_Instruction;
	
	}
	virtual ~scDecoder();


private:
 

private:
	void insert_noop(void);
	void Decode(uint32_t nI);
	uint32_t get_RegData(REGS);
	void entry(void);
    bool_t CondTest(enum COND cond);
};

#endif 