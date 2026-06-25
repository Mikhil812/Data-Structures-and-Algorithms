#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class HashTable{
    private:
        Node **hashArray;
    public:
        HashTable(){
            hashArray = new Node*[10];

            // Initialize all to Nulls
            for(int i=0; i<10; i++){
                hashArray[i] = nullptr;
            }
        }
        ~HashTable(){
            for (int i=0; i<10; i++){
                Node* p = hashArray[i];
                while (hashArray[i] != nullptr){
                    hashArray[i] = hashArray[i]->next;
                    delete p;
                    p = hashArray[i];
                }
            }
            delete [] hashArray;
        }

        int hash(int key){  
            // Hash Function -> returns the index where key exists
            // In this example : hash function is this i.e. last digit of a number
            return (key % 10);
        }       
        
        void SortedInsert(int key){
            Node *temp = new Node();
            temp->data = key;
            temp->next = nullptr;

            int index = hash(key);

            if(hashArray[index] == nullptr)
                hashArray[index] = temp;
            else{
                Node *p = hashArray[index];
                Node *q = nullptr;
                while(p != nullptr && temp->data > p->data){
                    q = p;
                    p = p->next;
                }
                // Case : insert position is first : 
                if(q == nullptr){
                    temp->next = hashArray[index];
                    hashArray[index] = temp;
                }else{
                    temp->next = p;
                    q->next = temp;
                }
            }
        }

        int Search(int key){
            int index = hash(key);
            Node *p = hashArray[index];
            while(p != nullptr){
                if(p->data == key)
                    return p->data;
                p = p->next;
            }
            return -1;
        }

        int Delete(int key){
            int index = hash(key);
            
            if(hashArray[index] == nullptr)
                return -1;
            else{
                Node *p = hashArray[index];
                Node *q = nullptr;

                while(p != nullptr && key > p->data){
                    q = p;
                    p = p->next;
                }

                // Node not found
                if(p == nullptr || p->data != key)
                    return -1;

                // Case : Head node to be delete
                if(q == nullptr)
                    hashArray[index] = p->next;
                else
                    q->next = p->next;

                int ans = p->data;
                delete p;
                return ans;
            }
        }

        void Display() {    // written by GPT
            cout << "\nHash Table\n";
            cout << "-----------------------------\n";

            for (int i = 0; i < 10; i++) {
                cout << "[" << i << "] -> ";

                Node *p = hashArray[i];

                if (p == nullptr) {
                    cout << "NULL";
                } else {
                    while (p != nullptr) {
                        cout << p->data;
                        if (p->next != nullptr)
                            cout << " -> ";
                        p = p->next;
                    }
                }

                cout << endl;
            }

            cout << "-----------------------------\n";
        }
};

int main() {

    int A[] = {16, 12, 25, 39, 6, 122, 5, 68, 75};
	int n = sizeof(A)/sizeof(A[0]);

	HashTable H;
	for (int i=0; i<n; i++){
		H.SortedInsert(A[i]);
	}

    cout<<"Displaying : "<<endl;
    H.Display();

    int key, value;

	cout << "Search : " << endl;
    key = 6;
	value = H.Search(key);
	if(value != -1){
        cout<<"Key Found ! : "<<endl;
        cout << "Key: " << key << ", Value: " << value << endl;
    }else{
        cout<<"Key not found !, does not exist"<<endl;
        cout << "Key: " << key << ", Value: " << value << endl;
    }

    key = 122;
    value = H.Delete(key);
    cout<<"Deleting : "<<value<<endl;;
    if(value != -1){
        cout<<"Key Deleted ! : "<<endl;
        cout << "Key: " << key << ", Value: " << value << endl;
    }else{
        cout<<"Key not found !, does not exist"<<endl;
        cout << "Key: " << key << ", Value: " << value << endl;
    }
    
    key = 6;
    value = H.Delete(key);
    cout<<"Deleting : "<<value<<endl;;
    if(value != -1){
        cout<<"Key Deleted ! : "<<endl;
        cout << "Key: " << key << ", Value: " << value << endl;
    }else{
        cout<<"Key not found !, does not exist"<<endl;
        cout << "Key: " << key << ", Value: " << value << endl;
    }

    cout << "Searching : " << endl;
    key = 6;
	value = H.Search(key);
	if(value != -1){
        cout<<"Key Found ! : "<<endl;
        cout << "Key: " << key << ", Value: " << value << endl;
    }else{
        cout<<"Key not found !, does not exist"<<endl;
        cout << "Key: " << key << ", Value: " << value << endl;
    }

    cout<<"Displaying : "<<endl;
    H.Display();

    return 0;
}