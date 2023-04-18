#pragma once
#include <string>
#include <map>
#include "OrderBookEntry.h"

class Wallet
{
public:
	Wallet();
	/** Insert currency to the wallet	*/
	void insertCurrency(std::string type, double amount);
	/** Remove currency to the wallet	*/
	bool removeCurrency(std::string type, double amount);
	/** check if the wallet contains this much currency or more	*/
	bool constainsCurrency(std::string type, double amount);
	/** Generate a string representation of the wallet*/
	std::string toString();
	/** check if the wallet can cope with this ask or bid*/
	bool canFullfillOrder(OrderBookEntry order);

	/** Update the contents of the wallet
	* assumes the order was made by the owner of the wallet 
	*/
	void processSale(OrderBookEntry& sale);

private:
	std::map<std::string, double> currencies;
};

