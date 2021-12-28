//Find
		if (pInsertTextTail->pOwnerTextInstance)
		{
			pInsertTextTail->pOwnerTextInstance->SetPosition(pInsertTextTail->x, pInsertTextTail->y, pInsertTextTail->z);
			pInsertTextTail->pOwnerTextInstance->Update();

			pInsertTextTail->pTextInstance->SetColor(pInsertTextTail->Color.r, pInsertTextTail->Color.g, pInsertTextTail->Color.b);
			pInsertTextTail->pTextInstance->SetPosition(pInsertTextTail->x, pInsertTextTail->y + 15.0f, pInsertTextTail->z);
			pInsertTextTail->pTextInstance->Update();

		}
		else
		{
			pInsertTextTail->pTextInstance->SetColor(pInsertTextTail->Color.r, pInsertTextTail->Color.g, pInsertTextTail->Color.b);
			pInsertTextTail->pTextInstance->SetPosition(pInsertTextTail->x, pInsertTextTail->y, pInsertTextTail->z);
			pInsertTextTail->pTextInstance->Update();

		}

///Change
#if defined(__BL_DROP_DESTROY_TIME__)
		BYTE bLine = 0;
		for (CGraphicTextInstance* obj : { pInsertTextTail->pDestroyTimeTextInstance, pInsertTextTail->pOwnerTextInstance, pInsertTextTail->pTextInstance })
		{
			if (obj == nullptr)
				continue;

			if (obj == pInsertTextTail->pTextInstance)
				obj->SetColor(pInsertTextTail->Color.r, pInsertTextTail->Color.g, pInsertTextTail->Color.b);

			obj->SetPosition(pInsertTextTail->x, pInsertTextTail->y + ((bLine++) * 15.0f), pInsertTextTail->z);
			obj->Update();
		}
#else
		if (pInsertTextTail->pOwnerTextInstance)
		{
			pInsertTextTail->pOwnerTextInstance->SetPosition(pInsertTextTail->x, pInsertTextTail->y, pInsertTextTail->z);
			pInsertTextTail->pOwnerTextInstance->Update();

			pInsertTextTail->pTextInstance->SetColor(pInsertTextTail->Color.r, pInsertTextTail->Color.g, pInsertTextTail->Color.b);
			pInsertTextTail->pTextInstance->SetPosition(pInsertTextTail->x, pInsertTextTail->y + 15.0f, pInsertTextTail->z);
			pInsertTextTail->pTextInstance->Update();

		}
		else
		{
			pInsertTextTail->pTextInstance->SetColor(pInsertTextTail->Color.r, pInsertTextTail->Color.g, pInsertTextTail->Color.b);
			pInsertTextTail->pTextInstance->SetPosition(pInsertTextTail->x, pInsertTextTail->y, pInsertTextTail->z);
			pInsertTextTail->pTextInstance->Update();

		}
#endif

//Find
		if (pTextTail->pOwnerTextInstance)
			pTextTail->pOwnerTextInstance->Render();

///Add
#if defined(__BL_DROP_DESTROY_TIME__)
		if (pTextTail->pDestroyTimeTextInstance)
			pTextTail->pDestroyTimeTextInstance->Render();
#endif

//Find in void CPythonTextTail::SetItemTextTailOwner(DWORD dwVID, const char* c_szName)
		int xOwnerSize, yOwnerSize;
		pTextTail->pOwnerTextInstance->GetTextSize(&xOwnerSize, &yOwnerSize);
		pTextTail->yStart = -2.0f;
		pTextTail->yEnd += float(yOwnerSize + 4);
		pTextTail->xStart = fMIN(pTextTail->xStart, float(-xOwnerSize / 2 - 1));
		pTextTail->xEnd = fMAX(pTextTail->xEnd, float(xOwnerSize / 2 + 1));

///Add
#if defined(__BL_DROP_DESTROY_TIME__)
		if (pTextTail->pDestroyTimeTextInstance)
		{
			int xDestroyTimeSize, yDestroyTimeSize;
			pTextTail->pDestroyTimeTextInstance->GetTextSize(&xDestroyTimeSize, &yDestroyTimeSize);
			
			pTextTail->xStart = fMIN(pTextTail->xStart, static_cast<float>(-xDestroyTimeSize / 2 - 1));
			pTextTail->xEnd = fMAX(pTextTail->xEnd, static_cast<float>(xDestroyTimeSize / 2 + 1));
		}
#endif

