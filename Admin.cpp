#include "Admin.h"
#include "ECommerceSystem.h"
#include "Product.h"
using namespace std;

Admin::Admin(const std::string &_username, const std::string &_password):
    User(_username, _password) {}

void Admin::searchProduct(ECommerceSystem* ecommerce) {
    ecommerce->searchProduct();
}

void Admin::addProduct(ECommerceSystem* ecommerce) {
    string name, category;
    double price;
    int quantity;

    cout << "Enter product name: ";
    cin >> name;
    cout << "Enter category: ";
    cin >> category;
    cout << "Enter price: $";
    cin >> price;
    cout << "Enter quantity: ";
    cin >> quantity;

    auto [isExist, _p] = ecommerce->IsExistProduct(name);
    if (isExist) {
        cout << "Product already exists!\n\n";
        return;
    }

    if (price <= 0 || quantity < 0) {
        cout << "Invalid price or quantity!\n\n";
        return;
    }

    Product* newProduct = new Product(name, category, quantity, price);
    ecommerce->addProduct(newProduct);
    cout << "Product added successfully!\n\n";
}

void Admin::deleteProduct(ECommerceSystem* ecommerce) {
    cout << "Enter product name to delete: ";
    string name;
    cin >> name;

    auto [isExist, _p] = ecommerce->IsExistProduct(name);
    if (isExist) {
        ecommerce->deleteProduct(name);
        cout << "Product deleted successfully!\n\n";
    } else {
        cout << "Product not found!\n\n";
    }
}

void Admin::editProductPrice(ECommerceSystem* ecommerce) {
    cout << "Enter product name: ";
    string name;
    cin >> name;

    auto [isExist, product] = ecommerce->IsExistProduct(name);
    if (isExist) {
        cout << "Current price: $" << product->getPrice() << "\n";
        cout << "Enter new price: $";
        double newPrice;
        cin >> newPrice;

        if (newPrice > 0) {
            product->setPrice(newPrice);
            cout << "Price updated successfully!\n\n";
        } else {
            cout << "Invalid price!\n\n";
        }
    } else {
        cout << "Product not found!\n\n";
    }
}

void Admin::editProductQuantity(ECommerceSystem* ecommerce) {
    cout << "Enter product name: ";
    string name;
    cin >> name;

    auto [isExist, product] = ecommerce->IsExistProduct(name);
    if (isExist) {
        cout << "Current quantity: " << product->getQuantity() << "\n";
        cout << "Enter new quantity: ";
        int newQuantity;
        cin >> newQuantity;

        if (newQuantity >= 0) {
            product->setQuantity(newQuantity);
            cout << "Quantity updated successfully!\n\n";
        } else {
            cout << "Invalid quantity!\n\n";
        }
    } else {
        cout << "Product not found!\n\n";
    }
}