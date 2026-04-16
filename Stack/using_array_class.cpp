#include <iostream>
using namespace std;

class Stack{
    private:
        int size;
        int top;
        int *A;
    public: 
        Stack(int size){
            top = -1;
            this->size = size;
            A = new int[size];
        }
        ~Stack(){
            delete []A;
        }
        void display();
        void push(int x);
        int pop();
        int peek(int pos);
        int stackTop();
        bool isEmpty();
        bool isFull();
};

void Stack :: display(){
    for(int i=top; i>=0; i--){
        cout<<A[i]<<endl;
    }
}

void Stack :: push(int x){
    if(top == size - 1){
        cout<<"Stack Overflow"<<endl;
        return;
    }
    top++;
    A[top] = x;
}

int Stack :: pop(){
    if(top == -1){
        cout<<"Stack Empty"<<endl;
        return -1;
    }
    int x = A[top];
    top--;
    return x;
}

int Stack :: peek(int pos){
    if(top - pos + 1 < 0 || top-pos+1 > size){
        cout<<"Invalid Index"<<endl;
        return -1;
    }
    int x = A[top - pos + 1];
    return x;
}

int Stack :: stackTop(){
    if(top == -1){
        cout<<"Stack is Empty"<<endl;
        return -1;
    }
    return A[top];
}

bool Stack :: isEmpty(){
    if(top == -1){
        cout<<"Stack is empty"<<endl;
        return true;
    }
    return false;
}

bool Stack :: isFull(){
    if(top == size - 1){
        cout<<"Stack is Full"<<endl;
        return true;
    }
    return false;
}

int main() {
    Stack st(5);

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    cout<<"Displaying : "<<endl;
    st.display();

    cout<<"Popped : "<<st.pop()<<endl;
    st.display();

    cout<<"Peek : "<<st.peek(3)<<endl;
    cout<<"Top : "<<st.stackTop()<<endl;
    cout<<"Is Empty : "<<st.isEmpty()<<endl;
    cout<<"Is Full : "<<st.isFull()<<endl;

    return 0;
}