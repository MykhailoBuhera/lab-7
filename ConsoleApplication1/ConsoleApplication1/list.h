#pragma once
#include <iostream>
#include <memory>
#include "Node.h"

using namespace std;

template <typename Type>
class list {
private:
    shared_ptr<Node<Type>> data; // створенні обєкту класу створюється перша змінна яка містить рядок для значеннята дварядки для посилання.

public:
    void push_back(Type value) {
        auto new_node = make_shared<Node<Type>>(value);
        if (!data) {
            data = new_node;
            return;
        }
        auto current = data;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }

    void push_front(Type value) {
        auto new_node = make_shared<Node<Type>>(value); // Створюється новий обєктякому назначається передана змінна value
        new_node->next = data; // Вказівник next новоствореного обєкту node вказує на попередньо створену зміннуАдресу                                     
        data = new_node; // Перевизначаємо вказівник data та вказуємо що тепер першим елементом списку є node
    }

    bool empty() {
        if (!data) return true;
        else return false;
    }

    void pop_front() {
        if (!data) {
            cout << "List is empty!" << endl;
            return;
        }
        data = data->next;
    }

    void pop_back() {
        auto current = data;
        while (current->next) {
            current = current->next;
        }
        current = nullptr;
    }
    
    int rozm()
    {
        auto current = data;
        int count = 0;
        while (current)
        {
            current = current->next;
            count++;
        }
        return count;
    }
    bool search(Type value)
    {
        auto current = data;
        while (current)
        {
            if (current->data == value)
            {
                return true;
            }
        }
        return false;
    }

         

    void print() const {
        auto current = data;
        while (current)
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
    
    
    friend ostream& operator <<(ostream& os, const list<Type> list) {
        auto current = list.data;
        while (current) {
            os << current->data << " -> ";
            current = current->next;
        }
        os << "nullptr";
        return os;
    }
    Type  ind(int index)
    {
        if (index < 0 )
        {
            cout << "tu debil index ne mozche bytu menshum za null" << endl;
        }
        auto current = data;
        int i = 0;
        while (current)
        {
            if (i == index)
            {
                return current->data;
                
            }
            current = current->next;
            i++;
        }
    }
    void insert(int index, Type value) {
        if (index < 0) {
            cout << "Index cannot be negative." << endl;
            return;
        }

        auto new_node = make_shared<Node<Type>>(value);

        if (index == 0) {
            new_node->next = data;
            data = new_node;
            return;
        }

        auto current = data;
        int i = 0;
        while (current && i < index - 1) {
            current = current->next;
            i++;
        }

        if (!current) {
            cout << "Index out of bounds." << endl;
            return;
        }

        new_node->next = current->next;
        current->next = new_node;
    }
    void erase(int index) {
        if (index < 0 || !data) {
            cout << "Invalid index or empty list." << endl;
            return;
        }

        if (index == 0) {
            data = data->next;
            return;
        }

        auto current = data;
        int i = 0;
        while (current->next && i < index - 1) {
            current = current->next;
            i++;
        }

        if (!current->next) {
            cout << "Index out of bounds." << endl;
            return;
        }

        current->next = current->next->next;
    }

    // запитаттся чи це та сама функція прінт і чи для потворення каоду про перегрузку оператора
};
