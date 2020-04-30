#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 100003
#define MIN -100003
#define RANDOM 11111111

//No need of height

int max(int x,int y){
    if(x>y){
        return x;
    }
    return y;
}

struct node{
    int value;
    int key;
    int maxFreqValue;
    int maxFreqCount;
    struct node*left;
    struct node*right;
};

struct node*newnode(int key,int value){
    struct node*temp=(struct node*)calloc(1,sizeof(struct node));
    temp->key=key;
    temp->value=value;
    temp->maxFreqCount=1;
    temp->maxFreqValue=value;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

struct node*createBBST(int*array,int left, int right){
    struct node*node=NULL;
    if(left<=right){
        int middle=(left+right)/2;
        node=newnode(middle,array[middle]);
        node->left=createBBST(array,left,middle-1);
        node->right=createBBST(array,middle+1,right);
    }
    return node;
}






void updateValues(struct node*root){
    if(root==NULL){
        return;
    }
    else if(root->left==NULL && root->right==NULL){
        root->maxFreqValue=root->value;
        root->maxFreqCount=1;
    }
    else{
        updateValues(root->left);updateValues(root->right);
        int leftValue=RANDOM,rightValue=RANDOM,leftFreqValue=RANDOM,rightFreqValue=RANDOM,leftFreqCount=MIN,rightFreqCount=MIN;
        if(root->left){
            leftFreqValue=root->left->maxFreqValue;
            leftFreqCount=root->left->maxFreqCount;
            leftValue=root->left->value;
        }
        if(root->right){
            rightFreqValue=root->right->maxFreqValue;
            rightFreqCount=root->right->maxFreqCount;
            rightValue=root->right->value;
        }
        if(leftFreqValue==rightFreqValue && leftFreqValue==root->value){
            root->maxFreqCount=1+(leftFreqCount)+(rightFreqCount);
            root->maxFreqValue=leftFreqValue;
        }
        else{
            if(leftFreqValue==root->value){
                root->maxFreqValue=leftFreqValue;root->maxFreqCount=1+leftFreqCount;
                if(rightFreqCount>root->maxFreqCount){
                    root->maxFreqCount=rightFreqCount;root->maxFreqValue=rightFreqValue;
                }
            }
            else if(rightFreqValue==root->value){
                root->maxFreqValue=rightFreqValue;root->maxFreqCount=1+rightFreqCount;
                if(leftFreqCount>root->maxFreqCount){
                    root->maxFreqCount=leftFreqCount;root->maxFreqValue=leftFreqValue;
                }
            }
            else{
                //we can set what to return if left and right values and node are different but the left and right counts are same
                if(leftFreqCount>rightFreqCount){
                    root->maxFreqValue=leftFreqValue;root->maxFreqCount=leftFreqCount;
                }
                else{
                    root->maxFreqValue=rightFreqValue;root->maxFreqCount=rightFreqCount;
                }
            }
        }

    }
}

void recursion(struct node*root,int l,int r,int s,int e,int*element,int*count){
    if(s>e){
        *element=RANDOM;*count=RANDOM;
        return;
    }
    if(s>=l && r>=e){
        *element=root->maxFreqValue;*count=root->maxFreqCount;
        return;
    }
    else if(e<l || r<s){
        *element=RANDOM;*count=RANDOM;
        return ;
    }
    else{
        int m=(s+e)/2;
        if(l<=m && m<=r){
            *element=root->maxFreqValue;*count=root->maxFreqValue;
        }
        else if(m>r){
            recursion(root->left,l,r,s,m-1,element,count);
            return;
        }
        else if(m<l){
            recursion(root->right,l,r,m+1,e,element,count);
            return;
        }
        else{
            *element=RANDOM;*count=RANDOM;
            return;
        }
        recursion(root->right,l,r,m+1,e,element,count);
        int currentElementRight=*element,currentCountRight=*count;
        recursion(root->left,l,r,s,m-1,element,count);
        int currentElementLeft=*element,currentCountLeft=*count;
        if(currentCountLeft==RANDOM && currentCountRight==RANDOM && currentElementLeft==RANDOM && currentElementRight==RANDOM){
            *element=root->value;*count=1;return;
        }
        else if(currentCountRight==RANDOM && currentElementRight==RANDOM){
            if(currentElementLeft==root->value){
                *count=currentCountLeft+1;*element=currentElementLeft;
                return ;
            }
            else{
                *count=currentCountLeft;*element=currentElementLeft;
                return ;
            }    
        }
        else if(currentElementLeft==RANDOM && currentCountLeft==RANDOM){
            if(currentElementRight==root->value){
                *count=currentCountRight+1;*element=currentElementRight;
                return ;
            }
            else{
                *count=currentCountRight;*element=currentElementRight;
                return ;
            }
        }
        else{
            if(currentElementLeft==currentElementRight){
                *element=currentElementLeft;*count=currentCountLeft+currentCountRight;
                if(root->value==currentElementLeft){
                    *count=(*count)+1;
                }
                return;
            }
            else{
                if(currentElementLeft==root->value){
                    *element=currentElementLeft;*count=currentCountLeft+1;
                    if(*count<currentCountRight){
                        *count=currentCountRight;*element=currentElementRight;
                    }
                    return;
                }
                else if(currentElementRight==root->value){
                    *element=currentElementRight;*count=currentCountRight+1;
                    if(*count<currentCountLeft){
                        *count=currentCountLeft;*element=currentElementLeft;
                    }
                    return;
                }
                else{
                    if(currentCountLeft>currentCountRight){
                        *element=currentElementLeft;*count=currentCountLeft;
                    }
                    else{
                        *element=currentElementRight;*count=currentCountRight;
                    }
                    return;
                }
            }
        }
    }
}

int findMaxFreqElement(struct node*root,int len,int l,int r){
    int s=0,e=len-1,element,count;
    recursion(root,l,r,s,e,&element,&count);
    return element;
}







int main(){
    int*array=(int*)calloc(1000000,sizeof(int));
    int len;
    scanf("%d",&len);
    for(int i=0;i<len;i++){
        scanf("%d",&array[i]);
    }
    
    struct node*root=NULL;
    root=createBBST(array,0,len-1);
    updateValues(root);
    
    int m;
    scanf("%d",&m);
    for(int p=0;p<m;p++){
        int i,j;
        scanf("%d %d",&i,&j);
        printf("%d\n",findMaxFreqElement(root,len,i-1,j-1));
    }

    free(array);
    return 0;
}