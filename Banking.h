#include <iostream>
#include <string.h>

#ifndef BANKING_H
#define BANKING_H

using namespace std;
//Class Account Forward Declaration
class Account;
//Class Accounts Definition to store all accounts information

//Class Account Definition to store information of single account;
class Account{
private:
    unsigned int accountNumber;
    string name;
    unsigned int balance;
    char typeOfAccount;
public:
    Account(): accountNumber(0),balance(0),typeOfAccount('s'){
    };
    unsigned int getAccountNumber();
    string getName();
    unsigned int getBalance();
    void setBalance(unsigned int,string);
    char getTypeOfAccount();
    void createNewAccount();
    void depositMoneyToAccount(unsigned int);
    void WithdrawMoneyFromAccount(unsigned int);
    void editAccountInformation(unsigned int);
}static sharedInstanceOfAccount;

class Accounts{
public:

    unsigned int AccountNumbers[10];
    Account AllAccounts[10];

}sharedInstanceOfAllAccounts;

#endif // BANKING_H
