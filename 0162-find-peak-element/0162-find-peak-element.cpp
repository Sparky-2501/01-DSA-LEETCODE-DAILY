class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int st = 0, end = nums.size() - 1;

        while (st < end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] > nums[mid + 1]) {
                end = mid; // peak is on left
            } else {
                st = mid + 1;//peak on right
            }
        }
        return st;
    }
};