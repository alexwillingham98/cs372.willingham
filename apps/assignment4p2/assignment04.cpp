#include "StringClass.h"

#include <iostream>

#include <string>

#include <sstream>

#include <fstream>

using namespace std;

int main(int argc, char* argv[])
//inspired from https://www.chegg.com/homework-help/questions-and-answers/write-c-program-given-keyword-text-file-print-contexts-keyword-appears-file-define-context-q7292527
{
    
    //declare the required variables;
    
    string context;
    
    string filename;
    
    string keyword;
    
    string line;
    
    string words[100];
    
    string word;
    
    int count;
    
    int i;
    
    char ch;
    
    do
        
    {
        
        StringContext strings[30];
        
        count=0;
        
        //prompt the user to enter the file name
        
        cout<<"\nEnter a file name: ";
        
        cin>>filename;
        
        //create a file object
        
        ifstream fileIn(filename);
        
        //if the file exists then read the data from the file
        
        if(fileIn)
            
        {
            
            //prompt the user to enter the keyword
            
            cout<<"Enter a keyword: ";
            
            cin>>keyword;
            
            //read the data from the file
            
            while(!fileIn.eof())
                
            {
                
                //get line by line
                
                getline(fileIn, line);
                
                i=0;
                
                //split the line into words
                
                stringstream ss(line);
                
                while(ss>>word)
                    
                {
                    
                    //store the words into an array
                    
                    words[i]=word;
                    
                    i++;
                    
                }
                
                
                for(int j=0; j < i; j++)
                    
                {
                    
                    if(words[j].compare(keyword)==0)
                        
                    {
                        
                        context="";
                        
                        context+=words[j-2]+" ";
                        
                        context+=words[j-1]+" ";
                        
                        context+=words[j]+" ";
                        
                        context+=words[j+1]+" ";
                        
                        context+=words[j+2];
                        
                        strings[count].setStringValues(context);
                        
                    }
                    
                }
                
                count++;
                
            }
            
            //by using a loop print the data
            
            for(int l=0;l<count;l++)
                
            {
                
                cout<<" \""<<strings[l].getStringValues()<<" \""<<endl;
                
            }
            
        }
        
        //if the file does not exist then display an error message
        
        else
            
        {
            
            cout<<"\nSorry! Unable to open the file."<<endl;
            
        }
        
        //close the file
        
        fileIn.close();
        
        //prompt the user whether he wants to continue or not
        
        cout<<"\nWould you like to enter another file: Press (y), Quit (Q): ";
        
        cin>>ch;
