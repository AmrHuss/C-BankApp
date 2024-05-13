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
    int choice=0;
    int num = 0;
    string username = "";
    string password = "";
    
        std::cout << "Login successful!\n";
        break;


        std::cout << "Hello Welcome to your banking app please press a number to continue \n";
        std::cout << "1. Sign in \n";
        std::cout << "2. Sign up \n";
        std::cout << "3. Exit\n";
        cin >> choice;

        switch (choice)
        {
            
        case 1:
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


                    
;           
            case 2:
                cout << "\n Please enter your name:";
                cin >> username;
                cout << "\n Please enter a Password:";
                cin >> password;
            case 3:
                cout << "\n You have succesfully quit the app ";
                break;


        }
}

        



  
} 

