#include <iostream>
#define size 10
using namespace std;

class LinearProbing{
    private:
        int HT[size];
    public:
        LinearProbing(){
            // Initialize hasharray to 0
            for(int i=0; i<size; i++){
                HT[i] = 0;
            }
        }
        ~LinearProbing(){
            // No heap memory   
        }

        // Hash Function which returns the index where key is
        int hash(int key){
            return (key % size);
        }

        int probe(int key){
            int index = hash(key);
            int i=0;

            // Hash Function : [h(x) + f(i)] % 10 
            while(HT[(index + i) % size] != 0)  
                i++;

            return (index + i) % size;
        }

        void Insert(int key){
            int index = hash(key);

            // If that space is already occupied, we explore till the next free space
            if(HT[index] != 0)
                index = probe(key);

            HT[index] = key;
        }

        int Search(int key){
            int index = hash(key);

            // Probe till you get the key or the space becomes empty
            int i = 0;
            while(HT[(index + i) % size] != key){
                if (HT[(index + i) % size] == 0){
                    return -1;
                }
                i++;
            }
            return (index + i) % size;
        }
};

int main() {

    LinearProbing hashTable;
    hashTable.Insert(12);
    hashTable.Insert(22);
    hashTable.Insert(34);
    hashTable.Insert(45);
    hashTable.Insert(73);


    // Theres no function for visualizing so put breakpoint and debug to see the hash array
    cout<<"Searching : "<<hashTable.Search(79)<<endl;

    return 0;
}