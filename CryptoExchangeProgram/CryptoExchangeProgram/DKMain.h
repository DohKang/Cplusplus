#pragma once

#include <vector>
#include "OrderBookEntry.h"
#include "OrderBook.h"
#include "Wallet.h"


class DKMain
{
private:
    /* data */
public:
    DKMain(/* args */);
    ~DKMain();

public:
    //Call this to start the sim
    void Init();
private:
    void PrintMenu();
    void PrintHelp();
    void PrintMarketStats();
    void EnterAsk();
    void EnterBid();
    void PrintWallet();
    void GotoNextTimeFrame();
    void ExitTheApplication();
    void InvalidOption();
    int GetUserOption();
    void processUserOption(int UserOption);

    std::string currentTime;

    OrderBook orderbook{"20200317.csv"};

    Wallet wallet;
};