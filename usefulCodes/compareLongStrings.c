int compare(char*num1,char*num2){
    int len1=strlen(num1),len2=strlen(num2);
    if(len1>len2){
        return 1;
    }
    else if(len1<len2){
        return -1;
    }
    else
    {
        int i=0;
        while(i<len1){
            if(num1[i]>num2[i]){
                return 1;
            }
            else if(num1[i]<num2[i])
            {
                return -1;                
            }
            i++;
        }
    }
    return 0;
}