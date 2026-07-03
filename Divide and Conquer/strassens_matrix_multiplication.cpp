#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

void display(const vector<vector<int>> &A, int numRowA, int numColA){
    for(int i=0; i<numRowA; i++){
        for(int j=0; j<numColA; j++){
            cout<<setw(3)<<(A[i][j])<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int nextPowerofTwo(int n){
    return pow(2, ceil(log2(n)));
}

// Return the padded square matrix of size n x n:
vector<vector<int>> padMatrix(const vector<vector<int>> &A, int n){
    vector<vector<int>> paddedMatrix(n, vector<int>(n, 0));

    for(int i = 0; i<A.size(); i++){
        for(int j = 0; j<A[0].size(); j++){
            paddedMatrix[i][j] = A[i][j];
        }
    }
    
    return paddedMatrix;
}

vector<vector<int>> matAdd(const vector<vector<int>> &A, const vector<vector<int>> &B, int n, int sign = 1){
    vector<vector<int>> C(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            C[i][j] = A[i][j] + sign * B[i][j];     // to support subtraction too
        }
    }
    return C;
}

// Basic Matrix Multiplication using Divide and Conquer without Strassen : 
vector<vector<int>> MatMul(vector<vector<int>> &A, vector<vector<int>> &B, int n){
    vector<vector<int>> res(n, vector<int>(n, 0));

    // Base condition : 
    if(n == 2){
        res[0][0] = (A[0][0] * B[0][0]) + (A[0][1] * B[1][0]);
        res[0][1] = (A[0][0] * B[0][1]) + (A[0][1] * B[1][1]);
        res[1][0] = (A[1][0] * B[0][0]) + (A[1][1] * B[1][0]);
        res[1][1] = (A[1][0] * B[0][1]) + (A[1][1] * B[1][1]); 

        return res;
    }else{
        // Split the n x n matrix to 4 n/2 x n/2 matrices each : 
        int newSize = n/2;
        vector<vector<int>> A11(n/2, vector<int>(n/2, 0));
        vector<vector<int>> A12(n/2, vector<int>(n/2, 0));
        vector<vector<int>> A21(n/2, vector<int>(n/2, 0));
        vector<vector<int>> A22(n/2, vector<int>(n/2, 0));
        vector<vector<int>> B11(n/2, vector<int>(n/2, 0));
        vector<vector<int>> B12(n/2, vector<int>(n/2, 0));
        vector<vector<int>> B21(n/2, vector<int>(n/2, 0));
        vector<vector<int>> B22(n/2, vector<int>(n/2, 0));

        // Fill these submatrices : 
        for(int i=0; i<n/2; i++){
            for(int j=0; j<n/2; j++){
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + newSize];
                A21[i][j] = A[i + newSize][j];
                A22[i][j] = A[i + newSize][j + newSize];
                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + newSize];
                B21[i][j] = B[i + newSize][j];
                B22[i][j] = B[i + newSize][j + newSize];            }
        }
        
        // Perform the same formulas on these matrices now : 
        auto C11 = matAdd(MatMul(A11, B11, newSize), MatMul(A12, B21, newSize), newSize);
        auto C12 = matAdd(MatMul(A11, B12, newSize), MatMul(A12, B22, newSize), newSize);
        auto C21 = matAdd(MatMul(A21, B11, newSize), MatMul(A22, B21, newSize), newSize);
        auto C22 = matAdd(MatMul(A21, B12, newSize), MatMul(A22, B22, newSize), newSize);

        // Combine the result quadrants into a final matrix : 
        for(int i=0; i<newSize; i++){
            for(int j=0; j<newSize; j++){
                res[i][j] = C11[i][j];
                res[i][j + newSize] = C12[i][j];
                res[i + newSize][j] = C21[i][j];
                res[i + newSize][j + newSize] = C22[i][j];
            }
        }

        return res;
    }
}

