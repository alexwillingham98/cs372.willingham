//
// File:   assignment1.cpp
// Author: Alex Willingham
// Purpose:
// Towers of Hanoi/ Recursive
//
#include <iostream>
#include <chrono>
using namespace std;
//recursive solution
//code inspired from https://www.geeksforgeeks.org/iterative-tower-of-hanoi/

void moveDisks(int j, char from_rod,
               char to_rod, char aux_rod)
{
    if (j == 1)
    {
        cout << "Move disk 1 from rod " << from_rod <<
        " to rod " << to_rod<<endl;
        return;
    }
    moveDisks(j - 1, from_rod, aux_rod, to_rod);
    cout << "Move disk " << j << " from rod " << from_rod <<
    " to rod " << to_rod << endl;
    moveDisks(j - 1, aux_rod, to_rod, from_rod);
}

// Driver code
int main()
{
    clock_t start = clock();
    
    int n = 100;
    int i=0;
    while(i<100*n)
        i++;
    int j = 30;
    moveDisks(j, 'A', 'C', 'B');
    cout << "All of the pegs are moved!" << endl;
    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    
    return 0;
}
