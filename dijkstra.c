#include<stdio.h>
int main(){
    int c[10][10], d[10], i, j, s, n;
    printf("enter no of nodes: ");
    scanf("%d", &n);
    printf("enter cost matrix\n");
    for (i = 1; i <= n;i++){
        for (j = 1; j <= n; j++){
            scanf("%d", &c[i][j]);
        }
    }
    printf("enter source node: ");
    scanf("%d", &s);
    dij(c, s, n, d);
    for (i = 1; i <= n;i++){
        printf("shortest distance from node %d to node %d is %d\n", s, i, d[i]);
    }
    return 0;

}

void dij(int c[10][10],int s,int n, int d[10]){
    int v[10] ,min,i,j,u;

    for (i = 1; i <= n;i++){
        d[i] = c[s][i];
        v[i] = 0;
    }
    v[s] = 1;
    for (i = 1; i <= n;i++){
        min = 999;
        for (j = 1; j <= n;j++){
            if(v[j]==0 && d[j]<min){
                min = d[j];
                u = j;

            }
        }
        v[u] = 1;
        for (j = 1; j <= n;j++){
            if(v[j]==0 && (d[u] + c[u][j] < d[j]))
                d[j] = d[u] + c[u][j];
        }
    }
}
