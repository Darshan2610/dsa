#include <stdio.h>
#include <string.h>
#define max 6
void push(int[], int *, int);
int pop(int[], int *);
void disp(int[], int);
int pal(int[], int *, char[]);

int main()
{
    int stack[max],a, top = -1, ch, ele;
    char p[max];
    int done = 0;
    while (!done)
    {
        printf("1=push  2=pop  3=disp  4=pal\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter data: ");
            scanf("%d", &ele);
            push(stack, &top, ele);
            break;
        case 2:
            a =pop(stack, &top);
            break;
        case 3:
            disp(stack, top);
            break;
        case 4:
            printf("enter pal string");
            scanf("%s", p);
            top = -1;
            int flag = pal(stack, &top, p);
            if (flag == 1)
                printf("palindrome \n");
            else
                printf("not a palindrome");
            top = -1;
            break;
        default:
            done = 1;
            break;
        }
    }
    return 0;
}

void push(int stack[], int *top, int ele)
{
    if (*top == max - 1)
    {
        printf("stack is full");
    }
    ++(*top);
    stack[*top] = ele;
    // printf("element entered: %d\n", ele);
}

int pop(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("Stack Underflow \n");
    }
    int item = stack[*top];
    --(*top);
    printf("\nelement popped: %d\n", item);
    return item;
}

void disp(int stack[], int top)
{
    if (top == -1)
    {
        printf("stack underflows");
    }
    for (int i = top; i >= 0; i--)
    {
        printf("element is : %d", stack[i]);
    }
}

int pal(int stack[], int *top, char p[]){
    for (int i = 0;i<strlen(p);i++){
        push(stack, top, p[i]);
    }
    for (int i = 0; i < strlen(p); i++){
        if(p[i]!=pop(stack, top)){
            return -1;
    }
    return 1;
    
    }
}