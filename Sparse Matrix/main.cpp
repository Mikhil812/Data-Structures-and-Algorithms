#include <iostream>
using namespace std;

class Element
{
    public:
        int row;
        int col;
        int x;
};

class Sparse
{
    private:
        int m;
        int n;
        int num;
        Element *e;
    
    public:
        Sparse(int m, int n, int num){
            this->m = m;
            this->n = n;
            this->num = num;
            e = new Element[this->num];
        }
        ~Sparse(){
            delete [] e;
        }

        Sparse operator +(Sparse &s);

        friend istream & operator >> (istream &is, Sparse &s);
        friend ostream & operator << (ostream &os, Sparse &s);
};

        istream & operator>>(istream &is, Sparse &s){
            cout<<"Enter row, col and the non zero element : "<<endl;
            for(int i=0; i<s.num; i++){
                cin >> s.e[i].row >> s.e[i].col >> s.e[i].x;
            }
            cout<<endl;
            return is;
        }
        ostream & operator<<(ostream &os, Sparse &s){
            cout<<"Matrix : "<<endl;
            int k=0;
            for(int i=0; i<s.m; i++){
                for(int j=0; j<s.n; j++){
                    if(i == s.e[k].row && j == s.e[k].col)
                        cout<<s.e[k++].x<<" ";
                    else
                        cout<<"0 ";
                }
                cout<<endl;
            }
            cout<<endl;
            return os;
        }
        
        Sparse Sparse :: operator+(Sparse &s2){
            if(m != s2.m || n != s2.n)
                Sparse(0, 0, 0) ;
            
            Sparse *s3 = new Sparse(m, n, num + s2.num);
            int i=0, j=0, k=0;

            while(i < num && j < s2.num){
                if(e[i].row < s2.e[j].row)
                    s3->e[k++] = e[i++];
                else if(s2.e[j].row < e[i].row)
                    s3->e[k++] = s2.e[j++];
                else if(e[i].col < s2.e[j].col)
                    s3->e[k++] = e[i++];
                else if(s2.e[j].col < e[i].col)
                    s3->e[k++] = s2.e[j++];
                else{
                    s3->e[k] = e[i];
                    s3->e[k++].x = e[i++].x + s2.e[j++].x;
                }
            }
            for(; i<num; i++)
                s3->e[k++] = e[i];
            for(; j<s2.num; j++)
                s3->e[k++] = s2.e[j];
            
            s3->num = k;

            return *s3;    
        }

int main()
{
    Sparse s1(3, 3, 3);
    cin >> s1;

    Sparse s2(3, 3, 3);
    cin >> s2;

    cout << s1;
    cout<< s2;

    Sparse s3 = s1 + s2;
    cout<<s3;

    return 0;
}