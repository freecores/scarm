// scUART.h: interface for the scUART class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCUART_H__14577C18_3BE8_11D6_B9E3_000000000000__INCLUDED_)
#define AFX_SCUART_H__14577C18_3BE8_11D6_B9E3_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define UARTCTRL_NUMREGS 8

#define R_UARTTXDATA     0x0
#define R_UARTRXDATA     0x1
#define R_UARTCONTROL    0x2
#define R_UARTSTATUS     0x3
#define R_UARTRESERVED1  0x4
#define R_UARTRESERVED2  0x5
#define R_UARTRESERVED3  0x6
#define R_UARTRESERVED4  0x7

#define UARTSTATUS_IN_DATA 0x1
#define UARTSTATUS_OUT_FREE 0x2
#include"scTypes.h"
class scUART  
{
typedef struct UARTCTRLBTAG
{
  uint32_t addr: 32;      // IN - address, 0 to 7
  uint32_t data: 32;      // IN/OUT - 32 bits of data
  uint32_t interrupt: 1;  // OUT - has an interrupt happened?
  uint32_t r:1;           // IN - is a read happening?
  uint32_t w:1;           // IN - is a write happening?
};
public:
	scUART();
	virtual ~scUART();

};

#endif // !defined(AFX_SCUART_H__14577C18_3BE8_11D6_B9E3_000000000000__INCLUDED_)
