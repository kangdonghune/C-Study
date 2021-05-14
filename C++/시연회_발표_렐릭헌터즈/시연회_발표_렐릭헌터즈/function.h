#pragma once

template <typename T>
void Delete_Dynamic(T* pObject)
{
	if (nullptr != pObject)
	{
		delete pObject;
		pObject = nullptr;
	}
}