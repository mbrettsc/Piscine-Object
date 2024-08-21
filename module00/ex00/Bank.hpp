#pragma once

#include <map>
#include <iostream>


class Bank
{
public:
    Bank()
        : liquidity(0) {}
    Bank(size_t l)
        : liquidity(l) {}

    void createAccount(const size_t& id, const size_t& value);
    void deleteAccount(const size_t& id);
    void setAccountAttributes(const size_t& id, const size_t& value);
    void deposit(const size_t& id, size_t amount);
    void withdraw(const size_t& id, const size_t& amount);
    void giveLoan(const size_t& id, const size_t& amount);
    void setLiquidity(size_t liquidity);

    size_t getLiquidity() const;
    size_t getClientBalance(const size_t& id) const;

private:
    class Account
    {
    public:
        Account(const size_t& id, const size_t& value)
            : id(id), value(value) {}

        size_t getId() const { return id; }
        size_t getValue() const { return value; }

    private:
        Account();
        size_t id;
        size_t value;

        friend class Bank;
    };

    typedef std::map<size_t, Account*>::iterator bankIt;
    typedef std::map<size_t, Account*>::const_iterator cBankIt;

    std::map<size_t, Account *> clientAccounts;
    size_t liquidity;

    Account* operator[](const size_t& id);
};
