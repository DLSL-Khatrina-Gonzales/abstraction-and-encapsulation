#include <iostream>
using namespace std;

class Account {
protected:
    double balance; 
public:
    Account() : balance(0) {}

    // Abstract methods to be overridden by derived classes
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void checkBalance() const = 0;
};

// Derived class for Savings Account with encapsulated functionality
class SavingsAccount : public Account {
public:
    SavingsAccount() : Account() {
        balance = 1000;  // Initialize with minimum balance for Savings Account
    }

    // Overriding the deposit method for SavingsAccount
    void deposit(double amount) override {
        if (amount > 0) {
            balance += amount;
            cout << "\nDeposit successful! Your new savings balance is: " << balance << " Php" << endl;
        } else {
            cout << "\nInvalid amount! Please enter a positive number." << endl;
        }
    }

    // Overriding the withdraw method for SavingsAccount
    void withdraw(double amount) override {
        if (amount > 0) {
            if (balance - amount >= 1000) {  // Ensuring minimum balance of 1000
                balance -= amount;
                cout << "\nWithdrawal successful! Your new savings balance is: " << balance << " Php" << endl;
            } else {
                cout << "\nInsufficient balance! You must maintain a minimum balance of 1000." << endl;
            }
        } else {
            cout << "\nInvalid amount! Please enter a positive number." << endl;
        }
    }

    // Overriding the checkBalance method for SavingsAccount
    void checkBalance() const override {
        cout << "\nYour current savings balance is: " << balance << " Php" << endl;
    }
};

// Derived class for Current Account with encapsulated functionality
class CurrentAccount : public Account {
public:
    CurrentAccount() : Account() {}

    // Overriding the deposit method for CurrentAccount
    void deposit(double amount) override {
        if (amount > 0) {
            balance += amount;
            cout << "\nDeposit successful! Your new current account balance is: " << balance << " Php" << endl;
        } else {
            cout << "\nInvalid amount! Please enter a positive number." << endl;
        }
    }

    // Overriding the withdraw method for CurrentAccount
    void withdraw(double amount) override {
        if (amount > 0) {
            if (amount <= balance) {
                balance -= amount;
                cout << "\nWithdrawal successful! Your new current account balance is: " << balance << " Php" << endl;
            } else {
                cout << "\nInsufficient balance! Your current account balance is: " << balance << " Php" << endl;
            }
        } else {
            cout << "\nInvalid amount! Please enter a positive number." << endl;
        }
    }

    // Overriding the checkBalance method for CurrentAccount
    void checkBalance() const override {
        cout << "\nYour current account balance is: " << balance << " Php" << endl;
    }
};

// Function to clear input buffer after an invalid input
void clearInput() {
    cin.clear();
    cin.ignore();
}

// Function to display the Savings Account menu
void savingsMenu(SavingsAccount &savings) {
    int choice;
    do {
        cout << "\nSavings Account\n";
        cout << "1 - Deposit\n2 - Withdraw\n3 - Check Balance\n4 - Back\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            clearInput();
            cout << "\nInvalid input! Please enter a number." << endl;
            continue;
        }

        double amount;
        switch (choice) {
            case 1:
                cout << "\nEnter the amount to deposit: ";
                cin >> amount;
                if (cin.fail()) {
                    clearInput();
                    cout << "\nInvalid input! Please enter a valid number." << endl;
                } else {
                    savings.deposit(amount);
                }
                break;
            case 2:
                cout << "\nEnter the amount to withdraw: ";
                cin >> amount;
                if (cin.fail()) {
                    clearInput();
                    cout << "\nInvalid input! Please enter a valid number." << endl;
                } else {
                    savings.withdraw(amount);
                }
                break;
            case 3:
                savings.checkBalance();
                break;
            case 4:
                return;
            default:
                cout << "\nInvalid option! Please enter a valid choice." << endl;
        }
    } while (true);
}

// Function to display the Current Account menu
void currentMenu(CurrentAccount &current) {
    int choice;
    do {
        cout << "\nCurrent Account\n";
        cout << "1 - Deposit\n2 - Withdraw\n3 - Check Balance\n4 - Back\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            clearInput();
            cout << "\nInvalid input! Please enter a number." << endl;
            continue;
        }

        double amount;
        switch (choice) {
            case 1:
                cout << "\nEnter the amount to deposit: ";
                cin >> amount;
                if (cin.fail()) {
                    clearInput();
                    cout << "\nInvalid input! Please enter a valid number." << endl;
                } else {
                    current.deposit(amount);
                }
                break;
            case 2:
                cout << "\nEnter the amount to withdraw: ";
                cin >> amount;
                if (cin.fail()) {
                    clearInput();
                    cout << "\nInvalid input! Please enter a valid number." << endl;
                } else {
                    current.withdraw(amount);
                }
                break;
            case 3:
                current.checkBalance();
                break;
            case 4:
                return;
            default:
                cout << "\nInvalid option! Please enter a valid choice." << endl;
        }
    } while (true);
}

// Function to display the main menu
void mainMenu() {
    SavingsAccount savings;
    CurrentAccount current;
    int choice;

    do {
        cout << "\nMain Menu\n";
        cout << "1 - Savings Account\n2 - Current Account\n3 - Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            clearInput();
            cout << "\nInvalid input! Please enter a number." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                savingsMenu(savings);
                break;
            case 2:
                currentMenu(current);
                break;
            case 3:
                cout << "\nExiting...\nThank you for using the bank system!" << endl;
                return;
            default:
                cout << "\nInvalid option! Please enter a valid choice." << endl;
        }
    } while (true);
}

int main() {
    mainMenu();
    return 0;
}