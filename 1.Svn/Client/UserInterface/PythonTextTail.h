//Find
			CGraphicTextInstance*			pOwnerTextInstance;

///Add
#if defined(__BL_DROP_DESTROY_TIME__)
			CGraphicTextInstance*			pDestroyTimeTextInstance;
#endif

//Find
		void SetItemTextTailOwner(DWORD dwVID, const char * c_szName);

///Add
#if defined(__BL_DROP_DESTROY_TIME__)
		void SetItemTextTailDestroyTime(DWORD dwVID, time_t tDestroyTime);
#endif