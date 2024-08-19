#pragma once

#include <map>
#include <iostream>
#include "Account.hpp"

class Bank
{
public:
	Bank(): liquidity(0) {}
    void createAccount(const int& id, const int& value);
    void deleteAccount(const int& id);
    void setAccountAttributes(const int& id, const int& value);
    void deposit(const int& id, int amount);
    void withdrawl(const int& id, const size_t& amount);

    int getLiquidity() const;
    int getClientBalance(const int& id) const;

private:
    int liquidity;
	std::map<int, Account *> clientAccounts;
};
