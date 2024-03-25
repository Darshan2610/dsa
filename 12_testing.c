#include<stdio.h>
#include<stdlib.h>
#define max 100

int create(int);
void linearprobe(int[], int, int);
void display(int[]);

int main()
{
    int a[max],choice, num, key, i;
    int ans = 1;
    printf("linear probing : ......");

    for (i = 0; i < max;i++){
        a[i] = -1;
    }
    do{
        printf(" enter emp id: ");
        scanf("%d", &num);
        key = create(num);
        linearprobe(a, key, num);
        printf("do you wish to enter more: (1/0) ");
        scanf("%d",&ans);
    } while (ans);
    display(a);

    return 0;
}

int create(int num){
    int key;
    key = num % max;
    return key;
}

void linearprobe(int a[],int key,int num){
    int flag = 0, i, count = 0;
    if(a[key]==-1){
        a[key] = num;
    }
    else{
        printf("collision occured:\n");
        for (i = 0; i < max;i++)
            if(a[i]!= -1)
                count++;
            printf("collison avoided:\n");
            if(count==max){
                printf("hash is full: \n");
                display(a);
                exit(1);
            }
            for (i = key + 1;i<max;i++) {
                if(a[i] == -1) {
                    a[i] = num;
                    flag = 1;
                    break;
                }
            }
            for (i = 0; i < key;i++)
                if(a[i]==-1){
                    a[i] = num;
                    flag = 1;
                    break;
                }
            
        
    }
}


void display(int a[max]){
    int i, ch;
    printf("1.full display  2.filtered: ");
    scanf("%d", &ch);
    if(ch == 1){
        for (i = 0; i <max;i++){
            printf("\n%d\t%d", i, a[i]);
            
        }
    }else{
        printf("filtered : \n");
        for (i = 0; i < max; i++)
        {
            if (a[i] != -1)
            {

                printf("%d  %d", i, a[i]);
                continue;
            }
            
        }
    }
    

}
