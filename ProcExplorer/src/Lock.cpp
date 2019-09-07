#include "stdafx.h"
#include "..\include\Lock.h"

CLock gLock1, gLock2, gLock3, gVerificationItemListLock, gLock5;

CLock::CLock()
{
}


CLock::~CLock()
{
}

void CLock::Init()
{
	InitializeCriticalSection(&m_Impl);

}

void CLock::Delete()
{
	DeleteCriticalSection(&m_Impl);

}