#include <limits.h>
#include <iostream>
#include <math.h>
#include <bitset>
// Get 32-bit IEEE 754 format of the decimal value
std::string GetBinary32(float value)
{
	union
	{
		float input;   // assumes sizeof(float) == sizeof(int)
		int   output;
	}    data;
	data.input = value;
	std::bitset<sizeof(float) * CHAR_BIT>   bits(data.output);
	std::string mystring = bits.to_string<char,
		std::char_traits<char>,
		std::allocator<char> >();
	return mystring;
}
int main()
{
	// Convert 19.5 into IEEE 754 binary format..
	float f1 = 1.32f;
	double d3 = 1.32;
	std::string str = GetBinary32(f1);
	std::cout << str << std::endl << std::endl;
	std::string str2 = GetBinary32(d3);
	std::cout << str2 << std::endl << std::endl;
	return 0;
}