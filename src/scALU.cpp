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
//////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////              
//          
//  Original Author: Allen Tao Zhong,
//  University of Electronic Science and Technology in China
//  email: zhong@opencores.org
//  info   This is a SystemC ARM model,I "stole" some codes from 
//       "swarm" , author Michael Dales (michael@dcs.gla.ac.uk)
//        
// scALU.cpp: implementation of the scALU class.
//
//////////////////////////////////////////////////////////////////////

#include "scALU.h"
#define DEBUG
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

#include "scALU.h"
#include"scARMInstruction.h"
#define CARRY_FROM(_a,_b,_r) ((_a >> 31) ? ((_b >> 31) | ((~_r) >> 31)) : ((_b >> 31) * ((~_r) >> 31)))

#define BORROWED_FROM(_a,_b,_r) ((_a >> 31) ? ((_b >> 31) & (_r >> 31)) : ((_b >> 31) | (_r >> 31)))

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////



scALU::~scALU()
{

}
/******************************************************************************
 *
 */
uint32_t scALU::adc_op(uint32_t a, uint32_t b, uint32_t* cond)
{
  int64_t temp;
  //int64_t result;
  uint32_t short_res;
  uint32_t c = (*cond);

  temp = (int32_t)a;
  temp += (int32_t)b;
  if (c & C_FLAG)
    temp++;

  //result = temp & 0x00000000FFFFFFFFL;
  short_res = (uint32_t)((uint64_t)temp);

  // Clear flags 
  *cond &= 0x0FFFFFFF;

  // N Flags = Rd[31] 
  if (((temp >> 31) & 0x1) == 1)
    (*cond) |= N_FLAG;

  // Z Flag = if Rd == 0 then 1 else 0
  if (short_res == 0)
    (*cond) |= Z_FLAG;

  // C Flag = CarryFrom(Rn + shifter_operand + C Flag)
  if (CARRY_FROM((uint32_t)a, (uint32_t)b, short_res))
    (*cond) |= C_FLAG;

  // V Flag = OverflowFrom(Rn + shifter_operand + C Flag)
  if (((temp >> 32) & 0x1) != ((temp >> 31) & 0x1))
    (*cond) |= V_FLAG;

  return (uint32_t)short_res;
}



uint32_t scALU::add_op(uint32_t a, uint32_t b, uint32_t* cond)
{
  int64_t temp;
  //int64_t result;
  uint32_t short_res;
  uint32_t c = (*cond);

  temp = (int64_t)((int32_t)a);
  temp += (int64_t)((int32_t)b);

  //result = temp & 0x00000000FFFFFFFFL;
  short_res = (uint32_t)((uint64_t)temp);

  // Clear flags 
  *cond &= 0x0FFFFFFF;

  // N Flags = Rd[31] 
  if (((temp >> 31) & 0x1) == 1)
    (*cond) |= N_FLAG;

  // Z Flag = if Rd == 0 then 1 else 0
  if (short_res == 0)
    (*cond) |= Z_FLAG;

  // C Flag = CarryFrom(Rn + shifter_operand)
  if (CARRY_FROM((uint32_t)a, (uint32_t)b, short_res))
    (*cond) |= C_FLAG;

  // V Flag = OverflowFrom(Rn + shifter_operand)
  if (((temp >> 32) & 0x1) != ((temp >> 31) & 0x1)) {
    (*cond) |= V_FLAG;
  }

  return (uint32_t)short_res;
}

/******************************************************************************
 *
 */
uint32_t scALU::and_op(uint32_t a, uint32_t b, uint32_t* cond)
{
  uint32_t temp;

  temp = a & b;

  // Clear flags - V flag uneffected
  *cond &= (0x0FFFFFFF | V_FLAG);

  // N Flag = Rd[31]
  if (((temp >> 31) & 0x1) == 1)
    (*cond) |= N_FLAG;
  
  // Z Flag = if Rd == 0 then 1 else 0
  if (temp == 0)
    (*cond) |= Z_FLAG;

  // C Flag = shifter_carry_out 
  // Done otherwhere

  // V Flag = unaffected

  return temp;
}


/******************************************************************************
 *
 */
uint32_t scALU::bic_op(uint32_t a, uint32_t b, uint32_t* cond)
{
  uint32_t temp;

  temp = a & ~b;

  // Clear flags
  *cond &= (0x0FFFFFFF | V_FLAG);

  // N Flag = Rd[31]
  if (((temp >> 31) & 0x1) == 1)
    (*cond) |= N_FLAG;

  // Z Flag = if Rd == 0 then 1 else 0
  if (temp == 0)
    (*cond) |= Z_FLAG;

  // C Flag = shifter_carry_out 
  // Done otherwhere

  // V Flag = unaffected

  return temp;
}


