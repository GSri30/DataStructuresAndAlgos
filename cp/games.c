#include<stdio.h>

// int main(){
//     int array[30][2];
//     int number;int count;
//     scanf("%d",&number);
//     for(int i=0;i<number;i++){
//         scanf("%d %d",&array[i][0],&array[i][1]);
//     }
//     for(int j=0;j<number;j++){
//         for(int k=0;k<number;k++){
//             if(array[j][0]==array[k][1]){
//                 count++;
//             }
//         }
//     }
//     printf("%d",count);
//     return 0;
// }

int main()
{
    int n,i,j,x,y,cnt=0;
    scanf("%d",&n);
    int a[n],b[n];
    for(i=0; i<n; i++)
    {
        scanf("%d%d",&x,&y);
        a[i]=x;
        b[i]=y;
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(a[i]==b[j])
            {
                cnt++;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}