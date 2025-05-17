// stack.h
#ifndef STACK_H
#define STACK_H

class Stack {
private:
    int* data;
    int capacity;
    int top;

    void resize();

public:
    Stack();
    Stack(const Stack& other);              // Copy constructor
    Stack& operator=(const Stack& other);   // Copy assignment
    ~Stack();

    void push(int elem);
    int pop();
    bool isEmpty() const;
    int multiPop(int N);
    void show() const;
};
#endif
