//Here lower end points should not collid (i.e. multiple intervals should not have same lower end points)

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int max(int x,int y){
    if(x>y){
        return x;
    }
    return y;
}

struct node{
    int highPoint;
    int lowPoint;
    int max;
    int height;
    struct node*left;
    struct node*right;
};

struct node*newnode(int low,int high){
    struct node*temp=(struct node*)calloc(1,sizeof(struct node));
    temp->lowPoint=low;
    temp->left=NULL;
    temp->right=NULL;
    temp->height=0;
    temp->highPoint=high;
    temp->max=high;
    return temp;
}

int height(struct node*node){
    if(node==NULL){
        return -1;
    }
    return node->height;
}

int getBalance(struct node*node){
    if(node==NULL){
        return 0;
    }
    return height(node->left)-height(node->right);
}

void updateMax(struct node*node){
    if(node){
        node->max=node->highPoint;
        if(node->left && node->left->max>node->max){
            node->max=node->left->max;
        }
        if(node->right && node->right->max>node->max){
            node->max=node->right->max;
        }
    }
}

struct node*rightRotate(struct node *node){ 
    struct node*child = node->left; 
    struct node*grandChild = child->right; 
    child->right = node; 
    node->left = grandChild; 
    node->height = max(height(node->left), height(node->right))+1; 
    child->height = max(height(child->left), height(child->right))+1;
    updateMax(node);
    updateMax(child); 
    return child; 
} 

struct node*leftRotate(struct node*node){ 
    struct node*child = node->right; 
    struct node*grandChild = child->left;
    child->left = node; 
    node->right = grandChild; 
    node->height = max(height(node->left), height(node->right))+1; 
    child->height = max(height(child->left), height(child->right))+1; 
    updateMax(node);
    updateMax(child); 
    return child; 
} 

struct node*insert(struct node*node, int low, int high){ 
    if(node == NULL){
        return(newnode(low,high)); 
    }   
    if (low < node->lowPoint){
        node->left=insert(node->left,low,high); 
    } 
    else if (low > node->lowPoint){
        node->right=insert(node->right,low,high); 
    } 
    else{
        return node; 
    }
    node->height=1+max(height(node->left),height(node->right)); 
    updateMax(node);
    int balance=getBalance(node); 
    //Left-Left case
    if(balance > 1 && low < node->left->lowPoint){
        return rightRotate(node); 
    } 
    //Left-Right case
    if(balance > 1 && low > node->left->lowPoint){ 
        node->left =  leftRotate(node->left); 
        return rightRotate(node); 
    }
    //Right-Right case
    if(balance < -1 && low > node->right->lowPoint){
        return leftRotate(node); 
    }
    //Right-Left case 
    if(balance < -1 && low < node->right->lowPoint){ 
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

struct node*delete(struct node* root, int low,int high) 
{ 
    if(root == NULL){
        return root; 
    } 
    if(low < root->lowPoint){
        root->left = delete(root->left, low,high); 
    } 
    else if (low > root->lowPoint){
        root->right = delete(root->right, low,high); 
    }
    else{ 
        if(root->left == NULL){ 
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
        root->lowPoint = temp->lowPoint; 
        root->highPoint=temp->highPoint;
        root->right = delete(root->right, temp->lowPoint,temp->highPoint); 
    } 

    root->height = 1 + max(height(root->left),height(root->right));
    updateMax(root);
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

bool overlap(struct node*root,int l,int h){
    while(root){
        //overlap condition
        if(root->lowPoint<=h && root->highPoint>=l){
            return true;
        }
        else if(root->left && root->left->max>=l){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return false;
}

int main(){
    int*inputLow=(int*)calloc(1000000,sizeof(int));
    int*inputHigh=(int*)calloc(1000000,sizeof(int));
    int len;
    scanf("%d",&len);
    for(int i=0;i<len;i++){
        scanf("%d %d",&inputLow[i],&inputHigh[i]);
    }
    struct node*root=NULL;
    for(int i=0;i<len;i++){
        root=insert(root,inputLow[i],inputHigh[i]);
    }
    //root=delete(root,7,8);
    printf("%d",overlap(root,2,4));
    free(inputLow);free(inputHigh);
    return 0;
}