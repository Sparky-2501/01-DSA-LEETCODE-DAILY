class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
    
        int totalOnes = 0;
        int prevZero = INT_MIN;
        int best = 0;

        for (int i = 0; i < s.size();) {
            int j = i;
            while (j < s.size() && s[j] == s[i]){
                j++;
            }

            int len = j - i;

            if (s[i] == '1') {
                totalOnes += len;
            } else {
                best = max(best, prevZero + len);
                prevZero = len;
            }
            i = j;
        }

        return totalOnes + best;
    }
};