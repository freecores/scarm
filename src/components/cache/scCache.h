// scCache.h: interface for the scCache class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCCACHE_H__3D36E4DE_3B3D_11D6_B9E2_000000000000__INCLUDED_)
#define AFX_SCCACHE_H__3D36E4DE_3B3D_11D6_B9E2_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include"scTypes.h"
#include<systemc.h>
#include <sc_mslib.h>

class scCache:public sc_module
{
public://ports
	//sc_out<bool>        out_b_nRW;
	sc_outmaster<uint32_t>    out_n_A;
	sc_inoutslave<uint32_t>   inout_n_D;	
public:
	scCache();
	virtual ~scCache();

};

#endif // !defined(AFX_SCCACHE_H__3D36E4DE_3B3D_11D6_B9E2_000000000000__INCLUDED_)
