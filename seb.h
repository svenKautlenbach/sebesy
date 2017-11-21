#pragma once

#include <cstdint>
#include <ctime>
#include <string>
#include <vector>

namespace seb
{
	struct Entry
	{
		std::string clientAccount;
		std::string documentNumber;
		std::time_t date;
		std::string participantAccount;
		std::string participantName;
		std::string receiverBank;
		std::string type;
		std::string debitOrCredit;
		float amount;
		std::string reference;
		std::string archive;
		std::string comment;
		float service;
		std::string currency;
		std::string nationalId;
	};

	std::vector<Entry> getEntriesFromCsv(const std::string& csv);
}