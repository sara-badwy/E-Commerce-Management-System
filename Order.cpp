#include "Order.h"
#include <iomanip>
#include <iostream>
#include "Utility.h"
using namespace std;

Order::Order(std::unordered_map<std::string, Product*> _items, double _total)
    : items(_items), total(_total) {
    orderId = Utility::IDGenerator();
}

std::string Order::getId() const {
    return orderId;
}

double Order::getTotal() const {
    return total;
}

void Order::printOrder() const {
    cout << "Order ID: " << orderId << "\n";
    cout << left << setw(20) << "Product Name"
         << setw(15) << "Price" << "\n";
    cout << "------------------------------------\n";

    for (auto &[name, product] : items) {
        cout << left << setw(20) << name
             << setw(15) << "$" + to_string(product->getPrice()) << "\n";
    }
    cout << "------------------------------------\n";
    cout << "Total: $" << total << "\n\n";
}