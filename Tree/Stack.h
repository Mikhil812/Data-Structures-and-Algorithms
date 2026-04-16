#pragma once
#include <iostream>
using namespace std;

template <class T>
class Stack{
private:
    int size;
    int top;
    T *A;

public:
    Stack(int size){
        top = -1;
        this->size = size;
        A = new T[size];
    }

    ~Stack(){
        delete []A;
    }

    void display(){
        for(int i = top; i >= 0; i--){
            cout << A[i] << endl;
        }
    }

    void push(T x){
        if(top == size - 1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        A[++top] = x;
    }

    T pop(){
        if(top == -1){
            cout<<"Stack Empty"<<endl;
            return T();  
        }
        return A[top--];
    }

    T peek(int pos){
        if(top - pos + 1 < 0){
            cout<<"Invalid Index"<<endl;
            return T();
        }
        return A[top - pos + 1];
    }

    T stackTop(){
        if(top == -1){
            cout<<"Stack Empty"<<endl;
            return T();
        }
        return A[top];
    }

    bool isEmpty(){
        return top == -1;
    }

    bool isFull(){
        return top == size - 1;
    }
};