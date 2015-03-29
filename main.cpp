#include <iostream>
#include <sstream>
#include <string.h>

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
    char getTypeOfAccount();
    void createNewAccount();
    void depositMoneyToAccount(unsigned int,unsigned int);
    void WithdrawMoneyFromAccount(unsigned int,unsigned int);
    void editAccountInformation(unsigned int);
};

class Accounts{
public:

    int AccountNumbers[10];
    Account AllAccounts[10];

}sharedInstanceOfAllAccounts;

unsigned int Account::getAccountNumber(){
    return accountNumber;
}
string Account::getName(){
        return name;
}
unsigned int Account::getBalance(){
    return balance;
}
char Account::getTypeOfAccount(){
    return typeOfAccount;
}
void Account::createNewAccount(){

    Account account;
    static int accountNum = 1;
    account.accountNumber = accountNum;
    cout<<"Enter Name of Account Holder:";
    cin>>account.name;
    cout<<"Enter Money You Want To Deposit In Account($500 to $10000):";
    cin>>account.balance;
    cout<<"Enter Type Of Account (s/c):";
    cin>>account.typeOfAccount;
    cout<<"New Account Has Successfully Been Created"<<endl<<endl;
    sharedInstanceOfAllAccounts.AccountNumbers[accountNum-1] = accountNum;
    sharedInstanceOfAllAccounts.AllAccounts[accountNum-1] = account;
    accountNum++;
}

void Account::depositMoneyToAccount(unsigned int,unsigned int){

}

int  main(){
    static Account sharedInstanceOfAccount;
    int i = 0;
    int option;
    unsigned int verifyAccountNumber;
    string verifyName;
    do{


        cout<<"1. Main Screen"<<endl<<endl;
        cout<<"2. New Account"<<endl;
        cout<<"3. Deposit Amount"<<endl;
        cout<<"4. Withdraw Amount"<<endl;
        cout<<"5. Balance Enquiry"<<endl;
        cout<<"6. All Account Holder List"<<endl;
        cout<<"7. Close An Account"<<endl;
        cout<<"8. Modify An Account"<<endl;
        cout<<"9. Exit"<<endl<<endl;
        cout<<"Enter Your Option:";
        cin>>option;

        switch(option){
            case 1:

                continue;
            case 2:
                sharedInstanceOfAccount.createNewAccount();

                break;
            case 3:
                cout<<"Enter Your Account Number:";
                cin>>verifyAccountNumber;
                cout<<endl;
                cout<<"Verify Your Name:";
                cin>>verifyName;
                cout<<endl;


                break;
            case 4:

                break;
            case 5:

                break;
            case 6:
                cout<<"------------------------------------------------------------------"<<endl;

                for(i=0;sharedInstanceOfAllAccounts.AccountNumbers[i] > 0;i++){
                    sharedInstanceOfAccount = sharedInstanceOfAllAccounts.AllAccounts[i];
                    cout<<"Account Number: "<<sharedInstanceOfAccount.getAccountNumber()<<endl;
                    cout<<"Account Holder Name: "<<sharedInstanceOfAccount.getName()<<endl;
                    cout<<"Account Balance: "<<sharedInstanceOfAccount.getBalance()<<endl;
                    cout<<"Type Of Account: "<<sharedInstanceOfAccount.getTypeOfAccount()<<endl;
                }
                cout<<"------------------------------------------------------------------"<<endl;
                break;
            case 7:

                break;
            case 8:

                break;
            case 9:

            default:
                cout<<"Select An Valid Option!!"<<endl;
        };
    }while(option != 9);
    return 0;

}
