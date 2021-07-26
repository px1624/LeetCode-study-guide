int numDecodings(char * s){
    if(s[0] == '0') return 0;
    
    // memo[0] stores number of ways to decode string ending at i-2
    // memo[1] stores number of ways to decode string ending at i-1
    int memo[2]={1, 1};
    long long numDecoding;
    int i=0;
    while(s[i]){
        numDecoding=0;
        // if current character can be decoded on its own
        if(s[i] != '0')
            numDecoding = memo[1];
        // 9x the decoding if current character is "*" since "*" can take values from 1-9
        if(s[i] == '*')
            numDecoding *= 9LL;

        // if current character and the previous character can be decoded together
        if(i-1 >= 0){
            // both digits are "*", there are 15 ways to decode it:
            // 11-19, 21-26 
            if(s[i-1] == '*' && s[i] == '*'){
                numDecoding += memo[0] * 15LL;
            // first digit is "*" and second digit is < 6, then "*" can be 1 or 2, doubling the number of encodings
            // otherwise the "*" can only be 1, the number of encodings is the same as memo[0]
            } else if(s[i-1] == '*'){
                if(s[i] <= '6')
                    numDecoding += memo[0] * 2;
                else
                    numDecoding += memo[0] * 1;
            // if second digit is "*" and first digit is 1, then there are 9 possible values "*" can take, 1-9
            // if first digit is 2, then there are 6 possible values "*" can take, 1-6
            } else if(s[i] == '*'){
                if(s[i-1] == '1'){
                    numDecoding += memo[0] * 9LL;
                } else if(s[i-1] == '2'){
                    numDecoding += memo[0] * 6LL;
                }
            // if none of the digits are "*", then check if two digits are within [10,26]
            } else if(s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6'))
                numDecoding += memo[0];
        }
        i++;
        numDecoding %= (int)pow(10,9) + 7;
        // update number of ways for previous two positions
        memo[0] = memo[1];
        memo[1] = numDecoding;
    }
    return memo[1];
}