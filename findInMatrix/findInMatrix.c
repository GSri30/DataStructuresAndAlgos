//Given an number, find whether it is present in matrix or not
//This is worst method

#include<stdio.h>
#include<stdlib.h>

void findInMatrix(int**matrix,int rows,int columns,int toFind){
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            if(matrix[i][j]==toFind){
                printf("Index: row=%d column=%d\n",i,j);
            }
        }
    }
}

int main(){
    int row,column,find;
    scanf("%d %d %d",&row,&column,&find);
    int**input=(int**)calloc(row,sizeof(int*));
    for(int i=0;i<row;i++){
        input[i]=(int*)calloc(column,sizeof(int));
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            scanf("%d",&input[i][j]);
        }
    }
    findInMatrix(input,row,column,find);
    //free using loop(come from inside)
    return 0;
}