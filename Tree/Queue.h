# pragma once
# include "Node.h"

class Queue{
    private:
        int size;
        int front;
        int rear;
        Node **A;
    public:
        Queue(int size);
        ~Queue();

        bool isEmpty();
        bool isFull();

        void enqueue(Node* x);
        Node* dequeue();
};