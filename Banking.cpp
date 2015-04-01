#include "Banking.h"



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

    int index,len = (sizeof(sharedInstanceOfAllAccounts.AccountNumbers)/sizeof(sharedInstanceOfAllAccounts.AccountNumbers[0]));
    Account account;
    static int accountNum = 1;
    for(index=0;index<len;index++){
        if(sharedInstanceOfAllAccounts.AccountNumbers[index] == 0){
            break;
        }
    }
    account.accountNumber = accountNum;
    cout<<"Enter Name of Account Holder:";
    cin>>account.name;
    cout<<"Enter Money You Want To Deposit In Account($500 to $10000):";
    cin>>account.balance;
    cout<<"Enter Type Of Account (s/c):";
    cin>>account.typeOfAccount;
    cout<<"New Account Has Successfully Been Created"<<endl<<endl;
    sharedInstanceOfAllAccounts.AccountNumbers[index] = accountNum;
    sharedInstanceOfAllAccounts.AllAccounts[index] = account;
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
int accountNumberSeacrh(unsigned int accountNumber){
    int len = (sizeof(sharedInstanceOfAllAccounts.AccountNumbers)/sizeof(sharedInstanceOfAllAccounts.AccountNumbers[0]));
    int i = 0;
    bool flag;
    for(i=0;i<len;i++){
        if(sharedInstanceOfAllAccounts.AccountNumbers[i] == accountNumber){
            flag = true;
            break;
        }
        else{
            flag = false;
        }
    }
    if(flag){
        return i;
    }
    else{
        return -1;
    }
}
bool verifyAccountName(int index, string name){
    sharedInstanceOfAccount = sharedInstanceOfAllAccounts.AllAccounts[index];

    if(!name.compare(sharedInstanceOfAccount.getName())){
        return true;
    }
    else{
        return false;
    }
}
int verifyAccounts(){

    unsigned int verifyAccountNumber;
    int index;
    string verifyName;

    cout<<"Enter Your Account Number:";
    cin>>verifyAccountNumber;
    cout<<endl;
    index = accountNumberSeacrh(verifyAccountNumber);
    if( index != -1){
        cout<<"Verify Your Name:";
        cin>>verifyName;
        cout<<endl;
        if(verifyAccountName(index,verifyName)){
            return index;
        }
        else{
            return -1;
        }

    }
    else{
        return -1;
    }

}

void closeAnAccount(int index){

    int len = (sizeof(sharedInstanceOfAllAccounts.AccountNumbers)/sizeof(sharedInstanceOfAllAccounts.AccountNumbers[0]));
    int counter =0;
    int j=index;
    for(int i=0; i<len; i++){

        if(sharedInstanceOfAllAccounts.AccountNumbers[i] != 0)
        {
            counter++;
        }
    }

    if(index != -1){
        if(index != len-1){

            for(int i=index; i<len; i++){

                if(i==j){
                    continue;
                }
                else if(sharedInstanceOfAllAccounts.AccountNumbers[j] !=0 && sharedInstanceOfAllAccounts.AccountNumbers[i] !=0){

                    sharedInstanceOfAllAccounts.AccountNumbers[j] = sharedInstanceOfAllAccounts.AccountNumbers[i];
                    sharedInstanceOfAllAccounts.AllAccounts[j] = sharedInstanceOfAllAccounts.AllAccounts[i];
                    j++;
                }
            }
            sharedInstanceOfAllAccounts.AccountNumbers[j] = 0;
            cout<<"Your Account Has Been Closed"<<endl;

        }
        else{
            sharedInstanceOfAllAccounts.AccountNumbers[index] = 0;
            cout<<"Your Account Has Been Closed"<<endl;
        }
    }
    else{
        cout<<"Account Not Found"<<endl;
    }
}

int  main(){
    int index;
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
                index = verifyAccounts();
                if(index != -1){
                    sharedInstanceOfAccount = sharedInstanceOfAllAccounts.AllAccounts[index];
                    sharedInstanceOfAccount.depositMoneyToAccount(sharedInstanceOfAccount.getAccountNumber());
                }
                else{
                    cout<<"Account Not Found"<<endl;
                }

            }
                break;
            case 4:{                                                                      //Withdrawing Money From Account
                index = verifyAccounts();
                if(index != -1){
                    sharedInstanceOfAccount = sharedInstanceOfAllAccounts.AllAccounts[index];
                    sharedInstanceOfAccount.WithdrawMoneyFromAccount(sharedInstanceOfAccount.getAccountNumber());
                }
                else{
                    cout<<"Account Not Found"<<endl;
                }

            }
                break;
            case 5:{
                index = verifyAccounts();
                if(index != -1){
                    sharedInstanceOfAccount = sharedInstanceOfAllAccounts.AllAccounts[index];
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
                index = verifyAccounts();
                closeAnAccount(index);

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
