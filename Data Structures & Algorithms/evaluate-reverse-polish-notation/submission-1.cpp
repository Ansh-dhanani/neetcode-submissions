class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> stk;
        for(const std::string& token : tokens){
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                long long op2 = stk.top(); stk.pop();
                long long op1 = stk.top(); stk.pop();
                
                if (token == "+") stk.push(op1 + op2);
                else if (token == "-") stk.push(op1 - op2);
                else if (token == "*") stk.push(op1 * op2);
                else if (token == "/") stk.push(op1 / op2);
            }else{
                stk.push(stoll(token));
            }
        }
        return stk.top();
    }
};
