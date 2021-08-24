//
// File:   assignment1.cpp
// Author: Alex Willingham
// Purpose:
// Illustrate some of the bad thins that can happen with
// pointers
//
#include <iostream>
using namespace std;


int main() {
  //Problem A

  int* firstP = new int [100000];
  int* secondP = new int [100000];
  //array delete of the first pointer
  delete[] firstP;
    for (int i = 0; i <= 10; i++)
    {
        cout << secondP[i];
    }
    cout << "\n";
  //Problem B
  int* newP = new int [200000];
  int* newerP = new int [200000];
  //regular delete of the first pointer
  delete newP;
    for (int b = 0; b <= 10; b++)
    {
        cout << newerP[b];
    }
    cout << "\n";
  //Problem C


  return 0;
}
