#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        struct Node *next;
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
                cout<<p->data<<endl;
                p = p->next;
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
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    st.display();

    cout<<"Popped : "<<st.pop()<<endl;
    st.display();

    cout<<"Peek : "<<st.peek(2)<<endl;

    return 0;
}