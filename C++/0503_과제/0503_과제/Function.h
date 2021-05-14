#pragma once

template <typename T>

void Dynamic_delete(T& pObject)
{
	if (pObject)
	{
		delete pObject;
		pObject = nullptr;
	}
}