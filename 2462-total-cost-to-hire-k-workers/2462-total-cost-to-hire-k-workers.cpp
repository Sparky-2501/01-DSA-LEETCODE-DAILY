class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        priority_queue<int, vector<int>, greater<int>> left, right;

        int l = 0, r = n - 1;
        // Fill left heap
        while (l <= r && left.size() < candidates) {
            left.push(costs[l++]);
        }

        // Fill right heap
        while (l <= r && right.size() < candidates) {
            right.push(costs[r--]);
        }

        long long ans = 0;

        while (k--) {
            // Pick cheaper worker
            if (right.empty() || (!left.empty() && left.top() <= right.top())) {
                ans += left.top();
                left.pop();

                // Add next worker from left
                if (l <= r) {
                    left.push(costs[l++]);
                }
            } else {
                ans += right.top();
                right.pop();

                // Add next worker from right
                if (l <= r) {
                    right.push(costs[r--]);
                }
            }
        }
        return ans;
    }
};