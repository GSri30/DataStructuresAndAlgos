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
    int data;
    int height;
    struct node*left;
    struct node*right;
};

struct node*newnode(int value){
    struct node*temp=(struct node*)calloc(1,sizeof(struct node));
    temp->data=value;
    temp->left=NULL;
    temp->right=NULL;
    temp->height=0;
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

struct node*rightRotate(struct node *node){ 
    struct node*child = node->left; 
    struct node*grandChild = child->right; 
    child->right = node; 
    node->left = grandChild; 
    node->height = max(height(node->left), height(node->right))+1; 
    child->height = max(height(child->left), height(child->right))+1; 
    return child; 
} 

struct node*leftRotate(struct node*node){ 
    struct node*child = node->right; 
    struct node*grandChild = child->left;
    child->left = node; 
    node->right = grandChild; 
    node->height = max(height(node->left), height(node->right))+1; 
    child->height = max(height(child->left), height(child->right))+1; 
    return child; 
} 

//No duplicates are allowed(If duplicates are entered,only the first is taken and the second is neglected)
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
    //Right-Right case
    if(balance < -1 && key > node->right->data){
        return leftRotate(node); 
    }
    //Right-Left case 
    if(balance < -1 && key < node->right->data){ 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    } 
    return node; 
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

int main(){
    int*input=(int*)calloc(1000,sizeof(int));
    int len;
    scanf("%d",&len);
    for(int i=0;i<len;i++){
        scanf("%d",&input[i]);
    }
    struct node*root=NULL;
    for(int i=0;i<len;i++){
        root=insert(root,input[i]);
    }
    //input:1 2 3 4 5 6
    //root=delete(root,1);
    // printf("%d",root->height);
    // root=delete(root,1);
    // printf("%d",root->height);
    levelorder(&root);
    free(input);
    return 0;
}