#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*left;
    struct node*right;
    struct node*parent;
};

struct node*node(int value,struct node*currentNodeParent){
    struct node*temp=(struct node*)calloc(1,sizeof(struct node));
    temp->data=value;
    temp->left=NULL;
    temp->right=NULL;
    temp->parent=currentNodeParent;
}

void buildBST(struct node**root,int*array,int length){
    *root=node(array[0],NULL);
    struct node*pointer=NULL;
    for(int i=1;i<length;i++){
        pointer=*root;
        while(1){
            if(array[i]<pointer->data){
                if(pointer->left!=NULL){
                    pointer=pointer->left;
                }
                else{
                    pointer->left=node(array[i],pointer);
                    break;
                }
            } 
            else{
                if(pointer->right!=NULL){
                    pointer=pointer->right;
                }
                else{
                    pointer->right=node(array[i],pointer);
                    break;
                }
            }
        }
    }
}

//Given a sorted sequence,build the bst
struct node*buildFromSorted(int*array,int l,int r){
    int m=(l+r)/2;
    struct node*temp=NULL;
    if(l<=r){
        temp=node(array[m],NULL);
        temp->left=buildFromSorted(array,l,m-1);
        temp->right=buildFromSorted(array,m+1,r);
        if(temp->left){
            temp->left->parent=temp;
        }
        if(temp->right){
            temp->right->parent=temp;
        }
    }
    return temp;
}



void levelorder(struct node**root){
    if(*root==NULL){
        return ;
    }
    struct node*queue[10000];
    int head=-1,tail=-1;
    struct node*ptr=*root;
    queue[++tail]=ptr;head++;
    while(tail-head>-1){
        printf("%d ",queue[head++]->data);
        ptr=queue[head-1];
        if(ptr->left){
            queue[++tail]=ptr->left;
        }
        if(ptr->right){
            queue[++tail]=ptr->right;
        }
    }
}

int main(){
    int*input=(int*)calloc(100000,sizeof(int));
    int len;
    scanf("%d",&len);
    for(int i=0;i<len;i++){
        scanf("%d",&input[i]);
    }
    struct node*root=NULL;
    //buildBST(&root,input,len);
    //root=buildFromSorted(input,0,len-1);
    levelorder(&root);
    free(input);
    return 0;
}