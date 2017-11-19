#include <iostream>
#include <exception>

#include "esy.h"
#include "seb.h"

void printUsage(const char* callPath)
{
	std::cout << "Usage:" << std::endl << callPath << " {seb .csv file}" << std::endl;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printUsage(argv[0]);
		return -1;
	}

	const auto records = std::string(argv[1]);
	try
	{
		const auto& entries = seb::getEntriesFromCsv(records);
		const auto& esyRecords = esy::convertSebEntries(entries);
		esy::printCsv(esyRecords);
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught exception yo:" << std::endl << e.what() << std::endl << "Have to exit." << std::endl;
		return -2;
	}
	catch (...)
	{
		std::cout << "Unanimous error, gotta exit." << std::endl;
		return -3;
	}

	return 0;
}