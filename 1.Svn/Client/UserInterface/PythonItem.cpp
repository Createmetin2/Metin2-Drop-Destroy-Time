//Find
void CPythonItem::Update(const POINT& c_rkPtMouse)
{
	...
}

///Change Function
void CPythonItem::Update(const POINT& c_rkPtMouse)
{
#if defined(__BL_DROP_DESTROY_TIME__)
	static DWORD s_dwLastUpdate = 0;
	const bool bCanUpdate = (CTimer::Instance().GetCurrentMillisecond() - s_dwLastUpdate) >= 1000;
#endif
	
	TGroundItemInstanceMap::iterator itor = m_GroundItemInstanceMap.begin();
	for(; itor != m_GroundItemInstanceMap.end(); ++itor)
	{
		itor->second->Update();
#if defined(__BL_DROP_DESTROY_TIME__)
		if (bCanUpdate)
			CPythonTextTail::Instance().SetItemTextTailDestroyTime(itor->first, itor->second->tDestroyTime);
#endif
	}

#if defined(__BL_DROP_DESTROY_TIME__)
	if (bCanUpdate)
		s_dwLastUpdate = CTimer::Instance().GetCurrentMillisecond();
#endif

	m_dwPickedItemID=__Pick(c_rkPtMouse);
}

//Find
	pGroundItemInstance->dwVirtualNumber = dwVirtualNumber;

///Add
#if defined(__BL_DROP_DESTROY_TIME__)
	pGroundItemInstance->tDestroyTime = 0;
#endif

///Add new func
#if defined(__BL_DROP_DESTROY_TIME__)
void CPythonItem::SetDestroyTime(DWORD dwVID, short sDestroySeconds)
{
	TGroundItemInstanceMap::const_iterator itor = m_GroundItemInstanceMap.find(dwVID);

	if (m_GroundItemInstanceMap.end() != itor)
		itor->second->tDestroyTime = time(NULL) + sDestroySeconds;
}
#endif