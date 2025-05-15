#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <memory>
#include <exception>

using namespace std;

template <typename T>
class Stack {
private:
    int top;          // Індекс верхнього елемента в масиві (покажчик, де вставляти наступний елемент)
    int m_size;       // Кількість елементів, що знаходяться в стеку
    T m_stackArr[100]; // Фіксований масив для зберігання елементів стеку (максимум 100 елементів)

public:
    // Конструктор: ініціалізує top та m_size нулями, а масив очищує (за допомогою {}).
    Stack() : top{ 0 }, m_size{ 0 }, m_stackArr{} {};

    // Додає елемент у стек
    void pushWithArray(T value) {
        // Перевіряємо, чи не вийшли за межі розміру стеку
        if (top < m_size)
            throw out_of_range("top beyond");  // Помилка: індекс top не має бути меншим за m_size (логічна помилка у коді, див нижче)
        else {
            m_stackArr[top] = value;  // Додаємо значення в масив на позицію top
            top++;                   // Зсуваємо індекс top на наступну позицію
            m_size++;                // Збільшуємо лічильник розміру стеку
        }
    };

    // Перевіряємо, чи стек порожній (якщо так — кидаємо виключення)
    void isEmpty() {
        if (m_size <= 0)
            throw out_of_range("stack is empty");
    }

    // Видаляємо верхній елемент зі стеку
    void popWithArray() {
        if (top > 0) {
            --top;              // Зсуваємо top назад (логічно видаляємо елемент)
            m_stackArr[top];    // Цей рядок нічого не робить — можна видалити (не має сенсу)
            m_size--;           // Зменшуємо розмір стеку
        }
        else
            throw out_of_range("Stack is empty");  // Помилка: не можна видалити з пустого стеку
    }

    // Показати верхній елемент стеку
    void peek() {
        cout << m_stackArr[top - 1] << " Peek is called "; // Виводимо елемент у верху стеку
    }

    // Перевіряємо, чи стек заповнений
    void isFull() {
        if (m_size >= 100)
            throw out_of_range("stack is full");
    }

    // Перевантаження оператора виводу для друку стеку
    friend ostream& operator<<(ostream& os, const Stack<T>& obj) {
        for (int i = 0; i < obj.m_size; i++) {
            os << obj.m_stackArr[i] << " ";  // Виводимо всі елементи стеку
        }
        return os;
    }
};

#endif