/******************************************************************************
 *
 */
uint32_t scALU::cmn_op(uint32_t a, uint32_t b, uint32_t* cond)
{
  int64_t temp;
  //int64_t result;
  uint32_t short_res;
  uint32_t c = (*cond);

  temp = (int64_t)a;
  temp += (int64_t)b;

  //result = temp & 0x00000000FFFFFFFFL;
  short_res = (uint32_t)((uint64_t)temp);

  // Clear flags
  *cond &= 0x0FFFFFFF;

  // N Flags = Rd[31] 
  if (((temp >> 31) & 0x1) == 1)
    (*cond) |= N_FLAG;

  // Z Flag = if Rd == 0 then 1 else 0
  if (short_res == 0)
    (*cond) |= Z_FLAG;

  // C Flag = CarryFrom(Rn + shifter_operand)
  if (CARRY_FROM((uint32_t)a, (uint32_t)b, short_res))
    (*cond) |= C_FLAG;

  temp = (int64_t)((int32_t)a);
  temp += (int32_t)b;

  // V Flag = OverflowFrom(Rn + shifter_operand)
  if (((temp >> 32) & 0x1) != ((temp >> 31) & 0x1))
    (*cond) |= V_FLAG;

  return 0;
}


/******************************************************************************
 *
 */
uint32_t scALU::cmp_op(uint32_t a, uint32_t b, uint32_t* cond)
{
  int64_t temp, result;
  uint32_t short_res;
  uint32_t c = (*cond);

  temp = (int32_t)a;
  temp -= (int32_t)b;

  result = temp & 0x00000000FFFFFFFFL;
  short_res = (uint32_t)((uint64_t)temp);

  uint64_t temp2 = (uint32_t)a;
  temp2 -= (uint32_t)b;
  
  uint64_t result2 = temp2 & 0x00000000FFFFFFFF;

  // Clear flags
  *cond &= 0x0FFFFFFF;

  // N Flag = Rd[31]
  if (((temp >> 31) & 0x1) == 1)
    (*cond) |= N_FLAG;

  // Z Flag = if Rd == 0 then 1 else 0
  if (short_res == 0)
    (*cond) |= Z_FLAG;

  // C Flag = NOT BorrowFrom(Rn - shifter_operand)
  //if (result2 == temp2)
  if (BORROWED_FROM((uint32_t)a, (uint32_t)b, short_res) == 0)
    (*cond) |= C_FLAG;

  // V Flag = OverFlowFrom (Rn - shifter_operand)
  if (((temp >> 32) & 0x1) != ((temp >> 31) & 0x1))
    (*cond) |= V_FLAG;

  return 0;
}


/******************************************************************************
 *
 */
uint32_t scALU::eor_op(uint32_t a, uint32_t b, uint32_t* cond)
{
  uint32_t temp;

  temp = a ^ b;

  // Clear flags (overflow unaffected)
  *cond &= (0x0FFFFFFF | V_FLAG);

  // N Flag = Rd[31]
  if (((temp >> 31) & 0x1) == 1)
    (*cond) |= N_FLAG;

  // Z Flag = if Rd == 0 then 1 else 0
  if (temp == 0)
    (*cond) |= Z_FLAG;

  // C Flag = shifter_carry_out 
  // Done otherwhere

  // V Flag = unaffected

  return temp;
}


/******************************************************************************
 *
 */
uint32_t scALU::mov_op(uint32_t a, uint32_t b, uint32_t* cond)
{
  // Clear flags (overflow unaffected)
  *cond &= (0x0FFFFFFF | V_FLAG);

  // N Flag = Rd[31]
  if (((b >> 31) & 0x1) == 1)
    (*cond) |= N_FLAG;

  // Z Flag = if Rd == 0 then 1 else 0
  if (b == 0)
    (*cond) |= Z_FLAG;

  //cout<<"move"<<endl;
  // C Flag = shifter_carry_out 
  // Done otherwhere

  // V Flag = unaffected

  return b;
}


/******************************************************************************
 *
 */
uint32_t scALU::mvn_op(uint32_t a, uint32_t b, uint32_t* cond)
{
  // Clear flags (overflow unaffected)
  *cond &= (0x0FFFFFFF | V_FLAG);

  // N Flag = Rd[31]
  if (((b >> 31) & 0x1) == 1)
    (*cond) |= N_FLAG;

  // Z Flag = if Rd == 0 then 1 else 0
  if (~b == 0)
    (*cond) |= Z_FLAG;

  // C Flag = shifter_carry_out 
  // Done otherwhere

  // V Flag = unaffected

  return ~b;
}


/******************************************************************************
 *
 */
