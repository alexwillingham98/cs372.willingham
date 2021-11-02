//
//  assignment9pt3.cpp
//
//
//  Created by Alex Willingham on 11/2/21.
#include <iostream>
#include <fstream>
#include <string>
//because of how i initially created my tasks, i wasn;t really sure how to incorporate a priority queue with the list, but this is a start.
using namespace std;

typedef struct node
{
    int data;
 
    int priority;
 
    struct node* next;
 
} Node;
 
Node* newNode(int d, int p)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;
 
    return temp;
}
 
int peek(Node** head)
{
    return (*head)->data;
}
 
void pop(Node** head)
{
    Node* temp = *head;
    (*head) = (*head)->next;
    free(temp);
}
 
void push(Node** head, int d, int p)
{
    Node* start = (*head);
 
    
    Node* temp = newNode(d, p);
 
    
    if ((*head)->priority > p)
    {
         
        
        temp->next = *head;
        (*head) = temp;
    }
    else
    {
         
        
        while (start->next != NULL &&
            start->next->priority < p)
        {
            start = start->next;
        }
 
        
        temp->next = start->next;
        start->next = temp;
    }
}
 

int isEmpty(Node** head)
{
    return (*head) == NULL;
}
 
int main(){
    
    
    
    ifstream file ("asg4.txt");
    string readout,
    taskNum,state,statement,line;
    bool quit = false;

    while(!quit){
    cout << "Select from one of the options:(1-4)";
    cout << "\n\n";
    cout << "1. Display all items\n";
    cout << "2. Display selected item\n";
    cout << "3. Mark as task done\n";
    cout << "4. Exit the program\n";

 int selection;

        
     Node* pq = newNode(4, 1);
            push(&pq, 5, 2);
            push(&pq, 6, 3);
            push(&pq, 7, 0);
         
            while (!isEmpty(&pq))
            {
                cout << " " << peek(&pq);
                pop(&pq);
            }
            
        
 cin >> selection;
    switch (selection) {
        case 1:
            if (file.is_open()) {
                while (getline(file, readout)) {
                    cout << readout << endl;
                }

            }
            break;
        case 2:
            cout << "Which item would you like to see?(1-4)\n";

            if (file.is_open()) {
                int Line;
                cin >> Line;
                for (int i = 1; i <= Line; i++)
                    getline(file, line);
                cout << line;

            }
            break;
        case 3:
            cout << "Mark as task done" << endl;
            break;
        case 4:
            quit = true;

    }
    }
    return 0;
};
