#pragma once
#include "Node.h"
#include <iostream>
#include <memory>

using namespace std;
template <typename Type>
class queue
{
	private:
		shared_ptr<Node<Type>> data;

	public:
        void enqueue(Type value) {
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
        void dequeue() {
            if (!data) {
                cout << "Queue is empty" << endl;
                return;
            }
            data = data->next; //shared ptr sam vudaluti kolu zanylutsa i cherez ce ne byde vutoky
        }


};

