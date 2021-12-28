//Find
			Set(HEADER_GC_ITEM_OWNERSHIP,		CNetworkPacketHeaderMap::TPacketType(sizeof(TPacketGCItemOwnership), STATIC_SIZE_PACKET));

///Add
#if defined(__BL_DROP_DESTROY_TIME__)
			Set(HEADER_GC_ITEM_DESTROY_TIME, CNetworkPacketHeaderMap::TPacketType(sizeof(TPacketGCItemDestroyTime), STATIC_SIZE_PACKET));
#endif