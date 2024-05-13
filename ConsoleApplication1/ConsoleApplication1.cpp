#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void RegisterUser(string username, string password) {
    ofstream file("k.txt", ios::out | ios::app);
    if (file.is_open()) {
        file << username + "," + password << endl;
        file.close();
        cout << "Registration successful!\n";
    }
    else {
        cout << "Error: Unable to open file for registration.\n";
    }
}

bool checkCredentials(const string& username, const string& password) {
    ifstream file("k.txt");
    if (!file.is_open()) {
        cout << "Error: Unable to open file for checking credentials.\n";
        return false;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string storedUsername, storedPassword;
        if (getline(iss, storedUsername, ',') && getline(iss, storedPassword, ',')) {
            if (storedUsername == username && storedPassword == password) {
                file.close();
                return true;
            }
        }
    }
    file.close();
    return false;
}

int main() {
    int choice;
    string username, password;

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

            if (checkCredentials(username, password)) {
                cout << "Login successful!\n";
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
