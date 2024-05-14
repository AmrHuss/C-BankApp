#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void RegisterUser(string username, string password) {
    ofstream file("k.txt", ios::out | ios::app);
    if (file.is_open()) {
        file << username << "," << password << "," << "0" << endl; // Initialize balance to 0
        file.close();
        cout << "Registration successful!\n";
    }
    else {
        cout << "Error: Unable to open file for registration.\n";
    }
}

bool checkCredentials(const string& username, const string& password, float& balance) {
    ifstream file("k.txt");
    if (!file.is_open()) {
        cout << "Error: Unable to open file for checking credentials.\n";
        return false;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string storedUsername, storedPassword;
        float storedBalance;
        if (getline(iss, storedUsername, ',') && getline(iss, storedPassword, ',') && iss >> storedBalance) {
            if (storedUsername == username && storedPassword == password) {
                balance = storedBalance;
                file.close();
                return true;
            }
        }
    }
    file.close();
    return false;
}

void updateBalance(const string& username, float newBalance) {
    ifstream file("k.txt");
    ofstream tempFile("temp.txt");

    if (!file.is_open() || !tempFile.is_open()) {
        cout << "Error: Unable to open file for updating balance.\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string storedUsername, storedPassword;
        float storedBalance;
        if (getline(iss, storedUsername, ',') && getline(iss, storedPassword, ',') && iss >> storedBalance) {
            if (storedUsername == username) {
                tempFile << storedUsername << "," << storedPassword << "," << newBalance << endl;
            }
            else {
                tempFile << line << endl;
            }
        }
    }
    file.close();
    tempFile.close();
    remove("k.txt");
    rename("temp.txt", "k.txt");
}

void Logged(string username, float& balance) {
    int choice;
    float deposit;
    float withdraw;

    cout << "Hello " << username << ", Welcome to your banking app. Please select an option: \n";
    cout << "1. Check balance\n";
    cout << "2. Withdraw\n";
    cout << "3. Deposit\n";
    cout << "4. Exit\n";

    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Your balance is: " << balance << endl;
        break;
    case 2:
        cout << "Enter amount to withdraw: ";
        cin >> withdraw;
        if (withdraw <= balance) {
            balance -= withdraw;
            updateBalance(username, balance);
            cout << "Withdrawal successful. Your new balance is: " << balance << endl;
        }
        else {
            cout << "Insufficient funds.\n";
        }
        break;
    case 3:
        cout << "Enter amount to deposit: ";
        cin >> deposit;
        balance += deposit;
        updateBalance(username, balance);
        cout << "Deposit successful. Your new balance is: " << balance << endl;
        break;
    case 4:
        cout << "Exiting to main menu.\n";
        return;
    default:
        cout << "Invalid choice. Please select a valid option.\n";
    }
}

int main() {
    int choice;
    string username, password;
    float balance;

    while (true) {
        cout << "Hello! Welcome to your banking app. Please select an option:\n";
        cout << "1. Sign in\n";
        cout << "2. Sign up\n";
        cout << "3. Exit\n";

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter your username: ";
            cin >> username;

            cout << "Enter your password: ";
            cin >> password;

            if (checkCredentials(username, password, balance)) {
                cout << "Login successful!\n";
                Logged(username, balance);
            }
            else {
                cout << "Invalid username or password.\n";
            }
            break;

        case 2:
            cout << "Enter a new username: ";
            cin >> username;

            cout << "Enter a new password (must be at least 6 characters long): ";
            cin >> password;

            if (password.length() < 6) {
                cout << "Password must be at least 6 characters long. Registration failed.\n";
            }
            else {
                RegisterUser(username, password);
            }
            break;

        case 3:
            cout << "Exiting the app. Goodbye!\n";
            return 0;

        default:
            cout << "Invalid choice. Please select a valid option.\n";
        }
    }

    return 0;
}
