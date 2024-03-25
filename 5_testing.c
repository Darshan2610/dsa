#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_SIZE 30

int stack[MAX_SIZE];
int top = -1;

void push(int item)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    stack[++top] = item;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack[top--];
}

int main()
{
    char postfix[25];
    printf("Enter the Postfix expression: ");
    scanf("%s", postfix);

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char sym = postfix[i];
        if (isdigit(sym))
        {
            push(sym - '0'); // Convert char digit to integer
        }
        else
        {
            int op2 = pop();
            int op1 = pop();

            switch (sym)
            {
            case '+':
                push(op1 + op2);
                break;
            case '-':
                push(op1 - op2);
                break;
            case '*':
                push(op1 * op2);
                break;
            case '/':
                push(op1 / op2);
                break;
            case '%':
                push(op1 % op2);
                break;
            case '^':
                push(pow(op1, op2));
                break;
            default:
                printf("Invalid operator\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    int result = pop();
    printf("Result is %d\n", result);
    return 0;
}
