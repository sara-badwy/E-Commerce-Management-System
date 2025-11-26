#include "Product.h"
#include "Utility.h"

Product::Product(const std::string &name, const std::string &category, const int &qnt, const double &price):
    Name(name), categoryType(category), quantity(qnt), price(price) {
    id = Utility::IDGenerator();
}

void Product::setName(const std::string &n) {
    Name = n;
}

void Product::setQuantity(const int &quan) {
    quantity = quan;
}

void Product::setCategoryType(const std::string &s) {
    categoryType = s;
}

void Product::setPrice(const double &Price) {
    this->price = Price;
}

std::string Product::getName() const {
    return Name;
}

std::string Product::getId() const {
    return id;
}

int Product::getQuantity() const {
    return quantity;
}

std::string Product::getCategoryType() const {
    return categoryType;
}

double Product::getPrice() const {
    return price;
}

void Product::Details() const {
    std::cout << "Name: " << Name << "\n";
    std::cout << "Category: " << categoryType << "\n";
    std::cout << "Price: $" << price << "\n";
    std::cout << "Quantity: " << quantity << "\n";
    std::cout << "ID: " << id << "\n";
    std::cout << "-------------------------------------------------\n\n";
}