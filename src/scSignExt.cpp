// scSignExt.cpp: implementation of the scSignExt class.
/*                            -------------------
    begin                : Oct 2 2002
    copyright            : (C) 2002 UESTC 
    author               : Zhong Tao
    email                : zhong@opencores.org
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#include "scSignExt.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

scSignExt::scSignExt(sc_module_name name_):sc_module(name_)
{ 
  SC_METHOD(entry);
  sensitive<<in_Data;
}

scSignExt::~scSignExt()
{

}

void scSignExt::entry()
{

  //24bit  offset Sign extension
  uint32_t temp=in_Data;
  if(temp&(0x00800000))
  {
     temp=(temp|0xFF000000);
  
  }
  out_Data=temp;
}
