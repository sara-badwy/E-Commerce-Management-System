#ifndef ECOMMERCESYSTEM_H
#define ECOMMERCESYSTEM_H
#include <iostream>
#include <unordered_map>
#include <string>

class Admin;
class Customer;
class Product;

enum class UserType {
    Customer,
    Admin
};

class ECommerceSystem {
    std::unordered_map<std::string, Admin*> allAdmins;
    std::unordered_map<std::string, Customer*> allCustomers;
    std::unordered_map<std::string, Product*> allProducts;

public:
    ECommerceSystem();
    ~ECommerceSystem();

    static void printLine();
    void browseProducts() const;
    static void menuStart();

    std::pair<std::string, bool> Login(UserType type);
    void loginAsCustomer();
    void loginAsAdmin();
    void searchProduct() const;

    std::pair<std::string, std::string> newAccount(UserType type) const;
    void newRegister();

    std::pair<bool, Product*> IsExistProduct(const std::string &name);
    void addProduct(Product* _prod);
    void deleteProduct(const std::string &name);
};

#endif