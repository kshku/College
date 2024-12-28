#include <math.h>
#include <stdio.h>

int main() {
    char postfix[100];
    int stack[100], top = -1;
    printf("Enter valid suffix expression(numberic operands): ");
    scanf(" %[^\n]", postfix);

    for (int i = 0; postfix[i]; ++i) {
        char symb = postfix[i];
        if (symb >= '0' && symb <= '9') {  // Input is a digit, push to stack
            // Convert the ASCII character to integer value and push
            stack[++top] = symb - '0';
        } else {
            // First pop second operand.
            int op2 = stack[top--];
            // Then first operand
            int op1 = stack[top--];
            // After performing the operation push result to stack
            switch (symb) {
                case '+':
                    stack[++top] = op1 + op2;
                    break;
                case '-':
                    stack[++top] = op1 - op2;
                    break;
                case '*':
                    stack[++top] = op1 * op2;
                    break;
                case '/':
                    // If dividing by 0 then push 0 as error handling
                    if (op2 == 0) {
                        printf("Divided by zero\n");
                        stack[++top] = 0;
                    }
                    stack[++top] = op1 / op2;
                    break;
                case '%':
                    stack[++top] = op1 % op2;
                    break;
                case '^':
                    stack[++top] = pow(op1, op2);
                    break;
                default:  // Should not reach here
                    printf("Invaild suffix expression?\n");
                    // Push 0 to stack as error handling
                    stack[++top] = 0;
            }
        }
    }
    printf("Result = %d\n", stack[top--]);
}
