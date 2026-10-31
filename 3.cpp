#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct Node {
    char data;
    Node *next;
};

Node *top = NULL;

void push(char x) {
    Node *newNode = new Node;
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

char pop() {
    if (top == NULL)
        return '\0';

    Node *temp = top;
    char x = temp->data;
    top = top->next;
    delete temp;

    return x;
}

char peek() {
    if (top == NULL)
        return '\0';

    return top->data;
}

int precedence(char x) {
    if (x == '^')
        return 3;
    if (x == '*' || x == '/')
        return 2;
    if (x == '+' || x == '-')
        return 1;
    return 0;
}

bool isOperator(char x) {
    return x == '+' || x == '-' ||
           x == '*' || x == '/' || x == '^';
}

bool isRightAssociative(char x) {
    return x == '^';
}

string infixToPostfix(string infix) {
    string postfix = "";

    while (top != NULL)
        pop();

    for (int i = 0; i < infix.length(); i++) {
        char x = infix[i];

        if (x == ' ')
            continue;

        if (isalnum(x)) {
            postfix += x;
        }
        else if (x == '(') {
            push(x);
        }
        else if (x == ')') {
            while (top != NULL && peek() != '(')
                postfix += pop();

            if (top != NULL)
                pop();
        }
        else if (isOperator(x)) {
            while (top != NULL && peek() != '(' &&
                   (precedence(peek()) > precedence(x) ||
                   (precedence(peek()) == precedence(x) &&
                   !isRightAssociative(x)))) {
                postfix += pop();
            }

            push(x);
        }
    }

    while (top != NULL)
        postfix += pop();

    return postfix;
}

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    string prefix = infixToPostfix(infix);

    reverse(prefix.begin(), prefix.end());

    return prefix;
}

int main() {
    string infix;

    cout << "Enter infix expression: ";
    cin >> infix;

    cout << "Postfix Expression: "
         << infixToPostfix(infix) << endl;

    cout << "Prefix Expression: "
         << infixToPrefix(infix) << endl;

    return 0;
}