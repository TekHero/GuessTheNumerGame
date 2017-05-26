//
//  main.cpp
//  GuessTheNumberGame
//
//  Created by Brian Lim on 5/13/17.
//  Copyright © 2017 codebluapps. All rights reserved.
//

#include <iostream>

using namespace std;

void introMsg();
int generateRandNum();

int main(int argc, const char * argv[]) {
    
    srand(time(0));
    
    int randNum = generateRandNum();
    int usersGuess;
    char usersChoice;
    
    introMsg();
    do {
        
        cout << "? ";
        cin >> usersGuess;
        
        if (cin.fail()) {
            
            cout << "Invalid guess. Try again." << endl;
            cin.clear();
            cin.ignore(256, '\n');

        } else {
            
            if (usersGuess < randNum) {
                cout << "Too Low. Try again." << endl;
            } else if (usersGuess > randNum) {
                cout << "Too High. Try again." << endl;
            } else if (usersGuess == randNum) {
                cout << "\n";
                cout << "Excellent! You guessed the number!" << endl;
                cout << "Would you like to play again (y or n)? ";
                
                cin >> usersChoice;
                cout << "\n";
                
                if (usersChoice == 'y' || usersChoice == 'Y') {
                    randNum = generateRandNum();
                    introMsg();
                } else if (usersChoice == 'n' || usersChoice == 'N') {
                    return 0;
                } else if (usersChoice != 'n' || usersChoice != 'N' || usersChoice != 'y' || usersChoice != 'Y') {
                    cout << "Invalid choice." << endl;
                }
            }

        }
        
    } while (usersGuess != randNum);
    
    return 0;
}

void introMsg() {
    cout << "I have a number between 1 and 1000." << endl;
    cout << "Can you guess my number?" << endl;
    cout << "Please type your first guess." << endl;
}

int generateRandNum() {
    
    int number;
    number = rand() % 1000 + 1;
    cout << "Generated Number is: " << number << endl;
    return number;
}
