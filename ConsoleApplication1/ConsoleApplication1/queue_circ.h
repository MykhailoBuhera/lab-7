#pragma once
#include "Node.h"
#include <iostream>
#include <memory>

using namespace std;

template <typename Type>
class queue_circ
{
private:
    shared_ptr<Node<Type>> front;  // start queue
    shared_ptr<Node<Type>> rear;   // end queue

public:

    void enqueue(Type value) {
        auto new_node = make_shared<Node<Type>>(value);

        if (!front) {
            front = rear = new_node;
            front->next = front; // pershuy elemnt vkazye sam na sebe
            front->prev = front; // ostaniy element takoz sam nna sebe
        }
        else {
            rear->next = new_node;
            new_node->prev = rear;
            new_node->next = front;  // zvyazyyem z start
            front->prev = new_node;  // zvayazyyemo start z cum elementom
            rear = new_node;         // update end element
        }
    }

    // zaburaye element z pochatky chergu
    void dequeue() {
        if (!front) {
            cout << "Queue is empty" << endl;
            return;
        }

        if (front == rear) {
            // if only one element we make all null
            front = rear = nullptr;
        }
        else {
            // if a lot of elemnts we go to next element and make it first
            front = front->next;
            rear->next = front;  // update link z start
            front->prev = rear;  // botk but with end
        }
    }

    // vuvedenya elementy satrt
    void peek() {
        if (!front) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "1st element in the queue: " << front->data << endl;
    }

    // Виводить всі елементи черги
    void display() const {
        if (!front) {
            cout << "Queue is empty" << endl;
            return;
        }

        auto current = front;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != front);  // Перевірка на кінець черги (кругова черга)
        cout << endl;
    }
};

};