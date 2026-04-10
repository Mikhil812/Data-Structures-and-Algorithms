#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class Queue{
    private:
        Node *front;
        Node *rear;
    public:
        Queue(){
            front = rear = NULL;
        }

        ~Queue(){
            while(front != NULL){
                Node *p = front;
                front = front->next;
                delete p;
            }
        }

        bool isEmpty(){
            if(front == NULL)
                return true;
            return false;
        }

        bool isFull(){
            Node *t = new Node;
            if(t == NULL)
                return true;
            return false;
        }

        void enqueue(int x){
            if(isFull()){
                cout<<"Queue is Full"<<endl;
                return ;
            }
            Node *t = new Node;
            t->data = x;
            t->next = NULL;
            if(isEmpty()){
                front = rear = t;
            }else{
                rear->next = t;
                rear = t;
            }
        }

        int dequeue(){
            if(isEmpty()){
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            Node *p = front;
            front = front->next;
            int x = p->data;
            delete p;
            return x;
        }

        void display(){
            Node *p = front;
            while(p != NULL){
                cout<<p->data<<" ";
                p = p->next;
            }
            cout<<endl;
        }
};

int main() {

    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();

    cout<<"Dequeued : "<<q.dequeue()<<endl;
    cout<<"Dequeued : "<<q.dequeue()<<endl;

    q.display();

    return 0;
}