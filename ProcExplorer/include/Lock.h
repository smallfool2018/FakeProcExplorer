#ifndef __LOCK_H__
#define __LOCK_H__

#pragma once

class CLock
{
public:
	CLock();
	~CLock();

	void Init();
	void Delete();

	void Lock()
	{
		EnterCriticalSection(&m_Impl);
	}
	void Unlock()
	{
		LeaveCriticalSection(&m_Impl);
	}

protected:
	CRITICAL_SECTION m_Impl;
};

extern CLock gLock1, gLock2, gLock3, gVerificationItemListLock, gLock5;

#endif //
