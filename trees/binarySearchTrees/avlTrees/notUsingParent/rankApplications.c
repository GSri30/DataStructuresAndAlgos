//For these kind of problems, we generally include anthoer slot called count, which stores the number of the nodes present in the subtree (rooted at this node)

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    int height;
    int count;
    struct node*left;
    struct node*right;
};

int max(int x,int y){
    if(x>y){
        return x;
    }
    return y;
}

struct node*newnode(int value){
    struct node*temp=(struct node*)calloc(1,sizeof(struct node));
    temp->data=value;
    temp->left=NULL;
    temp->right=NULL;
    temp->height=0;
    temp->count=1;
    return temp;
}

int height(struct node*node){
    if(node==NULL){
        return -1;
    }
    return node->height;
}

int count(struct node*node){
    if(node==NULL){
        return 0;
    }
    return node->count;
}

int getBalance(struct node*node){
    if(node==NULL){
        return 0;
    }
    return height(node->left)-height(node->right);
}

struct node*rightRotate(struct node *node){ 
    struct node*child = node->left; 
    struct node*grandChild = child->right; 
    child->right = node; 
    node->left = grandChild; 
    node->height = max(height(node->left), height(node->right))+1; 
    node->count=1+count(node->left)+count(node->right);
    child->height = max(height(child->left), height(child->right))+1;
    child->count=1+count(child->left)+count(child->right);
    return child; 
} 

struct node*leftRotate(struct node*node){ 
    struct node*child = node->right; 
    struct node*grandChild = child->left;
    child->left = node; 
    node->right = grandChild; 
    node->height = max(height(node->left), height(node->right))+1;
    node->count=1+count(node->left)+count(node->right); 
    child->height = max(height(child->left), height(child->right))+1;
    child->count=1+count(child->left)+count(child->right); 
    return child; 
}

struct node*insert(struct node*node, int key){ 
    if(node == NULL){
        return(newnode(key)); 
    }   
    if (key < node->data){
        node->left=insert(node->left, key); 
    } 
    else if (key > node->data){
        node->right=insert(node->right, key); 
    } 
    else{
        return node; 
    }
    node->height=1+max(height(node->left),height(node->right)); 
    node->count=1+count(node->left)+count(node->right); 
    int balance=getBalance(node); 
    //Left-Left case
    if(balance > 1 && key < node->left->data){
        return rightRotate(node); 
    } 
    //Left-Right case
    if(balance > 1 && key > node->left->data){ 
        node->left =  leftRotate(node->left); 
        return rightRotate(node); 
    }
    //Right-Left case 
    if(balance < -1 && key > node->right->data){
        return leftRotate(node); 
    }
    //Right-Right case
    if(balance < -1 && key < node->right->data){ 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    } 
    return node; 
}

/*Delete*/
struct node*minValueNode(struct node*node) 
{ 
    struct node* current = node;
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 

struct node*delete(struct node* root, int key) 
{ 
    if(root == NULL){
        return root; 
    } 
    if(key < root->data){
        root->left = delete(root->left, key); 
    } 
    else if (key > root->data){
        root->right = delete(root->right, key); 
    }
    else{ 
        if (root->left == NULL){ 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if(root->right == NULL){ 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        }
        struct node* temp = minValueNode(root->right); 
        root->data = temp->data; 
        root->right = delete(root->right, temp->data); 
    } 

    root->height = 1 + max(height(root->left),height(root->right));
    root->count=1+count(root->left)+count(root->right);
    int balance = getBalance(root);
    if(balance > 1 && getBalance(root->left) >= 0){
        return rightRotate(root);
    } 
    if(balance > 1 && getBalance(root->left) < 0){ 
        root->left =  leftRotate(root->left); 
        return rightRotate(root); 
    }
    if(balance < -1 && getBalance(root->right) <= 0){
        return leftRotate(root);
    } 
    if(balance < -1 && getBalance(root->right) > 0){ 
        root->right = rightRotate(root->right); 
        return leftRotate(root); 
    }

    return root; 
}

bool search(struct node*root,int key){
    if(root==NULL){
        return 0;
    }
    if(root->data==key){
        return 1;
    }
    else if(root->data>key){
        return search(root->left,key);
    }
    else if(root->data<key){
        return search(root->right,key);
    }
    return 0;
}


//Given node value, find its rank!
//If the key doesnot exist, then return -1
int rank(struct node*root,int value){
    if(root==NULL){
        return -1;
    }
    int rank=0;
    while(root){
        if(root->data==value){
            if(root->right){
                rank+=(root->right->count);
            }
            return rank;
        }
        else if(root->data>value){
            if(root->right){
                rank+=(root->right->count);
            }
            rank+=1;
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return -1;
}

//Given rank, return a pointer to the node whose rank is this!
//If there doesnot exist any, then return null pointer
struct node*findRank(struct node*root,int rank){
    int calRank=0;
    while(root){
        if(count(root->right)==rank){
            return root;
        }
        else if(count(root->right)>rank){
            root=root->right;
        }
        else{
            rank-=(1+count(root->right));
            root=root->left;
        }
    }
    return NULL;
}

int findRankAndReturnData(struct node*root,int rank){
    struct node*ptr=findRank(root,rank);
    if(ptr){
        return ptr->data;
    }
    return -1;
}

//rangeCount returns number of numbers between l and r (included)
int rangeCount(struct node*root,int l,int r){
    if(l>r){
        return 0;
    }
    int count=0;
    count+=(rank(root,l)-rank(root,r));
    if(search(root,l)){
        count++;
    }
    return count;
}

int main(){
    int*input=(int*)calloc(1000000,sizeof(int));
    int length;
    scanf("%d",&length);
    for(int i=0;i<length;i++){
        scanf("%d",&input[i]);
    }
    struct node*root=NULL;
    for(int i=0;i<length;i++){
        root=insert(root,input[i]);
    }
    printf("%d",rangeCount(root,3,2));
    free(input);
    return 0;
}