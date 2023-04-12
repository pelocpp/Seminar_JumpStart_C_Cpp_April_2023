// ===========================================================================
// Program.cpp // Demo Implementation Inheritance (Accounts and Bank)
// ===========================================================================

#include <iostream>
#include <string>

#include "IAccount.h"
#include "Account.h"
#include "CreditAccount.h"
#include "DepositAccount.h"
#include "StudentsAccount.h"


void test_01_accounts () {

    using namespace AccountsAndBank;

    std::cout << "Testing accounts:" << std::endl;

    AccountsAndBank::CreditAccount ca(123456, 1000);
    ca.deposit(100);
    ca.withdraw(40);
    std::cout << ca << std::endl;

    StudentsAccount sa(343434);
    sa.deposit(50);
    sa.withdraw(25);
    std::cout << sa << std::endl;

    DepositAccount da(654321, 4.0);
    da.deposit(200);
    da.withdraw(120);
    da.computeInterest(31);
    std::cout << da << std::endl;
}

void test_02_accounts() {

    using namespace AccountsAndBank;

    std::cout << "Testing accounts:" << std::endl;

    CreditAccount ca(123456, 1000);
    ca.deposit(100);

    StudentsAccount sa(343434);
    sa.deposit(50);

    DepositAccount da(654321, 4.0);
    da.deposit(200);

    IAccount* accounts[3] = { &ca, &sa, &da };

    double totalBalance = 0;

    // polymorphism
    for (int i = 0; i < 3; ++i) {
        totalBalance = totalBalance + accounts[i]->getBalance();
    }

    std::cout << "TotalBalance: " << totalBalance << std::endl;
}

int main_accounts() 
{

    test_01_accounts();
    test_02_accounts();
    return 0;
}

// ===========================================================================
// End-of-File
// ===========================================================================
