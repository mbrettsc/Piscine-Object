#include "Bank.hpp"
#include <exception>

void Bank::createAccount(const size_t& id, const size_t& value)
{
    try {
        Account *ac = (*this)[id];
    } catch (std::exception & e) {
        clientAccounts[id] = new Account(id, value);
        return;
    }
    throw std::runtime_error("Account with this id already exist.");
}

void Bank::deleteAccount(const size_t& id)
{
    Account *ac = (*this)[id];
    delete ac;
    clientAccounts.erase(id);
}

void Bank::setAccountAttributes(const size_t& id,  const size_t& value)
{
    Account *ac = (*this)[id];
    ac->value = value;
}

void Bank::deposit(const size_t& id, size_t amount)
{
    Account *ac = (*this)[id];
    size_t bankShare = static_cast<size_t>(0.05 * amount);
    this->liquidity += bankShare;
    ac->value += amount - bankShare;
}

void Bank::withdraw(const size_t& id, const size_t& amount) 
{
    Account *ac = (*this)[id]; 
    if (ac->value > amount)
    {
        throw std::runtime_error("You don't have enough money to withdraw that amount.");
    }
    ac->value -= amount;
}

void Bank::giveLoan(const size_t& id, const size_t& amount)
{
    Account *ac = (*this)[id];
    if (amount > liquidity)
    {
        throw std::runtime_error("Bank don't have that much money!");
    }
    ac->value += amount;
}

size_t Bank::getClientBalance(const size_t& id) const
{
    cBankIt it = clientAccounts.begin();
    if (it == clientAccounts.end())
    {
        throw std::runtime_error("Account with this ID cannot found.");
    }
    return it->second->getValue();
}

Bank::Account* Bank::operator[](const size_t& id)
{
    bankIt it = clientAccounts.find(id);
    if (it == clientAccounts.end())
    {
        throw std::runtime_error("Account with this ID cannot found.");
    }
    return it->second;
}

size_t Bank::getLiquidity() const
{
    return liquidity;
}
