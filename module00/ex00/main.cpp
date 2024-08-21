#include "Bank.hpp"

int main()
{
    Bank b;
    try {
        b.createAccount(1, 0);
        b.deposit(1, 200);
        std::cout << "Your balance is: " << b.getClientBalance(1) << std::endl; 
        b.withdraw(1, 150);
        std::cout << "Your balance is: " << b.getClientBalance(1) << std::endl;
        b.withdraw(1, 150);
        std::cout << "Your balance is: " << b.getClientBalance(1) << std::endl; 
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        b.createAccount(1, 0);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        b.deleteAccount(1);
        b.deleteAccount(1);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        b.createAccount(10, 20);
        std::cout << "Your balance is: " << b.getClientBalance(10) << std::endl;
        b.giveLoan(10, 10);
        std::cout << "Your balance is: " << b.getClientBalance(10) << std::endl; 
        b.giveLoan(10, 50);

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        b.deleteAccount(10);
        Bank c(200);
        c.createAccount(10, 50);
        std::cout << "Your balance is: " << c.getClientBalance(10) << std::endl;
        c.giveLoan(10, 200);
        std::cout << "Your balance is: " << c.getClientBalance(10) << std::endl;
        c.deleteAccount(10);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
