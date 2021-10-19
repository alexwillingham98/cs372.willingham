//
// File:   assignment1.cpp
// Author: Alex Willingham
// Purpose:
// Towers of Hanoi/ Iterative
//
#include <iostream>
#include <chrono>
#include <cmath>
using namespace std;
//inspired by https://www.geeksforgeeks.org/iterative-tower-of-hanoi/
struct Stack
{
    unsigned capacity;
    int top;
    int *array;
};

struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack =
    (struct Stack*) malloc(sizeof(struct Stack));
    stack -> capacity = capacity;
    stack -> top = -1;
    stack -> array =
    (int*) malloc(stack -> capacity * sizeof(int));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{
    return (stack->top == stack->capacity - 1);
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{
    return (stack->top == -1);
}

// Function to add an item to stack. It increases
// top by 1
void push(struct Stack *stack, int item)
{
    if (isFull(stack))
        return;
    stack -> array[++stack -> top] = item;
}

int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack -> array[stack -> top--];
}

void moveDisk(char fromPeg, char toPeg, int disk)
{
    cout <<"Move the disk " << disk <<" from " << fromPeg << " to "<< toPeg << endl;
}


void moveDisksBetweenTwoPoles(struct Stack *src,
                              struct Stack *dest, char s, char d)
{
    int pole1TopDisk = pop(src);
    int pole2TopDisk = pop(dest);
    
    if (pole1TopDisk == INT_MIN)
    {
        push(src, pole2TopDisk);
        moveDisk(d, s, pole2TopDisk);
    }
    
    else if (pole2TopDisk == INT_MIN)
    {
        push(dest, pole1TopDisk);
        moveDisk(s, d, pole1TopDisk);
    }
    
    else if (pole1TopDisk > pole2TopDisk)
    {
        push(src, pole1TopDisk);
        push(src, pole2TopDisk);
        moveDisk(d, s, pole2TopDisk);
    }
    
    else
    {
        push(dest, pole2TopDisk);
        push(dest, pole1TopDisk);
        moveDisk(s, d, pole1TopDisk);
    }
}

//Function to implement TOH puzzle
void tohIterative(int num_of_disks, struct Stack
                  *src, struct Stack *aux,
                  struct Stack *dest)
{
    int i, total_num_of_moves;
    char s = 'A', d = 'B', a = 'C';
    
    //If number of disks is even, then interchange
    //destination pole and auxiliary pole
    if (num_of_disks % 2 == 0)
    {
        char temp = d;
        d = a;
        a = temp;
    }
    total_num_of_moves = pow(2, num_of_disks) - 1;
    
    //Larger disks will be pushed first
    for (i = num_of_disks; i >= 1; i--)
        push(src, i);
    
    for (i = 1; i <= total_num_of_moves; i++)
    {
        if (i % 3 == 1)
            moveDisksBetweenTwoPoles(src, dest, s, d);
        
        else if (i % 3 == 2)
            moveDisksBetweenTwoPoles(src, aux, s, a);
        
        else if (i % 3 == 0)
            moveDisksBetweenTwoPoles(aux, dest, a, d);
    }
}

// Driver Code
int main()
{
    clock_t start = clock();
    
    int n = 100;
    int i=0;
    while(i<100*n)
        i++;
    
    unsigned num_of_disks = 25;
    
    struct Stack *src, *dest, *aux;
    
    src = createStack(num_of_disks);
    aux = createStack(num_of_disks);
    dest = createStack(num_of_disks);
    
    tohIterative(num_of_disks, src, aux, dest);
    cout << "All the disks are moved!" << endl;
    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    
    return 0;
    
}
