// scSWP.cpp: implementation of the scSWP class.
//
//////////////////////////////////////////////////////////////////////

#include "scSWP.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

scSWP::scSWP(uint32_t)
{

}

scSWP::~scSWP()
{

}
const char* scSWP::kind_string="SWP";
const char* scSWP::kind(){
  return kind_string;
}

uint32_t scSWP::A()
{
  return 0;
}
