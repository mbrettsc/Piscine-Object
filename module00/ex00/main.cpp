#include "Bank.hpp"

int main()
{
    Bank a;
    try {
        a.createAccount(1, 0);
        a.createAccount(1, 10); 
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
