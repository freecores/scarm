// scLCDCtrl.h: interface for the scLCDCtrl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCLCDCTRL_H__F9C92034_3EBF_11D6_B9EA_000000000000__INCLUDED_)
#define AFX_SCLCDCTRL_H__F9C92034_3EBF_11D6_B9EA_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define LCDCTRL_NUMREGS 8
#define LCDCTRL_NUMPALS 256
#define LCDCTRL_SCREENFILE "/tmp/swarm_screen"
#define LCDCTRL_UPDATEINTERVAL 25

#define R_LCDVER        0x0
#define R_LCDRESOLUTION 0x1
#define R_LCDCOLORDEPTH 0x2
#define R_LCDSTARTADDR  0x3
#define R_LCDRESERVED1  0x4
#define R_LCDPALINDEX   0x5
#define R_LCDPALDATA    0x6
#define R_LCDSTATUS     0x7

typedef struct LCDCTRLBTAG
{
  uint32_t addr: 32;      // IN - address, 0 to 5
  uint32_t data: 32;      // IN/OUT - 32 bits of data
  uint32_t interrupt: 1;  // OUT - has an interrupt happened?
  uint32_t r:1;           // IN - is a read happening?
  uint32_t w:1;           // IN - is a write happening?
} LCDCTRLBUS;


class scLCDCtrl  
{
public:
	scLCDCtrl();
	virtual ~scLCDCtrl();
public:
  void Cycle(LCDCTRLBUS* bus);
  void Reset();

 private:
  uint32_t m_regs[LCDCTRL_NUMREGS];
  uint32_t m_pals[LCDCTRL_NUMPALS];
  FILE *fScreen;
  void UpdateScreen();
};

#endif // !defined(AFX_SCLCDCTRL_H__F9C92034_3EBF_11D6_B9EA_000000000000__INCLUDED_)
