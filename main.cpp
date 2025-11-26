#include <iostream>
#include "ECommerceSystem.h"
using namespace std;

int main() {

    ECommerceSystem ecommerce = ECommerceSystem();
    while (true) {
        ecommerce.menuStart();
        int yourChoise;
        cin >> yourChoise;
        if (yourChoise == 1) {
            ecommerce.loginAsCustomer();
        } else if (yourChoise == 2) {
            ecommerce.loginAsAdmin();
        } else if (yourChoise == 3) {
            ecommerce.newRegister();
        } else if (yourChoise == 0) {
            cout << "Saving data to files...\n";
            cout << "Thank you for using E-Shop!\n";
            cout << "Have a great day!\n";
            break;
        } else {
            cout << "You Entered Not Valid number. Try to Enter new number\n\n";
        }
    }
    return 0;
}