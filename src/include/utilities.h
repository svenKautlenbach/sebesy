#pragma once

#include <ctime>
#include <string>

namespace utilities
{
	void replaceContent(std::string& toFormat, const std::string& what, const std::string& to); // We need to fuck up some commas "," -> "." and remove '"'.
	time_t convertEstDate(const std::string& time);
}