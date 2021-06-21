class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        int index = 0;
        int num = 0;
        while(index < expression.size() && isdigit(expression[index]))
            num = num * 10 + expression[index++] - '0';
        if(index == expression.size()){
            hash[expression] = {num};
            return {num};
        }
        vector<int> ans;
        for(int i = 0; i < expression.size(); i++){
            if(isOp(expression[i])){
                string s1 = expression.substr(0,i);
                string s2 = expression.substr(i);
                vector<int> result1, result2;
                if(!hash.count(s1))
                    result1 = diffWaysToCompute(expression.substr(0,i));
                else
                    result1 = hash[s1];
                if(!hash.count(s2))
                    result2 = diffWaysToCompute(expression.substr(i+1));
                else
                    result2 = hash[s2];
                for(int r1 : result1){
                    for(int r2 : result2){
                        ans.push_back(calculate(r1,expression[i],r2));
                    }
                }
            }
        }
        hash[expression] = ans;
        return ans;
    }

    bool isOp(const char& c){
        return c == '+' || c == '-' || c == '*';
    }

    int calculate(const int& num1, const char& op, const int& num2){
        if(op == '+')
            return num1 + num2;
        else if(op == '-')
            return num1 - num2;
        else
            return num1 * num2;
    }
private:
    unordered_map<string,vector<int>> hash;
};
