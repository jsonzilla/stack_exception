#ifndef STACK_H
#define STACK_H

#include <stdexcept>

template<class T = int>
class Stack {
private:
    unsigned nelems; //not initialized
    int top; //not initialized
    T* v; //not initialized
public:
    unsigned count() {
        return top + 1;
    }

    void push(T element) {
        top++;
        if (top == nelems - 1) {
            T* new_buffer = new T[nelems += 10];
            if (new_buffer == 0)
                throw std::exception("out of memory");
            for (int i = 0; i < top; i++)
                new_buffer[i] = v[i];
            delete[] v;
            v = new_buffer;
        }
        v[top] = element;
    }

    T pop() {
        if (top < 0)
            throw std::exception("pop on empty stack");
        return v[top--];
    }

    Stack() {
        top = -1;
        v = new T[nelems = 10];
        if (v == 0)
            throw std::exception("out of memory");
    }

    Stack(const Stack& s) {
        v = new T[nelems = s.nelems];
        if (v == 0)
            throw std::exception("out of memory");
        if (s.top > -1) {
            for (top = 0; top <= s.top; top++) {
                v[top] = s.v[top];
            }
            top--;
        }
    }

    ~Stack() {
        delete[] v;
    }

    Stack& operator=(const Stack& s) {
        delete[] v;
        v = new T[nelems = s.nelems];
        if (v == 0) {
            throw std::exception("out of memory");
        }
        if (s.top > -1) {
            for (top = 0; top <= s.top; top++) {
                v[top] = s.v[top];
            }
            top--;
        }
        return *this;
    }
};

#endif // !STACK_H