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

	class CommentData
	{
	public:

		CommentData() = default;
		CommentData(const std::string& input);
		~CommentData() = default;

		std::string article();
		time_t time();
		uint32_t transaction();

	private:

		void throwIfMissing();

		static constexpr uint32_t MISSING_TRANSACTION = 0;

		std::string m_article;
		time_t m_time;
		uint32_t m_transaction = MISSING_TRANSACTION;
	};
}