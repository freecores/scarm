///////////////////////////////////////////////////////////////////////////////
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//
//  main.h -- This is a simple ARM modeling using SystemC.
//               Architecure defined by Allen Tao Zhong.
//          
//  Original Author: Allen Tao Zhong,
//  University of Electronic Science and Technology in China
//  email: zhong@opencores.org
//  header n/a
//  info   This is a simple ARM modeling using SystemC.
//               Architecure defined by Allen Tao Zhong. 
//
///////////////////////////////////////////////////////////////////////////////
 
/*****************************************************************************
 
  MODIFICATION LOG - modifiers, enter your name, affiliation, date and
  changes you are making here.
 
      Name, Affiliation, Date:
  Description of Modification:
 
 *****************************************************************************/

#ifndef Main_H
#define Main_H

const int FAST_CYCLE=1;
const int SLOW_CYCLE=4;

const int MEMORY_SIZE=1024 * 1024 * 12;
const int DEFAULT_CACHESIZE=1024 * 8;
const int SWI_EXIT=0x00800000;
const int SWI_DUMP=0x0080000F;
const int SWI_ARGS=0x0080000E;

#endif

