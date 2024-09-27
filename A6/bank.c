#include "bank.h"

Bank* CreateBank(double money, double maxLoan,
                    double loanInterest, double transferFeeRate) {
    // Allocate bank
    Bank *bank = malloc(sizeof(Bank));
    assert(bank);
    // No accounts yet
    bank->accounts = NULL;
    bank->nAcc = 0;
    // Assign inputs
    bank->money = money;
    bank->maxLoan = maxLoan;
    bank->loanInterest = loanInterest;
    bank->transferFeeRate = transferFeeRate;

    return bank;
}

Account* OpenAccount(Bank *bank) {
    struct Account *newAcc = malloc(sizeof(struct Account));
    ++bank->nAcc;

    newAcc->id = bank->nAcc;
    newAcc->balance = 0.0;
    newAcc->active = true;
    newAcc->loan.active = false;
    newAcc->loan.amount = 0.0;
    newAcc->loan.interest = 0.0;
    newAcc->bank = bank;

    bank->accounts = realloc(bank->accounts, (bank->nAcc) *(sizeof(struct Account)));
    bank->accounts[bank->nAcc - 1] = newAcc;

    return newAcc;

}

void Deposit(double amount, Account *account) {
    if(account->active == true){
        account->balance += amount;
    }
}

bool Withdraw(double amount, Account *account) {
    if(account->balance - amount >= 0){
        account->balance -=amount;
        return true;
    }
    return false;
}

bool TakeLoan(double amount, Account *account) {
    if(account->active && account->loan.active == false && amount <= account->bank->maxLoan){
        account->balance += amount;
        account->bank->money -= amount;
        account->loan.active = true;
        account->loan.amount += amount;
        account->loan.interest = account->bank->loanInterest;

        return true;
    }
    return false;
}

bool PayLoan(Account *account) {
    account->loan.interest = account->bank->loanInterest * account->loan.amount;

    if(account->active && account->loan.active && account->balance >= account->loan.interest){
        account->loan.amount -= account->loan.interest;
        account->balance -= account->loan.interest;
        account->bank->money += account->loan.interest;
        account->loan.active = false;

        return true;
    }
    return false;
}

bool Transfer(double amount, Account *sender, Account *receiver) {
  double fee = amount * sender->bank->transferFeeRate;

    if (sender->balance >= amount * fee) {
        receiver->balance += amount;
        if (sender->bank != receiver->bank) {
            sender->balance -= amount + fee;
            sender->bank->money += fee;
        } else{
            sender->balance -= amount;
        }
        return true;
        } 
    return false;   
}

bool CollectLoanPayments(Bank *bank) {
    for(int i = 0 ; i < bank->nAcc ; i++){
        if(bank->accounts[i]->loan.active && !PayLoan(bank->accounts[i])){
            return false;
        }
    }
    return true;
}

bool CloseAccount(Account *account) {
    if((account->loan.active && PayLoan(account)) || (!account->loan.active)){
        account->active = false;
        account->balance - 0;
        return true;
    }
    return false;
}

Bank* ForceDestroyBank(Bank *bank) {
    // Check if bank exists
    if (!bank)
        return NULL;
    // Just free the memory
    for (int i = 0; i < bank->nAcc; i++) {
                  free(bank->accounts[i]);
    }
    free(bank->accounts);
        
    free(bank);
    bank = NULL;
    return NULL;
}

void ShowAccount(Account *account) {
    printf("Account #%d:\n", account->id);
    if (account->active) {
        printf("Balance: %.3f\n", account->balance);
        if (account->loan.active) {
            printf("Loaned %.3f with interest %f\n",
                account->loan.amount, account->loan.interest);
        }
    } else {
        printf("Inactive account\n");
    }
}

void ShowBank(Bank *bank) {
    printf("BANK:\n");
    printf("Total money in bank: %.3f\n", bank->money);
    printf("Maximum loan offered: %.3f\n", bank->maxLoan);
    printf("Interest for loans: %f\n", bank->loanInterest);
    printf("Fee for a money transfer: %f\n", bank->transferFeeRate);
    //printf("----------------\n");
    for (int i = 0; i < bank->nAcc; i++) {
        ShowAccount(bank->accounts[i]);
        printf("----------------\n");
    }
}

