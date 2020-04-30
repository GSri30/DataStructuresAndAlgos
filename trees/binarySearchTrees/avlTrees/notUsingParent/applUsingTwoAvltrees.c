// You are given a sequence ofndistinct intergersa0, a1, . . . an−1.  In eachiteration you pick the maximum number and delete it, the cost detetingthe maximum number is the number of numbers to the left of it. Repeatthisnnumber of times.  Givenai’s implemetO(nlogn) algorithm tocompute the total cost ofniterations.

#include<stdio.h>
#include<stdlib.h>

struct node1{
    int key;
    int value;
    int height;
    struct node1*left;
    struct node1*right;
};

int max(int x,int y){
    if(x>y){
        return x;
    }
    return y;
}

struct node1*newnode(int key,int value){
    struct node1*temp=(struct node1*)calloc(1,sizeof(struct node1));
    temp->key=key;
    temp->value=value;
    temp->left=NULL;
    temp->right=NULL;
    temp->height=0;
    return temp;
}

int height(struct node1*node){
    if(node==NULL){
        return -1;
    }
    return node->height;
}

int getBalance(struct node1*node){
    if(node==NULL){
        return 0;
    }
    return height(node->left)-height(node->right);
}

struct node1*rightRotate(struct node1*node){ 
    struct node1*child = node->left; 
    struct node1*grandChild = child->right; 
    child->right = node; 
    node->left = grandChild; 
    node->height = max(height(node->left), height(node->right))+1; 
    child->height = max(height(child->left), height(child->right))+1; 
    return child; 
} 

struct node1*leftRotate(struct node1*node){ 
    struct node1*child = node->right; 
    struct node1*grandChild = child->left;
    child->left = node; 
    node->right = grandChild; 
    node->height = max(height(node->left), height(node->right))+1; 
    child->height = max(height(child->left), height(child->right))+1; 
    return child; 
} 

struct node1*insert(struct node1*node, int key,int value){ 
  if(node == NULL){
      return(newnode(key,value)); 
  }   
  if (value < node->value){
      node->left=insert(node->left, key,value); 
  } 
  else if (value > node->value){
      node->right=insert(node->right, key , value ); 
  } 
  else{
      return node; 
  }
  node->height=1+max(height(node->left),height(node->right)); 
  int balance=getBalance(node); 
  if(balance > 1 && value < node->left->value){
      return rightRotate(node); 
  } 
  if(balance > 1 && value > node->left->value){ 
      node->left =  leftRotate(node->left); 
      return rightRotate(node); 
  }
  if(balance < -1 && value > node->right->value){
      return leftRotate(node); 
  } 
  if(balance < -1 && value < node->right->value){ 
      node->right = rightRotate(node->right); 
      return leftRotate(node); 
  } 
  return node; 
} 

struct node1*minValueNode1(struct node1*node) 
{ 
    struct node1* current = node;
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 

struct node1*delete1(struct node1* root, int key) 
{ 
    if(root == NULL){
        return root; 
    } 
    if(key < root->value){
        root->left = delete1(root->left, key); 
    } 
    else if (key > root->value){
        root->right = delete1(root->right, key); 
    }
    else{ 
        if (root->left == NULL){ 
            struct node1 *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if(root->right == NULL){ 
            struct node1 *temp = root->left; 
            free(root); 
            return temp; 
        }
        struct node1* temp = minValueNode1(root->right); 
        root->value = temp->value; 
        root->key=temp->key;
        root->right = delete1(root->right, temp->value); 
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

struct node1*findMax(struct node1*node){
  while(node->right){
    node=node->right;
  }
  return node;
}






struct node2{
    int key;
    int count;
    struct node2*left;
    struct node2*right;
};

struct node2 * create2(int l,int r)
{
  struct node2 *node = NULL;
  if (l <= r)
    {
      int m = (l + r) / 2;
      node = (struct node2 *) malloc (sizeof (struct node2));
      node->key = m;

      node->left = create2 (l, m - 1);

      node->right = create2 (m + 1, r);

    }

  return node;
};

void updateCount(struct node2*node){
  if(node==NULL){
    return;
  }
  updateCount(node->left);updateCount(node->right);
  node->count=1;
  if(node->left){
    node->count += node->left->count;
  }
  if(node->right){
    node->count += node->right->count;
  }
}

void count(struct node2*node){
  if(node==NULL){
    return;
  }
  node->count=1;
  if(node->left){
    node->count += node->left->count;
  }
  if(node->right){
    node->count += node->right->count;
  }
}

struct node2*minValueNode2(struct node2*node) 
{ 
    struct node2* current = node;
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
}

struct node2*delete2(struct node2*root,int key){
  if(root==NULL){
    return root;
  }
  else if(key<root->key){
    root->left=delete2(root->left,key);
  }
  else if(key>root->key){
    root->right=delete2(root->right,key);
  }
  else{
    if (root->left == NULL){ 
      struct node2 *temp = root->right; 
      free(root); 
      return temp; 
    } 
    else if(root->right == NULL){ 
      struct node2 *temp = root->left; 
      free(root); 
      return temp; 
    }
    struct node2* temp = minValueNode2(root->right); 
    root->key = temp->key; 
    root->right = delete2(root->right, temp->key); 
  }
  if(root){
    root->count=1;
    if(root->left){
      root->count += root->left->count;
    }
    if(root->right){
      root->count += root->right->count;
    }
  }
  return root;
}

void calculateCount(struct node2*root,int key,int*calCount){
  while(1){
    if(root==NULL){
    return;
    }
    if(key>root->key){
      if(root->left){
        (*calCount)+=(root->left->count);
      }
      (*calCount)+=1;
      root=root->right;
    }
    else if(key<root->key){
      root=root->left;
    }
    else{
      if(root->left){
        (*calCount)+=(root->left->count);
      }
      return;
    }
  }
}


int main(){
  int array[50];
  int length;
  scanf("%d",&length);
  int i=0,j=0,k=0;
  for(i=0;i<length;i++){
    scanf("%d",&array[i]);
  }
  struct node1*rootMain=NULL;
  struct node2*rootIndices=NULL;
  for(j=0;j<length;j++){
    rootMain=insert(rootMain,j,array[j]);
  }
  rootIndices=create2(0,length-1);
  updateCount(rootIndices);  
  int answer=0;
  for(k=0;k<length;k++){
    struct node1*maximum=findMax(rootMain);
    int countt=0;
    calculateCount(rootIndices,maximum->key,&countt);
    answer+=countt;
    rootIndices=delete2(rootIndices,maximum->key);
    rootMain=delete1(rootMain,maximum->value);
  }
  printf("%d",answer);
  return 0;
}
