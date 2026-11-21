class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        int m = num1.size(), n = num2.size();
        string res(m + n, '0');
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mult = (num1[i] - '0') * (num2[j] - '0');
                int sum = mult + (res[i + j + 1] - '0');
                
                res[i + j + 1] = (sum % 10) + '0';
                res[i + j] += sum / 10;
            }
        }
        
        size_t startpos = res.find_first_not_of('0');
        return (startpos == string::npos) ? "0" : res.substr(startpos);
    }
};
