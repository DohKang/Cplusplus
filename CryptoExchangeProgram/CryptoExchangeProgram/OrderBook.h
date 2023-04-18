#pragma once

#include "OrderBookEntry.h"
#include "CSVReader.h"
#include <vector>
#include <string>

class OrderBook
{
public:
	/** Construct, reading a csv data file*/
	OrderBook(std::string filename);
	/**return vector of all known products in the dataset	*/
	std::vector<std::string> GetKnownProducts();
	/*return vector of Orders according to the sent fillters*/
	std::vector<OrderBookEntry> GetOrders(OrderBookType type,
										  std::string product,
										  std::string timestamp);

	/**
	 * @brief 
	 * @return the earliest time in the orderBook 
	*/
	std::string getEarliestTime();
	/**
	 * @brief 
	 * @return the next time after the sent time in the orderbook
	 * if there is no next timestamp, wraps around to the start
	*/
	std::string getNextTime(std::string timestamp);

	void insertOrder(OrderBookEntry& order);

	std::vector<OrderBookEntry> matchAsksToBids(std::string product, std::string timestamp);

	static double getHightPrice(std::vector<OrderBookEntry>& orders);
	static double getLowestPrice(std::vector<OrderBookEntry>& orders);

private:
	std::vector<OrderBookEntry> orders;
};

