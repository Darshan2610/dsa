#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

char stack[25];
int top = -1;
void push(char item){
    stack[++top] = item;
}

char pop(){
    return stack[top--];
}

int priority(char symbol){
    if(symbol == '(')  return 0;
    else if (symbol=='+' || symbol=='-')   return 1;
    else if(symbol=='*'|| symbol== '/'||symbol=='%')
        return 2;
    else if(symbol=='^'||symbol=='$')
        return 3;
    else
        return 0;
}

void infix_post(char infix[])
{
    printf("postfix expression is : ");
    for (int i = 0; infix[i] != '\0'; i++)
    {
        char sym = infix[i];

        if (isalnum(sym))
            printf("%c ", sym);
        else if (sym == '(')
        {
            push(sym);
        }
        else if (sym == ')')
        {
            while (stack[top] != '(')
                printf("%c ", pop());
            pop();
        }
        else
        {
            while (priority(stack[top]) >= priority(sym))
            {
                printf("%c ", pop());
            }
            push(sym);
        }
    }
}

    int main()
{
    char infix[25];
    printf("enter infix exp: ");
    scanf( "%s",infix);
    push('(');
    strcat(infix,")"); //add opening and closing
    infix_post(infix); 

    return 0;
}

