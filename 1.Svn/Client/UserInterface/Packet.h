//Find
	HEADER_GC_RESPOND_CHANNELSTATUS				= 210,

///Add
#if defined(__BL_DROP_DESTROY_TIME__)
	HEADER_GC_ITEM_DESTROY_TIME = 212,
#endif

//Find
typedef struct packet_item_ownership
{
	...
} TPacketGCItemOwnership;

///Add
#if defined(__BL_DROP_DESTROY_TIME__)
typedef struct packet_item_destroy_time
{
	BYTE	bHeader;
	DWORD	dwVID;
	time_t	tDestroyTime;
} TPacketGCItemDestroyTime;
#endif