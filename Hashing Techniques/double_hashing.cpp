#include <iostream>
#define size 10
#define R 7
using namespace std;

class DoubleHashing{
    private:
        int HT[size]; 
    public:
        DoubleHashing(){
            for(int i=0; i<size; i++){
                HT[i] = 0;
            }
        }
        ~DoubleHashing(){
            // no heap memory
        }

        int hash1(int key){             // h1(x) = x % 10
            return (key % size);
        }

        int hash2(int key){             // h2(x) = R - (x % R)
            return (R - (key % R));
        }

        int doubleHash(int key){
            int h1 = hash1(key);
            int i = 0;

            while(HT[(h1 + i*hash2(key)) % size] != 0)  // (h1 + i*h2) % size
                i++;
                
            return (h1 + i*hash2(key)) % size;
        }

        void Insert(int key){
            int index = hash1(key);

            if(HT[index] != 0){
                index = doubleHash(key);
            }
            HT[index] = key;
        }

        int Search(int key){
            int h1 = hash1(key);

            int i=0;
            while(HT[(h1 + i*hash2(key)) % size] != key){
                i++;
                if(HT[(h1 + i*hash2(key)) % size] == 0)
                    return -1;
            }

            return (h1 + i*hash2(key)) % size;
        }
};

int main() {

    DoubleHashing hashTable;

    int A[] = {5, 25, 15, 35, 95};
    int n = sizeof(A)/sizeof(A[0]);

    for (int i=0; i<n; i++){
        hashTable.Insert(A[i]);
    }
 
    int index = hashTable.Search(25);
    cout << "Key found at: " << index << endl;
 
    index = hashTable.Search(42);
    cout << "Key found at: " << index << endl;

    // This code is correct according to abdul baris teachings, but GPT says that 
    // here table size should also be PRIME number so that probe sequence can 
    // visit all slots, that means it says that right now all slots are not visited.

    // Heres the actual GPT response : 

    // Good question. No—in your particular example, all slots actually 
    // do get visited. That's because of the specific values you've chosen.

    // Your probe sequence is therefore
    // (h1+3i)mod10
    // Since 3 and 10 are coprime (gcd(3,10)=1), repeatedly 
    // adding 3 modulo 10 visits every slot exactly once.

    // So why do textbooks insist on a prime table size?
    // Because you cannot guarantee that h2 will 
    // always be coprime with the table size.

    // So your implementation is not guaranteed to work for arbitrary inputs, 
    // even though it works for the sample you've tested. 
    // That's why the standard recommendation is:

    // Choose a prime table size (e.g., 11, 13, 17, ...).
    // Choose R as the largest prime smaller than the table size.
     
    return 0;
}