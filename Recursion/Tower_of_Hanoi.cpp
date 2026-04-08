#include <iostream>
using namespace std;

int num_of_steps = 0;
void TOH(int n, int A, int B, int C)
{
    if(n>0)
    {
        TOH(n-1, A, C, B);
        printf("(%d, %d) \n", A, C);
        num_of_steps++;
        TOH(n-1, B, A, C);
    }
}
int main()
{
    TOH(16, 1, 2, 3);
    cout<<"Number of steps : "<<num_of_steps<<endl;
    
    return 0;
}