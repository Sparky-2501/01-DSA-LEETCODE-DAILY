class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;

        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            }
            else if (c == ')') {
                low--;
                high--;
            }
            else { // for * case
                low--;
                high++;
            }

            // We cannot have negative unmatched '('
            low = max(low, 0);

            // Even the maximum possibility is invalid
            if (high < 0)
                return false;
        }

        return low == 0;
    }
};