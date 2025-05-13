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
            new_node->next = front;  // Зв'язуємо з першим елементом
            front->prev = new_node;  // Зв'язуємо перший елемент з новим
            rear = new_node;         // Оновлюємо rear
        }
    }

    // Видаляє елемент з початку черги
    void dequeue() {
        if (!front) {
            cout << "Queue is empty" << endl;
            return;
        }

        if (front == rear) {
            // Якщо в черзі тільки один елемент
            front = rear = nullptr;
        }
        else {
            // Переміщаємо front на наступний елемент
            front = front->next;
            rear->next = front;  // Оновлюємо зв'язок з rear
            front->prev = rear;  // Оновлюємо зв'язок з front
        }
    }

    // Показує перший елемент
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