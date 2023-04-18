//#include <iostream>
//#include <string>
//#include <vector>
#include "OrderBookEntry.h"
#include "DKMain.h"
#include "CSVReader.h"
#include "Wallet.h"

int main()
{
    //CSVReader::ReadCSV("20200317.csv");
    DKMain App{};
    App.Init();
    //Wallet wallet;
    //wallet.insertCurrency("BTC", 5);
    //wallet.insertCurrency("USD", 100);
    //
    //std::cout << wallet.toString() << std::endl;
    //wallet.removeCurrency("USD", 10);
    //wallet.removeCurrency("BTC", 10);
    //std::cout << wallet.toString() << std::endl;

}



//#include "wallet.h"
//#include <iostream>
//
//int main()
//{
//	Wallet wallet{};
//	std::cout << "Inserting 50 BTC" << std::endl;
//	wallet.insertCurrency("BTC", 50);
//	std::cout << "Wallet contents " << wallet.toString() << std::endl;
//	std::cout << "Removing 5 BTC" << std::endl;
//	std::cout << "Contain BTC 5?" << std::endl;
//	wallet.constainsCurrency("BTC", 5);
//	wallet.removeCurrency("BTC", 5);
//	std::cout << "Wallet contents " << wallet.toString() << std::endl;
//	Wallet wallet1{};
//	std::cout << "Inserting 10 ETH" << std::endl;
//	wallet1.insertCurrency("ETH", 10);
//	std::cout << "Wallet contents " << wallet1.toString() << std::endl;
//	std::cout << "removing 1 ETH" << std::endl;
//	wallet1.removeCurrency("ETH", 1);
//	std::cout << "Wallet contents " << wallet1.toString() << std::endl;
//	std::cout << "Contain BTC 12?" << std::endl;
//	wallet1.constainsCurrency("BTC", 12); //return false
//	Wallet wallet2{};
//	std::cout << "Inserting 1000 USD" << std::endl;
//	wallet2.insertCurrency("USD", 1000);
//	std::cout << "Wallet contents " << wallet2.toString() << std::endl;
//	//std::cout << "removing 100 USD" << std::endl;
//	//wallet2.removeCurrency("USD", -100);
//	//std::cout << "Wallet contents " << wallet2.toString() << std::endl;
//
//
//}
