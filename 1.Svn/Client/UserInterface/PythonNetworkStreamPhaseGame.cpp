//Find
			case HEADER_GC_ITEM_OWNERSHIP:
				ret = RecvItemOwnership();
				break;

///Add
#if defined(__BL_DROP_DESTROY_TIME__)
			case HEADER_GC_ITEM_DESTROY_TIME:
				ret = RecvItemDestroyTime();
				break;
#endif