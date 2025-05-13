#pragma once
#include <iostream>
#include <memory>
#include "Node.h"

template <typename Type>
class Stack
{
private:
    shared_ptr<Node<Type>> data;

public:

    void push(Type value) { //add object in srat
        auto new_node = make_shared<Node<Type>>(value); // Створюється новий об'єкт, якому назначається передана змінна value.
        if (!data) {
            data = new_node;
            return;
        }
        new_node->next = data;// Вказівник next новоствореного об'єкту new_node вказує на попередньо створену змінну data(Адресу).                                     
        data->prev = new_node;
        data = new_node;
    }

    void isEmpty() {
        if (!data) {
            cout << "Stack is empty!" << endl;
            return;
        }
    }

    void pop() {//del strt element
        if (!data) {
            isEmpty();
            return;
        }
        data = data->next;
    }


    void peek() { // displayed verhniy element
        if (!data) {
            isEmpty();
            return;
        }
        cout << "Current element in the stack: " << data->data << endl;
    }
};
