class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxSum = 0,ans=0;
        for (int x : gain) {
            ans +=x;
            maxSum = max(maxSum, ans);
        }
        return maxSum;
    }
};