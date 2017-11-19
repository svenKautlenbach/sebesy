#pragma once

#include <iostream>

#include "seb.h"

namespace esy
{
	struct Record
	{
		std::string usDate;
		std::string article;
		std::string typeA;
		std::string typeB;
		float amount;
	};

	std::vector<Record> convertSebEntries(const std::vector<seb::Entry>& input);
	void printCsv(const std::vector<Record>& input, std::ostream& stream = std::cout);
}