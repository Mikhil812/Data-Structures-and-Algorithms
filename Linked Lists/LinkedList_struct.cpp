#include <iostream>
#include <climits>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*first = NULL, *second = NULL, *third = NULL;
struct Node *last = NULL;

void create(int A[], int n){
    struct Node *t, *last;
    first = new struct Node();
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i=1; i<n; i++){
        t = new struct Node();
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void create_2(int A[], int n){
    struct Node *t, *last;
    second = new struct Node();
    second->data = A[0];
    second->next = NULL;
    last = second;

    for(int i=1; i<n; i++){
        t = new struct Node();
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p){
    while (p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }    
    cout<<endl;
}

void recursive_display(struct Node *p){
    if(p == NULL)
        return ;
    cout<<p->data<<" ";
    recursive_display(p->next);
}

int count(struct Node *p){
    int count = 0;
    while(p != NULL){
        count = count + 1;
        p = p->next;
    }
    return count;
}

int recursive_count(struct Node *p){
    if(p == NULL)
        return 0;
    return 1 + recursive_count(p->next);
}

int sum(struct Node *p){
    int sum = 0;
    while(p != NULL){
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int recursive_sum(struct Node *p){
    if(p == NULL)
        return 0;
    return  p->data + recursive_sum(p->next);
}

int max(struct Node *p){
    int max = INT_MIN;
    while(p){
        if(p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

int recursive_max(struct Node *p){
    int x;
    if(p == NULL)
        return INT_MIN;
    x = recursive_max(p->next);
    return x > p->data ? x : p->data;
}

Node*search(struct Node *p, int key){
    struct Node *q = NULL;          // This is a prev pointer for following p
    while(p != NULL){
        if(p->data == key){
            q->next = p->next;      // There were 2 methods to improve linear search
            p->next = first;        // in arrays : Transposition and Move to Head
            first = p;              // This implementation is move to head.

            return p;
        }
        q = p;
        p = p->next;
    }
    cout<<"Node doesn't exist."<<endl;
    return NULL;
}

Node *recursive_search(struct Node *p, int key){
    if(p->data == key)
        return p;
    if(p == NULL)
        return NULL;
    return recursive_search(p->next, key);
}

void insert(struct Node *p, int index, int data){
    if(index < 0 || index > count(p)){
        cout<<index<<endl;
        cout<<"Invalid Index "<<endl;
        return ;
    }
    Node *temp = new Node();
    temp->data = data;

    if(index == 0){
        temp->next = first;
        first = temp;
    }else{
        for(int i=0; i<index - 1; i++){
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;
    }
}

void append(int x){
    Node *t = new Node();
    t->data = x;
    t->next = NULL;

    if(first == NULL){
        first = last = t;
    }else{
        last->next = t;
        last = t;
    }
}

void sorted_insert(struct Node *p, int x){
    struct Node *q = NULL;
    struct Node *t = new Node();
    t->data = x;

    if(p == NULL){
        t->next = NULL;
        first = t;
    }
    else{
        while(p && p->data < x){
            q = p;
            p = p->next;
        }
        if(p == first){
            t->next = first;
            first = t;
        }else{
            t->next = q->next;
            q->next = t;
        } 
    } 
}

void delete_node(struct Node *p, int x){
    struct Node *q = NULL;

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

bool is_sorted(struct Node *p){
    int x = INT_MIN;
    while(p != NULL){
        if(p->data < x){
            return false;
        }
        x = p->data;
        p = p->next;
    }
    return true;    
}

void remove_duplicates(struct Node *p){
    struct Node *q = p;
    p = p->next;

    while(p != NULL){
        if(q->data != p->data){
            q = p;
            p = p->next;
        }else{
            q->next = p->next;
            delete p;
            p = q->next;
        }
    }
}

void reverse(struct Node *p){
    struct Node *q = NULL, *r = NULL;
    while(p != NULL){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void recursive_reverse(struct Node *q, struct Node *p){
    if(p != NULL){
        recursive_reverse(p, p->next);
        p->next = q;
    }   
    else{
        first = q;
    }
}

void concatenate(struct Node *p, struct Node *q){
    third = p;
    while(p->next != NULL)
        p = p->next;
    p->next = q;
}

void merge(struct Node *p, struct Node *q){
    if(p->data < q->data){
        third = last = p;
        p = p->next;
        last->next = NULL;
    }else{
        third = last = q;
        q = q->next;
        last->next = NULL;
    }
    while(p != NULL && q != NULL){
        if(p->data < q->data){
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }else{
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if(p != NULL){
        last->next = p;
        last = p;
    }else{
        last->next = q;
        last = q;
    }
}

bool isLoop(struct Node *p){
    struct Node *q = p;
    do{
        q = q->next;
        p = p->next;
        p = p ? p->next : p;
    }while(p && q && p != q);

    return p==q ? true : false;
}

int main() {
    // int A[] {1, 2, 3, 4, 5};

    // create(A, 5);
    
    // display(first);
    // recursive_display(first);
    // cout<<endl;

    // cout<<count(first)<<endl;
    // cout<<recursive_count(first)<<endl;
    // cout<<sum(first)<<endl;
    // cout<<recursive_sum(first)<<endl;

    // cout<<max(first)<<endl;
    // cout<<recursive_max(first)<<endl;

    // struct Node* s = search(first, 4);
    // cout<<s->data<<" "<<s->next<<endl;

    // struct Node* rs = recursive_search(first, 4);
    // cout<<rs->data<<" "<<rs->next<<endl;

    // display(first);

    // insert(first, 0, 10);
    // insert(first, 4, 1000);

    // append(10);
    // append(20);
    // append(30);
    // append(40);
    // append(50);

    sorted_insert(first, 10);
    sorted_insert(first, 30);
    sorted_insert(first, 25);
    sorted_insert(first, 30);
    sorted_insert(first, 2);

    display(first);

    // delete_node(first, 10);

    // display(first);
    // cout<<"Sorted : "<<is_sorted(first)<<endl;

    // remove_duplicates(first);

    // reverse(first);
    // display(first);
    // recursive_reverse(NULL, first);
    // display(first);

    int B[] {12, 14, 32, 41, 52};
    create_2(B, 5);

    display(second);

    // concatenate(first, second);
    // display(third);

    merge(first, second);
    display(third);

    // struct Node *t1 = third->next->next->next->next->next->next;
    // struct Node *t2 = third->next->next;

    // t1->next = t2;
    cout<<isLoop(third)<<endl;

    // display(third);

    return 0;
}