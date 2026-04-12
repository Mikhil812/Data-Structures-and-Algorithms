#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class Stack{
    private:
        Node *top;
    public:
        Stack() {
            top = nullptr;
        }   

        ~Stack() {
            Node* p = top;
            while (top){
                top = top->next;
                delete p;
                p = top;
            }
        }

        bool isEmpty(){
            if(top == NULL)
                return true;
            return false;
        }

        bool isFull(){
            Node *t = new Node();
            if(t==NULL)
                return true;
            return false;
        }

        void push(int x){
            if(isFull()){
                cout<<"Stack Overflow"<<endl;
                return ;
            }
            Node *t = new Node();
            t->data = x;
            t->next = top;
            top = t;
        }
        
        int pop(){
            if(isEmpty()){
                cout<<"Nothing in stack"<<endl;
                return -1;
            }
            Node *p = top;
            top = top->next;
            int x = p->data;
            delete p;
            return x;
        }

        int peek(int pos){
            Node *p = top;
            for(int i=1; i<pos; i++){
                p = p->next;
                if(p == NULL){
                    cout<<"Invalid Position "<<endl;
                    return -1;
                }
            }
            return p->data;
        }

        void display(){
            Node *p = top;
            while(p != NULL){
                cout<<p->data<<" ";
                p = p->next;
            }
        }

        void display_reverse(){
            recursive_reverse_display(top);
            cout<<endl;
        }

        Node * recursive_reverse_display(Node *p){
            if(p == NULL){
                return NULL ;
            }
            recursive_reverse_display(p->next);
            cout<<p->data<<" ";
        }
};

class Queue{
    private :
        Stack st1;
        Stack st2;  
    public:
        Queue(){

        }

        ~Queue(){

        }

        void enqueue(int x){
            st1.push(x);
        }

        int dequeue(){
            if(st2.isEmpty()){
                if(st1.isEmpty()){
                    cout<<"Queue is Empty"<<endl;
                    return -1;
                }else{
                    while(!st1.isEmpty()){
                        st2.push(st1.pop());
                    }
                }
            }
            return st2.pop();
        }

        void display(){
            if(st1.isEmpty() && st2.isEmpty()){
                cout<<"Queue is empty"<<endl;
                return ;
            }
            st2.display();
            st1.display_reverse();
        }

};

int main() {

    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    cout<<"Dequeued : "<<q.dequeue()<<endl;
    cout<<"Dequeued : "<<q.dequeue()<<endl;

    q.display();

    q.enqueue(60);
    q.enqueue(70);

    q.display();

    return 0;
}