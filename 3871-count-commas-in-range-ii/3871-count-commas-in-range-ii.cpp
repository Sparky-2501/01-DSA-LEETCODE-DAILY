class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        
        // Numbers with:
        // 4-6 digits -> 1 comma
        // 7-9 digits -> 2 commas
        // 10-12 digits -> 3 commas, etc.
        long long start = 1000;
        long long commas = 1;

        while (start <= n) {
            long long end = min(n, start * 1000 - 1);

            ans += (end - start + 1) * commas;

            start *= 1000;
            commas++;
        }
        return ans;
    }
};