#include <iostream>
#include <string>
using namespace std;


class stack
{
    int top;
    string str;

public:
    stack();
    void push(char x);
    char pop();
    bool empty();
    int check_palindrome(string input);
};

stack::stack()
{
    top = 0;
}

int main()
{
    stack s1;
    string input;
    int i, half;
    char token;
    int flag;

    cout << "Enter > ";
    cin >> input;


    half = input.size()/2;

    //push half of input into stack 
    for (i = 0; i < half; i++){   
        s1.push(input[i]);
    }

    flag = s1.check_palindrome(input);

    if(flag) cout << "Yes, It's a palindrome.\n";
    else return 0;

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

int stack::check_palindrome(string input) {
    int half = input.size() / 2;
    char token;
    int flag, i, start;

    if((input.size()%2) != 0) start = half+1;       //if input size is odd, then start from half+1
    else start = half;      //if input size is even, then start from half

    for (i = start; i<input.size(); i++) {
            token = pop();
            if(token != input[i]) {     //if token and input is not matched, then it is not a palindrome
                cout << "No, It's not a palindrome.\n";
                return 0;
            }
            else {      //It's a palindrome
                flag = 1;
            }
    }
    
    return flag;
}