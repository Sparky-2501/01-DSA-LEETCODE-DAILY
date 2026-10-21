class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        // already sorted
        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }

        // cant sort an unsorted string of length 2
        if (n == 2) {
            return -1;
        }

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        // 1 operation is sufficient
        if (s[0] == mn || s[n - 1] == mx) {
            return 1;
        }

        // extreme character is in the middle
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == mn || s[i] == mx) {
                return 2;
            }
        }

        // both extremes are trapped at the wrong ends
        return 3;
    }
};