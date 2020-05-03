//All pair shortest path problem
//Uses adjacency matrix

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

void addIntoAM_W(int**adjacencyMatrix,int i,int j,int weight){
    adjacencyMatrix[i][j]=weight;
}

int**floydWarshall(int**am,int n){
    int**sd=(int**)calloc(n,sizeof(int*));
    for(int i=0;i<n;i++){
        sd[i]=(int*)calloc(n,sizeof(int));
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sd[i][j]=am[i][j];
        }
    }
    for(int i=0;i<n;i++){
        sd[i][i]=0;
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(sd[i][j]>sd[i][k]+sd[k][j]){
                    sd[i][j]=sd[i][k]+sd[k][j];
                }
            }
        }
    }
    return sd;
}

int main(){
    int**am=adjacencyMatrix(4);
    addIntoAM_W(am,0,1,5);addIntoAM_W(am,0,2,10);addIntoAM_W(am,1,2,15);addIntoAM_W(am,2,3,20);
    int**sd=floydWarshall(am,4);
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            printf("%d ",sd[i][j]);
        }
        printf("\n");
    }
    return 0;
}