uint32_t scALU::orr_op(uint32_t a, uint32_t b, uint32_t* cond)
{
  uint32_t temp;

  temp = a | b;

  // Clear flags (overflow unaffected)
  *cond &= (0x0FFFFFFF | V_FLAG);

  // N Flag = Rd[31]
  if (((b >> 31) & 0x1) == 1)
    (*cond) |= N_FLAG;

  // Z Flag = if Rd == 0 then 1 else 0
  if (temp == 0)
    (*cond) |= Z_FLAG;

  // C Flag = shifter_carry_out 
  // Done otherwhere

  // V Flag = unaffected

  return temp;
}


/******************************************************************************
 *
 */
uint32_t scALU::rsb_op(uint32_t a, uint32_t b, uint32_t* cond)
{
  int64_t temp, result;
  uint32_t short_res;
  uint32_t c = (*cond);

  temp = (int32_t)b;
  temp -= (int32_t)a;

  result = temp & 0x00000000FFFFFFFFL;
  short_res = (uint32_t)((uint64_t)temp);

  // Clear flags
  *cond &= 0x0FFFFFFF;

  // N Flag = Rd[31]
  if (((temp >> 31) & 0x1) == 1)
    (*cond) |= N_FLAG;

  // Z Flag = If Rd == 0 then 1 else 0
  if (result == 0)
    (*cond) |= Z_FLAG;

  // C Flag = NOT BorrowedFrom(shifter_operand - Rn)
  if (BORROWED_FROM((uint32_t)b, (uint32_t)a, short_res) == 0)
    (*cond) |= C_FLAG;

  // V Flag = OverflowFrom(shifter_operand - Rn)
  if (((temp >> 32) & 0x1) != ((temp >> 31) & 0x1))
    (*cond) |= V_FLAG;

  return (uint32_t)result;
}


/******************************************************************************
 *
 */
uint32_t scALU::rsc_op(uint32_t a, uint32_t b, uint32_t* cond)
{
  int64_t temp, result;
  uint32_t short_res;
  uint32_t c = (*cond);

  temp = (int32_t)b;
  temp -= (int32_t)a;
  if (!(c & C_FLAG))
    temp--;

  result = temp & 0x00000000FFFFFFFFL;
  short_res = (uint32_t)((uint64_t)temp);

  // Clear flags
  *cond &= 0x0FFFFFFF;

  // N Flag = Rd[31]
  if (((temp >> 31) & 0x1) == 1)
    (*cond) |= N_FLAG;

  // Z Flag = If Rd == 0 then 1 else 0
  if (result == 0)
    (*cond) |= Z_FLAG;

  // C Flag = NOT BorrowedFrom(shifter_operand - Rn - NOT(C Flag))
  if (BORROWED_FROM((uint32_t)b, (uint32_t)a, short_res) == 0)
    (*cond) |= C_FLAG;

  // V Flag = OverflowFrom(shifter_operand - Rn - NOT(C Flag))
  if (((temp >> 32) & 0x1) != ((temp >> 31) & 0x1))
    (*cond) |= V_FLAG;

  return (uint32_t)result;
}


/******************************************************************************
 *
 */
uint32_t scALU::sbc_op(uint32_t a, uint32_t b, uint32_t* cond)
{
  int64_t temp, result;
  uint32_t short_res;
  uint32_t c = (*cond);

  temp = (int32_t)a;
  temp -= (int32_t)b;
  if (!(c & C_FLAG))
    temp--;

  result = temp & 0x00000000FFFFFFFFL;
  short_res = (uint32_t)((uint64_t)temp);

  // Clear flags
  *cond &= 0x0FFFFFFF;

  // N Flag = Rd[31]
  if (((temp >> 31) & 0x1) == 1)
    (*cond) |= N_FLAG;

  // Z Flag = If Rd == 0 then 1 else 0
  if (result == 0)
    (*cond) |= Z_FLAG;

  // C Flag = NOT BorrowedFrom(Rn - shifter_operand - NOT(C Flag))
  if (BORROWED_FROM((uint32_t)a, (uint32_t)b, short_res) == 0)
    (*cond) |= C_FLAG;

  // V Flag = OverflowFrom(Rn - shifter_operand - NOT(C Flag))
  if (((temp >> 32) & 0x1) != ((temp >> 31) & 0x1))
    (*cond) |= V_FLAG;

  return (uint32_t)result;
}


/******************************************************************************
 *
 */
