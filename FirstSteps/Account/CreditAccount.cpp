// ===========================================================================
// CreditAccount.cpp // Demo Implementation Inheritance (Accounts and Bank)
// ===========================================================================

#include <iostream>

#include "CreditAccount.h"

namespace AccountsAndBank {

    CreditAccount::CreditAccount(int accountNumber)
        : CreditAccount(accountNumber, 1000.0) {}

    CreditAccount::CreditAccount(int account, double limit)
        : Account(account), m_limit(limit) {}

    bool CreditAccount::withdraw(double amount) {
        if (m_balance + m_limit < amount)
            return false;

        m_balance -= amount;
        return true;
    }

    double CreditAccount::getLimit() {
        return m_limit;
    }

    void CreditAccount::setLimit(double limit) {
        m_limit = limit;
    }

    void CreditAccount::print(std::ostream& os) {
        os << *this;
    }

    std::ostream& operator<< (std::ostream& os, const CreditAccount& ca) {
        os << "CurrentAccount [Nr. " << ca.m_accountNumber << "]:" << std::endl;
        os << "   Balance=" << ca.m_balance << ";" << std::endl;
        os << "   Limit=" << ca.m_limit << "." << std::endl;
        return os;
    }
}

// ===========================================================================
// End-of-File
// ===========================================================================
