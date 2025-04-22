#pragma once
#include <memory>

using namespace std;

template <typename Type>
struct Node {
    Type data; // Змінна, в якій записується значення.
    shared_ptr<Node<Type>> next; // Посилання на наступний елемент в листі.
    shared_ptr<Node<Type>> previous;

    Node(Type value) : data(value), next(nullptr), previous(nullptr) {}
};
