class Solution {
public:
    int digitSum(int x) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end(), [&](int a, int b) {
            int sumA = digitSum(a);
            int sumB = digitSum(b);
            if (sumA != sumB) {
                return sumA < sumB;
            }

            return a < b;
        });

        unordered_map<int, int> target;
        for (int i = 0; i < n; i++) {
            target[sortedNums[i]] = i;
        }

        vector<bool> visited(n, false);
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                continue;
            }

            int j = i;
            int cycleSize = 0;
            while (!visited[j]) {
                visited[j] = true;
                cycleSize++;

                j = target[nums[j]];
            }
            if (cycleSize > 1) {
                swaps += cycleSize - 1;
            }
        }
        return swaps;
    }
};