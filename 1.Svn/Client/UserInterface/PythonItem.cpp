//Find
		itor->second->Update();

///Add
#if defined(__BL_DROP_DESTROY_TIME__)
		CPythonTextTail::Instance().SetItemTextTailDestroyTime(itor->first, itor->second->tDestroyTime);
#endif

//Find
	pGroundItemInstance->dwVirtualNumber = dwVirtualNumber;

///Add
#if defined(__BL_DROP_DESTROY_TIME__)
	pGroundItemInstance->tDestroyTime = 0;
#endif

///Add new func
#if defined(__BL_DROP_DESTROY_TIME__)
void CPythonItem::SetDestroyTime(DWORD dwVID, time_t tDestroyTime)
{
	TGroundItemInstanceMap::const_iterator itor = m_GroundItemInstanceMap.find(dwVID);

	if (m_GroundItemInstanceMap.end() != itor)
		itor->second->tDestroyTime = tDestroyTime;
}
#endif