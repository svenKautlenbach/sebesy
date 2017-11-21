#include "seb.h"

#include <array>
#include <fstream>
#include <sstream>
#include <iostream>

namespace
{
	std::vector<std::string> getLines(const std::string& csv)
	{
		std::vector<std::string> ls;

		std::ifstream in(csv);
		std::string l;
		while (std::getline(in, l))
			ls.push_back(l);

		return ls;
	}

	std::vector<std::string> getItems(const std::string& line)
	{
		std::istringstream ss(line);
		std::vector<std::string> items;
		for (std::array<char, 200> item; ss.getline(&item[0], 200, ';');)
			items.push_back(std::string(item.data()));

		if (items.size() < 14)
			throw std::runtime_error("Data does not have correct count of items on one record.");

		return items;
	}

	std::time_t toTimeT(const std::string& timestamp)
	{
		(void)timestamp;
		return std::time(nullptr);
	}
}

namespace seb
{
	std::vector<Entry> getEntriesFromCsv(const std::string& csv)
	{
		std::vector<Entry> entries;
		bool skipThis = true;
		for (const auto& l : getLines(csv))
		{
			if (skipThis)
			{
				skipThis = false;
				continue;
			}
			if (l.length() < 30)
				break;

			const auto& items = getItems(l);
			Entry e{items[0], items[1], toTimeT(items[2]), items[3], items[4],
							   items[5], items[6], items[7], std::stof(items[8]), items[9], items[10],
							   items[11], std::stof(items[12]), items[13], (items.size() == 15 ? items[14] : "")};
			entries.push_back(e);
		}

		return entries;
	}
}