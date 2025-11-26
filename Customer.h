#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <unordered_map>
#include "User.h"
#include "Order.h"

class ECommerceSystem;

class Customer: public User {
    std::unordered_map<std::string, Order*> _Orders;
    std::unordered_map<std::string, Product*> cart;
public:
    Customer(const std::string &_username, const std::string &_password);
    ~Customer();

    void addToCart(ECommerceSystem* ecommerce);
    void removeFromCart();
    void viewCart() const;
    void checkout();
    void viewOrders() const;
};

#endif