#include <iostream>
#include <string>
#define EOS '$'
using namespace std;

bool is_operand(char x);
int get_precedence(char op);

class stack {
    int top;
    string str;
    public:
            stack();
            void push(char x);
            char pop();
            bool empty();
            char top_element();
};

stack::stack() {
    top = 0;
}

int main() {
    string input, output;
    stack s1;
    int top_precedence, token_precedence;
    int i;
    char token;

    cout << "Enter infix expression to replace with Postfix expression > ";
    cin >> input;

    input += EOS;
    s1.push(EOS);

    for(i=0;i<input.size();i++) {
        if(is_operand(input[i])) 
            output += input[i];
        else {
            if(input[i] == '(') 
                s1.push(input[i]);
            else if(input[i] == ')') {
                while(1) {
                    token = s1.pop();
                    if(token == '(') break;
                    else output += token;
                }
            }
            else {
                while(1) {
                    token_precedence = get_precedence(input[i]);
                    top_precedence = get_precedence(s1.top_element());
                    if(token_precedence <= top_precedence) {
                        token = s1.pop();
                        if(token != '$')
                            output += token;
                    }
                    else break;
                }
                s1.push(input[i]);
            }
        }
    }

    cout << output << "\n";
    return 0;
}

void stack::push(char x) {
    str[top] = x;
    top++;
}

char stack::pop() {
    top--;
    return str[top];
}

bool stack::empty() {
    return (top==0);
}

char stack::top_element() {
    return (str[top-1]);
}

bool is_operand(char x) {
    if((x == '$') || (x == '(') || (x == ')') || (x == '+') || (x == '-') || (x == '*') || (x == '/') || (x == '%'))
        return false;
    else return true;
}

int get_precedence(char op) {
    if((op == '$') || (op == '('))
        return 0;
    if((op == '+') || (op == '-'))
        return 1;
    if((op == '*') || (op == '/') || (op == '%'))
        return 2;
    else return -1;
}