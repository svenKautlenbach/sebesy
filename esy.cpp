#include "esy.h"

#include <string_view>

using namespace std::string_view_literals;
namespace
{
	constexpr std::string_view SEPARATOR = ";"sv;
}

namespace esy
{
	std::vector<Record> convertSebEntries(const std::vector<seb::Entry>& input)
	{
		(void)input;
		return std::vector<Record>{};
	}

	void printCsv(const std::vector<Record>& input, std::ostream& stream)
	{
		for (const auto& record : input)
		{
			stream << record.usDate << SEPARATOR
				   << record.article << SEPARATOR
				   << record.typeA << SEPARATOR
				   << record.typeB << SEPARATOR;

			const auto& a = record.amount;
			if (a < 0)
				stream << a << SEPARATOR << 0;
			else
				stream << 0 << SEPARATOR << a;

			stream << SEPARATOR << std::endl;
		}
	}
}

