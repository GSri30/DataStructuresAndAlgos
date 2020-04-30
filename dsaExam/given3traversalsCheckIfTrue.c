#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*left;
    struct node*right;
};

struct node*newNode(int value)
{
    struct node*temp=calloc(1,sizeof(struct node));
    temp->data=value;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

int Search(int*arr,int start,int end,int value)
{
    int i;
    for(i=start;i<=end;i++){
        if (arr[i]==value){
            return i;
        }
    }
}

int compare(int*array1,int*array2,int len){
    for(int i=0;i<len;i++){
        if(array1[i]!=array2[i]){
            return 1;
        }
    }
    return 0;
}

int returnPreOrder(struct node*node,int*preOrderFound,int i)
{
    if(node==NULL){
        return i;
    }
    preOrderFound[i++]=node->data;
    i=returnPreOrder(node->left,preOrderFound,i);
    i=returnPreOrder(node->right,preOrderFound,i);
}

struct node*build(int*inOrder,int*postOrder,int iStart,int iEnd,int*pIndex)
{
    if(iStart>iEnd){
        return NULL;
    }
    struct node*node=newNode(postOrder[*pIndex]);
    (*pIndex)--;
    if(iStart==iEnd){
        return node;
    }
    int iIndex=Search(inOrder,iStart,iEnd,node->data);
    node->right=build(inOrder,postOrder,iIndex+1,iEnd,pIndex);
    node->left=build(inOrder,postOrder,iStart,iIndex-1,pIndex);
    return node;
}

struct node*buildtree(int*inOrder,int*postOrder,int n)
{
    int pIndex=n-1;
    return build(inOrder,postOrder,0,n-1,&pIndex);
}

int main(){
    int*inOrder=(int*)calloc(1000000,sizeof(int));
    int*preOrder=(int*)calloc(1000000,sizeof(int));
    int*postOrder=(int*)calloc(1000000,sizeof(int));
    int*preOrderFound=(int*)calloc(1000000,sizeof(int));
    int size=0;
    for(int i=0;i<6;i++){
        scanf("%d",&preOrder[i]);
    }
    for(int i=0;i<6;i++){
        scanf("%d",&postOrder[i]);
    }
    for(int i=0;i<6;i++){
        scanf("%d",&inOrder[i]);
    }
    while(inOrder[size]!='\0'){
        size++;
    }
    struct node*root=buildtree(inOrder,postOrder,size);
    returnPreOrder(root,preOrderFound,0);
    if(!compare(preOrder,preOrderFound,size)){
        printf("YES");
    }
    else{
        printf("NO");
    }
    free(inOrder);free(preOrder);free(postOrder);
    return 0;
}