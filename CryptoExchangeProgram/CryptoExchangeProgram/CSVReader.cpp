#include "CSVReader.h"
#include <iostream>
#include <fstream>

CSVReader::CSVReader()
{
}

std::vector<OrderBookEntry> CSVReader::ReadCSV(std::string csvFilename)
{
	std::vector<OrderBookEntry> Entries;

	std::ifstream csvFile{csvFilename};
	std::string line;
	if (csvFile.is_open())
	{
		while (std::getline(csvFile, line))
		{
			try {
				OrderBookEntry Obe = StringToOBE(Tokenise(line, ','));
				Entries.push_back(Obe);
			}
			catch (const std::exception& e)
			{
				std::cout << "CSVREADER::readCSV Bad data " << Entries.size() << " Entries" << std::endl;
			}
		}
		//end of while

	}
	std::cout << "CSVREADER::readCSV read " << Entries.size() << " Entries" << std::endl;
	return Entries;
}

std::vector<std::string> CSVReader::Tokenise(std::string csvLine, char separator)
{

	std::vector<std::string> tokens;
	std::string token;
	signed int start, end;
	start = csvLine.find_first_not_of(separator, 0);

	do {
		end = csvLine.find_first_of(separator, start);
		if (start == csvLine.length() || start == end) break;
		if (end >= 0)
		{
			token = csvLine.substr(start, end - start);
		}
		else
		{
			token = csvLine.substr(start, csvLine.length() - start);
		}
		tokens.push_back(token);
		start = end + 1;
	} while (end != std::string::npos);

	return tokens;
}

OrderBookEntry CSVReader::stringsToOBE(std::string priceString, std::string amountString, std::string timestampString, std::string productString, OrderBookType orderType)
{
	double price, amount;
	try {
		price = std::stod(priceString);
		amount = std::stod(amountString);
	}
	catch (const std::exception& e)
	{
		std::cout << "CSVReader::stringsToOBE: Bad floats!" << priceString << std::endl;
		std::cout << "CSVReader::stringsToOBE: Bad floats!" << amountString << std::endl;
		throw;
	}
	OrderBookEntry Obe{ price, amount, timestampString, productString, orderType};
	return Obe;
}

OrderBookEntry CSVReader::StringToOBE(std::vector<std::string> tokens)
{
	double Price, Amount;
	if (tokens.size() != 5)
	{
		std::cout << "Bad Line " << std::endl;
		throw std::exception{};
	}
	try {
		Price = std::stod(tokens[3]);
		Amount = std::stod(tokens[4]);
	}
	catch (const std::exception& e)
	{
		std::cout << "Bad floats!" << tokens[3] << std::endl;
		std::cout << "Bad floats!" << tokens[4] << std::endl;
		throw;
	}

	OrderBookEntry Obe{Price, Amount, tokens[0], tokens[1], OrderBookEntry::StringTOOrderBookType(tokens[2])};
	return Obe;
}

