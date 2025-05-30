#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <memory>
#include <exception>

using namespace std;

template <typename T>
class Stack {
private:
    int top;          // ������ ��������� �������� � ����� (��������, �� ��������� ��������� �������)
    int m_size;       // ʳ������ ��������, �� ����������� � �����
    T m_stackArr[100]; // Գ�������� ����� ��� ��������� �������� ����� (�������� 100 ��������)

public:
    // �����������: ��������� top �� m_size ������, � ����� ����� (�� ��������� {}).
    Stack() : top{ 0 }, m_size{ 0 }, m_stackArr{} {};

    // ���� ������� � ����
    void pushWithArray(T value) {
        // ����������, �� �� ������ �� ��� ������ �����
        if (top < m_size)
            throw out_of_range("top beyond");  // �������: ������ top �� �� ���� ������ �� m_size (������ ������� � ���, ��� �����)
        else {
            m_stackArr[top] = value;  // ������ �������� � ����� �� ������� top
            top++;                   // ������� ������ top �� �������� �������
            m_size++;                // �������� �������� ������ �����
        }
    };

    // ����������, �� ���� �������� (���� ��� � ������ ����������)
    void isEmpty() {
        if (m_size <= 0)
            throw out_of_range("stack is empty");
    }

    // ��������� ������� ������� � �����
    void popWithArray() {
        if (top > 0) {
            --top;              // ������� top ����� (������ ��������� �������)
            m_stackArr[top];    // ��� ����� ������ �� ������ � ����� �������� (�� �� �����)
            m_size--;           // �������� ����� �����
        }
        else
            throw out_of_range("Stack is empty");  // �������: �� ����� �������� � ������� �����
    }

    // �������� ������� ������� �����
    void peek() {
        cout << m_stackArr[top - 1] << " Peek is called "; // �������� ������� � ����� �����
    }

    // ����������, �� ���� ����������
    void isFull() {
        if (m_size >= 100)
            throw out_of_range("stack is full");
    }

    // �������������� ��������� ������ ��� ����� �����
    friend ostream& operator<<(ostream& os, const Stack<T>& obj) {
        for (int i = 0; i < obj.m_size; i++) {
            os << obj.m_stackArr[i] << " ";  // �������� �� �������� �����
        }
        return os;
    }
};

#endif
