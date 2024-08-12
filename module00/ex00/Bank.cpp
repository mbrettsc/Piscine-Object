#include "Bank.hpp"
#include <exception>


void Bank::createAccount(const int& id, const int& value)
{
    if (clientAccounts[id])
        throw std::logic_error("Error: This id has already taken!");
    Account tmp(id, value);
    clientAccounts[id] = &tmp;
}
