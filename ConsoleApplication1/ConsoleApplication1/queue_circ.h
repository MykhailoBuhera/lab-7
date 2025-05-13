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
            front->next = front; // pershuy 
            front->prev = front; // �������, �� ������� ������� �� ����
        }
        else {
            // ����� �� �������, ������ ����� ������� � �����
            rear->next = new_node;
            new_node->prev = rear;
            new_node->next = front;  // ��'����� � ������ ���������
            front->prev = new_node;  // ��'����� ������ ������� � �����
            rear = new_node;         // ��������� rear
        }
    }

    // ������� ������� � ������� �����
    void dequeue() {
        if (!front) {
            cout << "Queue is empty" << endl;
            return;
        }

        if (front == rear) {
            // ���� � ���� ����� ���� �������
            front = rear = nullptr;
        }
        else {
            // ��������� front �� ��������� �������
            front = front->next;
            rear->next = front;  // ��������� ��'���� � rear
            front->prev = rear;  // ��������� ��'���� � front
        }
    }

    // ������ ������ �������
    void peek() {
        if (!front) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "1st element in the queue: " << front->data << endl;
    }

    // �������� �� �������� �����
    void display() const {
        if (!front) {
            cout << "Queue is empty" << endl;
            return;
        }

        auto current = front;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != front);  // �������� �� ����� ����� (������� �����)
        cout << endl;
    }
};

};