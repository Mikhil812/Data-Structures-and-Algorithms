#include <iostream>
#include <cstring>
using namespace std;

template <class T>
class Node{
    public:
        T data;
        Node<T> *next;
};

template <class T>
class Stack{
    private:
        Node<T> *top;
    public:
        Stack() {
            top = nullptr;
        }   

        ~Stack() {
            Node<T> *p = top;
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

        T stackTop(){
            if(top == NULL){
                cout<<"Stack Empty"<<endl;
                return T();
            }
            return top->data;
        }

        void push(T x){
            Node<T> *t = new Node<T>();
            if(t==NULL){
                cout<<"Stack Overflow"<<endl;
                return ;
            }
            t->data = x;
            t->next = top;
            top = t;
        }
        
        T pop(){
            if(top == NULL){
                cout<<"Nothing in stack"<<endl;
                return T();
            }
            Node<T> *p = top;
            top = top->next;
            T x = p->data;
            delete p;
            return x;
        }

        T peek(int pos){
            Node<T> *p = top;
            for(int i=1; i<pos; i++){
                p = p->next;
                if(p == NULL){
                    cout<<"Invalid Position "<<endl;
                    return T();
                }
            }
            return p->data;
        }

        void display(){
            Node<T> *p = top;
            while(p != NULL){
                cout<<p->data<<endl;
                p = p->next;
            }
        }
};

bool is_Paranthesis_Balanced(char *exp){
    Stack<char> st;
    for(int i=0; exp[i] != '\0'; i++){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            st.push(exp[i]);
        }else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if(st.isEmpty()){
                cout<<"No closing bracket to pop, stack empty"<<endl;
                return false;
            }
            char x = st.pop();
            if((exp[i] == ')' && x == '(') || (exp[i] == '}' && x == '{') || (exp[i] == ']' && x == '[')){
                continue;
            }
            else
                return false;
        }
    }
    if(st.isEmpty()){
        cout<<"Balanced"<<endl;
        return true;
    }else{
        cout<<"Not Balanced"<<endl;
        return false;
    }
}

int isOperand(char x){
    if(x == '+' || x== '-' || x=='*' || x=='/' || x=='(' || x==')' || x=='^')
        return 0;
    else 
        return 1;
}

int out_precedence(char x){
    if(x == '+' || x== '-')
        return 1;
    else if(x == '*' || x=='/')
        return 3;
    else if(x == '^')
        return 6;
    else if(x == '(')
        return 7;
    else if(x == ')')
        return 0;
    return -1;
}

int in_precedence(char x){
    if(x == '+' || x== '-')
        return 2;
    else if(x == '*' || x=='/')
        return 4;
    else if(x == '^')
        return 5;
    else if(x == '(')
        return 0;
    return -1;
}

char * infix_to_postfix(char *infix){
    Stack<char> st;

    int i=0, j=0;
    char *postfix = new char[strlen(infix) + 1];
    while(infix[i] != '\0'){
        if(isOperand(infix[i])){
            postfix[j++] = infix[i++];
        }else{
            if(st.isEmpty() || out_precedence(infix[i]) > in_precedence(st.stackTop())){
                st.push(infix[i]);
                i++;
            }else if(out_precedence(infix[i]) == in_precedence(st.stackTop())){
                st.pop();  
                i++;
            }else{
                postfix[j] = st.pop();
                j++;
            }
        }
    }
    while(!st.isEmpty()){
        postfix[j++] = st.pop();
    }
    postfix[j] = '\0';                              
    return postfix;
}

int main() {
    // *********************** Stack ADT ***********************
    // Stack<float> st;
    // st.push(10);
    // st.push(20);
    // st.push(30);
    // st.push(40);

    // st.display();

    // cout<<"Popped : "<<st.pop()<<endl;
    // st.display();

    // cout<<"Peek : "<<st.peek(2)<<endl;

    // ********************* Parenthesis Matching *****************
    // char exp[] = "{(a+b) * [c+d]}";
    // cout<<"Paranthesis Balanced : "<<is_Paranthesis_Balanced(exp)<<endl;

    // ********************** Infix expression to postfix expression ***********
    char infix1[] = "a+b*c-d/e";
    char infix2[] = "((a+b)*c)-d^e^f";
    char *postfix = infix_to_postfix(infix2);
    cout<<"Infix Expression : "<<infix2<<endl;
    cout<<"Postfix Expression : "<<postfix<<endl;

    return 0;
}