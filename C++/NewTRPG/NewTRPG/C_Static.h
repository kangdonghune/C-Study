#pragma once
class C_Static
{
public:
	C_Static();
	~C_Static();

public:
	template<typename T>
	static void deleteAllocation(T*& ptr)
	{
		if (ptr != nullptr)
		{
			delete ptr;
			ptr = nullptr;
		}
	}

};

