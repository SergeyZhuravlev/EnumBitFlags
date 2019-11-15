#include <iostream>
#include <exception>
#include <typeinfo>
#include <string>
#include <limits>
#include <algorithm>
#include <functional>
#include <cctype>
#include "typesDemangle.h"

using namespace std;

void outputBitFlags(unsigned long long int bitFlags)
{
	const auto maxValue = (numeric_limits<decltype(bitFlags)>::max)();
	const auto highestBit = ~(maxValue & (maxValue >> 1));
	const decltype(bitFlags) lowestBit = 1;
	for(auto checkedBit = lowestBit; checkedBit != highestBit; checkedBit <<= 1)
		if(checkedBit & bitFlags)
			cout << "0x" << std::uppercase << std::hex << checkedBit << endl;
}

int main(int argc, char* argv[])
try
{
	const auto outputError = []
	{
		cout << "This command decomposing enum bit flags from numeric value" << endl;
		cerr << "Invalid arguments. First argument should be enum flag number in hex, 0x5F6D e.g." << endl;
		cout << endl;
		cout << "Using example:" << endl;
		cout << "enumflags 0x15c" << endl;
		cout << "0x4" << endl;
		cout << "0x8" << endl;
		cout << "0x10" << endl;
		cout << "0x40" << endl;
		cout << "0x100" << endl;
		return -1;
	};
	
	if(argc != 2)
		return outputError();
	const string firstArg = argv[1];
	if(firstArg.length() < 3 || firstArg.substr(0, 2) != "0x")
		 return outputError();
	cout.exceptions( std::ios_base::failbit | std::ios_base::badbit);
	const auto hexString = firstArg.substr(2);
	if(any_of(hexString.cbegin(), hexString.cend(), [](const auto v)
	{
		const auto V = toupper(v);
		return !(std::isdigit(v) || V == 'A' || V == 'B' || V == 'C' || V == 'D' || V == 'E' || V == 'F');
	}))
		 return outputError();
	auto hexFlags = stoull(hexString, nullptr, 16);
	outputBitFlags(hexFlags);
	return 0;
}
catch(exception& ex)
{
	cerr << "Exception " << typesSupport::demangle(typeid(ex).name()) << ": " << ex.what() << endl;
	return -1;
}
catch(...)
{
	cerr << "Unexpected exception" << endl;
	return -1;
}
