#include <iostream>
using namespace std;

struct stack{
    int size;
    int top;
    int *A;
};

void create(struct stack *st){
    cout<<"Enter size of the stack : "<<endl;
    cin>>st->size;
    st->top = -1;
    st->A = new int[st->size];
}

void display(struct stack st){
    for(int i=st.top; i>=0; i--){
        cout<<st.A[i]<<endl;
    }
}

void push(struct stack *st, int x){
    if(st->top == st->size - 1){
        cout<<"Stack Overflow"<<endl;
        return;
    }
    st->top++;
    st->A[st->top] = x;
}

int pop(struct stack *st){
    if(st->top == -1){
        cout<<"Stack Empty"<<endl;
        return -1;
    }
    int x = st->A[st->top];
    st->top--;
    return x;
}

int peek(struct stack st, int pos){
    if(st.top - pos + 1 < 0 || st.top-pos+1 > st.size){
        cout<<"Invalid Index"<<endl;
        return -1;
    }
    int x = st.A[st.top - pos + 1];
    return x;
}

int stackTop(struct stack st){
    if(st.top == -1){
        cout<<"Stack is Empty"<<endl;
        return -1;
    }
    return st.A[st.top];
}

bool isEmpty(struct stack st){
    if(st.top == -1){
        cout<<"Stack is empty"<<endl;
        return true;
    }
    return false;
}

bool isFull(struct stack st){
    if(st.top == st.size - 1){
        cout<<"Stack is Full"<<endl;
        return true;
    }
    return false;
}

int main() {
    struct stack st;
    create(&st);
    cout<<"Displaying : "<<endl;
    display(st);

    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);

    cout<<"Popped : "<<pop(&st)<<endl;
    display(st);

    cout<<"Peek : "<<peek(st, 3)<<endl;
    cout<<"Top : "<<stackTop(st)<<endl;
    cout<<"Is Empty : "<<isEmpty(st)<<endl;
    cout<<"Is Full : "<<isFull(st)<<endl;

    return 0;
}