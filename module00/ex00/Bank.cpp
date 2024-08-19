#include "Bank.hpp"
#include <exception>

void Bank::createAccount(const int& id, const int& value)
{
    if (clientAccounts[id])
        throw std::logic_error("Error: This id has already taken!");
    Account tmp(id, value);
    clientAccounts[id] = &tmp;
}

void Bank::deleteAccount(const int& id)
{
    if (!clientAccounts[id])
        throw std::logic_error("Error: id cannot found");
    clientAccounts.erase(id);
}

void Bank::setAccountAttributes(const int& id,  const int& value)
{
    if (!clientAccounts[id])
        throw std::logic_error("Error: id cannot found");
    clientAccounts[id]->value = value;
}

void Bank::deposit(const int& id, int amount)
{
    if (!clientAccounts[id])
        throw std::logic_error("Error: id cannot found");
    int bankShare = static_cast<int>(0.05 * amount);
    this->liquidity += bankShare;
    amount -= bankShare;
    clientAccounts[id]->deposit(amount);
}

void Bank::withdrawl(const int& id, const size_t& amount) 
{

}

int Bank::getLiquidity() const
{
    return liquidity;
}

int Bank::getClientBalance(const int& id) const
{
    if (clientAccounts.find(id) == clientAccounts.end())
        throw std::logic_error("Error: id cannot found");
    return (clientAccounts[id]->value);
}
