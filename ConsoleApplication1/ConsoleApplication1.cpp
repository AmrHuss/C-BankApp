// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>



using namespace std;

void RegisterUser(string username, string password)
{

    std::fstream file;
    

    file.open("k.txt", std::ios::out | std::ios::app);

        file << username + "," + password << endl;

        file.close();

}

bool checkCredentials(const std::string& username, const std::string& password) {
    std::ifstream file("k.txt");
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string storedUsername, storedPassword;
        if (std::getline(iss, storedUsername, ',') && getline(iss, storedPassword, ',')) {
            if (storedUsername == username && storedPassword == password) {
                return true; 
            }
        }
    }

    return false; 
}

int main()
{
    int choice = 0;
    int num = 0;
 
    cout << "Hello Welcome to your banking app please press a number to continue \n";
    cout << "1. Sign in \n";
    cout << "2. Sign up \n";
    cout << "3. Exit\n";
    cin >> choice;

  string username, password; 

    switch (choice) {
    case 1:
        std::cout << "Enter username: ";
        std::cin >> username;

        std::cout << "Enter password: ";
        std::cin >> password;

        while (!checkCredentials(username, password)) {
            std::cout << "\nInvalid username or password. Please try again.\n";

            std::cout << "\nPlease enter your name:";
            std::cin >> username;

            std::cout << "\nPlease enter your Password:";
            std::cin >> password;
        }

        std::cout << "Login successful!\n";
        break;



    case 2:
        cout << "\n Please enter your name:";
        cin >> username;
        while (username == "")
        {

            cout << "\n Please enter your name:";
            cin >> username;


        }

        cout << "\n Please enter your Password:";
        cin >> password;
        while (password == ""|| password.length() < 6 )
        {

            cout << "\n Please enter your password make sure it has more than 6 charcters:";
            cin >> password;

        }

        RegisterUser(username, password);
        break;



    case 3:
        cout << "\n You have succesfully quit the app ";
        break;


    }
}




 


       



  


