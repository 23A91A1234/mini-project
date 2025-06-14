#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BankAccount {
private:
    int accountNumber;
    string name;
    float balance;

public:
    BankAccount(int accNum, string accName, float initBalance) {
        accountNumber = accNum;
        name = accName;
        balance = initBalance;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    void display() {
        cout << "\n--- Account Details ---\n";
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << name << endl;
        cout << "Current Balance: ?" << balance << endl;
    }

    void showBalance() {
        cout << "Current Balance: ?" << balance << endl;
    }

    void deposit(float amount) {
        if (amount > 0) {
            balance += amount;
            cout << "?" << amount << " deposited successfully.\n";
        } else {
            cout << "Invalid deposit amount!\n";
        }
    }

    void withdraw(float amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "?" << amount << " withdrawn successfully.\n";
        } else {
            cout << "Invalid or insufficient balance!\n";
        }
    }
};

vector<BankAccount> accounts;

BankAccount* findAccount(int accNum) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].getAccountNumber() == accNum) {
            return &accounts[i];
        }
    }
    return NULL;
}

int main() {
    int choice, accNum;
    string name;
    float balance, amount;

    while (true) {
        cout << "\n====== BANK MANAGEMENT MENU ======\n";
        cout << "1. Create New Account\n";
        cout << "2. Display Account Info\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. Show Balance\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Account Number: ";
            cin >> accNum;
            cin.ignore();
            cout << "Enter Account Holder Name: ";
            getline(cin, name);
            cout << "Enter Initial Balance: ?";
            cin >> balance;
            BankAccount newAcc(accNum, name, balance);
            accounts.push_back(newAcc);
            cout << "Account created successfully!\n";

        } else if (choice == 2) {
            cout << "Enter Account Number: ";
            cin >> accNum;
            BankAccount* acc = findAccount(accNum);
            if (acc != NULL)
                acc->display();
            else
                cout << "Account not found!\n";

        } else if (choice == 3) {
            cout << "Enter Account Number: ";
            cin >> accNum;
            BankAccount* acc = findAccount(accNum);
            if (acc != NULL) {
                cout << "Enter amount to deposit: ?";
                cin >> amount;
                acc->deposit(amount);
            } else {
                cout << "Account not found!\n";
            }

        } else if (choice == 4) {
            cout << "Enter Account Number: ";
            cin >> accNum;
            BankAccount* acc = findAccount(accNum);
            if (acc != NULL) {
                cout << "Enter amount to withdraw: ?";
                cin >> amount;
                acc->withdraw(amount);
            } else {
                cout << "Account not found!\n";
            }

        } else if (choice == 5) {
            cout << "Enter Account Number: ";
            cin >> accNum;
            BankAccount* acc = findAccount(accNum);
            if (acc != NULL) {
                acc->showBalance();
            } else {
                cout << "Account not found!\n";
            }

        } else if (choice == 6) {
            cout << "Thank you for using our service!\n";
            break;

        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

