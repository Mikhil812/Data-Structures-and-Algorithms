// class based

#include <iostream>
using namespace std;

class Term
{
    public : 
        int coeff;
        int exp;
};

class Polynomial
{
    private : 
        int n;
        Term *terms;
    public :
        Polynomial(){
            
        } 
        Polynomial(int n){
            this->n = n;
            terms = new Term[this->n];

            cout<<"Enter the terms : "<<endl;
            for(int i=0; i<n; i++){
                cin >> terms[i].coeff >> terms[i].exp;
            }
        }
        ~Polynomial(){
            delete [] terms;
        }
        void display();
        Polynomial * add(Polynomial *p);
};

void Polynomial :: display(){
    for(int i=0; i<n; i++){
        cout<<terms[i].coeff<<"x"<<terms[i].exp<<" + ";
    }
    cout<<endl;
}

Polynomial* Polynomial :: add(struct Polynomial *p){
    int i, j, k;
    i=j=k=0;

    Polynomial *sum = new Polynomial();
    sum->terms = new Term[n + p->n];

    while(i < n && j < p->n){
        if(terms[i].exp > p->terms[j].exp)
            sum->terms[k++] = terms[i++];
        else if(p->terms[j].exp > terms[i].exp)
            sum->terms[k++] = p->terms[j++];
        else{
            sum->terms[k].exp = terms[i].exp;
            sum->terms[k++].coeff = terms[i++].coeff + p->terms[j++].coeff;
        }    
    }
    while(i < n)
        sum->terms[k++] = terms[i++];
    while(j < p->n)
        sum->terms[k++] = p->terms[j++];

    sum->n = k;

    return sum;
}

int main()
{
    Polynomial p1(5);
    Polynomial p2(5);

    Polynomial *p3 = p1.add(&p2);

    p1.display();
    p2.display();
    (*p3).display();
    
    return 0;
}
