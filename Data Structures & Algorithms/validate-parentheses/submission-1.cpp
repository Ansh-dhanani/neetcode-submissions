class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(char c:s){
            if( c=='{' || c=='(' || c=='[' ){
                stk.push(c);
            }else{
                if(!stk.empty()){
                    if(
                        stk.top()=='{' && c=='}' ||
                        stk.top()=='[' && c==']' ||
                        stk.top()=='(' && c==')'
                    ){
                        stk.pop();
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
            }
        }
        if(stk.empty()) return true;
        return false;
    }
};
