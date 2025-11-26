#include "ECommerceSystem.h"
#include "Admin.h"
#include "Customer.h"
#include "Product.h"
#include <iomanip>
using namespace std;

ECommerceSystem::ECommerceSystem() {
    // Add some default products
    Product* p1 = new Product("Laptop", "Electronics", 10, 999.99);
    Product* p2 = new Product("Smartphone", "Electronics", 25, 699.99);
    Product* p3 = new Product("Book", "Education", 100, 29.99);
    Product* p4 = new Product("Headphones", "Electronics", 15, 149.99);

    allProducts[p1->getName()] = p1;
    allProducts[p2->getName()] = p2;
    allProducts[p3->getName()] = p3;
    allProducts[p4->getName()] = p4;

    // Add default admin
    Admin* admin = new Admin("admin", "admin123");
    allAdmins[admin->getUserName()] = admin;

    cout << "=====================================\n";
    cout << "       Welcome to E-Shop\n";
    cout << "=====================================\n\n";
}

ECommerceSystem::~ECommerceSystem() {
    for (auto &[name, product] : allProducts) delete product;
    for (auto &[name, admin] : allAdmins) delete admin;
    for (auto &[name, customer] : allCustomers) delete customer;

    allProducts.clear();
    allAdmins.clear();
    allCustomers.clear();
}

void ECommerceSystem::printLine() {
    cout << "------------------------------------------------------------\n";
}

void ECommerceSystem::browseProducts() const {
    if (allProducts.empty()) {
        cout << "No products available at the moment.\n\n";
        return;
    }

    cout << "=========== Available Products ===========\n";
    cout << left << setw(20) << "Name"
         << setw(20) << "Category"
         << setw(15) << "Price"
         << setw(10) << "Qty" << "\n";
    printLine();

    for (const auto& [name, product] : allProducts) {
        cout << left << setw(20) << name
             << setw(20) << product->getCategoryType()
             << setw(15) << "$" + to_string(product->getPrice())
             << setw(10) << product->getQuantity() << "\n";
    }
    printLine();
    cout << "\n";
}

void ECommerceSystem::menuStart() {
    cout << "1. Login as Customer\n";
    cout << "2. Login as Admin\n";
    cout << "3. Register New Account\n";
    cout << "0. Exit\n";
    printLine();
    cout << "Enter your choice: ";
}

pair<string, bool> ECommerceSystem::Login(UserType type) {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (type == UserType::Customer) {
        auto it = allCustomers.find(username);
        if (it == allCustomers.end() || it->second->getPassword() != password) {
            cout << "Invalid username or password!\n\n";
            return {"", false};
        }
    } else {
        auto it = allAdmins.find(username);
        if (it == allAdmins.end() || it->second->getPassword() != password) {
            cout << "Invalid username or password!\n\n";
            return {"", false};
        }
    }

    cout << "Welcome, " << username << "!\n\n";
    return {username, true};
}

void customerMenu() {
    cout << "====== Customer Menu ======\n";
    cout << "1. Browse Products\n";
    cout << "2. Search Product\n";
    cout << "3. Add to Cart\n";
    cout << "4. Remove from Cart\n";
    cout << "5. View Cart\n";
    cout << "6. Checkout\n";
    cout << "7. View My Orders\n";
    cout << "0. Logout\n";
    cout << "---------------------------\n";
    cout << "Enter your choice: ";
}

void adminMenu() {
    cout << "====== Admin Menu ======\n";
    cout << "1. Search Product\n";
    cout << "2. Add Product\n";
    cout << "3. Delete Product\n";
    cout << "4. Edit Product Price\n";
    cout << "5. Edit Product Quantity\n";
    cout << "0. Logout\n";
    cout << "---------------------------\n";
    cout << "Enter your choice: ";
}

void ECommerceSystem::loginAsCustomer() {
    auto [username, success] = Login(UserType::Customer);
    if (!success) return;

    Customer* customer = allCustomers[username];
    int choice;

    do {
        customerMenu();
        cin >> choice;

        switch (choice) {
            case 1: browseProducts(); break;
            case 2: searchProduct(); break;
            case 3: customer->addToCart(this); break;
            case 4: customer->removeFromCart(); break;
            case 5: customer->viewCart(); break;
            case 6: customer->checkout(); break;
            case 7: customer->viewOrders(); break;
            case 0: cout << "Logging out...\n\n"; break;
            default: cout << "Invalid choice!\n\n";
        }
    } while (choice != 0);
}

void ECommerceSystem::loginAsAdmin() {
    auto [username, success] = Login(UserType::Admin);
    if (!success) return;

    Admin* admin = allAdmins[username];
    int choice;

    do {
        adminMenu();
        cin >> choice;

        switch (choice) {
            case 1: admin->searchProduct(this); break;
            case 2: admin->addProduct(this); break;
            case 3: admin->deleteProduct(this); break;
            case 4: admin->editProductPrice(this); break;
            case 5: admin->editProductQuantity(this); break;
            case 0: cout << "Logging out...\n\n"; break;
            default: cout << "Invalid choice!\n\n";
        }
    } while (choice != 0);
}

void ECommerceSystem::searchProduct() const {
    cout << "Enter product name to search: ";
    string name;
    cin >> name;

    auto it = allProducts.find(name);
    if (it != allProducts.end()) {
        cout << "Product found:\n";
        it->second->Details();
    } else {
        cout << "Product not found!\n\n";
    }
}

pair<string, string> ECommerceSystem::newAccount(UserType type) const {
    string username, password, confirmPassword;

    cout << "Enter username: ";
    cin >> username;

    // Check if username exists
    if ((type == UserType::Customer && allCustomers.count(username)) ||
        (type == UserType::Admin && allAdmins.count(username))) {
        cout << "Username already exists!\n";
        return {"", ""};
    }

    do {
        cout << "Enter password (min 6 characters): ";
        cin >> password;
        cout << "Confirm password: ";
        cin >> confirmPassword;

        if (password != confirmPassword) {
            cout << "Passwords don't match! Try again.\n";
        } else if (password.length() < 6) {
            cout << "Password must be at least 6 characters! Try again.\n";
        }
    } while (password != confirmPassword || password.length() < 6);

    return {username, password};
}

void ECommerceSystem::newRegister() {
    int choice;
    cout << "1. Register as Customer\n";
    cout << "2. Register as Admin\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice != 1 && choice != 2) {
        cout << "Invalid choice!\n\n";
        return;
    }

    UserType type = (choice == 1) ? UserType::Customer : UserType::Admin;
    auto [username, password] = newAccount(type);

    if (username.empty()) {
        return;
    }

    if (type == UserType::Customer) {
        Customer* newCustomer = new Customer(username, password);
        allCustomers[username] = newCustomer;
        cout << "Customer account created successfully! \n";
    } else {
        Admin* newAdmin = new Admin(username, password);
        allAdmins[username] = newAdmin;
        cout << "Admin account created successfully! \n";
    }
}

pair<bool, Product*> ECommerceSystem::IsExistProduct(const std::string &name) {
    auto it = allProducts.find(name);
    if (it != allProducts.end()) {
        return {true, it->second};
    }
    return {false, nullptr};
}

void ECommerceSystem::addProduct(Product* _prod) {
    allProducts[_prod->getName()] = _prod;
}

void ECommerceSystem::deleteProduct(const std::string &name) {
    auto it = allProducts.find(name);
    if (it != allProducts.end()) {
        delete it->second;
        allProducts.erase(it);
    }
}