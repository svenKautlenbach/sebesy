#include "esy.h"

#include <iomanip>

namespace
{
	constexpr char SEPARATOR = ';';
}

namespace esy
{
	std::vector<Record> convertSebEntries(const std::vector<seb::Entry>& input)
	{
		std::vector<Record> rs;
		for (const auto& se : input)
		{
			Record r;
			char usFormat[100];
			std::strftime(usFormat, 100, "%m/%e/%Y", std::localtime(&se.date));
			r.usDate = std::string(usFormat);
			r.amount = se.amount;
			r.typeB = "B";
			r.typeA = "A";
			r.article = se.comment;
			rs.push_back(r);
		}

		return rs;
	}

	void printCsv(const std::vector<Record>& input, std::ostream& stream)
	{
		stream << std::fixed << std::setprecision(2);
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

