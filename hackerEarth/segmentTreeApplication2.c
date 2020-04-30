//Update and query

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include<string.h>

int abs(int num){
    if(num<0){return -num;}
    return num;
}

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

int*buildMin(int*array,int*length){
    int tempLen=(*length);
    array[tempLen]=2147483646;
    *length=nearTwoPower(*length);
    int*segmentTree=(int*)calloc(2*(*length)-1,sizeof(int));
    for(int i=0;i<*length;i++){
        segmentTree[(*length)+i-1]=i;
    }
    //Fill of extra nodes
    for(int i=2*(*length)-2;i>((*length)+tempLen)-2;i--){
        segmentTree[i]=tempLen;
    }
    for(int i=(*length)-2;i>=0;i--){
        if(array[segmentTree[2*i+1]]>array[segmentTree[2*i+2]]){
            segmentTree[i]=segmentTree[2*i+2];
        }
        else{
            segmentTree[i]=segmentTree[2*i+1];
        }
    }
    return segmentTree;
}

void updateMin(int*array,int length,int i,int x,int*segmentTree){
    array[i]=x;
    i=(i+length-2)/2;
    while(i>0){
        if(array[segmentTree[2*i+1]]>array[segmentTree[2*i+2]]){
            segmentTree[i]=segmentTree[2*i+2];
        }
        else{
            segmentTree[i]=segmentTree[2*i+1];
        }
        i=(i-1)/2;
    }
}

int*buildMax(int*array,int*length){
    int tempLen=(*length);
    array[tempLen]=-2147483646;
    *length=nearTwoPower(*length);
    int*segmentTree=(int*)calloc(2*(*length)-1,sizeof(int));
    for(int i=0;i<*length;i++){
        segmentTree[(*length)+i-1]=i;
    }
    //Fill of extra nodes
    for(int i=2*(*length)-2;i>((*length)+tempLen)-2;i--){
        segmentTree[i]=tempLen;
    }
    for(int i=(*length)-2;i>=0;i--){
        if(array[segmentTree[2*i+1]]<array[segmentTree[2*i+2]]){
            segmentTree[i]=segmentTree[2*i+2];
        }
        else{
            segmentTree[i]=segmentTree[2*i+1];
        }
    }
    return segmentTree;
}

void updateMax(int*array,int length,int i,int x,int*segmentTree){
    array[i]=x;
    i=(i+length-2)/2;
    while(i>0){
        if(array[segmentTree[2*i+1]]<array[segmentTree[2*i+2]]){
            segmentTree[i]=segmentTree[2*i+2];
        }
        else{
            segmentTree[i]=segmentTree[2*i+1];
        }
        i=(i-1)/2;
    }
}

int nextRightMin(int*array,int*st,int length,int i,int c){
    int p=0,s=0,e=length-1,j=-1;
    while(p<length-1){
        int m=(s+e)/2;
        if(i<m){
            if(array[st[2*p+2]]<array[i]-c){
                j=2*p+2;
            }
            p=2*p+1;
            e=m;
        }
        else{
            p=2*p+2;
            s=m+1;
        }
    }
    if(array[st[p]]>=array[i]-c){
        if(j==-1){
            return -1;
        }
        while(j<length-1){
            if(array[st[2*j+1]]<array[i]-c){
                j=2*j+1;
            }
            else{
                j=2*j+2;
            }
        }
        return st[j];
    }
    return st[p];
}

int nextRightMax(int*array,int*st,int length,int i,int c){
    int p=0,s=0,e=length-1,j=-1;
    while(p<length-1){
        int m=(s+e)/2;
        if(i<m){
            if(array[st[2*p+2]]>array[i]+c){
                j=2*p+2;
            }
            p=2*p+1;
            e=m;
        }
        else{
            p=2*p+2;
            s=m+1;
        }
    }
    if(array[st[p]]<=array[i]+c){
        if(j==-1){
            return -1;
        }
        while(j<length-1){
            if(array[st[2*j+1]]>array[i]+c){
                j=2*j+1;
            }
            else{
                j=2*j+2;
            }
        }
        return st[j];
    }
    return st[p];
}

//xmax ymin
int min(int x,int y){
    if(x==-1){
        return y;
    }
    else if(y==-1){
        return x;
    }
    return x<y ? x:y;
}

int query(int*input,int length,int*stMin,int*stMax,int x,int c){
    x--;
    if(c<0){
        return -1;
    }
    return abs(min(nextRightMax(input,stMax,length,x,c),nextRightMin(input,stMin,length,x,c))-x);
}

void update(int*input,int length,int x,int y,int*stMin,int*stMax){
    updateMin(input,length,x-1,y,stMin);
    updateMax(input,length,x-1,y,stMax);
}

int bsearchForZ(int*input,int length,int*stMin,int*stMax,int x,int q,int l,int r){
    int m=(l+r)/2;
    int quer=query(input,length,stMin,stMax,x,m);
    if(l==r && quer!=-1 && quer==q){
        return l;
    }
    if(l<r){
        if(quer!=-1 && quer==q){
            return bsearchForZ(input,length,stMin,stMax,x,q,l,m);
        }
        else{
            return bsearchForZ(input,length,stMin,stMax,x,q,m+1,r);
        }
    }
    return -1;
}

int main(){
    int*input=(int*)calloc(1000000,sizeof(int));
    int length;
    scanf("%d",&length);
    int queries;
    scanf("%d",&queries);
    for(int i=0;i<length;i++){
        scanf("%d",&input[i]);
    }
    int*stMin=buildMin(input,&length);
    int*stMax=buildMax(input,&length);
    for(int i=0;i<2*queries;i++)
    {
        int x,y;
        char queryType[2];
        scanf("%c %d %d",queryType,&x,&y);
        if(strcmp("Q",queryType)==0){
            int q=query(input,length,stMin,stMax,x,y);
            int binaryS=bsearchForZ(input,length,stMin,stMax,x,q,0,y);
            printf("%d %d\n",q,binaryS);
        }
        else if(strcmp("U",queryType)==0){
            update(input,length,x,y,stMin,stMax);
        }
    }    
    free(input);
    return 0;
}