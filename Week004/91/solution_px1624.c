int numDecodings(char * s){
    
    if(s[0] == '0') return 0;
    
    // memo[0] stores number of ways to decode string ending at i-2
    // memo[1] stores number of ways to decode string ending at i-1
    int memo[2]={1, 1};
    int numDecoding;
    int i=1;
    while(s[i]){
        numDecoding=0;
        // if current character can be decoded on its own, then the number
        // of ways to decode the current string ending at i is the same as the number
        // of ways to decode the string ending at i-1
        if(s[i] != '0')
            numDecoding = memo[1];
        // if current character and the previous character can be decoded together into a letter
        // then we add number of ways to decode string ending at i-2 to the total
        if(s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6'))
            numDecoding += memo[0];
        i++;
        
        // update number of ways for previous two positions
        memo[0] = memo[1];
        memo[1] = numDecoding;
    }
    return memo[1];
}