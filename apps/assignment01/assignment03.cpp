#include <iostream>
#include <stack>
using namespace std ;
//inspired from geeksforgeeks.com
void infixToPostfix(string);
string infixToPrefix(string);
int main() {
    string infix;
    cout << "Type a fully parenthesized expression:" << endl;
    cin >> infix;
    cout << "Prefix:" << infixToPrefix(infix) << endl;
    cout << "Postfix:";
    infixToPostfix(infix);
    
    return 0;
}

int precedence(char c) {
    if(c == '^')
        return 3;
    else if(c == '/' || c=='*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(string s) {
    
    stack<char> st;
    string result;
    
    for(int i = 0; i < s.length(); i++) {
        char c = s[i];
        
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;
        
        else if(c == '(')
            st.push('(');
        
        else if(c == ')') {
            while(st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while(!st.empty() && precedence(s[i]) <= precedence(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()) {
        result += st.top();
        st.pop();
    }
    
    cout << result << endl;
}

bool isOperator(char c)
{
    return (!isalpha(c) && !isdigit(c));
}

int getPriority(char C)
{
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    return 0;
}

string infixToPostfix1(string infix)
{
    infix = '(' + infix + ')';
    int l = infix.size();
    stack<char> char_stack;
    string output;
    
    for (int i = 0; i < l; i++) {
        
        
        if (isalpha(infix[i]) || isdigit(infix[i]))
            output += infix[i];
        
        
        else if (infix[i] == '(')
            char_stack.push('(');
        
        
        else if (infix[i] == ')') {
            while (char_stack.top() != '(') {
                output += char_stack.top();
                char_stack.pop();
            }
            
            
            char_stack.pop();
        }
        
        
        else
        {
            if (isOperator(char_stack.top()))
            {
                if(infix[i] == '^')
                {
                    while (getPriority(infix[i]) <= getPriority(char_stack.top()))
                    {
                        output += char_stack.top();
                        char_stack.pop();
                    }
                    
                }
                else
                {
                    while (getPriority(infix[i]) < getPriority(char_stack.top()))
                    {
                        output += char_stack.top();
                        char_stack.pop();
                    }
                    
                }
                
                
                char_stack.push(infix[i]);
            }
        }
    }
    return output;
}

string infixToPrefix(string infix)
{
    int l = infix.size();
    
    
    reverse(infix.begin(), infix.end());
    
    
    for (int i = 0; i < l; i++) {
        
        if (infix[i] == '(') {
            infix[i] = ')';
            i++;
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
            i++;
        }
    }
    
    string prefix = infixToPostfix1(infix);
    
    reverse(prefix.begin(), prefix.end());
    
    return prefix;
}
