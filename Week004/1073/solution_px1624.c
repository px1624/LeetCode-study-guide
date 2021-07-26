

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* addNegabinary(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){
    int maxSize = arr1Size>arr2Size ? arr1Size : arr2Size;
    maxSize += 2;
    int *result = malloc(sizeof(int) * maxSize);
    // carry[0] store the carry for the next digit
    // carry[1] stores the carry for the digit after next digit
    int carry[2] = {0,0};
    int i;
    for(i=0; i<maxSize; ++i){
        int arr1Num = arr1Size-i-1 >= 0 ? arr1[arr1Size-i-1] : 0;
        int arr2Num = arr2Size-i-1 >= 0 ? arr2[arr2Size-i-1] : 0;
        int sum = arr1Num + arr2Num + carry[0];
        result[maxSize-1-i] = sum % 2;
        carry[0] = carry[1];
        carry[1] = 0;
        // carry over two digits
        if(sum>1){ carry[1]++; carry[0]++; }
        // check if carry-over can be cancelled
        if(carry[1]==1 && carry[0]==2){ carry[1]=0; carry[0]=0; }
    }
    
    // remove leading zeros
    for(i=0; i<maxSize; ++i){
        if(result[i])
            break;
    }
    // get return size
    if(i >= maxSize) i = maxSize-1;
    *returnSize = maxSize-i;
    // create final result
    int *finalResult = malloc(sizeof(int)*(*returnSize));
    memcpy(finalResult, result+i, sizeof(int)*(*returnSize));
    free(result);
    return finalResult;
}