//Find
bool CPythonNetworkStream::RecvItemOwnership()
{
	...
}

///Add
#if defined(__BL_DROP_DESTROY_TIME__)
bool CPythonNetworkStream::RecvItemDestroyTime()
{
	TPacketGCItemDestroyTime p;

	if (!Recv(sizeof(TPacketGCItemDestroyTime), &p))
		return false;

	CPythonItem::Instance().SetDestroyTime(p.dwVID, p.tDestroyTime);
	return true;
}
#endif