#include "Customer.h"
#include "ECommerceSystem.h"
#include <iostream>
#include <iomanip>
using namespace std;

Customer::Customer(const std::string &_username, const std::string &_password):
    User(_username, _password) {}

Customer::~Customer() {
    for (auto &[id, order] : _Orders) {
        delete order;
    }
    _Orders.clear();
    cart.clear();
}

void Customer::addToCart(ECommerceSystem* ecommerce) {
    cout << "Enter Product Name: ";
    string name;
    cin >> name;

    auto [isExist, _prod] = ecommerce->IsExistProduct(name);
    if (isExist && _prod->getQuantity() > 0) {
        auto cartIt = cart.find(name);
        if (cartIt != cart.end()) {
            cout << "Product is already in your cart.\n\n";
        } else {
            cart.insert({name, _prod});
            cout << "Product added to cart successfully!\n\n";
        }
    } else if (isExist && _prod->getQuantity() <= 0) {
        cout << "Sorry, this product is out of stock.\n\n";
    } else {
        cout << "Product doesn't exist.\n\n";
    }
}

void Customer::removeFromCart() {
    if (cart.empty()) {
        cout << "Your cart is already empty.\n\n";
        return;
    }

    cout << "Enter Product Name to remove: ";
    string prod;
    cin >> prod;

    auto it = cart.find(prod);
    if (it != cart.end()) {
        cart.erase(it);
        cout << "Product removed from cart successfully!\n\n";
    } else {
        cout << "Product not found in your cart.\n\n";
    }
}

void Customer::viewCart() const {
    if (cart.empty()) {
        cout << "Your shopping cart is empty.\n\n";
        return;
    }

    cout << "=========== Shopping Cart ===========\n";
    cout << left << setw(20) << "Name"
         << setw(20) << "Category"
         << setw(15) << "Price"
         << setw(10) << "Qty" << "\n";
    cout << "------------------------------------------------------------\n";

    double total = 0.0;
    for (auto &[name, _prod] : cart) {
        cout << left << setw(20) << name
             << setw(20) << _prod->getCategoryType()
             << setw(15) << "$" + to_string(_prod->getPrice())
             << setw(10) << _prod->getQuantity() << "\n";
        total += _prod->getPrice();
    }
    cout << "------------------------------------------------------------\n";
    cout << "Total: $" << total << "\n\n";
}

void Customer::checkout() {
    cout << "=========== Checkout ===========\n";
    if (cart.empty()) {
        cout << "Your cart is empty. Please add items before checkout.\n\n";
        return;
    }

    double total = 0.0;
    cout << left << setw(20) << "Product Name"
         << setw(15) << "Price" << "\n";
    cout << "------------------------------------\n";

    for (auto &[name, product] : cart) {
        cout << left << setw(20) << name
             << setw(15) << "$" + to_string(product->getPrice()) << "\n";
        total += product->getPrice();
    }
    cout << "------------------------------------\n";
    cout << "Total Amount: $" << total << "\n\n";

    // Create and store order
    Order* newOrder = new Order(cart, total);
    _Orders[newOrder->getId()] = newOrder;

    cout << "Order placed successfully!\n";
    cout << "Your Order ID: " << newOrder->getId() << "\n\n";

    // Clear cart
    cart.clear();

    cout << "Thank you for shopping with us!\n\n";
}

void Customer::viewOrders() const {
    if (_Orders.empty()) {
        cout << "You have no orders yet.\n\n";
        return;
    }

    cout << "=========== Your Orders ===========\n";
    for (auto &[orderId, order] : _Orders) {
        order->printOrder();
    }
}