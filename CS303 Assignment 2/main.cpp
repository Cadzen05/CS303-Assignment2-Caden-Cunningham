#include <iostream>
#include <string>
#include <limits>
#include "Stack.h"

int main() {
    cout << "Welcome to my STACK program!\n";

    // Initialize variables
    Stack user_stack;
    string input;
    char user_choice = ' ';

    // Main loop while user_choice != 'Q'
    while (user_choice != 'Q') {
        cout << "\n----------------------------------\n";
        cout << "A. Check if stack is empty\n";
        cout << "B. Insert an integer onto the stack\n";
        cout << "C. Remove an integer from the stack\n";
        cout << "D. Find the top of the stack\n";
        cout << "E. Find the average of the stack\n";
        cout << "Q. Quit\n";
        cout << "\nWhat would you like to do: ";

        // Validate input is only 1 character and uppercase it
        getline(std::cin, input);
        if (input.length() != 1) {
            cout << "Please enter exactly one character.\n";
            continue;
        }
        user_choice = toupper(static_cast<unsigned char>(input[0]));

        // Switch statement for user_choice 
        switch (user_choice) {
            case 'A': {
                // If stack is empty
                if (user_stack.empty()) {
                    cout << "The stack is empty!\n";
                }
                // If stack has 1 or more values
                else {
                    cout << "The stack is not empty!\n";
                }
                break;
            }
            case 'B': {
                int num;
                // Make sure user input is an integer
                while (true) {
                    cout << "What number would you like to add: ";
                    cin >> num;
            
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input. Please enter an integer.\n";
                    }
                    else {
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }
                }
                // Push integer onto the stack
                user_stack.push(num);
                cout << num << " was added to the stack!\n";
                break;
            }
            case 'C': {
                // Do not pop() if stack is empty
                if (user_stack.empty()) {
                    cout << "Cannot pop() an empty stack.\n";
                }
                // Pop the top value
                else {
                    user_stack.pop();
                    cout << "An integer was removed from the stack!\n";
                }
                break;
            }
            case 'D': {
                // Do not top() if stack is empty
                if (user_stack.empty()) {
                    cout << "Cannot top() an empty stack.\n";
                }
                // Display the top value
                else {
                    cout << "The integer at the top is: " << user_stack.top() << endl;
                }
                break;
            }
            case 'E': {
                // Do not average() if stack is empty
                if (user_stack.empty()) {
                    cout << "Your stack is empty.\n";
                }
                // Display the average of the stack
                else {
                    double average = user_stack.average();
                    cout << "The average of the stack is: " << average << endl;
                }
                break;
            }
            case 'Q': {
                // Quit program
                cout << "Goodbye!\n";
                break;
            }
            default: {
                // If user input is invalid
                cout << "Invalid option. Please try again.\n";
                break;
            }
        }
    }
    return 0;
}