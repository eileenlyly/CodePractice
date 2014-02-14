class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return vector<string>(1, "");
        if (n == 1) return vector<string> (1, "()");
        vector<string> result;
        for (int i = 0; i < n; ++i)
            for (string inner : generateParenthesis (i))
                for (string outer : generateParenthesis (n - 1 - i))
                    result.push_back ("(" + inner + ")" + outer);
        return result;
    }
};