#include <stdio.h>

int priority(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '$':
        case '^':
            return 3;
        case '(':
            return 4;
        default:
            return -1;
    }
}

int isTerm(char symb) {
    if (symb >= 'a' && symb <= 'z') return 1;  // is small letter?
    if (symb >= 'A' && symb <= 'Z') return 1;  // is capital letter?
    if (symb >= '0' && symb <= '9') return 1;  // is a digit?
    if (symb == ' ') return 1;                 // is a space?
    return 0;
    // Or just
    // return (symb >= 'a' && symb <= 'Z') || (symb >= 'A' && symb <= 'Z') ||
    //        (symb >= '0' && symb <= '9') || (symb == ' ');
}

void infixToPostfix(char *infix, char *postfix) {
    char stack[100];
    int top = -1;
    int postindex = 0;
    for (int i = 0; infix[i]; ++i) {
        char symb = infix[i];
        if (isTerm(symb)) {
            // Insert to postfix
            postfix[postindex++] = symb;
        } else if (symb == ')') {
            // Insert stack elements to postfix until we find the '('
            while (stack[top] != '(') postfix[postindex++] = stack[top--];
            // Top will be pointing to '('. So pop it
            top--;
        } else if (priority(symb) >= priority(stack[top])) {
            // Push to stack only if the priority is greater than or equal
            stack[++top] = symb;
        } else {
            // Until the symb has less priority and top of stack is not '(' pop
            // to postfix
            while (priority(symb) < priority(stack[top]) && stack[top] != '(')
                postfix[postindex++] = stack[top--];

            // Now push the symb to stack
            stack[++top] = symb;
        }
    }
    // Never forget to end the string with the null character
    postfix[postindex] = 0;
}

int main() {
    char infix[100], postfix[100];
    int i;

    printf("Enter a valid infix expression: ");
    // Write from index 1 since we are going to put '(' in the 0th index
    scanf(" %[^\n]", &infix[1]);

    // Add paranthesis around the infix expression
    // Add ( at the beginning of the expression
    infix[0] = '(';
    // Go till the last character
    for (i = 1; infix[i]; ++i);
    // Add ) at the end of the expression
    infix[i] = ')';
    // Don't forget to add the null character at the end of string
    infix[i + 1] = 0;

    infixToPostfix(infix, postfix);
    printf("Postfix expression is: %s\n", postfix);
}
