#include <iostream>
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

unsigned int Account::getAccountNumber(){
    return accountNumber;
}
string Account::getName(){
        return name;
}
unsigned int Account::getBalance(){
    return balance;
}
void Account::setBalance(unsigned int money, string type){
    if(type == "deposit"){
        balance = balance + money;
    }
    else if(type == "withdraw"){
        balance = balance - money;
    }
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

void Account::depositMoneyToAccount(unsigned int accountNumber){
    unsigned int money;
    cout<<"Enter Money To Deposit:";
    cin>>money;
    sharedInstanceOfAccount = sharedInstanceOfAllAccounts.AllAccounts[accountNumber-1];
    sharedInstanceOfAccount.setBalance(money, "deposit");
    sharedInstanceOfAllAccounts.AllAccounts[accountNumber-1] = sharedInstanceOfAccount;
    cout<<"Money has been successfully Deposited to your Account"<<endl;
}

void Account::WithdrawMoneyFromAccount(unsigned int accountNumber){
    unsigned int money;
    cout<<"Enter Money To Deposit:";
    cin>>money;
    sharedInstanceOfAccount = sharedInstanceOfAllAccounts.AllAccounts[accountNumber-1];
    sharedInstanceOfAccount.setBalance(money, "withdraw");
    sharedInstanceOfAllAccounts.AllAccounts[accountNumber-1] = sharedInstanceOfAccount;
    cout<<"Money has been successfully Withdrawn From your Account"<<endl;
}
// Local Functions
bool accountNumberSeacrh(unsigned int accountNumber){
    unsigned int len = (sizeof(sharedInstanceOfAllAccounts.AccountNumbers)/sizeof(sharedInstanceOfAllAccounts.AccountNumbers[0]));
    unsigned int counter =0;
    bool flag = false;
    for(unsigned int i=0;i<len;i++){
        if(sharedInstanceOfAllAccounts.AccountNumbers[i] != 0){
            counter++;
        }
    }
    for(unsigned int i=0;i<counter;i++){
        if(sharedInstanceOfAllAccounts.AccountNumbers[i] == accountNumber){
            flag = true;
            break;
        }
        else{
            flag = false;
        }
    }

    return flag;
}
bool verifyAccountName(unsigned int AccountNumber, string name){
    sharedInstanceOfAccount = sharedInstanceOfAllAccounts.AllAccounts[AccountNumber-1];

    if(!name.compare(sharedInstanceOfAccount.getName())){
        return true;
    }
    else{
        return false;
    }
}
unsigned int verifyAccounts(){

    unsigned int verifyAccountNumber;
    string verifyName;

    cout<<"Enter Your Account Number:";
    cin>>verifyAccountNumber;
    cout<<endl;
    if(accountNumberSeacrh(verifyAccountNumber)){
        cout<<"Verify Your Name:";
        cin>>verifyName;
        cout<<endl;
        if(verifyAccountName(verifyAccountNumber,verifyName)){
            return verifyAccountNumber;
        }
        else{
            return 0;
        }

    }
    else{
        return 0;
    }

}
int  main(){
    int AccountNum;
    int i = 0;
    int option;

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
            case 1:{

                continue;
            }
            break;
            case 2:{                                                                     //Creating New Account
                sharedInstanceOfAccount.createNewAccount();
            }
                break;
            case 3:{                                                                     //Depositing Money To Account
                AccountNum = verifyAccounts();
                if(AccountNum != 0){
                    sharedInstanceOfAccount = sharedInstanceOfAllAccounts.AllAccounts[AccountNum-1];
                    sharedInstanceOfAccount.depositMoneyToAccount(AccountNum);
                }
                else{
                    cout<<"Account Not Found"<<endl;
                }

            }
                break;
            case 4:{                                                                      //Withdrawing Money From Account
                AccountNum = verifyAccounts();
                if(AccountNum != 0){
                    sharedInstanceOfAccount = sharedInstanceOfAllAccounts.AllAccounts[AccountNum-1];
                    sharedInstanceOfAccount.WithdrawMoneyFromAccount(AccountNum);
                }
                else{
                    cout<<"Account Not Found"<<endl;
                }

            }
                break;
            case 5:{
                AccountNum = verifyAccounts();
                if(AccountNum != 0){
                    sharedInstanceOfAccount = sharedInstanceOfAllAccounts.AllAccounts[AccountNum-1];
                    cout<<"Your Current Balance Is: "<<sharedInstanceOfAccount.getBalance()<<endl;
                }
                else{
                    cout<<"Account Not Found"<<endl;
                }
            }
                break;
            case 6:{
                cout<<"------------------------------------------------------------------"<<endl;

                for(i=0;sharedInstanceOfAllAccounts.AccountNumbers[i] > 0;i++){
                    sharedInstanceOfAccount = sharedInstanceOfAllAccounts.AllAccounts[i];
                    cout<<"Account Number: "<<sharedInstanceOfAccount.getAccountNumber()<<endl;
                    cout<<"Account Holder Name: "<<sharedInstanceOfAccount.getName()<<endl;
                    cout<<"Account Balance: "<<sharedInstanceOfAccount.getBalance()<<endl;
                    cout<<"Type Of Account: "<<sharedInstanceOfAccount.getTypeOfAccount()<<endl;
                }
                cout<<"------------------------------------------------------------------"<<endl;
            }
                break;
            case 7:{
                int len = (sizeof(sharedInstanceOfAllAccounts.AccountNumbers)/sizeof(sharedInstanceOfAllAccounts.AccountNumbers[0]));
                AccountNum = verifyAccounts();
                unsigned int counter =0;
                    for(unsigned int i=0; i<len; i++)
                    {
                        if(sharedInstanceOfAllAccounts.AccountNumbers[i] != 0)
                        {
                            counter++;
                        }
                    }
                if(AccountNum != 0 && ((AccountNum == 1 && counter != AccountNum) || (AccountNum != 1 && counter == AccountNum)))
                {
                    for(int i=AccountNum-1; i<counter; i++)
                    {
                        sharedInstanceOfAllAccounts.AccountNumbers[i] = sharedInstanceOfAllAccounts.AccountNumbers[i+1];
                        sharedInstanceOfAllAccounts.AllAccounts[i] = sharedInstanceOfAllAccounts.AllAccounts[i+1];
                    }
                    cout<<"Your Account Has Been Closed"<<endl;

                }
                else if((AccountNum == 1 && counter == AccountNum) || (AccountNum != 1 && counter == AccountNum)){
                    sharedInstanceOfAllAccounts.AccountNumbers[AccountNum-1] = 0;
                    cout<<"Your Account Has Been Closed"<<endl;
                }
                else{
                    cout<<"Account Not Found"<<endl;
                }

            }
                break;
            case 8:{
            }
                break;
            case 9:{

            }
            break;
            default:{
                cout<<"Select An Valid Option!!"<<endl;
            }
            break;
        };
    }while(option != 9);
    return 0;

}
