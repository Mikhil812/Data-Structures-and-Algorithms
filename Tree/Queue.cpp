#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue(int size){
    this->size = size;
    front = rear = 0;
    A = new Node*[size];
}

Queue::~Queue(){
    delete []A;
}

bool Queue::isEmpty(){
    return front == rear;
}

bool Queue::isFull(){
    return (rear+1)%size == front;
}

void Queue::enqueue(Node* x){
    if(isFull()){
        cout<<"Queue Overflow"<<endl;
        return;
    }
    rear = (rear+1)%size;
    A[rear] = x;
}

Node* Queue::dequeue(){
    if(isEmpty()){
        cout<<"Queue empty"<<endl;
        return nullptr;
    }
    front = (front+1)%size;
    return A[front];
}