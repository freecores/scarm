// scLCDCtrl.cpp: implementation of the scLCDCtrl class.
//
//////////////////////////////////////////////////////////////////////

#include "scLCDCtrl.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

sscLCDCtrl::scLCDCtrl()
{
  //printf(MODULE_NAME": In Constructor\n");
  if((fScreen = fopen(LCDCTRL_SCREENFILE,"w")) == NULL)
  {
    fprintf(stderr,MODULE_NAME": Error opening %d\n",LCDCTRL_SCREENFILE);
    exit(1);
  }
  Reset();
}
///////////////////////////////////////////////////////////////////////////////
// ~CLCDCtrl - 
//
scLCDCtrl::~scLCDCtrl()
{
  //printf(MODULE_NAME": In Destructor\n");
  fclose(fScreen);
}


///////////////////////////////////////////////////////////////////////////////
// Reset -
//
void scLCDCtrl::Reset()
{
  int r, g, b, colorinc;
  double dcolorinc;
  
  memset(m_regs, 0, sizeof(uint32_t) * LCDCTRL_NUMREGS);
  m_regs[R_LCDVER] = 0x00001000; // v0.1

  r = g = b = 0;
  dcolorinc = (double)0xff/LCDCTRL_NUMPALS;
  colorinc = (int) dcolorinc+1;
  for(int i = 0; i < LCDCTRL_NUMPALS; i++)
  {
    r = g = b = i*colorinc;      
    m_pals[i] = ( (r << 16) | (g << 8) | b );
  }
}


///////////////////////////////////////////////////////////////////////////////
// UpdateScreen - 
//
void scLCDCtrl::UpdateScreen()
{
  //printf(MODULE_NAME": Updating Screen\n");
  fseek(fScreen,0,SEEK_SET);
  for(int i = 0; i < LCDCTRL_NUMPALS; i++)
    fprintf(fScreen, "Pal[%x] = %x\n", i, m_pals[i]);
  fflush(fScreen);
}

///////////////////////////////////////////////////////////////////////////////
// Cycle - 
//
void scLCDCtrl::Cycle(LCDCTRLBUS* bus)
{
  static int CycleCount = 0;
  

  if( (CycleCount++ % LCDCTRL_UPDATEINTERVAL) == 0)
          UpdateScreen();
  // See what the pesky real world wants
  if (bus->w != 0)
  {
    uint32_t addr = bus->addr;
    
    // R_LCDVER        0x0
    if (addr == 0x00000004) // R_LCDRESOLUTION 0x1
      m_regs[R_LCDRESOLUTION] = bus->data;
    else if (addr == 0x00000008) // R_LCDCOLORDEPTH 0x2
      m_regs[R_LCDCOLORDEPTH] = bus->data;
    else if (addr == 0x0000000C) // R_LCDSTARTADDR  0x3
      m_regs[R_LCDSTARTADDR] = bus->data;
    // R_LCDRESERVED1  0x4
    // R_LCDPALINDEX   0x5
    // R_LCDPALDATA    0x6
    // R_LCDSTATUS     0x7
  }


  // Did the nosy busy body want any info?
  if (bus->r != 0)
  {
    uint32_t addr = bus->addr;

    if (addr == 0x00000000)
	    bus->data = m_regs[R_LCDVER];
    else if (addr == 0x00000004)
	    bus->data = m_regs[R_LCDRESOLUTION];
    else if (addr == 0x00000008)
	    bus->data = m_regs[R_LCDCOLORDEPTH];
    else if (addr == 0x0000000C)
	    bus->data = m_regs[R_LCDSTARTADDR];
    else
	    bus->data = 0;
  }
}