//Find in void CPythonTextTail::SetItemTextTailOwner(DWORD dwVID, const char* c_szName)
		int xSize, ySize;
		pTextTail->pTextInstance->GetTextSize(&xSize, &ySize);
		pTextTail->xStart = (float)(-xSize / 2 - 2);
		pTextTail->yStart = -2.0f;
		pTextTail->xEnd = (float)(xSize / 2 + 2);
		pTextTail->yEnd = (float)ySize;

///Add
#if defined(__BL_DROP_DESTROY_TIME__)
		if (pTextTail->pDestroyTimeTextInstance)
		{
			int xDestroyTimeSize, yDestroyTimeSize;
			pTextTail->pDestroyTimeTextInstance->GetTextSize(&xDestroyTimeSize, &yDestroyTimeSize);

			pTextTail->xStart = fMIN(pTextTail->xStart, static_cast<float>(-xDestroyTimeSize / 2 - 1));
			pTextTail->xEnd = fMAX(pTextTail->xEnd, static_cast<float>(xDestroyTimeSize / 2 + 1));
			pTextTail->yEnd += static_cast<float>(yDestroyTimeSize + 4);
		}
#endif

///Add new func
#if defined(__BL_DROP_DESTROY_TIME__)
void CPythonTextTail::SetItemTextTailDestroyTime(DWORD dwVID, time_t tDestroyTime)
{
	if (tDestroyTime <= 0)
		return;
	
	TTextTailMap::const_iterator itor = m_ItemTextTailMap.find(dwVID);
	if (m_ItemTextTailMap.end() == itor)
		return;

	TTextTail* pTextTail = itor->second;

	bool bCreate = false;
	if (!pTextTail->pDestroyTimeTextInstance)
	{
		pTextTail->pDestroyTimeTextInstance = CGraphicTextInstance::New();
		bCreate = true;
	}
	
	const int iSeconds = static_cast<int>(difftime(tDestroyTime, time(nullptr)));
	std::string strName = "(" + std::to_string(iSeconds) + "s)";
	pTextTail->pDestroyTimeTextInstance->SetTextPointer(ms_pFont);
	pTextTail->pDestroyTimeTextInstance->SetHorizonalAlign(CGraphicTextInstance::HORIZONTAL_ALIGN_CENTER);
	pTextTail->pDestroyTimeTextInstance->SetValue(strName.c_str());
	pTextTail->pDestroyTimeTextInstance->SetColor(0.0f / 255.0f, 255.0f / 255.0f, 255.0f / 255.0f);
	pTextTail->pDestroyTimeTextInstance->Update();

	int xDestroyTimeSize, yDestroyTimeSize;
	pTextTail->pDestroyTimeTextInstance->GetTextSize(&xDestroyTimeSize, &yDestroyTimeSize);

	pTextTail->yStart = -2.0f;

	if (bCreate)
		pTextTail->yEnd += float(yDestroyTimeSize + 4);

	pTextTail->xStart = fMIN(pTextTail->xStart, static_cast<float>(-xDestroyTimeSize / 2 - 1));
	pTextTail->xEnd = fMAX(pTextTail->xEnd, static_cast<float>(xDestroyTimeSize / 2 + 1));

	if (pTextTail->pOwnerTextInstance)
	{
		int xOwnerSize, yOwnerSize;
		pTextTail->pOwnerTextInstance->GetTextSize(&xOwnerSize, &yOwnerSize);

		pTextTail->xStart = fMIN(pTextTail->xStart, static_cast<float>(-xOwnerSize / 2 - 1));
		pTextTail->xEnd = fMAX(pTextTail->xEnd, static_cast<float>(xOwnerSize / 2 + 1));
	}
}
#endif

//Find
	pTextTail->pOwnerTextInstance = NULL;

///Add
#if defined(__BL_DROP_DESTROY_TIME__)
	pTextTail->pDestroyTimeTextInstance = nullptr;
#endif

//Find
	if (pTextTail->pOwnerTextInstance)
	{
		CGraphicTextInstance::Delete(pTextTail->pOwnerTextInstance);
		pTextTail->pOwnerTextInstance = NULL;
	}

///Add
#if defined(__BL_DROP_DESTROY_TIME__)
	if (pTextTail->pDestroyTimeTextInstance)
	{
		CGraphicTextInstance::Delete(pTextTail->pDestroyTimeTextInstance);
		pTextTail->pDestroyTimeTextInstance = nullptr;
	}
#endif