#include<stdio.h>
#include<stdlib.h>
#define MAX 1000000

int**adjacencyMatrix(int n){
    int**adjacencyMatrix=(int**)calloc(n,sizeof(int*));
    for(int i=0;i<n;i++){
        adjacencyMatrix[i]=(int*)calloc(n,sizeof(int));
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            adjacencyMatrix[i][j]=MAX;
        }
    }
    return adjacencyMatrix;
}

//for un-weighted graphs
void addIntoAM(int**adjacencyMatrix,int i,int j){
    if(!adjacencyMatrix[i][j]){
        adjacencyMatrix[i][j]=1;
    }
}

//for weighted graphs
void addIntoAM_W(int**adjacencyMatrix,int i,int j,int weight){
    adjacencyMatrix[i][j]=weight;
}

int main(){
    int**am=adjacencyMatrix(10);
    addIntoAM(am,0,5);
    printf("%d",am[0][5]);
    return 0;
}