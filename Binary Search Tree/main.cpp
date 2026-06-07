#include <iostream>
using namespace std;

class Node
{
    public:
        Node *lchild;
        int data;
        Node *rchild;
};

class BST
{
    private:
        Node *root;

        void inorder(Node *p){
            if(p){
                inorder(p->lchild);
                cout<<p->data<<" ";
                inorder(p->rchild);
            }
        }

        Node* Rinsert(Node *p, int data){
            if(p == NULL){
                Node *temp = new Node();
                temp->data = data;
                temp->lchild = temp->rchild = nullptr;
                return temp;
            }
            if(data < p->data)
                p->lchild = Rinsert(p->lchild, data);
            else
                p->rchild = Rinsert(p->rchild, data);
            
            return p;
        }

        Node *Rsearch(Node *t, int data){
            if(t == nullptr)
                return nullptr;
            if(data == t->data)
                return t;
            else if(data < t->data)
                return Rsearch(t->lchild, data);
            else
                return Rsearch(t->rchild, data);
        }

        void destroy(Node *p){
            if(p){
                destroy(p->lchild);
                destroy(p->rchild);
                delete p;
            }
            // The reason its postorder form because you must delete the children
            // before the parent
        }

    public:
        BST(){
            root = nullptr;
        }

        ~BST(){
            destroy(root);
        }

        void inorder(){
            inorder(root);
        }

        void Iinsert(int data){
            if(root == nullptr){
                Node *p = new Node();
                p->data = data;
                p->lchild = p->rchild = nullptr;
                root = p;
                return ;
            }
            Node *t = root;
            Node *tailptr = nullptr;
            while(t != NULL){
                tailptr = t;
                if(data == t->data)
                    return ;
                else if(data < t->data)
                    t = t->lchild;
                else
                    t = t->rchild;
            }
            Node *temp = new Node();
            temp->data = data;
            temp->lchild = temp->rchild = nullptr;
            if(data < tailptr->data)
                tailptr->lchild = temp;
            else    
                tailptr->rchild = temp;

            return ;
        }

        Node * Isearch(int data){
            Node *t = root;
            while(t != NULL){
                if(data == t->data)
                    return t;
                else if(data < t->data)
                    t = t->lchild;
                else
                    t = t->rchild;
            }
            return t;
        }

        void Rinsert(int data){
            root = Rinsert(root, data);
        }

        Node* Rsearch(int data){
            return Rsearch(root, data);
        }   
};

int main(){

    // Iterative Insert
    BST t;
    t.Iinsert(10);
    t.Iinsert(5);
    t.Iinsert(20);
    t.Iinsert(8);
    t.Iinsert(30);

    cout<<"Inorder Traversal : (should be sorted)"<<endl;
    t.inorder();
    cout<<endl;

    cout<<"Iterative Search : "<<endl;
    Node *temp = t.Isearch(30);
    if(temp)
        cout<<"Element found : "<<temp->data<<endl;
    else
        cout<<"Element not found "<<endl;

    // Recursive Insert
    BST t2;
    t2.Rinsert(10);
    t2.Rinsert(5);
    t2.Rinsert(20);
    t2.Rinsert(8);
    t2.Rinsert(30);

    cout<<"Inorder Traversal : (should be sorted)"<<endl;
    t2.inorder();
    cout<<endl;

    cout<<"Recursive Search : "<<endl;
    Node *temp2 = t2.Rsearch(30);
    if(temp2)
        cout<<"Element found : "<<temp2->data<<endl;
    else
        cout<<"Element not found "<<endl;

    return 0;
}