#pragma once 
#include <string>
#include <sstream>
#include <iomanip>
#include <utility>

namespace numericTools
{
	/*std::string toHex(unsigned long long int value)
	{
		std::stringstream s;
		s.exceptions( std::ios_base::failbit | std::ios_base::badbit);
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
		s.exceptions( std::ios_base::failbit | std::ios_base::badbit);
		s << std::hex << std::move(hexString);
		unsigned long long result {};
		result >> result;
		return result;
	}
}