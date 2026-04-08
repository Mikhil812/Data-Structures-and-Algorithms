#include <iostream>
using namespace std;

int len(char s[]){
    int i;
    for(i=0; s[i] != '\0'; i++){
        
    }
    return i;
}

void toggle_case(char s[]){
    for(int i=0; i < len(s); i++){
        if(s[i] >= 65 && s[i] <= 90)
            s[i] += 32;
        else if(s[i] >= 'a' && s[i] <= 122)
            s[i] -= 32;
    }
    return ;
}

int count_words(char s[]){
    int spaces = 0;
    for(int i=0; i<len(s); i++){
        if(s[i] == ' ' && s[i-1] != ' ')
            spaces++;
    }
    return spaces + 1;
}

void swap(char *x, char *y){
    char temp = *x;
    *x = *y;
    *y = temp;
}

void reverse(char s[]){
    int i=0, j=len(s)-1;
    while(i < j){
        swap(s[i++], s[j--]);
    }
    return ;
}

bool is_palindrome(char s[]){
    int low = 0, high = len(s) - 1;
    while(low < high){
        if(s[low++] != s[high--])
            return false;
    }
    return true;
}

void duplicates_1(char s[]){
    int H[26]={0};
    for(int i=0; i<len(s); i++){
        H[s[i] - 65]++;
    }
    for(int i=0; i<26; i++){
        if(H[i] > 1){
            cout<<"Duplicates : "<<(char)(i + 65)<<" ";
        }
    }
    cout<<endl;
    return ;
}

// Important
void bitwise_duplicates(char s[]){
    int H = 0;                          // integer because 4 bytes i.e. 32 bits, we need 26 bits exactly for hashing but closest is 32.    

    for(int i=0; i<len(s); i++){
        int helper = 1;  
        int diff = s[i] - 65;
        helper = helper << diff;        // bitwise left shift
        if( (H & helper) > 0){          // Masking operation (ANDing)
            cout<<"Duplicates: "<<s[i]<<" ";
        }else{
            H = (H | helper);           // Merging operation (ORing)            
        }
    }
    cout<<endl;
}

bool is_anagram(char a[], char b[]){
    if(len(a) != len(b))
        return false;
    
    int H[26] = {0};
    for(int i=0; i<len(a); i++){
        H[a[i] - 97]++;
    }
    for(int i=0; i<len(b); i++){
        H[b[i] - 97]--;
        if(H[b[i] - 97] < 0)
            return false;
    }
    return true;
}

// Important : Backtracking
void perm(char s[], int k){
    static int A[20] = {0};
    static char res[20];
    int i;
    if(s[k] == '\0'){
        res[k] = '\0';
        cout<<res<<endl;
    }else{
        for(i=0; s[i] != '\0'; i++){
            if(A[i] == 0){
                res[k] = s[i];
                A[i] = 1;
                perm(s, k+1);
                A[i] = 0;
            }
        }
    }
}

void perm_swap(char s[], int l, int h){
    if(l == h){
        cout<<s<<endl;
        return;
    }else{
        for(int i=l; i <= h; i++){
            swap(s[l], s[i]);
            perm_swap(s, l+1, h);
            swap(s[l], s[i]);
        }
    }
}

int main()
{   
    char s[] = "ihaddahi";
    cout<<"Original : "<<s<<endl;

    cout<<"Length : "<<len(s)<<endl;

    toggle_case(s);
    cout<<"Toggle Case : "<<s<<endl;

    cout<<"Words : "<<count_words(s)<<endl;

    // reverse(s);
    // cout<<"Reverse : "<<s<<endl;

    cout<<"Palindrome : "<<is_palindrome(s)<<endl;
    duplicates_1(s);
    bitwise_duplicates(s);

    char a[] = "verbose";
    char b[] = "observe";
    cout<<"Anagram : "<<is_anagram(a, b)<<endl;

    cout<<"Permutations : "<<endl;
    // perm(s, 0);

    perm_swap(s, 0, len(s) - 1);

    return 0;
}