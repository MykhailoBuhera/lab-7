#pragma once
#include <memory>

using namespace std;

template <typename Type>
struct Node {
    Type data; // �����, � ��� ���������� ��������.
    shared_ptr<Node<Type>> next; // ��������� �� ��������� ������� � ����.
    shared_ptr<Node<Type>> prev;

    Node(Type value) : data(value), next(nullptr), prev(nullptr) {}
};
