#include<stdio.h>
#include<stdlib.h>
#define max 6
int cq[max];
int front = -1, rear = -1;

void enq();
void deq();
void disp();

int main(){
    int done = 0, choice;
    while (!done) {
        printf("1.insert  2.del  3.display:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enq();
            break;
        case 2:
            deq();
            break;
        
        case 3:
            disp();
            break;
        
        default:
            done = 1;
            printf("\nstopped");
            break;
        }
    }
}

void enq(){
    int item;
    if((front == rear+1) || (front==0 && rear==max-1)){
        printf("queue is full\n");
    }
    else{
        if(front==-1)
            front = 0;
        printf("enter item: \n");
        scanf("%d", &item);
        rear = (rear + 1) % max;
        cq[rear] = item;
    }
}

void deq(){
    if(front ==-1 && rear ==-1){
        printf("q is empty\n");
    }
    else if (front == rear)
    {
        printf("item is %d", cq[front]);
        
    }
    else{
        printf("item is %d", cq[front]);
        front = (front + 1) % max;
    }
}

void disp(){
    int i;
    if(front>rear){
        
        for (i = front; i < max;i++){
            printf("items are %d\n", cq[i]);
        }
        for (i = 0; i <= rear;i++){
            printf("%d\n", cq[i]);
        }
    }
    else{
        for (i = front; i <= rear;i++){
            printf("items are %d\n", cq[i]);
        }
    }
}