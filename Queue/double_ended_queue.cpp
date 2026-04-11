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

        void insert_from_rear(int x){
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

        void insert_from_front(int x){
            if(isFull()){
                cout<<"Queue is FUll"<<endl;
                return ;
            }
            Node *t = new Node();
            t->data = x;
            if(isEmpty()){
                t->next = NULL;
                front = rear = t;
            }else{
                t->next = front;
                front = t;
            }
        }

        int delete_from_front(){
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

        int delete_from_rear(){
            if(isEmpty()){
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            int x;
            Node *p = front;
            if(p == rear){
                x = rear->data;  
                front = rear = NULL;    
            }else{
                while(p->next != rear)
                    p = p->next;
                p->next = NULL;
                x = rear->data;
                delete rear;
                rear = p;
            }
            
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
    q.insert_from_rear(10);
    q.insert_from_rear(20);
    q.insert_from_rear(30);
    q.insert_from_rear(40);

    q.display();

    cout<<"Deleted from front : "<<q.delete_from_front()<<endl;
    cout<<"Deleted from front : "<<q.delete_from_front()<<endl;

    q.display();

    q.insert_from_front(200);
    q.insert_from_front(150);

    q.display();

    q.delete_from_rear();
    q.delete_from_rear();
    q.delete_from_rear();
    q.delete_from_rear();

    q.display();

    return 0;
}