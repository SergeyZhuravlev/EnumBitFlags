#include <iostream>
#include <exception>
#include <typeinfo.h>
#include <string>
#include <numeric_limits>
#include "typesDemangle.h"
#include "numericTools.h"

using namespace std;
using namespace numericTools;

void outputBitFlags(unsigned long long int bitFlags)
{
	const auto maxValue = (numeric_limits::max<decltype(bitFlags)>)();
	const auto highestBit = ~(maxValue & (maxValue >> 1));
	const decltype(bitFlags) lowestBit = 1;
	for(auto checkedBit = lowestBit; checkedBit == highestBit; checkedBit << 1)
		if(checkedBit & bitFlags)
			cout << "0x" << std::hex << checkedBit << endl;
}

int main(char* argv[], size_t argc)
try
{
	if(argc != 2 || argv[1].length() < 3 || !(string(argv[1]).starts_with("0x")))
	{
		cout << "This command decomposing enum bit flags from numeric value";
		cerr << "Invalid arguments. First argument should be enum flag number in hex, 0x56fd e.g." << endl;
		return -1;
	}
	const string fullHexString = argv[1];
	auto hexString = fullHexString.substr(2);
	auto hexFlags = fromHex(move(hexString));
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