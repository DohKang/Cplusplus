#include "OrderBook.h"
#include "CSVReader.h"
#include <map>
#include <algorithm>
OrderBook::OrderBook(std::string filename)
{
	orders = CSVReader::ReadCSV(filename);
}

std::vector<std::string> OrderBook::GetKnownProducts()
{
	std::vector<std::string> products;

	std::map<std::string, bool> prodMap;

	for (OrderBookEntry const& e : orders)
	{
		prodMap[e.Product] = true;
	}

	//now flatten the map to a vector of string
	for (auto const& e : prodMap)
	{
		products.push_back(e.first);
	}

	return products;
}

std::vector<OrderBookEntry> OrderBook::GetOrders(OrderBookType type, std::string product, std::string timestamp)
{
	 
	std::vector<OrderBookEntry> orders_sub;
	for (OrderBookEntry& e : orders)
	{
		if (e.OrderType == type &&
			e.Product == product &&
			e.Timestamp == timestamp)
		{
			orders_sub.push_back(e);
		}
	}
	return orders_sub;
}

std::string OrderBook::getEarliestTime()
{
	return orders[0].Timestamp;
}

std::string OrderBook::getNextTime(std::string timestamp)
{
	std::string next_timestamp = "";
	for (OrderBookEntry& e : orders)
	{
		if (e.Timestamp > timestamp)
		{
			next_timestamp = e.Timestamp;
			break;
		}
	}
	if (next_timestamp == "")
	{
		next_timestamp = orders[0].Timestamp;
	}
	return next_timestamp;

}

void OrderBook::insertOrder(OrderBookEntry& order)
{
	orders.push_back(order);
	std::sort(orders.begin(), orders.end(), OrderBookEntry::compareByTimestamp);
}

std::vector<OrderBookEntry> OrderBook::matchAsksToBids(std::string product, std::string timestamp)
{
	//ask = orderbook.ask
	std::vector<OrderBookEntry> asks = GetOrders(OrderBookType::ask, product, timestamp);
	//bids = orderbook.bid
	std::vector<OrderBookEntry> bids = GetOrders(OrderBookType::bid, product, timestamp);

	//sales = []

	std::vector<OrderBookEntry> sales;

	//sort asks lowest first
	std::sort(asks.begin(), asks.end(), OrderBookEntry::compareByPriceAsc);
	//sort bids highest first
	std::sort(bids.begin(), bids.end(), OrderBookEntry::compareByPriceDesc);

	//for ask in asks
	for (OrderBookEntry& ask : asks)
	{
		//for bid in bids
		for (OrderBookEntry& bid : bids)
		{
			if (bid.Price >= ask.Price)
			{
				OrderBookEntry sale{ ask.Price
					,
					0,
					timestamp,
					product,
					OrderBookType::asksale };
				OrderBookType type = OrderBookType::asksale;
				if (bid.username == "simuser")
				{
					sale.username = "simuser";
					sale.OrderType = OrderBookType::bidsale;
				}
				if (ask.username == "simuser")
				{
					sale.username = "simuser";
					sale.OrderType = OrderBookType::asksale;
				}

				if (bid.Amount == ask.Amount)
				{
					sale.Amount = ask.Amount;
					sales.push_back(sale);
					bid.Amount = 0;
					break;
				}

				if (bid.Amount > ask.Amount)
				{
					sale.Amount = ask.Amount;
					sales.push_back(sale);
					bid.Amount -= ask.Amount;
					break;
				}

				if (bid.Amount < ask.Amount
					&& bid.Amount >0)
				{
					sale.Amount = bid.Amount;
					sales.push_back(sale);
					bid.Amount = 0;
					continue;
				}
			}




		}
	}




	return sales;
}

double OrderBook::getHightPrice(std::vector<OrderBookEntry>& orders)
{
	double max = orders[0].Price;
	for (OrderBookEntry& e : orders)
	{
		if (e.Price > max)
		{
			max = e.Price;
		}
	}
	return max;
}

double OrderBook::getLowestPrice(std::vector<OrderBookEntry>& orders)
{
	double min = orders[0].Price;
	for (OrderBookEntry& e : orders)
	{
		if (e.Price < min)
		{
			min = e.Price;
		}
	}
	return min;
}
