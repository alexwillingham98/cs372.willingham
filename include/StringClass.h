#ifndef StringClass

#define StringClass

#include <iostream>

#include <string>

using namespace std;

//class StringContext

class StringContext

{
    
private:
    
    string values;
    
public:
    
    //constructor
    
    StringContext();
    
    //getter method
    
    string getStringValues();
    
    //setter method
    
    void setStringValues(string context);
    
};

#endif

StringContext::StringContext()

{
    
    values = "";
    
}

string StringContext::getStringValues()

{
    
    return values;
    
}

void StringContext::setStringValues(string context)

{
    
    values=context;
    
}


