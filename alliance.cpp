#include <iostream>
#include <vector>
using namespace std;

class Transaction {
private:
    double amount;

public:
    Transaction(double amount)  {
    }
    this->amount = amount;
    double getAmount() const {
        return amount;
    }
};

class BankAccount {
private:
    int accountNumber;
    double balance;
    vector<Transaction> transactions;
public:
    BankAccount(int accountNumber, double balance) : accountNumber(accountNumber),
	balance(balance) {}

    int getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
        transactions.push_back(Transaction(amount));
    }

    bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            transactions.push_back(Transaction(-amount));
            return true;
        }
        return false;
    }

    const vector<Transaction>& getTransactions() const {
        return transactions;
    }
};

class Customer {
private:
    string name;
    int customerId;
    BankAccount account;
public:
    Customer(string name, int customerId, int accountNumber, double initialBalance)
        : name(name), customerId(customerId), account(accountNumber, initialBalance) {}

    string getName() const {
        return name;
    }

    int getCustomerId() const {
        return customerId;
    }

    const BankAccount& getAccount() const {
        return account;
    }

    void deposit(double amount) {
        account.deposit(amount);
    }

    bool withdraw(double amount) {
        return account.withdraw(amount);
    }
};

class ATM {
public:
    static void displayMenu() {
        cout << "------------------------------  WELCOME TO ATM  --------------------------------\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. Exit\n";
    }

    static void processTransaction(Customer& customer) {
        int choice;
        double amount;

        do {
            displayMenu();
            cout << "\nEnter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "\nEnter amount to deposit: ";
                    cin >> amount;
                    customer.deposit(amount);
                    cout << "\nDeposit successful.\n";
                    break;
                case 2:
                    cout << "\nEnter amount to withdraw: ";
                    cin >> amount;
                    if (customer.withdraw(amount)) {
                        cout << "\nWithdrawal successful.\n";
                    } else {
                        cout << "\nInsufficient balance.\n";
                    }
                    break;
                case 3:
                    cout << "\nYour balance is: " << customer.getAccount().getBalance() << endl;
                    break;
                case 4:
                    cout << "\nThank You For Using ATM...\n";
                    break;
                default:
                    cout << "\nInvalid choice. Please try again.\n";
            }
        } while (choice != 4);
    }
};

int main() {
    Customer customer("Hassan", 2233317, 192837465, 10000);
	                //  Name,  Customer-ID, Acc-No, Balance
    ATM::processTransaction(customer);
    return 0;
}
