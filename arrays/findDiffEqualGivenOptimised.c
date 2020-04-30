#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//search for index q
int searchFor(int*list,int number,int left,int right){
    int middle=(left+right)/2;
    if(left<=right){
        if(*(list+middle)==number){
            return middle;
        }
        else if(*(list+middle)>number){
            return searchFor(list,number,left,middle-1);
        }
        return searchFor(list,number,middle+1,right);
    }
    return -1;
}

//fix index p and search for p+x using binary search
void findDifference(int*list,int length,int x){
    int check=0,j;
    for(int i=0;i<length;i++){
        int left=i,right=length-1;
        j=searchFor(list,x+*(list+i),left,right);
        if(j>-1){
            check++;
            printf("Index: p=%d q=%d after sorting!\n",i,j);
        }
    }
    if(check==0){
        if(j==-1){
            printf("No match found!");
        }
    }
}

void merge(int a[],int i,int k,int j){
    int left=i,right=k+1,p=0;
    int*b=(int*)calloc(100000,sizeof(int));
    while(left<=k && right<=j){
        if(a[left]<a[right]){
            b[p++]=a[left++];
        }
        else
        {
            b[p++]=a[right++];
        }
    }
    while (left<=k)
    {
        b[p++]=a[left++];
    }
    while (right<=j)
    {
        b[p++]=a[right++];
    }
    p=0;left=i;
    while(left<=j){
        a[left++]=b[p++];
    }   
    free(b); 
}

void mergeSort(int a[],int i,int j){
    if(i<j){
        int k=(i+j)/2;
        mergeSort(a,i,k);
        mergeSort(a,k+1,j);
        merge(a,i,k,j);
    }
}
//sort the list

int main(){
    int*input=(int*)calloc(100000,sizeof(int));
    int length;
    scanf("%d",&length);
    for(int i=0;i<length;i++){
        scanf("%d",&input[i]);
    }
    int x;
    scanf("%d",&x);
    mergeSort(input,0,length-1);
    findDifference(input,length,x);
    free(input);
    return 0;
}