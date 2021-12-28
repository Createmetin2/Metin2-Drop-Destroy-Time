//Find
	m_dwMaskVnum(0), m_dwSIGVnum (0)

///Add
#if defined(__BL_DROP_DESTROY_TIME__)
	, tDestroyTime(0)
#endif

//Find
	SetDestroyEvent(event_create(item_destroy_event, info, PASSES_PER_SEC(iSec)));

///Add
#if defined(__BL_DROP_DESTROY_TIME__)
	TPacketGCItemDestroyTime p;
	p.bHeader = HEADER_GC_ITEM_DESTROY_TIME;
	p.dwVID = m_dwVID;
	p.tDestroyTime = tDestroyTime = time(0) + iSec;
	PacketAround(&p, sizeof(p));
#endif

///Add to end of void CItem::EncodeInsertPacket(LPENTITY ent)
#if defined(__BL_DROP_DESTROY_TIME__)
	if (m_pkDestroyEvent && tDestroyTime > 0)
	{
		TPacketGCItemDestroyTime p;
		p.bHeader = HEADER_GC_ITEM_DESTROY_TIME;
		p.dwVID = m_dwVID;
		p.tDestroyTime = tDestroyTime;
		d->Packet(&p, sizeof(TPacketGCItemDestroyTime));
	}
#endif