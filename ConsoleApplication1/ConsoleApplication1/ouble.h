#pragma once
#include <iostream>
#include <memory>
#include "Node.h"

using namespace std;

template <typename Type>
class double_linlked_list {
private:
    shared_ptr<Node<Type>> head;
    shared_ptr<Node<Type>> tail;

public:
    void push_back(Type value) {
        auto new_node = make_shared<Node<Type>>(value);
        if (!head) {
            head = tail = new_node;
        }
        else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }
 
    void push_front(Type value) {
        auto new_node = make_shared<Node<Type>>(value);
        if (!head) {
            head = tail = new_node;
        }
        else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }

    void pop_front() {
        if (!head) return;
        head = head->next;
        if (head) head->prev.reset();
        else tail.reset();
    }

    void pop_back() {
        if (!tail) return;
        tail = tail->prev.lock();
        if (tail) tail->next.reset();
        else head.reset();
    }

    void insert(int index, Type value) {
        if (index < 0) {
            cout << "Invalid index\n";
            return;
        }

        if (index == 0) {
            push_front(value);
            return;
        }

        auto current = head;
        int i = 0;
        while (current && i < index - 1) {
            current = current->next;
            i++;
        }

        if (!current) {
            cout << "Index out of border\n";
            return;
        }

        auto new_node = make_shared<Node<Type>>(value);
        new_node->next = current->next;
        if (current->next) current->next->prev = new_node;
        new_node->prev = current;
        current->next = new_node;

        if (!new_node->next) tail = new_node;
    }

    void erase(int index) {
        if (index < 0 || !head) {
            cout << "ne mozhe index bytu menshum null\n";
            return;
        }

        if (index == 0) {
            pop_front();
            return;
        }

        auto current = head;
        int i = 0;
        while (current && i < index) {
            current = current->next;
            i++;
        }

        if (!current) {
            cout << "Index out of bounds\n";
            return;
        }

        auto prev_node = current->prev.lock();
        if (current->next) current->next->prev = prev_node;
        if (prev_node) prev_node->next = current->next;

        if (!current->next) tail = prev_node;
    }

    void print() const {
        auto current = head;
        while (current) {
            cout << current->data << " <-> ";
            current = current->next;
        }
        cout << "nullptr\n";
    }

    int size() const {
        int count = 0;
        auto current = head;
        while (current) {
            count++;
            current = current->next;
        }
        return count;
    }
};
