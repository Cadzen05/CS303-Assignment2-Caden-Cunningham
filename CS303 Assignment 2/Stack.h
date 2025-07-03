#pragma once
#include <vector>

using namespace std;

class Stack {
private:
    vector<int> stack;

public:
    // Constructor
    Stack() : stack() {}

    // Class functions
    bool empty() const {
        // Return true if stack is empty, otherwise return false
        if (stack.size() == 0) {
            return true;
        }
        return false;
    }

    void push(const int item) {
        // Use built in push_back() function
        stack.push_back(item);
    }

    void pop() {
        // Use built in pop_back() function
        stack.pop_back();
    }

    int top() {
        // Use built in back() function
        return stack.back();
    }

    double average() {
        // Initialize size and calculate the average using for loop and sum double
        int size = stack.size();

        double sum = 0;
        for (int i = 0; i < size; i++) {
            sum += stack[i];
        }
        return (sum / size);
    }
};