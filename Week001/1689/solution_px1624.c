int minPartitions(char * n){
    char min = 0;
    while(*n){
        if(*n - '0' == 9){
            return 9;
        } else if(*n - '0' > min){
            min = *n - '0';
        }
        n++;
    }
    return (int)min;
}