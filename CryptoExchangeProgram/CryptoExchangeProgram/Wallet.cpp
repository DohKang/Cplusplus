#include "Wallet.h"
#include "CSVReader.h"
#include <vector>
#include <string>
#include <iostream>

Wallet::Wallet()
{
}

void Wallet::insertCurrency(std::string type, double amount)
{
	double balance;
	if (amount < 0)
	{
		throw std::exception{};
	}
	if (currencies.count(type) == 0) //not there yet
	{
		balance = 0;
	}
	else
	{
		balance = currencies[type];
	}
	balance += amount;
	currencies[type] = balance;

}

bool Wallet::removeCurrency(std::string type, double amount)
{
	if (amount < 0)
	{
		throw std::exception{};
		return false;
	}
	if (currencies.count(type) == 0) //not there yet
	{
		return false;
	}
	else
	{
		if (constainsCurrency(type, amount))
		{
			currencies[type] -= amount;
			return true;
		}
		else //they have it but not enough
			return false;
		
	}
	
	

}


bool Wallet::constainsCurrency(std::string type, double amount)
{
	if (currencies.count(type) == 0)
	{
		std::cout << "In the wallet, there is no" << type << "currency" << std::endl;
		return false;
		
	}
	else
	{
		return currencies[type] >= amount;
	}
}


std::string Wallet::toString()
{
	std::string s;
	for (std::pair<std::string, double> pair : currencies)
	{
		std::string currency = pair.first;
		double amount = pair.second;
		s += currency + " : " + std::to_string(amount) + "\n";
	}

	return s;
}

bool Wallet::canFullfillOrder(OrderBookEntry order)
{
	std::vector<std::string> currs = CSVReader::Tokenise(order.Product, '/');

	//ask
	if (order.OrderType == OrderBookType::ask)
	{
		double amount = order.Amount;
		std::string currency = currs[0];
		std::cout << "Wallet::canFullfillOrder" << currency << " : " << amount << std::endl;
		return constainsCurrency(currency, amount);
	}

	//bid

	if (order.OrderType == OrderBookType::bid)
	{
		double amount = order.Amount * order.Price;
		std::string currency = currs[1];
		std::cout << "Wallet::canFullfillOrder" << currency << " : " << amount << std::endl;
		return constainsCurrency(currency, amount);
	}
	return false;
}

void Wallet::processSale(OrderBookEntry& sale)
{
	std::vector<std::string> currs = CSVReader::Tokenise(sale.Product, '/');

	//ask
	if (sale.OrderType == OrderBookType::asksale)
	{
		double outgoingAmount = sale.Amount;
		std::string outgoingCurrency = currs[0];
		double incommingAmount = sale.Amount * sale.Price;
		std::string incommingCurrency = currs[1];
		currencies[incommingCurrency] += incommingAmount;
		currencies[outgoingCurrency] -= outgoingAmount;
	}

	//bid

	if (sale.OrderType == OrderBookType::bidsale)
	{
		double outgoingAmount = sale.Amount * sale.Price;
		std::string outgoingCurrency = currs[1];
		double incommingAmount = sale.Amount ;
		std::string incommingCurrency = currs[0];

		currencies[incommingCurrency] += incommingAmount;
		currencies[outgoingCurrency] -= outgoingAmount;
	}
}
