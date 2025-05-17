#include "stack.h"
#include <iostream>
using namespace std;

Stack::Stack() : capacity(10), top(0) {
    data = new int[capacity];
}

Stack::Stack(const Stack& other) : capacity(other.capacity), top(other.top) {
    data = new int[capacity];
    for (int i = 0; i < top; ++i) {
        data[i] = other.data[i];
    }
}

Stack& Stack::operator=(const Stack& other) {
    if (this != &other) {
        delete[] data;
        capacity = other.capacity;
        top = other.top;
        data = new int[capacity];
        for (int i = 0; i < top; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

Stack::~Stack() {
    delete[] data;
}

void Stack::resize() {
    capacity *= 2;
    int* newData = new int[capacity];
    for (int i = 0; i < top; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}

void Stack::push(int elem) {
    if (top == capacity) {
        resize();
    }
    data[top++] = elem;
}

int Stack::pop() {
    if (isEmpty()) {
        cout << "Stack is empty.\n";
        return -1;
    }
    return data[--top];
}

bool Stack::isEmpty() const {
    return top == 0;
}

int Stack::multiPop(int N) {
    int count = 0;
    while (!isEmpty() && count < N) {
        pop();
        ++count;
    }
    return count;
}

void Stack::show() const {
    for (int i = 0; i < top; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;
}

