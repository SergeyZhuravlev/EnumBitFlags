#pragma once 
#include <string>
#include <sstream>
#include <iomanip>

namespace numericTools
{
	/*std::string toHex(unsigned long long int value)
	{
		std::stringstream s;
		s << std::hex << value;
		return std::move(s.str());
	}
	
	std::string toCHex(unsigned long long int value)
	{
		return "0x" + toHex(value);
	}*/
	
	unsigned long long int fromHex(std::string hexString)
	{
		std::stringstream s;
		s << std::hex << std::move(value);
		return std::move(s.str());
	}
}