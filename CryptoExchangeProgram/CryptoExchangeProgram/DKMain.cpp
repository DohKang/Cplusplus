#include "DKMain.h"
#include <iostream>
#include <vector>
#include "CSVReader.h"

DKMain::DKMain(/* args */)
{
}

DKMain::~DKMain()
{
}

void DKMain::Init()
{
    int input;
    currentTime = orderbook.getEarliestTime();
    wallet.insertCurrency("BTC", 10);
    while (true)
    {
        PrintMenu();
        input = GetUserOption();
        processUserOption(input);
    }
}

//void DKMain::LoadOrderBook()
//{
//    orders = CSVReader::ReadCSV("20200317.csv");
//
//    orders.push_back(OrderBookEntry{ 10000,
//                                    0.55,
//                                    "2020/03/17 17:01:24.884492",
//                                    "DOGE / BTC",
//                                    OrderBookType::bid });
//    orders.push_back(OrderBookEntry{ 20000,
//                                    0.55,
//                                    "2020/03/17 17:01:24.884492",
//                                    "DOGE / BTC",
//                                    OrderBookType::bid });
//
//    for (OrderBookEntry& order : orders)
//    {
//        std::cout << "The price is " << order.Price << std::endl;
//    }
//    for (unsigned int i = 0; i < orders.size(); ++i)
//    {
//        std::cout << "The price is " << orders[i].Price << std::endl; //directly accessing index
//    }
//    for (unsigned int i = 0; i < orders.size(); ++i)
//    {
//        std::cout << "The price is " << orders.at(i).Price << std::endl; //directly accessing index
//    }
//}

void DKMain::PrintMenu()
{
    //1 print help
    std::cout << "1 Print help" << std::endl;
    //2 print exchange stats
    std::cout << "2 print exchange stats" << std::endl;
    //3 make an offer
    std::cout << "3 make an ask" << std::endl;
    //4 make a bid
    std::cout << "4 make a bid" << std::endl;
    //5 print wallet
    std::cout << "5 print wallet" << std::endl;
    //6 continue
    std::cout << "6 continue" << std::endl;
    //7 exit
    std::cout << "7 exit" << std::endl;

    std::cout << " ============= " << std::endl;
    std::cout << "Type in 1-6 " << std::endl;

    std::cout << "Current time is " << currentTime << std::endl;
}

void DKMain::PrintHelp()
{
    std::cout << "Help - your aim is to make money. Analze the market" << std::endl;
}
void DKMain::PrintMarketStats()
{
    for (std::string const p: orderbook.GetKnownProducts())
    {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderbook.GetOrders(OrderBookType::ask, p, currentTime);

        std::cout << "Asks seen: " << entries.size() << std::endl;
        std::cout << "Max asks: " << OrderBook::getHightPrice(entries) << std::endl;
        std::cout << "Min asks: " << OrderBook::getLowestPrice(entries) << std::endl;
    }
    /*std::cout << "OrderBook Contains: " << orders.size() << " Entries" << std::endl;
    unsigned int bid{ 0 };
    unsigned int ask{ 0 };
    for (OrderBookEntry& e : orders)
    {
        if (e.OrderType == OrderBookType::ask)
        {
            ask++;
        }
        if (e.OrderType == OrderBookType::bid)
        {
            bid++;
        }
    }
    std::cout << "OrderBook asks: " << ask << "    bids: " << bid << std::endl;*/
}
void DKMain::EnterAsk()
{
    std::cout << "Make an ask  - enter the amount: product, price, amount, eg ETH/BTC,200,0.5" << std::endl;
    std::string input;
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, input);

    std::vector<std::string> tokens = CSVReader::Tokenise(input, ',');
    if (tokens.size() != 3)
    {
        std::cout << "Bad Input" << std::endl;
    }
    else
    {
        try {
            OrderBookEntry obe = CSVReader::stringsToOBE(
                tokens[1],
                tokens[2],
                currentTime,
                tokens[0],
                OrderBookType::ask
            );
            obe.username = "simuser";
        
            if (wallet.canFullfillOrder(obe))
            {
                std::cout << "Wallet Looks Good" << std::endl;
                orderbook.insertOrder(obe);
            }
            else
            {
                std::cout << "Wallet has insufficient funds" << std::endl;
            }
        
        }
        catch (const std::exception& e)
        {
            std::cout << "DKMain::EnterAsk Bad input" << std::endl;
        }
    }
    std::cout << "You typed: " << input << std::endl;
}
void DKMain::EnterBid()
{
    std::cout << "Make an bid  - enter the amount: product, price, amount, eg ETH/BTC,200,0.5" << std::endl;
    std::string input;
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, input);

    std::vector<std::string> tokens = CSVReader::Tokenise(input, ',');
    if (tokens.size() != 3)
    {
        std::cout << "DKMain::EnterBid Bad Input" << std::endl;
    }
    else
    {
        try {
            OrderBookEntry obe = CSVReader::stringsToOBE(
                tokens[1],
                tokens[2],
                currentTime,
                tokens[0],
                OrderBookType::bid);
            obe.username = "simuser";

            if (wallet.canFullfillOrder(obe))
            {
                std::cout << "Wallet Looks Good" << std::endl;
                orderbook.insertOrder(obe);
            }
            else
            {
                std::cout << "Wallet has insufficient funds" << std::endl;
            }

        }
        catch (const std::exception& e)
        {
            std::cout << "DKMain::Enterbid Bad input" << std::endl;
        }
    }
    std::cout << "You typed: " << input << std::endl;
}
void DKMain::PrintWallet()
{
    std::cout << "Your Wallet is empty" << std::endl;
    std::cout << wallet.toString() << std::endl;
}
void DKMain::GotoNextTimeFrame()
{
    std::cout << "Invalid choice. Choose 1-6" << std::endl;
    std::vector<OrderBookEntry> sales = orderbook.matchAsksToBids("ETH/BTC", currentTime);
    std::cout << "Sales: " << sales.size() << std::endl;
    for (OrderBookEntry& sale : sales)
    {
        std::cout << "Sale price: " << sale.Price << " amount: " << sale.Amount << std::endl;
        if (sale.username == "simuser")
        {
            //update the wallet
            wallet.processSale(sale);
        }
    }

    currentTime = orderbook.getNextTime(currentTime);
}
void DKMain::ExitTheApplication()
{
    std::cout << "See you later" << std::endl;
    exit(1);
}

void DKMain::InvalidOption()
{
    std::cout << "Invalid choice. Choose 1-6" << std::endl;
}
int DKMain::GetUserOption()
{
    int UserOption{0};
    std::string line;
    std::getline(std::cin, line);
    try {
        UserOption = std::stoi(line);
    }
    catch (const std::exception& e)
    {
        std::cout << "DKMain::GetUserOption, Invalid Input" << std::endl;
    }
        std::cout << "You chose: " << UserOption << std::endl;
    return UserOption;
}

void DKMain::processUserOption(int UserOption)
{
    if (UserOption == 0)
    {
        InvalidOption();
    }
    if (UserOption == 1)
    {
        PrintHelp();
    }
    if (UserOption == 2)
    {
        PrintMarketStats();
    }
    if (UserOption == 3)
    {
        EnterAsk();
    }
    if (UserOption == 4)
    {
        EnterBid();
    }
    if (UserOption == 5)
    {
        PrintWallet();
    }
    if (UserOption == 6)
    {
        GotoNextTimeFrame();
    }
    if (UserOption == 7)
    {
        ExitTheApplication();
    }
}