//This solution contains comments. If you don't need it, please see the file called "solution_NOcomment_hcao.cpp"



class Solution {
public:
    int minPartitions(string n) {
      /*
        We already know "n consists of only digits" && "n does not contain any leading zeros and represents a positive integer"; 
        therefore, we should trust the n here. 
        Otherwise, please test the property of n first 
      */
      //Initialize the result as the first number in the string && convert char to int:
        int result = char2int(n.at(0));
      //Finding the largest number in the string:
        for(int i =0; i < n.size(); i++){
            if (result < char2int(n.at(i))){
                result = char2int(n.at(i));
            }
        }
        return result;
    }

    //Don't forget to convert char to int：
    int char2int(char n){
        return n - '0';
    }
};
