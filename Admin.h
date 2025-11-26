#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include "User.h"

class ECommerceSystem;

class Admin: public User {
public:
    Admin(const std::string &_username, const std::string &_password);

    void searchProduct(ECommerceSystem* ecommerce);
    void addProduct(ECommerceSystem* ecommerce);
    void deleteProduct(ECommerceSystem* ecommerce);
    void editProductPrice(ECommerceSystem* ecommerce);
    void editProductQuantity(ECommerceSystem* ecommerce);
};

#endif