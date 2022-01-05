//Find
			std::string				stOwnership;

///Add
#if defined(__BL_DROP_DESTROY_TIME__)
			time_t					tDestroyTime;
#endif

//Find
		bool	GetOwnership(DWORD dwVID, const char ** c_pszName);

///Add
#if defined(__BL_DROP_DESTROY_TIME__)
		void	SetDestroyTime(DWORD dwVID, short sDestroySeconds);
#endif