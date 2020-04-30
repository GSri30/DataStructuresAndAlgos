#include<stdio.h>
#include<stdlib.h>

void cumulativeSum(int num[], int n, int cumsum[])
{
    cumsum[0] = 0;
    for(int i =1; i<n+1; i++)
    {
        cumsum[i] = cumsum[i-1] + num[i-1]; 
    }
}

void Merge(int array[], int left, int mid, int right)
{
    int l = left; int r = mid+1; int index = 0;
    int temp[1000];
    while(l <= mid && r <= right)
    {
        if(array[l] <= array[r])
            temp[index++] = array[l++];
        else
            temp[index++] = array[r++];
    }

    while (l<= mid) 
    {
        temp[index++] = array[l++];
    }
    while (r<= right)
    {
        temp[index++] = array[r++];
    }
    index = 0; l = left;
    while (l<=right)
    {
        array[l++] = temp[index++];
    }

}

void mergeKseq(int array[], int length[], int total, int k)
{
    int prefixSum[10000]; 
    cumulativeSum(length,k,prefixSum);

    int j = k;
    while(j>0)
    {
        int index = 1;
        for(int i =1; i<k; i+=2)
        {
            Merge(array,prefixSum[i-1],prefixSum[i]-1,prefixSum[i+1]-1);
            prefixSum[index++] = prefixSum[i+1];
        }

        if(k%2!=0)
            prefixSum[index++] = prefixSum[k];

        k = index-1;
        j-=2;    
    }
}

int main()
{
    int array[] = {1,2,3,2,3,4,5,3,4,7,8,5,6,7,9,12,2,6,8};
    int total = sizeof(array)/sizeof(int);
    int length[] = {3,4,4,5,2,1};
    int k = sizeof(length)/sizeof(int);
    
    mergeKseq(array,length,total,k);

    for(int i = 0; i<total; i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
    return 0;
}