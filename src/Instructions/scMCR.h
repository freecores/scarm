// scMCR.h: interface for the scMCR class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCMCR_H__A72DCFBC_3F9A_11D6_B9EB_000000000000__INCLUDED_)
#define AFX_SCMCR_H__A72DCFBC_3F9A_11D6_B9EB_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "scARMInstruction.h"

class scMCR : public scARMInstruction  
{
public:
	scMCR();
	virtual ~scMCR();

};

#endif // !defined(AFX_SCMCR_H__A72DCFBC_3F9A_11D6_B9EB_000000000000__INCLUDED_)
