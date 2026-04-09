#include <iostream>
using namespace std;

class Queue{
    private:
        int size;
        int front;
        int rear;
        int *A;
    public:
        Queue(int size){
            this->size = size;
            this->front = this->rear = 0;
            this->A = new int[size];
        }

        ~Queue(){
            delete []A;
        }
        
        void enqueue(int x){
            if((rear+1)%size == front){
                cout<<"Queue Overflow"<<endl;
                return ;
            }
            rear = (rear+1)%size;
            A[rear] = x;
        }

        int dequeue(){
            if(front == rear){
                cout<<"Queue empty, can't delete"<<endl;
                return -1;
            }
            front = (front+1)%size;
            int x = A[front];
            return x;
        }

        void display(){
            int i=(front+1)%size;
            do{
                cout<<A[i]<<" ";
                i = (i+1)%size;
            }while(i != (rear+1)%size);
            cout<<endl;
        }
};

int main() {
    Queue q(6);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    cout<<"Dequeuing : "<<q.dequeue()<<endl;
    cout<<"Dequeuing : "<<q.dequeue()<<endl;
    cout<<"Dequeuing : "<<q.dequeue()<<endl;

    q.display();

    cout<<"Circular Queue: "<<endl;
    q.enqueue(100);
    q.enqueue(200);

    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue();
    
    q.display();

    return 0;
}