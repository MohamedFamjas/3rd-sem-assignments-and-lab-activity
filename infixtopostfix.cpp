#include <iostream>
using namespace std;

class Stack
{
    char s[50];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(char x)
    {
        s[++top] = x;
    }

    char pop()
    {
        return s[top--];
    }

    char peek()
    {
        return s[top];
    }

    int isEmpty()
    {
        return top == -1;
    }
};

int priority(char x)
{
    if (x == '^')
        return 3;
    if (x == '*' || x == '/')
        return 2;
    return 1;
}

int main()
{
    string infix, postfix = "";

    cout << "Enter infix expression: ";
    cin >> infix;

    Stack s;

    for (char x : infix)
    {
        if (x >= 'a' && x <= 'z')
            postfix += x;

        else if (x == '(')
            s.push(x);

        else if (x == ')')
        {
            while (s.peek() != '(')
                postfix += s.pop();

            s.pop();
        }

        else
        {
            while (!s.isEmpty() &&
                   priority(s.peek()) >= priority(x))
                postfix += s.pop();

            s.push(x);
        }
    }

    while (!s.isEmpty())
        postfix += s.pop();

    cout << "Postfix = " << postfix;

    return 0;
}