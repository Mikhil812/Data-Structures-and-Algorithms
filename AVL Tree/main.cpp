#include <iostream>
using namespace std;

class Node
{
    public:
        Node *lchild;
        int data;
        Node *rchild;
        int height;         // Extra thing
};

class AVL_Tree
{
    private:
        Node *root;

        // Recursive Insert same as BST with variation
        Node * Rinsert(Node *p, int value){
            if(p == nullptr){
                Node *t = new Node();
                t->data = value;
                t->lchild = t->rchild = nullptr;
                t->height = 1;                          // Extra thing, you can also keep 0
                return t;
            }
            if(value < p->data)
                p->lchild = Rinsert(p->lchild, value);
            else if(value > p->data)
                p->rchild = Rinsert(p->rchild, value);

            // Update height here now : 
            p->height = nodeHeight(p);

            // Conditions for Different Rotations : 
            // LL Rotation : 
            if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
                return LLRotation(p);
            else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
                return LRRotation(p);
            else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
                return RRRotation(p);
            else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
                return RLRotation(p);

            return p;
        }

    public:
        AVL_Tree(){
            root = nullptr;
        }

        ~AVL_Tree(){

        }

        Node *get_root(){
            return root;
        }

        void inorder(Node *p){
            if(p){
                inorder(p->lchild);
                cout<<p->data<<" ";
                inorder(p->rchild);
            }
        }

        void * Rinsert(int value){
            root = Rinsert(root, value);
        }

        int nodeHeight(Node *p){
            // hl : height of left child, hr : height of right child
            int hl, hr;

            if(p && p->lchild)
                hl = p->lchild->height;
            else 
                hl = 0;

            // Similarly : 
            hr = (p && p->rchild) ? p->rchild->height : 0;

            return (hl > hr) ? hl + 1 : hr + 1;     // max of hl, hr + 1
        }

        int BalanceFactor(Node *p){
            // hl : height of left child, hr : height of right child
            int hl, hr;

            if(p && p->lchild)
                hl = p->lchild->height;
            else 
                hl = 0;

            // Similarly : 
            hr = (p && p->rchild) ? p->rchild->height : 0;

            return hl - hr;     // exact same function as nodeHeight but return difference
        }

        Node * LLRotation(Node *p){
            Node *pl = p->lchild;       // pl : p's left child
            Node *plr = pl->rchild;     // plr: p->left->right

            // 2 assignments for rotation
            pl->rchild = p;             
            p->lchild = plr;

            // Now update height (plr's height will remain the same after rotation)
            p->height = nodeHeight(p);          // altering p's height first is imp
            pl->height = nodeHeight(pl);        // as pl's height depends on it

            if(p == root)
                root = pl;
            
            return pl;
        }

        Node * LRRotation(Node *p){
            Node *pl = p->lchild;
            Node *plr = pl->rchild;         // or p->lchild->rchild;

            // 4 assignments to complete rotation: 

            // Handle plr's children first : 
            pl->rchild = plr->lchild;
            p->lchild = plr->rchild;
            // now handle plr itself
            plr->lchild = pl;
            plr->rchild = p;

            // Now Update heights in the right order : 
            pl->height = nodeHeight(pl);
            p->height = nodeHeight(p);
            plr->height = nodeHeight(plr);

            if(root == p)
                root = plr;

            return plr;
        }

        Node * RRRotation(Node *p){
            Node *pr = p->rchild;
            Node *prl = pr->lchild;         // or p->rchild->lchild;

            // 2 assignments to complete rotation : 
            p->rchild = prl;
            pr->lchild = p;

            p->height = nodeHeight(p);
            pr->height = nodeHeight(pr);

            if(root == p)
                root = pr;

            return pr;
        }

        Node * RLRotation(Node *p){
            Node *pr = p->rchild;
            Node *prl = pr->lchild;     // or p->rchild->lchild;

            // 4 assignments in which we handle children of prl first : 
            p->rchild = prl->lchild;
            pr->lchild = prl->rchild;
            prl->lchild = p;
            prl->rchild = pr;

            // Update heights also starting from children : 
            p->height = nodeHeight(p);
            pr->height = nodeHeight(pr);
            prl->height = nodeHeight(prl);

            if(root == p)
                root = prl;
            
            return prl;     // the new king, the new root.
        }
};


int main(){

    AVL_Tree t;

    t.Rinsert(20);
    t.Rinsert(10);
    t.Rinsert(30);
    t.Rinsert(25);
    t.Rinsert(40);
    t.Rinsert(22);
    t.Rinsert(27);


    // You need to add breakpoint and debug to check if rotation worked.
    cout<<"Inorder Traversal : "<<endl;
    t.inorder(t.get_root());
    cout<<endl;

    return 0;
}