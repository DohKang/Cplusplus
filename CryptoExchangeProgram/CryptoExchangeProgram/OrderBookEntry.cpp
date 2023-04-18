#include "OrderBookEntry.h"

OrderBookEntry::OrderBookEntry(double _Price,
    double _Amount,
    std::string _Timestamp,
    std::string _Product,
    OrderBookType _OrderType,
    std::string _username)
    : Price(_Price),
    Amount(_Amount),
    Timestamp(_Timestamp),
    Product(_Product),
    OrderType(_OrderType),
    username(_username)
{
}

OrderBookType OrderBookEntry::StringTOOrderBookType(std::string s)
{
    if (s == "ask")
    {
        return OrderBookType::ask;
    }
    if (s == "bid")
    {
        return OrderBookType::bid;
    }
    return OrderBookType::unknown;
}
