#include <iostream>
using namespace std;

template <class T>
class Arithmetic
{
    private:
        T a;
        T b;
    public:
        Arithmetic<T>(T a, T b){
            this->a = a;
            this->b = b;
        }
        T add();
        T sub();
};

template <class T>
T Arithmetic<T> :: add(){
    return a + b;
}

template <class T>
T Arithmetic<T> :: sub(){
    return a - b;
}

int main()
{
    Arithmetic<double> a(10.2, 5.3);
    cout<<a.add()<<endl;
    cout<<a.sub()<<endl;
}