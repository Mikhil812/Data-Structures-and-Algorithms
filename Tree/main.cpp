// In order to run this : 
// a. compile all : g++ *.cpp -o program
// b. run that exe: .\program.exe

#include "Queue.h"
#include "Stack.h"
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

        void iterative_preOrder(){
            Stack<Node *> st(100);
            Node *t = root;
            while(t!=NULL || !st.isEmpty()){
                if(t!=NULL){
                    cout<<t->data<<" ";
                    st.push(t);
                    t = t->lchild;
                }else{
                    t = st.pop();
                    t = t->rchild;
                }
            }
        }

        void iterative_inOrder(){
            Stack<Node *> st(100);
            Node *t = root;
            while(t!=NULL || !st.isEmpty()){
                if(t!=NULL){
                    st.push(t);
                    t = t->lchild;
                }else{
                    t = st.pop();
                    cout<<t->data<<" ";
                    t = t->rchild;
                }
            }
        }

        void iterative_postOrder(){
            Stack<long int> st(100);
            long int temp;
            Node *t = root;
            while(t!=NULL || !st.isEmpty()){
                if(t!=NULL){
                    st.push((long int)t);
                    t = t->lchild;
                }else{
                    temp = st.pop();
                    if(temp > 0){
                        st.push(-temp);
                        t = ((Node *)temp)->rchild;
                    }else{
                        cout<<((Node *)(-1 * temp))->data<<" ";
                        t = nullptr;
                    }
                }
            }
        }

        void levelOrder(){
            Node *t;
            Queue q(100);
            q.enqueue(root);

            while(!q.isEmpty()){
                t = q.dequeue();
                cout<<t->data<<" ";
                if(t->lchild)
                    q.enqueue(t->lchild);
                if(t->rchild)
                    q.enqueue(t->rchild);
            }
        }

        int searchInorder(int *arr, int inStart, int inEnd, int data){
            for(int i=inStart; i<=inEnd; i++){
                if(arr[i] == data)
                    return i;
            }
            return -1;
        }

        void generate_from_traversal(int *preorder, int *inorder, int n)
        {
            root = generate_from_traversal(preorder, inorder, 0, n-1);
        }

        Node * generate_from_traversal(int *preorder, int *inorder, int inStart, int inEnd){
            static int preOrderIndex = 0;
            
            if(inStart > inEnd){
                return nullptr;
            }

            Node *temp = new Node();
            temp->data = preorder[preOrderIndex++];

            if(inStart == inEnd){
                return temp;
            }

            int splitIndex = searchInorder(inorder, inStart, inEnd, temp->data);
            temp->lchild = generate_from_traversal(preorder, inorder, inStart, splitIndex-1);
            temp->rchild = generate_from_traversal(preorder, inorder, splitIndex+1, inEnd);

            return temp;
        }
};

int main() {
    // Tree t;
    // t.createTree();

    // cout<<"PreOrder Traversal : "<<endl;
    // t.preOrder();
    // cout<<endl;
    // cout<<"Iterative PreOrder Traversal : "<<endl;
    // t.iterative_preOrder();
    // cout<<endl;

    // cout<<"InOrder Traversal : "<<endl;
    // t.inOrder();
    // cout<<endl;
    // cout<<"Iterative InOrder Traversal : "<<endl;
    // t.iterative_inOrder();
    // cout<<endl;

    // cout<<"PostOrder Traversal : "<<endl;
    // t.postOrder();
    // cout<<endl;
    // cout<<"Iterative PostOrder Traversal : "<<endl;
    // t.iterative_postOrder();
    // cout<<endl;

    // cout<<"LevelOrder Traversal : "<<endl;
    // t.levelOrder();
    // cout<<endl;

    cout<<"Generate Tree from Traversal : "<<endl;
    int preorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};
    Tree t2;
    t2.generate_from_traversal(preorder, inorder, sizeof(inorder)/sizeof(inorder[0]));
    t2.preOrder();

    return 0;
}