//Here we pick the last row first element and proceed accordingly towards right or towards up

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

void findInMatrix(int**matrix,int row,int column,int toFind){
    int currenti=row-1,currentj=0,iteration=0;
    bool found=false;
    while(!found){
        if(matrix[currenti][currentj]==toFind){
            printf("Index: row=%d column=%d\nNumber of Iterations=%d",currenti,currentj,iteration);
            found=true;
        }
        else if(matrix[currenti][currentj]>toFind){
            currenti--;
        }
        else
        {
            currentj++;
        }
        iteration++;
    }
}

int main(){
    int rows,columns,find;
    scanf("%d %d %d",&rows,&columns,&find);
    int**input=(int**)calloc(rows,sizeof(int*));
    for(int i=0;i<rows;i++){
        input[i]=(int*)calloc(columns,sizeof(int));
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            scanf("%d",&input[i][j]);
        }
    }
    findInMatrix(input,rows,columns,find);
    //free
    return 0;
}