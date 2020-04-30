struct node*cleanerPresent,*cleanerNext;    
for(int c=0;c<PRIME;c++){
    if(hashTable[c]){
        cleanerPresent=hashTable[c];
        while(cleanerPresent->link){
            cleanerNext=cleanerPresent->link;
            hashTable[c]=cleanerNext;
            free(cleanerPresent);
            cleanerPresent=cleanerNext;
        }
        hashTable[c]=NULL;
        free(cleanerPresent);
    }
}