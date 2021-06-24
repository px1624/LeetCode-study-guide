class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        int index = 0;
        int num = 0;
        vector<int> ans;
        // In case:
        if( expression.size() == 1){
            ans.push_back(expression[0] - '0');
            return ans;
        }
        // Store decimal digits
        while(index < expression.size() && isdigit(expression[index]))
            num = num * 10 + expression[index++] - '0';
        if(index == expression.size()){
            hash[expression] = {num};
            return {num};
        }
        
        for(int i = 0; i < expression.size(); i++){
            // Separate the expression into two parts when we got an operator:
            if(isOp(expression[i])){
                string s1 = expression.substr(0,i);
                string s2 = expression.substr(i);
                vector<int> result1, result2;
                // If we don't have the string in the hash map, recursively separate the expressions:
                if(!hash.count(s1))
                    result1 = diffWaysToCompute(expression.substr(0,i));
                else
                    result1 = hash[s1];
                if(!hash.count(s2))
                    result2 = diffWaysToCompute(expression.substr(i+1));
                else
                    result2 = hash[s2];
                // Calculate and store the results of the sepatated expressions:
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
    
    // Check if the char is operator:
    bool isOp(const char& c){
        return c == '+' || c == '-' || c == '*';
    }

    // Math：
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
