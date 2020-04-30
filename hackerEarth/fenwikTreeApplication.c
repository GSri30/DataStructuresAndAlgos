// Akash and too many assignments

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void update(char*array,int i,int alphabet,int**fenwikTree,int n){
    int olderAlphabet=array[i]-'a';
    array[i]=alphabet+'a';
    int j=i+1;
    while(j<n+1){
        fenwikTree[j][alphabet]++;
        j=j+(j&(-j));
    }
    int k=i+1;
    while(k<n+1){
        fenwikTree[k][olderAlphabet]--;
        k=k+(k&(-k));
    }
}

int frequenceTillRange(int i,int alphabet,int**fenwikTree,int n){
    int j=i+1;
    int s=0;
    while(j>0){
        s+=fenwikTree[j][alphabet];
        j=j-(j&(-j));
    }
    return s;
}

int**buildTree(char*array,int n){
    int**fenwikTree=(int**)calloc(1000001,sizeof(int*));
    for(int i=0;i<n+1;i++){
        fenwikTree[i]=(int*)calloc(30,sizeof(int));
    }
    for(int i=0;i<26;i++){
        fenwikTree[0][i]=0;
    }
    for(int i=0;i<n;i++){
        int j=i+1;
        while(j<n+1){
            fenwikTree[j][array[i]-'a']++;
            j=j+(j&(-j));
        }
    }
    return fenwikTree;
}

void solveProblem(int l,int r,int k,int**fenwikTree,int n){
    int sum=0;int i;
    for(i=0;i<26;i++){
        sum+=(frequenceTillRange(r,i,fenwikTree,n)-frequenceTillRange(l-1,i,fenwikTree,n));
        if(sum>=k){
            break;
        }
    }
    if(sum>=k){
        printf("%c\n",i+'a');
    }
    else{
        printf("Out of range\n");
    }
}

int main(){
    int n,q;
    int op,l,r,k,ind;
    char c[1];
    scanf("%d %d",&n,&q);
    char*input=(char*)calloc(1000000,sizeof(char));
    scanf("%s",input);
    int**fenwikTree=buildTree(input,n);
    for(int i=0;i<q;i++){
        scanf("%d",&op);
        if(op==0){
            scanf("%d %c",&ind,c);
            update(input,ind-1,c[0]-'a',fenwikTree,n);
        }
        else{
            scanf("%d %d %d",&l,&r,&k);
            solveProblem(l-1,r-1,k,fenwikTree,n);
        }
    }
    free(input);
    return 0;
}
