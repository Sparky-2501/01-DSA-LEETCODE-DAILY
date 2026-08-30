class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIdx = 0;
        int maxIdx = 0;

        //index of min and max
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIdx])
                minIdx = i;
            if (nums[i] > nums[maxIdx])
                maxIdx = i;
        }

        if (minIdx > maxIdx){
            swap(minIdx, maxIdx);   //min=5 max=1  => min=1 max=5
        }

        //both from left 
        int left = maxIdx + 1;
        //both from right
        int right = n - minIdx;
        //left + right
        int both = (minIdx + 1) + (n - maxIdx);

        return min({left, right, both});
    }
};