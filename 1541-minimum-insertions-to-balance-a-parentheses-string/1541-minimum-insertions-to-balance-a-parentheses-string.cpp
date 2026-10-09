class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int open = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open++;
            } else {
                // Check for consecutive "))"
                if (i + 1 < s.size() && s[i + 1] == ')') { // not last ) and also have 2 in set
                    i++;
                } else {
                    ans++; // missing ')'
                }
                if (open > 0) {
                    open--;
                } else {
                    ans++; // missing '('
                }
            }
        }

        ans += open * 2;

        return ans;
    }
};