#include <iostream>
using namespace std;

class Node
{
    public:
        Node *prev;
        int data;
        Node *next;
};

class DoublyLinkedList
{
    private:
        Node *head;
        Node *last;
    public:
        DoublyLinkedList(){
            head = NULL;
            last = NULL;
        }
        DoublyLinkedList(int A[], int n){
            head = new Node();
            head->prev = NULL;
            head->data = A[0];
            head->next = NULL;

            last = head;
            for(int i=1; i<n; i++){
                Node *temp = new Node();
                temp->prev = last;
                temp->data = A[i];
                temp->next = last->next;
                last->next = temp;
                last = temp;
            }
        }
        ~DoublyLinkedList(){
            Node *p = head;
            while(head != NULL){
                head = head->next;
                delete p;
                p = head;
            }
        }
        void display(){
            Node *p = head;
            while(p != NULL){
                cout<<p->data<<" ";
                p = p->next;
            }
            cout<<endl;
        }
        int length(){
            Node *p = head;
            int len = 0;
            while(p != NULL){
                len++;
                p = p->next;
            }
            return len;
        }
        void insert(int index, int x){
            if(index < 0 || index > length()){
                cout<<"Invalid Index"<<endl;
                return ;
            }
            Node *temp = new Node;
            temp->prev = NULL;
            temp->data = x;
            if(index == 0){
                if(head == NULL){
                    head = temp;
                    head->next = NULL;
                }else{
                    temp->next = head;
                    head->prev = temp;
                    head = temp;
                }
            }else{
                Node *p = head;
                for(int i=0; i<index-1;i++){
                    p = p->next;
                }
                temp->prev = p;
                temp->next = p->next;
                if(p->next != NULL)
                    p->next->prev = temp;
                p->next = temp;
            }
        }
        int del(int index){
            if(index < 0 || index > length()){
                cout<<"Invalid Index"<<endl;
                return -1;
            }
            Node *p = head;
            int x;
            if(index == 0){
                if(head == NULL){
                    cout<<"No node in the list to delete"<<endl;
                }else{
                    x = head->data;
                    if(head->next){
                        head = head->next;
                        head->prev = NULL;
                    }
                    delete p;
                }
            }else{
                for(int i=0; i<index; i++){
                    p = p->next;
                }
                x = p->data;
                Node *q = p->prev;
                q->next = p->next;
                if(p->next){
                    p->next->prev = q;
                }
                delete p;
            }
            return x;
        }
        void reverse(){
            Node *p = head;
            Node *temp;
            while(p){
                temp = p->next;
                p->next = p->prev;
                p->prev = temp;
                p = p->prev;

                if(p!=NULL && p->next == NULL)
                    head = p;
            }
        }
};

class CircularDoublyLinkedList
{
    private:
        Node *head;
        Node *last;
    public:
        CircularDoublyLinkedList(){
            head = NULL;
            last = NULL;
        }

        CircularDoublyLinkedList(int A[], int n){
            head = new Node();
            head->prev = head;
            head->data = A[0];
            head->next = head;
            last = head;

            for(int i=1; i<n; i++){
                Node *temp = new Node();
                temp->data = A[i];
                temp->prev = last;
                temp->next = head;  // or temp->next = last->next;
                last->next = temp;
                head->prev = temp;
                last = temp;
            }
        }

        ~CircularDoublyLinkedList(){
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

        void debug_display(){
            if(head == NULL){
                cout << "List is empty\n";
                return;
            }

            Node *p = head;
            do{
                cout << "[" << p->data << "]";
                p = p->next;
                if(p != head)
                    cout << " <-> ";
            }while(p != head);
            cout << "\n";
            // Show circular connection
            cout << "Head: " << head->data 
                << " | Head->prev: " << head->prev->data << "\n";
            cout << "Last: " << last->data 
                << " | Last->next: " << last->next->data << "\n";
            cout<<endl;
        }

        void insert(int index, int x){
            Node *temp = new Node();
            temp->data = x;
            if(index == 0){
                if(head == NULL){
                    temp->next = temp;
                    temp->prev = temp;
                    head = temp;
                    last = temp;
                }else{
                    temp->next = head;
                    head->prev = temp;
                    last->next = temp;
                    temp->prev = last;
                    head = temp;
                }
            }else{
                Node *p = head;
                for(int i=0; i<index - 1; i++)
                    p = p->next;
                
                temp->next = p->next;
                p->next->prev = temp;
                temp->prev = p;
                p->next = temp;
                if(temp->next == head)
                    last = temp;
            }
        }
};

int main() {
    int A[] = {10, 20, 50, 30, 40};

    // DoublyLinkedList l1(A, 5);
    // l1.display();

    // l1.insert(0, -1);
    // l1.display();

    // cout<<l1.del(0)<<endl;
    // l1.display();

    // l1.reverse();
    // l1.display();

    CircularDoublyLinkedList cl1(A, 5);
    // cl1.display();
    cl1.debug_display();

    cl1.insert(5, 100);
    cl1.debug_display();

    cl1.insert(0, -1);
    cl1.debug_display();

    CircularDoublyLinkedList cl2;
    cl2.insert(0, 2);

    cl2.debug_display();

    return 0;
}