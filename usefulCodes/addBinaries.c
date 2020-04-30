char*addBinaries(char*num1,char*num2){
    int len1=strlen(num1),len2=strlen(num2);
    if(len2>len1){
        char*temp=num1;
        num1=num2;
        num2=temp;
        SWAP(len1,len2);
    }
    char*answer=(char*)calloc(100000,sizeof(char));
    int carry=0;
    int i;
    for(i=0;i<len2;i++){
        if(num1[len1-1-i]+num2[len2-1-i]-96>1){
            answer[i]=0+carry+'0';
            carry=1;
        }
        else if(num1[len1-1-i]+num2[len2-1-i]-96==1){
            if(carry){
                answer[i]=0+'0';
                carry=1;
            }
            else{
                answer[i]=1+'0';
                carry=0;
            }
        }
        else{
            answer[i]=carry+'0';
            carry=0;
        }
    }
    int j;
    for(j=i;j<i+len1-len2;j++){
        if(num1[len1-1-j]+carry-48>1){
            answer[j]=0+'0';
            carry=1;
        }
        else{
            answer[j]=num1[len1-1-j]+carry;   
            carry=0;
        }
    }
    if(carry){
        answer[j]=1+'0';
    }
    reverseString(answer);
    return answer;
}