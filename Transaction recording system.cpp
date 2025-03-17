#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Structure for transaction details
struct Transaction {
    int id;
    string type; // Income or Expense
    string category;
    double amount;
    string date;
};

// Global variables
vector<Transaction> transactions;
// Predefined user credentials
const string usernames[] = {"haram", "anisha", "azhar"};
const string passwords[] = {"admin123", "admin456", "admin789"};
const int userCount = 3; // Total number of predefined users

string currentUser;

// Function prototypes
bool login();
void menu();
void addTransaction();
void viewTransactions();
void searchTransactions();
void deleteTransaction();
void updateTransaction();
void calculateBalance();
void logout();

int main() {
	cout << "=== Transaction Recording System ===\n" << endl;
    while (true) {
        if (!login()) {
            cout << "Invalid credentials! Try again.\n";
            continue;
        }
        menu();
    }
}

// Function to log in a user
bool login() {
    string username, password;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    // Check if the username and password are correct
    for (int i = 0; i < userCount; i++) {
        if (usernames[i] == username && passwords[i] == password) {
            currentUser = username;
            cout << "Login Successful! Welcome, " << username << ".\n";
            return true;
        }
    }
    return false;
}

// Function to display the menu
// Function to display the menu
void menu() {
    while (true) {
        int choice;
        cout << "\n===== OPTIONS =====\n";
        cout << "1. Add Transaction\n2. View Transactions\n3. Search Transactions\n4. Delete Transaction\n5. Update Transaction\n6. Calculate Balance\n7. Log Out\n8. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTransaction(); break;
            case 2: viewTransactions(); break;
            case 3: searchTransactions(); break;
            case 4: deleteTransaction(); break;
            case 5: updateTransaction(); break;
            case 6: calculateBalance(); break;
            case 7: logout(); return;
            case 8: 
                cout << "Thank you for using. Goodbye!\nCopyrights -- 24BSSW031/HARAM-KHAN";
                exit(0);  // Exit the program
            default: cout << "Invalid choice! Try again.\n";
        }
    }
}


// Function to add a transaction
void addTransaction() {
    Transaction t;
    t.id = transactions.size() + 1;
    cout << "Enter Type (Income/Expense): ";
    cin >> t.type;
    cout << "Enter Category (Food, Shopping, Bills, Salary, etc.): ";
    cin >> t.category;
    cout << "Enter Amount: ";
    cin >> t.amount;
    cout << "Enter Date (YYYY-MM-DD): ";
    cin >> t.date;

    transactions.push_back(t);
    cout << "Transaction Added Successfully!\n";
}

// Function to view all transactions
void viewTransactions() {
    if (transactions.empty()) {
        cout << "No transactions recorded yet.\n";
        return;
    }

    cout << "\nID\tType\tCategory\tAmount\tDate\n";
    cout << "----------------------------------------------------\n";
    for (const auto &t : transactions) {
        cout << t.id << "\t" << t.type << "\t" << t.category << "\t" << fixed << setprecision(2) << t.amount << "\t" << t.date << "\n";
    }
}

// Function to search transactions by category or date
void searchTransactions() {
    if (transactions.empty()) {
        cout << "No transactions recorded yet.\n";
        return;
    }

    string keyword;
    cout << "Enter Category or Date to Search: ";
    cin >> keyword;
    
    cout << "\nID\tType\tCategory\tAmount\tDate\n";
    cout << "----------------------------------------------------\n";
    bool found = false;
    for (const auto &t : transactions) {
        if (t.category == keyword || t.date == keyword) {
            cout << t.id << "\t" << t.type << "\t" << t.category << "\t" << fixed << setprecision(2) << t.amount << "\t" << t.date << "\n";
            found = true;
        }
    }
    if (!found) cout << "No matching transactions found.\n";
}

// Function to delete a transaction
void deleteTransaction() {
    if (transactions.empty()) {
        cout << "No transactions to delete.\n";
        return;
    }

    int id;
    cout << "Enter Transaction ID to Delete: ";
    cin >> id;

    for (auto it = transactions.begin(); it != transactions.end(); ++it) {
        if (it->id == id) {
            transactions.erase(it);
            cout << "Transaction Deleted Successfully!\n";
            return;
        }
    }
    cout << "Transaction Not Found!\n";
}

// Function to update a transaction
void updateTransaction() {
    if (transactions.empty()) {
        cout << "No transactions to update.\n";
        return;
    }

    int id;
    cout << "Enter Transaction ID to Update: ";
    cin >> id;

    for (auto &t : transactions) {
        if (t.id == id) {
            cout << "Enter New Type (Income/Expense): ";
            cin >> t.type;
            cout << "Enter New Category: ";
            cin >> t.category;
            cout << "Enter New Amount: ";
            cin >> t.amount;
            cout << "Enter New Date: ";
            cin >> t.date;
            cout << "Transaction Updated Successfully!\n";
            return;
        }
    }
    cout << "Transaction Not Found!\n";
}

// Function to calculate total balance
void calculateBalance() {
    if (transactions.empty()) {
        cout << "No transactions recorded yet.\n";
        return;
    }

    double totalIncome = 0, totalExpense = 0;
    for (const auto &t : transactions) {
        if (t.type == "Income") {
            totalIncome += t.amount;
        } else {
            totalExpense += t.amount;
        }
    }
    cout << "\nTotal Income: $" << totalIncome << "\n";
    cout << "Total Expenses: $" << totalExpense << "\n";
    cout << "Net Balance: $" << totalIncome - totalExpense << "\n";
}

// Function to log out the user
void logout() {
    cout << "Logging out...\n";
    currentUser = "";
}
