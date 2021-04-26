#include <iostream>
#include <string>
using namespace std;

void printErr(char token);
int checking_err(string input, int index, char token);

class stack
{
    int top;
    string str;

public:
    stack();
    void push(char x);
    char pop();
    bool empty();
};

stack::stack()
{
    top = 0;
}

int main()
{
    stack s1;
    string input;
    int i, result;
    char token;

    cout << "Enter > ";
    cin >> input;

    for (i = 0; i < input.size(); i++)
    {   
        //if it is open parenthesis, push into stack
        if (input[i] == '(' || input[i] == '{' || input[i] == '[')
        {
            s1.push(input[i]);
        }
        //if it is close parentesis,
        else if (input[i] == ')' || input[i] == '}' || input[i] == ']')
        {
            if (s1.empty())     //if stack is empty (== there is extra parentesis), then error occurs
            {
                cout << "Error: An extra parenthesis '" << input[i] << "' is found.\n";
                return 0;
            }
            else token = s1.pop();

            result = checking_err(input, i, token);
            if (result) {       //if result is 1, then there is some error(mis-matched)
                printErr(token);
                return 0;
            }
        }
    }
    //after checking all inputs,and stack is not empty, then error occurs
    if(!s1.empty()) cout << "Error: Insufficient closing parenthesis\n";
    
    //else, there is no error at all
    else cout << "It's a normal expression.\n";
    return 0;
}

void stack::push(char x)
{
    str[top] = x;
    top++;
}

char stack::pop()
{
    top--;
    return str[top];
}

bool stack::empty()
{
    return (top == 0);
}

void printErr(char token)
{
    char expected;

    if(token == '(')
        expected = ')';
    else if(token == '{')
        expected = '}';
    else if(token == '[')
        expected = ']';
    cout << "Error: mis-matched parenthesis, '" << expected << "' is expected.\n";
}

int checking_err(string input, int index, char token){
    
    //check the input and if not matched, return 1 to indicate error
    if (input[index] == ')')
    {
        if (token != '(') {
            return 1;
        }
    }
    else if (input[index] == '}')
    {
        if (token != '{') {
            return 1;
        }
    }
    else if (input[index] == ']')
    {
        if (token != '[') {
            return 1;
        }
    }
    return 0;
}