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
        date.push_front(value); // ������ ������� �� ������� ������
    }

    void pop() {
        if (container.empty()) {
            cout << "Stack is empty! Cannot pop." << endl;
            return;
        }
        date.pop_front(); // ��������� ������ ������� ������
    }

    Type peek() {
        if (container.empty()) {
            cout << "Stack is empty"<<endl;
        }
        return date.ind(0); // ��������� ������ ������� ������
    }

    bool empty() {
        return data.empty();
    }

    int size() {
        return container.rozm();
    }

    void print() const {
        container.print();
    }
};
