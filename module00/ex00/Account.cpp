#include "Account.hpp"

Account::Account(const int& id, const int& value) : id(id), value(value) {}

void Account::deposit(int& amount)
{
    this->value += amount;
}

