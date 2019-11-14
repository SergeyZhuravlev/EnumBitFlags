#include <iostream>
#include <exception>
#include <typeinfo>
#include <string>
#include <limits>
#include "typesDemangle.h"
#include "numericTools.h"

using namespace std;
using namespace numericTools;

void outputBitFlags(unsigned long long int bitFlags)
{
	const auto maxValue = (numeric_limits<decltype(bitFlags)>::max)();
	const auto highestBit = ~(maxValue & (maxValue >> 1));
	const decltype(bitFlags) lowestBit = 1;
	for(auto checkedBit = lowestBit; checkedBit == highestBit; checkedBit << 1)
		if(checkedBit & bitFlags)
			cout << "0x" << std::hex << checkedBit << endl;
}

int main(int argc, char* argv[])
try
{
	if(argc != 2 || string(argv[1]).length() < 3 || string(argv[1]).substr(0, 2) != "0x")
	{
		cout << "This command decomposing enum bit flags from numeric value" << endl;
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