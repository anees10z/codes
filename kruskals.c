#include<stdio.h>
#define MAX 30

struct Edges{
    int u,v,w;
};

void sort(struct Edges e[MAX], int m){
    int i,j;
    struct Edges temp;
    // Sort according to min cost
    for(i = 0; i<m; i++){
        for(j =0; j<m-i-1; ++j){
            if(e[j].w >= e[j+1].w){
                temp = e[j];
                e[j] = e[j+1];
                e[j+1] = temp;
            }
        }
    }
}

int findparent(int parent[], int v){
    if(parent[v] == v)
        return v;
    return findparent(parent, parent[v]);
}

void unionSet(int parent[], int a, int b)
{
    parent[a] = b;
}

void kruskals(int n, int m, struct Edges e[]){
    struct Edges result[MAX];
    int parent[MAX];
    int a,b;
    int i, j;
    int cost= 0;
    
    sort(e, m);
    
    for(i=0; i<n; ++i){
        parent[i] = i;
    }
    
    j=0;
    for(i=0; i<m && j<n-1; ++i){
        a = findparent(parent, e[i].u);
        b = findparent(parent, e[i].v);
        
        if(a!=b){
            result[j] = e[i];
            cost+=e[i].w;
            unionSet(parent, a, b);
            j++;
        }
    }
    
    printf("\nEdges in MST: ");
    for(i=0; i<j; ++i){
        printf("\n(%d --> %d) - cost = %d ",result[i].u, result[i].v, result[i].w);
    }
    
    printf("\nMinimum cost = %d", cost);
}

int main()
{
    struct Edges e[MAX];
    int i, n, m;
    
    printf("\nEnter the number of vertex: ");
    scanf("%d", &n);
    
    printf("\nEnter the number of edges: ");
    scanf("%d", &m);
    
    printf("\nEnter edge details:\n");
    for(i=0; i<m; ++i){
        printf("Egde: %d (src dest weigth) : ", i+1);
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
    }
    
    kruskals(n,m,e);
}
