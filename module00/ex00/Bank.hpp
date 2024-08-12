#pragma once

#include <map>
#include <iostream>
#include "Account.hpp"

class Bank
{
public:
	Bank(): liquidity(0) {}
    void createAccount(const int& id, const int& value);


private:
    int liquidity;
	std::map<int, Account *> clientAccounts;
};
