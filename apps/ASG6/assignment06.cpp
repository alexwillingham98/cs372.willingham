//
// File:   assignment1.cpp
// Author: Alex Willingham
// Purpose:
//Big O
//
//
#include<iostream>
//unfinished code
using namespace std;
int anyEqual(int n, int A[50][20]) {
    
    int i, j, k, m;
    
    for (i = 0; i <= n; i++) {
        
        for (j = 0; j <= n; j++) {
            
            for (k = 0; k <= n; k++) {
                
                for (m = 0; m <= n; m++) {
                    
                    if ((A[i][j] == A[k][m]) && !(i == k && j == n)) {
                        
                        return 1;
                    }
                }
            }
        }
    }
}
int main(){
    int n;
    cout<<"Please enter size of matrix:"<<endl;
    cin>>n;
    int A[n][n];
    cout<<"Enter the matrix element one by one"<<endl;
    for (int i =0; i<n; i++){
        for (int j=0; j< n; j++){
            cin>>A[i][j];
        }
    }
    
    
    return 0;
}
