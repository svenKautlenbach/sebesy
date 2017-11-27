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
			if (se.participantName == std::string("SEB"))
			{
				CommentData comment(se.comment);
				r.article = comment.article();
			}
			else
			{
				r.article = se.comment;
			}
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

	CommentData::CommentData(const std::string &input) : m_article(input)
	{
		auto transactionStart = m_article.find_last_of("#");
		if (transactionStart == std::string::npos)
			return;

		auto kaartStart = m_article.find("kaart...");
		if (kaartStart == std::string::npos)
			return;

		m_article = m_article.substr(kaartStart + 8 + 6 + 1, transactionStart - kaartStart - 8 - 6 - 1);
	}

	std::string CommentData::article()
	{
		return m_article;
	}

	time_t CommentData::time()
	{
		throwIfMissing();

		return m_time;
	}

	uint32_t CommentData::transaction()
	{
		throwIfMissing();

		return m_transaction;
	}

	void CommentData::throwIfMissing()
	{
		if (m_transaction == 0)
			throw std::runtime_error("SEB comment did not include transaction details.");
	}
}

