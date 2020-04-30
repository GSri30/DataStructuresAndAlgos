char*makeDuplicate(char*string){
    char*dupe=(char*)calloc(100000,sizeof(char));
    for(int i=0;i<strlen(string);i++){
        dupe[i]=string[i];
    }
    return dupe;
}