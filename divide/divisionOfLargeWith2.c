char*divide(char*num){
    char*answer=(char*)calloc(100000,sizeof(char));
    int len=strlen(num);
    int carry=0;
    for(int i=0;i<len;i++){
        if(i!=len-1){
            if(checkEven(num[len-2-i])){
            answer[i]='0'+(num[len-1-i]-48)/2;
            }
            else{
                answer[i]='0'+(num[len-1-i]-48)/2+5;
            }
        }
        else{
            if((num[len-1-i]-48)/2!=0){
                answer[i]='0'+(num[len-1-i]-48)/2;
            }
        }
    }
    reverseString(answer);
    return answer;
}