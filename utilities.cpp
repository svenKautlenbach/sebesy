#include "utilities.h"

#include <iomanip>
#include <sstream>

namespace utilities
{
	void replaceContent(std::string& toFormat, const std::string& what, const std::string& to)
	{
		size_t start_pos = 0;
		while((start_pos = toFormat.find(what, start_pos)) != std::string::npos)
		{
			toFormat.replace(start_pos, what.length(), to);
			start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
		}
	}

	time_t convertEstDate(const std::string& time)
	{
		std::istringstream ss(time);
		std::tm t{};
		ss >> std::get_time(&t, "%d.%m.%Y");

		return std::mktime(&t);
	}

}