uint32_t scALU::sub_op(uint32_t a, uint32_t b, uint32_t* cond)
{
  int64_t temp, result, foo;
  uint32_t c = (*cond);
  //uint32_t res;
  
  temp = (int32_t)a;
  temp -= (int32_t)b;

  result = temp & 0x00000000FFFFFFFFL;

  // Clear flags
  *cond &= 0x0FFFFFFF;

  // N Flag = Rd[31]
  if (((temp >> 31) & 0x1) == 1)
    (*cond) |= N_FLAG;

  // Z Flag = If Rd == 0 then 1 else 0
  if (result == 0)
    (*cond) |= Z_FLAG;

// C Flag = NOT BorrowedFrom(Rn - shifter_operand - NOT(C Flag))
#if 0
  if (result == temp)
    (*cond) |= C_FLAG;
#else
  foo = (uint32_t)((uint64_t)result);
  //cout.form("foo = 0x%08x\n", foo);
  if (BORROWED_FROM(a, b, foo) == 0)
    (*cond) |= C_FLAG;
  
#endif

  // V Flag = OverflowFrom(Rn - shifter_operand - NOT(C Flag))
  if (((temp >> 32) & 0x1) != ((temp >> 31) & 0x1))
    (*cond) |= V_FLAG;

  return (uint32_t)result;
}


/******************************************************************************
 *
 */
uint32_t scALU::teq_op(uint32_t a, uint32_t b, uint32_t* cond)
{
  uint32_t result;

  result = a ^ b;

  // Clear Flags (overflow unaffected)
  *cond &= (0x0FFFFFFF | V_FLAG);

  // N Flag = Rd[31]
  if (((result >> 31) & 0x1) == 1)
    (*cond) |= N_FLAG;

  // Z Flag = If Rd == 0 then 1 else 0
  if (result == 0)
    (*cond) |= Z_FLAG;

  // C Flag = shifter_carry_out 
  // Done otherwhere

  // V Flag = unaffected

  return 0;
}


/******************************************************************************
 *
 */
uint32_t scALU::tst_op(uint32_t a, uint32_t b, uint32_t* cond)
{
  int32_t result;

  result = a & b;

  // Clear Flags (overflow unaffected)
  *cond &= (0x0FFFFFFF | V_FLAG);

  // N Flag = Rd[31]
  if (((result >> 31) & 0x1) == 1)
    (*cond) |= N_FLAG;

  // Z Flag = If Rd == 0 then 1 else 0
  if (result == 0)
    (*cond) |= Z_FLAG;

  // C Flag = shifter_carry_out 
  // Done otherwhere

  // V Flag = unaffected

  return 0;
}
void scALU::entry()
{
   OPCODE   op   =in_OP;
   uint32_t condition=inout_n_Flag;
   uint32_t a    =in_n_A;
   uint32_t b    =in_n_B;
  
   //sc_time local_time = sc_time_stamp();
 
   uint32_t result=0;
   switch (op)
   {
    case OP_AND: { 	result=and_op(a,b,&condition);/*cout<<"and_op";*/   break; }
    case OP_EOR: { 	result=eor_op(a,b,&condition);/*cout<<"eor_op";*/	break; }
    case OP_SUB: { 	result=sub_op(a,b,&condition);/*cout<<"sub_op";*/	break; }
    case OP_RSB: { 	result=rsb_op(a,b,&condition);/*cout<<"rsb_op";*/	break; }
    case OP_ADD: { 	result=add_op(a,b,&condition);/*cout<<"add_op";*/	break; }
    case OP_ADC: { 	result=adc_op(a,b,&condition);/*cout<<"adc_op";*/   break; }
    case OP_SBC: { 	result=sbc_op(a,b,&condition);/*cout<<"sbc_op";*/	break; }
    case OP_RSC: { 	result=rsc_op(a,b,&condition);/*cout<<"rsc_op";*/	break; }
    case OP_TST: { 	result=tst_op(a,b,&condition);/*cout<<"tst_op";*/	break; }
    case OP_ORR: { 	result=orr_op(a,b,&condition);/*cout<<"orr_op";*/	break; }
    case OP_TEQ: { 	result=teq_op(a,b,&condition);/*cout<<"teq_op";*/	break; }
    case OP_CMP: { 	result=cmp_op(a,b,&condition);/*cout<<"cmp_op";*/	break; }
    case OP_CMN: { 	result=cmn_op(a,b,&condition);/*cout<<"cmn_op";*/	break; }
    case OP_MOV: { 	result=mov_op(a,b,&condition);/*cout<<"mov_op";*/	break; }
    case OP_BIC: { 	result=bic_op(a,b,&condition);/*cout<<"bic_op";*/	break; }
    case OP_MVN: { 	result=mvn_op(a,b,&condition);/*cout<<"mvn_op";*/	break; }
    default:
		{
          cout<<"ALU: unknown op="<<op<<endl;
	
		}
   }//end of switch op
   inout_n_Flag=condition;
   //cout<<"flag="<<condition<<endl;
   out_n_Out=result;
   
#if defined(DEBUG)
   // cout<<" ALU: output="<<result<<endl;
#endif
}

void scALU::display()
{
   cout<<"A="<<in_n_A<<" B="<<in_n_B<<endl;
}
