class Solution {
public:
    int minPartitions(string n) {
        int result = char2int(n.at(0));
        for(int i =0; i < n.size(); i++){
            if (result < char2int(n.at(i))){
                result = char2int(n.at(i));
            }
        }
        return result;
    }

    int char2int(char n){
        return n - '0';
    }
};
