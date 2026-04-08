#include <iostream>
using namespace std;

class Rectangle
{
    private:
        int length;
        int breadth;
    public:
        Rectangle(){
            length = 5;
            breadth = 5;
        }
        Rectangle(int l, int b);
        int getLength(){return length;}
        int getBreadth(){return breadth;}
        void setLength(int l){length = l;}
        void setBreadth(int b){breadth = b;}
        
        int area();
        int perimeter();
};

Rectangle :: Rectangle(int l, int b){
    length = l;
    breadth = b;
}
int Rectangle :: area(){
    return length * breadth;
}
int Rectangle::perimeter(){
    return 2*(length + breadth);
}

int main()
{
    Rectangle r(10,2);
    cout<<r.getLength()<<endl;
    cout<<r.area()<<endl;
    r.setBreadth(25);
    cout<<r.perimeter()<<endl;

    return 0;
}