class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen=0, k=-1;
        vector<int> vec(128,-1);
        for (int i=0;i<s.size();i++){
            if(vec[int(s[i])]>k){
                k=vec[int(s[i])];
                vec[int(s[i])]=i;
            }
            else{
                vec[int(s[i])]=i;
                maxlen=max(maxlen,i-k);
            }
        }
        return maxlen;
    }
};
