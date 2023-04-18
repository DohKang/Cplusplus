#pragma once
#include "OrderBookEntry.h"
#include <vector>
#include <string>

class CSVReader
{
public:
	CSVReader();

	static std::vector<OrderBookEntry>ReadCSV(std::string csvFile);
	static std::vector<std::string> Tokenise(std::string csvLine, char separator);
	static OrderBookEntry stringsToOBE(	std::string price,
										std::string amount,
										std::string timestamp,
										std::string product,
										OrderBookType type);
private:
	
	static OrderBookEntry StringToOBE(std::vector<std::string> strings);
};

