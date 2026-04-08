#include <iostream>
using namespace std;

class Node
{
    public : 
        int data;
        Node *next;
};

class LinkedList
{
    private:
        Node *first;
    public:
        LinkedList(){
            first = NULL;
        }
        LinkedList(int A[], int n){
            Node *last, *t;
            first = new Node();
            first->data = A[0];
            first->next = NULL;
            last = first;
            
            for(int i=1; i<n; i++){
                t = new Node();
                t->data = A[i];
                t->next = NULL;
                last->next = t;
                last = t;
            }
        }
        ~LinkedList(){
            Node *p = first;
            while(first){
                first = first->next;
                delete p;
                p = first;
            }
        }
        void display(){
            Node *p = first;
            while(p){
                cout<<p->data<<" ";
                p = p->next;
            }
            cout<<endl;
        }
        int length(){
            Node *p = first;
            int len = 0;
            while (p)
            {
                len++;
                p = p->next;
            }
            return len;
        }
        void insert(int index, int x){
            if(index < 0 && index > length()){
                cout<<"Invalid Indexes"<<endl;
                return ;
            }
            Node *p, *t = first;
            t = new Node();
            t->data = x;
            t->next = NULL;
            if(index == 0){
                t->next = first;
                first = t;
            }else{
                for(int i=0; i<index-1; i++){
                    p = p->next;
                }
                t->next = p->next;
                p->next = t;
            }
        }
        int del(int x){
            Node *p = first, *q = NULL;

            if(p->data == x){
                first = first->next;
                delete p;
            }
            else{
                while(p && p->data != x){
                    q = p;
                    p = p->next;
                }
                q->next = p->next;
                delete p;
            }
        }
};

class CircularLinkedList
{
    private: 
        Node *head;
    public:
        CircularLinkedList(){
            head = NULL;
        }
        CircularLinkedList(int A[], int n){
            Node *last = NULL;
            head = new Node();
            head->data = A[0];
            head->next = head;
            last = head;

            for(int i=1; i<n; i++){
                Node *temp = new Node();
                temp->data = A[i];
                temp->next = last->next;
                last->next = temp;
                last = temp;
            }
            // (last->next = head;only this is what makes it circular) -> wrong representation
        }
        ~CircularLinkedList(){
            if(!head)  
                return ;
            Node *p = head->next;
            while(p != head){
                Node *temp = p;
                p = p->next;
                delete temp;
            }
            delete head;
        }
        void display(){
            Node *p = head;
            do{
                cout<<p->data<<" ";
                p = p->next;
            }while(p != head);
            cout<<endl;
        }
        void recursive_display(){
            if(head == NULL) return;
            recursive_display_helper(head);
            cout<<endl;
        }
        void recursive_display_helper(Node *h){
            static int flag = 0;
            if(h != head || flag == 0){
                flag = 1;
                cout<<h->data<<" ";
                recursive_display_helper(h->next);
            }
            flag = 0;
        }
        int length(){
            Node *p = head;
            int len = 0;
            do{
                len++;
                p = p->next;
            }while(p != head);
            return len;
        }
        void insert(int index, int x){
            if(index < 0 || index > length()){
                cout<<"Invalid Index"<<endl;
                return ;
            }
            Node *p = head;
            Node *t = new Node();
            t->data = x;
            if(index == 0){
                if(head == NULL){
                    head = t;
                    head->next = head;
                }else{
                    t->next = head;
                    while(p->next != head)
                        p = p->next;
                    p->next = t;
                    head = t;
                }
            }else{
                for(int i=0; i<index - 1; i++){
                    p = p->next;
                }
                t->next = p->next;
                p->next = t;
            }
        }
        int del(int index){
            if(index < 0 || index > length()){
                cout<<"Invalid Index "<<endl;
                return -1;
            }
            if(head == NULL){
                cout<<"No linked list to delete"<<endl;
                return -1;
            }
            Node *q = head;
            int x;
            if(index == 0){
                while(q->next != head)
                    q = q->next;
                x = head->data;
                if(q == head){
                    delete head;
                    head = NULL;
                }else{
                    q->next = head->next;
                    delete head;
                    head = q->next;
                }
            }else{
                for(int i=0; i<index - 1; i++)
                    q = q->next;
                Node *p = q->next;
                q->next = p->next;
                x = p->data;
                delete p;
            }
            return x;
        }
};

int main() {
    int A[] = {1, 2, 3, 4, 5};
    int B[] = {10, 20, 50, 40, 30};

    LinkedList list1(A, 5);
    LinkedList list2(B, 5);
    list1.del(4);
    list2.insert(0, 60);
    list2.insert(4, 100);

    cout<<"Length 1 : "<<list1.length()<<endl;
    cout<<"Length 2 : "<<list2.length()<<endl;
    
    list1.display();
    list2.display();

    CircularLinkedList cl1(A, 5);
    cl1.display();
    cl1.recursive_display();
    cout<<cl1.length()<<endl;

    cl1.insert(5, 10);
    cl1.display();

    cl1.del(0);
    cl1.display();

    return 0;
}