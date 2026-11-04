class Solution {
   public:
    void generateCombinations(const vector<string>& inputStrings, int depth, string current,
                              vector<string>& result) {
        if (depth == inputStrings.size()) {
            result.push_back(current);
            return;
        }
        for (char c : inputStrings[depth]) {
            generateCombinations(inputStrings, depth + 1, current + c, result);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        unordered_map<char, string> m = {
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
        };

        vector<string> inp;
        for (int i = 0; i < digits.size(); i++) {
            inp.push_back(m[digits[i]]);
        }
        vector<string> ans;
        generateCombinations(inp, 0, "", ans);
        return ans;
    }
};
