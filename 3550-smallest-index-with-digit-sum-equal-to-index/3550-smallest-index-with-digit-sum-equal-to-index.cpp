class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int dig = nums[i];
            int sum = 0;
            while (dig > 0) {
                sum += dig % 10;
                dig = dig / 10;
            }
            if (sum == i) {
                return i;
            }
        }
        return -1;
    }
};