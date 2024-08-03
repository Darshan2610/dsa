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
    while(ne<n){
        for (i = 1, min = 999; i <= n;i++){
            for (j = 1; j <= n;j++){
                if(cost[i][j]<min){
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);

        if(uni(u,v)){
            printf("edge %d (%d -> %d) = %d", ne++, a, b, min);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\nminimum cost = %d\n", mincost);
    return 0;
}

int find(int i){
    while(parent[i])
        i = parent[i];
    return i;
}

int uni(int i,int j){
    if(i!=j){
        parent[j] = i;
        return 1;
    }
    return 0;
}
