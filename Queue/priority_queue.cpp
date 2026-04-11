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

class PriorityQueue{
    private:
        int n;
        Queue *A;
    public:
        PriorityQueue(int n){
            this->n = n;
            A = new Queue[n];
        }

        ~PriorityQueue(){
            delete []A;
        }

        void enqueue(int priority, int data){
            if(priority<=0 || priority>n){
                cout<<"Invalid priority"<<endl;
                return ;
            }
            A[priority-1].enqueue(data);
        }

        int dequeue(){
            if(isEmpty()){
                return -1;
            }
            for(int i=0; i<n; i++){
                if(A[i].isEmpty()){
                    continue;
                }else{
                    int x = A[i].dequeue();
                    return x;
                };
            }
            return -1;
        }

        bool isEmpty(){
            for(int i=0; i<n; i++){
                if(!A[i].isEmpty())
                    return false;
            }
            cout<<"Priority Queue is empty"<<endl;
            return true;
        }

        void display(){
            for(int i=0; i<n; i++){
                cout<<"p"<<i+1<<" : ";
                A[i].display();
            }
        }
};

int main() {
    PriorityQueue pq(3);

    pq.enqueue(1, 20);
    pq.enqueue(2, 30);
    pq.enqueue(1, 10);
    pq.enqueue(2, 40);
    pq.enqueue(2, 50);
    pq.enqueue(3, 60);

    pq.display();

    pq.dequeue();
    pq.dequeue();
    pq.dequeue();
    pq.dequeue();
    pq.dequeue();
    pq.dequeue();

    pq.display();
    
    return 0;
}