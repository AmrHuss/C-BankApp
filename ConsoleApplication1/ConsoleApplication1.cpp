// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;
int main()
{
    int choice=0;
    int num = 0;
    string username = "";
    string password = "";
    


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

                cout << "\n Please enter your Password:";
                cin >> password;

                    
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

