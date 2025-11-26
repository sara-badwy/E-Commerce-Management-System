#ifndef ORDER_H
#define ORDER_H
#include <unordered_map>
#include <string>
#include "Product.h"

class Order {
    std::unordered_map<std::string, Product*> items;
    std::string orderId;
    double total;
public:
    Order(std::unordered_map<std::string, Product*> _items, double _total);
    std::string getId() const;
    double getTotal() const;
    void printOrder() const;
};

#endif