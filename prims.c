#include<stdio.h>
#include<stdlib.h>
int find(int);
int uni(int, int);
int cost[9][9], parent[9], min = 0,mincost = 0,ne = 1, i, j,a,b,u,v,n;

int main(){
    printf("enter nodes:");
    scanf("%d", &n);
    printf("enter matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n;j++){
            scanf("%d", &cost[i][j]);
            if(cost[i][j]==0){
                cost[i][j] = 999;
            }
        }
    }
    parent[1] = 1;
    while(ne<n){
        for (i = 1, min = 999; i <= n;i++){
            for (j = 1; j <= n;j++){
                if(cost[i][j]<min){
                    if(parent[i]!=0){
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                    }

                }
            }
        }
        printf("edge %d (%d -> %d) = %d\n", ne++, a, b, min);
        parent[b] = 1;
        mincost += min;
        cost[a][b] = cost[b][a] = 999;
    }
    printf("minimum cost is = %d", mincost);

    return 0;
}
//0 2 1 0
//2 0 3 1
// 1 3 0 2
// 4 1 2 0
