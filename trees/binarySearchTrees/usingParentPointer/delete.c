#include<stdlib.h>
#include<stdio.h>

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

//left==0    right==1
void delete(struct node**root,int value){
    struct node*pointer=*root;
    int num=-1;
    while(pointer->data!=value){
        if(pointer->data>value){
            pointer=pointer->left;
        }
        else{
            pointer=pointer->right;
        }
    }
    //To handle case where the node has 2 children
    if(pointer->left!=NULL && pointer->right!=NULL){
        struct node*minTracker=pointer->right;
        while(minTracker->left!=NULL){
            minTracker=minTracker->left;
        }
        pointer->data=minTracker->data;
        delete(&minTracker,minTracker->data);
    }
    //To handle case where the node is root node and has either of left or right childs or no childs
    else if(pointer->parent==NULL){
        if(pointer->left==NULL && pointer->right!=NULL){
            *root=pointer->right;
            pointer->right->parent=NULL;
            pointer->right=NULL;
            free(pointer);
            return ;
        }
        else if(pointer->right==NULL && pointer->left!=NULL){
            *root=pointer->left;
            pointer->left->parent=NULL;
            pointer->left=NULL;
            free(pointer);
            return ;
        }
        else{
            *root=NULL;
            free(pointer);
            return ;
        }
    }
    //To handle the case where the node has only 1 child or 0 child
    else{
        struct node*parentPointer=pointer->parent;
        if(parentPointer->left!=NULL && parentPointer->left->data==value){
            num=0;
        }
        else{
            num=1;
        }
        if(pointer->left==NULL){
            if(num==0){
                parentPointer->left=pointer->right;
                if(pointer->right!=NULL){
                    pointer->right->parent=parentPointer;
                }
                pointer->right=NULL;
                pointer->parent=NULL;
                free(pointer);
                return ;
            }
            else if(num==1){
                parentPointer->right=pointer->right;
                if(pointer->right!=NULL){
                    pointer->right->parent=parentPointer;
                }
                pointer->right=NULL;
                pointer->parent=NULL;
                free(pointer);
                return ;
            }
        }
        else if(pointer->right==NULL){
            if(num==0){
                parentPointer->left=pointer->left;
                if(pointer->left!=NULL){
                    pointer->left->parent=parentPointer;
                }
                pointer->left=NULL;
                pointer->parent=NULL;
                free(pointer);
                return ;
            }
            else if(num==1){
                parentPointer->right=pointer->left;
                if(pointer->left!=NULL){
                    pointer->left->parent=parentPointer;
                }
                pointer->left=NULL;
                pointer->parent=NULL;
                free(pointer);
                return ;
            }
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
    buildBST(&root,input,len);
    levelorder(&root);
    delete(&root,3);
    printf("\n");
    levelorder(&root);
    free(input);
    return 0;
}