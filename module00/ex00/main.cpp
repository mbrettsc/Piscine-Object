#include "Bank.hpp"

int main()
{
    Bank a;
    try {
        a.createAccount(1, 0);
        a.createAccount(1, 5);
        a.deposit(1, 20);
        a.deposit(1, 50);
        a.deposit(1, 40);
        
        
       
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
