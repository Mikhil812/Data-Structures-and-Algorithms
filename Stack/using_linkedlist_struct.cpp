#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*top=NULL;

void push(int x){
    Node *t = new struct Node();
    if(t==NULL){
        cout<<"Stack Overflow"<<endl;
        return ;
    }
    t->data = x;
    t->next = top;
    top = t;
}

int pop(){
    if(top == NULL){
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

int main() {
    push(10);
    push(20);
    push(30);
    push(40);

    display();

    cout<<"Popped : "<<pop()<<endl;
    display();

    cout<<"Peek : "<<peek(2)<<endl;

    return 0;
}