#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char item) {
    stack[++top] = item;
}

char pop() {
    return stack[top--];
}

int priority(char symbol) {
    if (symbol == '(') return 0;
    else if (symbol == '+' || symbol == '-') return 1;
    else if (symbol == '*' || symbol == '/' || symbol == '%') return 2;
    else if (symbol == '^' || symbol == '$') return 3;
    else return 0;
}

void infixToPostfix(char infix[]) {
    printf("Postfix Expression: ");
    for (int i = 0; infix[i] != '\0'; i++) {
        char symb = infix[i];
        if (isalnum(symb))
            printf("%c ", symb);
        else if (symb == '(')
            push(symb);
        else if (symb == ')') {
            while (stack[top] != '(')
                printf("%c ", pop());
            pop(); // Discard the '('
        } else {
            while (priority(stack[top]) >= priority(symb))
                printf("%c ", pop());
            push(symb);
        }
    }
}

int main() {
    printf("ASSUMPTION: The Infix Expression contains single-letter variables and single-digit constants only.\n");
    char infix[SIZE];
    printf("\nEnter the Infix Expression: ");
    scanf("%s", infix);
    push('(');
    strcat(infix, ")");
    infixToPostfix(infix);
    return 0;
}
