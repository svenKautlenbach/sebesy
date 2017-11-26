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
			std::strftime(usFormat, 100, "%m/%d/%Y", std::localtime(&se.date));
			r.usDate = std::string(usFormat);
			if (se.nationalId.empty())
				r.amount = -1 * se.amount;
			else
				r.amount = se.amount;
			r.typeB = "";
			r.typeA = "";
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
				stream << -1 * a << SEPARATOR << 0;
			else
				stream << 0 << SEPARATOR << a;

			stream << SEPARATOR << std::endl;
		}
	}
}