vector<vector<int>> StrassenMatMul(const vector<vector<int>> &A, const vector<vector<int>> &B, int n){
    vector<vector<int>> res(n, vector<int>(n, 0));

    // Base condition : 
    if(n == 2){
        res[0][0] = (A[0][0] * B[0][0]) + (A[0][1] * B[1][0]);
        res[0][1] = (A[0][0] * B[0][1]) + (A[0][1] * B[1][1]);
        res[1][0] = (A[1][0] * B[0][0]) + (A[1][1] * B[1][0]);
        res[1][1] = (A[1][0] * B[0][1]) + (A[1][1] * B[1][1]); 

        return res;
    }else{
        // Split the n x n matrix to 4 n/2 x n/2 matrices each : 
        int newSize = n/2;
        vector<vector<int>> A11(n/2, vector<int>(n/2, 0));
        vector<vector<int>> A12(n/2, vector<int>(n/2, 0));
        vector<vector<int>> A21(n/2, vector<int>(n/2, 0));
        vector<vector<int>> A22(n/2, vector<int>(n/2, 0));
        vector<vector<int>> B11(n/2, vector<int>(n/2, 0));
        vector<vector<int>> B12(n/2, vector<int>(n/2, 0));
        vector<vector<int>> B21(n/2, vector<int>(n/2, 0));
        vector<vector<int>> B22(n/2, vector<int>(n/2, 0));

        // Fill these submatrices : 
        for(int i=0; i<n/2; i++){
            for(int j=0; j<n/2; j++){
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + newSize];
                A21[i][j] = A[i + newSize][j];
                A22[i][j] = A[i + newSize][j + newSize];
                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + newSize];
                B21[i][j] = B[i + newSize][j];
                B22[i][j] = B[i + newSize][j + newSize];
            }
        }

        // Now Perform Strassens formulas : 
        auto p5 = StrassenMatMul(matAdd(A11, A22, newSize), matAdd(B11, B22, newSize), newSize);
        auto p4 = StrassenMatMul(A22, matAdd(B21, B11, newSize, -1), newSize);
        auto p2 = StrassenMatMul(matAdd(A11, A12, newSize), B22, newSize);
        auto p6 = StrassenMatMul(matAdd(A12, A22, newSize, -1), matAdd(B21, B22, newSize), newSize);
        auto p1 = StrassenMatMul(A11, matAdd(B12, B22, newSize, -1), newSize);
        auto p3 = StrassenMatMul(matAdd(A21, A22, newSize), B11, newSize);
        auto p7 = StrassenMatMul(matAdd(A11, A21, newSize, -1), matAdd(B11, B12, newSize), newSize);

        auto C11 = matAdd(matAdd(matAdd(p5, p4, newSize), p2, newSize, -1), p6, newSize);
        auto C12 = matAdd(p1, p2, newSize);
        auto C21 = matAdd(p3, p4, newSize);
        auto C22 = matAdd(matAdd(matAdd(p1, p5, newSize), p3, newSize, -1), p7, newSize, -1);

        // Combine the result quadrants into a final matrix : 
        for(int i=0; i<newSize; i++){
            for(int j=0; j<newSize; j++){
                res[i][j] = C11[i][j];
                res[i][j + newSize] = C12[i][j];
                res[i + newSize][j] = C21[i][j];
                res[i + newSize][j + newSize] = C22[i][j];
            }
        }

        return res;
    }
}

vector<vector<int>> bruteForceMatMul(const vector<vector<int>> &A, const vector<vector<int>> &B, int numRowA, int numColA, int numColB){
    vector<vector<int>> C(numRowA, vector<int>(numColB, 0));

    for (int i = 0; i < numRowA; i++) {
        for (int j = 0; j < numColB; j++) {
            for (int k = 0; k < numColA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

int main() {

    // vector<vector<int>> A = {{1, 2, 3}, {4, 5, 6}};
    // vector<vector<int>> B = {{7, 8}, {9, 10}, {11, 12}};

    vector<vector<int>> A = {
        {1, 2, 3, 4, 5, 6, 7},
        {8, 9, 1, 2, 3, 4, 5},
        {6, 7, 8, 9, 1, 2, 3},
        {4, 5, 6, 7, 8, 9, 1},
        {2, 3, 4, 5, 6, 7, 8},
        {9, 1, 2, 3, 4, 5, 6},
        {7, 8, 9, 1, 2, 3, 4}
    };

    vector<vector<int>> B = {
        {4, 3, 2, 1, 9, 8, 7},
        {6, 5, 4, 3, 2, 1, 9},
        {8, 7, 6, 5, 4, 3, 2},
        {1, 9, 8, 7, 6, 5, 4},
        {3, 2, 1, 9, 8, 7, 6},
        {5, 4, 3, 2, 1, 9, 8},
        {7, 6, 5, 4, 3, 2, 1}
    };

    int numRowA = A.size(), numRowB = B.size();
    int numColA = A[0].size(), numColB = B[0].size();

    cout<<"Original Matrices : "<<endl;
    cout<<"Matrix A("<<numRowA<<"x"<<numColA<<")"<<endl;
    display(A, numRowA, numColA);

    cout<<"Matrix B("<<numRowB<<"x"<<numColB<<")"<<endl;
    display(B, numRowB, numColB);

    int n = nextPowerofTwo(max(numRowA, max(numRowB, numColB)));
    cout<<"Next Power of Two : "<<n<<endl;

    vector<vector<int>> Apad = padMatrix(A, n);
    vector<vector<int>> Bpad = padMatrix(B, n);

    cout<<"Padded Matrices : "<<endl;
    cout<<"Matrix A("<<n<<"x"<<n<<")"<<endl;
    display(Apad, n, n);

    cout<<"Matrix B("<<n<<"x"<<n<<")"<<endl;
    display(Bpad, n, n);

    cout<<"Brute Force Matrix Multiplication  : "<<endl;
    vector<vector<int>> res3 = bruteForceMatMul(A, B, numRowA, numColA, numColB);
    display(res3, numRowA, numColB);    
    

    cout<<"Divide and Conquer Matrix Multiplication without Strassen : "<<endl;
    vector<vector<int>> res = MatMul(Apad, Bpad, n);
    display(res, n, n);

    cout<<"Strassens Matrix Multiplication : "<<endl;
    vector<vector<int>> res2 = StrassenMatMul(Apad, Bpad, n);
    display(res2, n, n);

    return 0;
}