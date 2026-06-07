// struct based

#include <iostream>
using namespace std;

struct Term
{
    int coeff;
    int exp;
};

struct Polynomial
{
    int n;
    struct Term *terms;
};

void create(struct Polynomial *p){
    cout<<"Enter dimension : "<<endl;
    cin >> p->n;
    p->terms = new struct Term[p->n];

    cout<<"Enter the terms : "<<endl;
    for(int i=0; i<p->n; i++){
        cin >> p->terms[i].coeff >> p->terms[i].exp;
    }
}

void display(struct Polynomial p){
    for(int i=0; i<p.n; i++){
        cout<<p.terms[i].coeff<<"x"<<p.terms[i].exp<<" + ";
    }
    cout<<endl;
}

struct Polynomial * add(struct Polynomial *p1, struct Polynomial *p2){
    int i, j, k;
    i=j=k=0;

    struct Polynomial *sum = new struct Polynomial();
    sum->terms = new struct Term[p1->n + p2->n];

    while(i < p1->n && j < p2->n){
        if(p1->terms[i].exp > p2->terms[j].exp)
            sum->terms[k++] = p1->terms[i++];
        else if(p2->terms[j].exp > p1->terms[i].exp)
            sum->terms[k++] = p2->terms[j++];
        else{
            sum->terms[k].exp = p1->terms[i].exp;
            sum->terms[k++].coeff = p1->terms[i++].coeff + p2->terms[j++].coeff;
        }    
    }
    while(i < p1->n)
        sum->terms[k++] = p1->terms[i++];
    while(j < p2->n)
        sum->terms[k++] = p2->terms[j++];

    sum->n = k;

    return sum;
}

int main()
{
    struct Polynomial p1;
    struct Polynomial p2;
    create(&p1);
    create(&p2);

    struct Polynomial *p3 = add(&p1, &p2);

    display(p1);
    display(p2);
    display(*p3);
    
    return 0;
}
