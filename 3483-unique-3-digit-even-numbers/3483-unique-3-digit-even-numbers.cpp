class Solution {
public:
    int totalNumbers(vector<int>& digits) {
         vector<int> freq(10, 0);
        //occurrences of every digit
        for (int d : digits) {
            freq[d]++;
        }

        int ans = 0;

        for (int i = 1; i <= 9; i++) {  // Choosing hundreds digit
            if (freq[i] == 0)
                continue;

            freq[i]--;

            for (int j = 0; j <= 9; j++) {  // Choose tens digit
                if (freq[j] == 0)
                    continue;
                freq[j]--;

                for (int k = 0; k <= 8; k += 2) {   // Choose units digit (must be even)
                    if (freq[k] > 0) {
                        ans++;
                    }
                }

                freq[j]++;
            }

            freq[i]++;
        }

        return ans;
    }
};