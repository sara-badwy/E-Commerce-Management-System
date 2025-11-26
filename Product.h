#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <string>

class Product {
    std::string Name, categoryType, id;
    int quantity;
    double price;
public:
    Product(const std::string &name, const std::string &Category, const int &qnt, const double &price);

    void setName(const std::string &n);
    void setCategoryType(const std::string &s);
    void setQuantity(const int &quan);
    void setPrice(const double &price);

    std::string getName() const;
    std::string getCategoryType() const;
    std::string getId() const;
    int getQuantity() const;
    double getPrice() const;
    void Details() const;
};

#endif