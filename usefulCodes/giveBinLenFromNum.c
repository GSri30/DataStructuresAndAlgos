//just gives the len of the binary which is obtained by converting the input

int giveBinLen(char*number){
    int len=strlen(number);
    int i=0;
    while(strlen(number)){
        number=divide(number);
        i++;
    }
    return i;
}