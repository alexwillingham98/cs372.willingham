//
// File:   assignment1.cpp
// Author: Alex Willingham
// Purpose:
//Big O
//
//
#include<iostream>
//unfinished code
//inspired by https://www.chegg.com/homework-help/questions-and-answers/1-40-points-s-interesting-algorithm-int-equal-int-n-ado-int-j-k-1-q86120519
// given the type of code and how it iterates i would say the big o is O(n^2)
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


// Driver code
int main()
{
    int A[] = { 10, 20, 30, 40, 50,100,500,1000 };
    int x = 20;
    int n = sizeof(A) / sizeof(A[0]);
    
    // Function call
    int result = anyEqual(n, A);
    (result == -1);
    cout << "Element is present at index " << result;
    return 0;
}
