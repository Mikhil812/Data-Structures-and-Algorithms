// Matrix indexing is assumed to start from 1 and arrays is 0.
#include <iostream>
using namespace std;

class Diagonal
{
    private : 
        int *A;
        int n;
    public : 
        Diagonal(){
            n = 5;
            A = new int[5];
        }
        Diagonal(int n){
            this->n = n;
            A = new int[n];
        }
        ~Diagonal(){
            delete []A;
        }
        void set(int i, int j, int x){
            if(i == j){
                A[i-1] = x;
                return ;
            }
            cout<<"Invalid Indexes"<<endl;
        }
        int get(int i, int j){
            if(i == j){
                return A[i-1];
            }
            return 0;
        }
        void display(){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    if(i == j)
                        cout<<A[j-1]<<" ";
                    else
                        cout<<"0 ";
                }
                cout<<endl;
            }
        }
};

class LowerTriangular
{
    private : 
        int *A;
        int n;
    public : 
        LowerTriangular(){
            n = 5;
            A = new int[5*6/2];
        }
        LowerTriangular(int n){
            this->n = n;
            A = new int[(n*(n+1))/2];
        }
        ~LowerTriangular(){
            delete []A;
        }
        void set(int i, int j, int x){
            if(i >= j){
                int row_major_formula = (i * (i-1))/2 + (j-1);
                A[row_major_formula] = x; 
                return ;
            }
        }
        int get(int i, int j){
            if(i >= j){
                int row_major_formula = (i * (i-1))/2 + (j-1);
                return A[row_major_formula]; 
            }
            return 0;
        }
        void display(){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    if(i >= j){
                        int row_major_formula = (i * (i-1))/2 + (j-1);
                        cout<<A[row_major_formula]<<" ";
                    }
                    else
                        cout<<"0 ";
                }
                cout<<endl;
            }
        }
};

int main()
{
    int dim;
    cout<<"Enter dimension : "<<endl;
    cin >> dim;

    LowerTriangular mat(dim);

    cout<<"Enter the matrix : "<<endl;
    for(int i=1; i<=dim; i++){
        for(int j=1; j<=dim; j++){ 
            int x;
            cin >> x;
            mat.set(i, j, x);
        }
    }

    cout<<"Matrix : "<<endl;
    mat.display();
    cout<<mat.get(3, 3)<<endl;

    return 0;
}