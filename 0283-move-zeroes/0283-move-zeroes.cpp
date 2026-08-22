#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int k = 0;

        while (k < n) {
            while (k < n && nums[k] != 0) {
                k++;
            }
            if (k == n) break;
            int j = k + 1;
            while (j < n && nums[j] == 0) {
                j++;
            }
            if (j == n) break;
            int temp = nums[k];
            nums[k] = nums[j];
            nums[j] = temp;
            k++;
        }
    }
};
