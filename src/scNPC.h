// scNPC.h: interface for the scNPC class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCNPC_H__0BC740FA_B4A2_11D6_BB37_000000000000__INCLUDED_)
#define AFX_SCNPC_H__0BC740FA_B4A2_11D6_BB37_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <systemc.h>
#include <sc_mslib.h>
#include "scTypes.h"
#include "scRegisterFile.h"
class scNPC : public sc_module  
{
public: 
	sc_in<bool>     in_b_hold;
    sc_in<bool>     in_b_Clock;
	sc_in<bool>     in_flush;
	sc_in<uint32_t> in_PC;
	sc_in<bool>     in_b_B;  //is it a branch?
	sc_in<uint32_t> in_n_B; //branch address
	sc_out<uint32_t> out_n_NPC;
	sc_outmaster<bool>        out_b_RW_PC;// 0-Read  1-Write
	sc_outmaster<REGS>     out_REG_PC;
	sc_inoutslave<uint32_t> inout_n_Data_PC;
public:
	void delay3();
	void delay2();
	void delay1();
	void write_pc();
	uint32_t m_nNPC; 
	void next_pc();
	SC_HAS_PROCESS(scNPC);
	scNPC(sc_module_name name_);
	virtual ~scNPC();
private:
    bool m_b_start;
	bool m_b_branch;
	bool m_b_B;
	uint32_t m_n_B,m_PC;
	sc_event trigger;
	sc_event trigger1_npc,trigger2_npc,trigger3_npc;
};

#endif // !defined(AFX_SCNPC_H__0BC740FA_B4A2_11D6_BB37_000000000000__INCLUDED_)
