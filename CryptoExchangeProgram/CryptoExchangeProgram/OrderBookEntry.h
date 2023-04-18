#pragma once
#include <string>

enum class OrderBookType { bid, ask, unknown, asksale, bidsale };

class OrderBookEntry
{
public:
    OrderBookEntry(double _Price,
        double _Amount,
        std::string _Timestamp,
        std::string _Product,
        OrderBookType _OrderType,
        std::string username = "dataset");

public:
    static OrderBookType StringTOOrderBookType(std::string s);
    static bool compareByTimestamp(OrderBookEntry& e1, OrderBookEntry& e2)
    {
        return e1.Timestamp < e2.Timestamp;
    }
    static bool compareByPriceAsc(OrderBookEntry& e1, OrderBookEntry& e2)
    {
        return e1.Price < e2.Price;
    }
    static bool compareByPriceDesc(OrderBookEntry& e1, OrderBookEntry& e2)
    {
        return e1.Price > e2.Price;
    }
    double Price;
    double Amount;
    std::string Timestamp;
    std::string Product;
    OrderBookType OrderType;

    std::string username;
};