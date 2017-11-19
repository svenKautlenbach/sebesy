#pragma once

#include <cstdint>
#include <ctime>
#include <string>
#include <vector>

namespace seb
{
	constexpr uint64_t MISSING_DOC_NR = 0;

	struct Entry
	{
		std::string clientAccount;
		uint64_t documentNumber; // Equals MISSING_DOC_NR if none exists.
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