#pragma once
#include <string>
#ifndef _MSC_VER
	#include <cxxabi.h>
	#include "OnScopeExit.h"
#endif
namespace typesSupport
{
	#ifndef _MSC_VER
		std::string demangle(const char* const typeName)
		{
			std::string result;
			int status = -1;
			const char* demangled = abi::__cxa_demangle(ti.name(), 0, 0, &status);
			OnScopeExit call = [demangled]{ free(demangled); };
			if(status)
				result = typeName;
			else
				result = demangled;
			return result;
		}
	#else
		std::string demangle(const char* const typeName)
		{
			return typeName;
		}
	#endif
}