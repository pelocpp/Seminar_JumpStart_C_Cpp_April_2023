// ===============================================================================
// CreditAccount.cpp // Demo Implementation Inheritance (Accounts and Bank)
// ===============================================================================

#pragma once

#include <iostream>

#include "Account.h"

namespace AccountsAndBank {

    class CreditAccount final : public Account
    {
        friend std::ostream& operator<< (std::ostream&, const CreditAccount&);

    private:
        double m_limit;

    public:
        // c'tors
        CreditAccount(int account);
        CreditAccount(int account, double limit);
        virtual ~CreditAccount() {};

        // getter / setter
        double getLimit();
        void setLimit(double limit);

        // public interface
        bool withdraw(double amount) override;

        void print(std::ostream& os) override;
    };
}

// ===============================================================================
// End-of-File
// ===============================================================================
