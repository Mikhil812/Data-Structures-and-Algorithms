// In order to run this : 
// a. compile all : g++ *.cpp -o program
// b. run that exe: .\program.exe

#include "Queue.h"
#include <iostream>
using namespace std;

class Tree{
    private:
        Node *root;

        void preOrder(Node *p){
            if(p){
                cout<<p->data<<" ";
                preOrder(p->lchild);
                preOrder(p->rchild);
            }
        }

        void inOrder(Node *p){
            if(p){
                inOrder(p->lchild);
                cout<<p->data<<" ";
                inOrder(p->rchild);
            }
        }

        void postOrder(Node *p){
            if(p){
                postOrder(p->lchild);
                postOrder(p->rchild);
                cout<<p->data<<" ";
            }
        }

        void destroy_postorder(Node *p){
            if(p){
                destroy_postorder(p->lchild);
                destroy_postorder(p->rchild);
                delete p;
            }
        }
    public:
        Tree(){
            root = nullptr;
        }

        ~Tree(){
            destroy_postorder(root);
        }

        void createTree(){
            Queue q(100);
            int x;

            root = new Node();
            cout<<"Enter root's data : "<<endl;
            cin >> x;
            root->lchild = nullptr;
            root->data = x;
            root->rchild = nullptr;

            q.enqueue(root);
            Node *p, *t;
            while(!q.isEmpty()){
                p = q.dequeue();
                cout<<"Left Child for "<<p->data<<" :"<<endl;
                cin>>x;
                if(x != -1){
                    t = new Node();
                    t->lchild = nullptr;
                    t->data = x;
                    t->rchild = nullptr;
                    p->lchild = t;
                    q.enqueue(t);
                }
                cout<<"Right Child for "<<p->data<<" :"<<endl;
                cin >> x;
                if(x != -1){
                    t = new Node();
                    t->lchild = nullptr;
                    t->data = x;
                    t->rchild = nullptr;
                    p->rchild = t;
                    q.enqueue(t);
                }
            }
        }

        void preOrder(){
            preOrder(root);
        }

        void inOrder(){
            inOrder(root);
        }

        void postOrder(){
            postOrder(root);
        }

};

int main() {
    Tree t;
    t.createTree();

    cout<<"PreOrder Traversal : "<<endl;
    t.preOrder();
    cout<<endl;

    cout<<"InOrder Traversal : "<<endl;
    t.inOrder();
    cout<<endl;

    cout<<"PostOrder Traversal : "<<endl;
    t.postOrder();
    cout<<endl;

    return 0;
}