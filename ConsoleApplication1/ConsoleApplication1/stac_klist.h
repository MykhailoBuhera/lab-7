#pragma once
#include <iostream>
#include <memory>
#include "List.h"
using namespace std;
template <typename Type>
class Stack {
private:
    list<Type> date;

public:
    void push(Type value) {
        date.push_front(value); // add element on start of list which is top of stack
    }

    void pop() {
        if (date.empty()) {
            cout << "Stack is empty! Cannot pop." << endl;
            return;
        }
        date.pop_front(); // delet first list's odject which is
    }

    Type peek() {
        if (date.empty()) {
            cout << "Stack is empty"<<endl;
        }
        return date.ind(0); // return first object
    }

    bool empty() {
        return date.empty();
    }

    void print() const {
        date.print();
    }
};
