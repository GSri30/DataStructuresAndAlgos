#define swap(x,y) {char temp=x;x=y;y=temp;}

void reverseString(char*string){
    int len=strlen(string);
    for(int i=0;i<len/2;i++){
        swap(string[i],string[len-i-1]);
    }
}