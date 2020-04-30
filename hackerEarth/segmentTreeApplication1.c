//Zeros and Ones 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

bool isOdd(int num){
    if(num%2==1){
        return true;
    }
    return false;
}

int nearTwoPower(int num){
    int i=0;
    int dup=num;
    while(num>0){
        i++;
        num=num/2;
    }
    if(pow(2,i-1)==dup){
        return (int)pow(2,i-1);
    }
    return (int)pow(2,i);
}

int*buildSuitable(int*length){
    int tempLen=(*length);
    (*length)=nearTwoPower((*length));
    int*segmentTree=(int*)calloc(2*(*length)-1,sizeof(int));
    for(int i=(*length)-1;i<2*(*length-1);i++){
        segmentTree[i]=1;
    }
    for(int i=2*(*length)-2;i>((*length)+tempLen)-2;i--){
        segmentTree[i]=0;
    }
    for(int i=(*length)-2;i>=0;i--){
        segmentTree[i]=segmentTree[2*i+1]+segmentTree[2*i+2];
    }
    return segmentTree;
}

void update(int i,int*segmentTree,int length){ 
    segmentTree[length+i-1]=0;
    i=(length+i-2)/2;
    while(i>0){
        segmentTree[i]=segmentTree[2*i+1]+segmentTree[2*i+2];
        i=(i-1)/2;
    }
    segmentTree[0]=segmentTree[1]+segmentTree[2];
}

int getIndexRecur(int i,int*segmentTree,int length,int dupe,int p){
    if(i>segmentTree[0]){
        return -1;
    }
    if(p>=length-1 && p<(length)-1+dupe){
        return p+2-length;
    }
    if(p<length-1){
        if(segmentTree[2*p+1]<i){
            return getIndexRecur(i-segmentTree[2*p+1],segmentTree,length,dupe,2*p+2);
        }
        else{
            return getIndexRecur(i,segmentTree,length,dupe,2*p+1);
        }
    }
}

int getIndex(int i,int*segmentTree,int length,int dupe){
    return getIndexRecur(i,segmentTree,length,dupe,0);
}   

int main(){
    int num;
    scanf("%d",&num);
    int dupe=num;
    int*st=buildSuitable(&num);
    int queries;
    scanf("%d",&queries);
    int**twodArray=(int**)calloc(queries,sizeof(int*));
    for(int i=0;i<queries;i++){
        twodArray[i]=(int*)calloc(2,sizeof(int));
    }
    for(int i=0;i<queries;i++){
        scanf("%d %d",&twodArray[i][0],&twodArray[i][1]);
    }
    for(int i=0;i<queries;i++){
        if(twodArray[i][0]==0){
            update(twodArray[i][1]-1,st,num);
        }
        else if(twodArray[i][0]==1){
            printf("%d\n",getIndex(twodArray[i][1],st,num,dupe));
        }
    }
    return 0;
}