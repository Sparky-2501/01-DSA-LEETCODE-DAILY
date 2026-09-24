class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        // Storing {nums2[i], nums1[i]} in vector
        vector<pair<int, int>> pairs;
        for (int i = 0; i < n; i++) {
            pairs.push_back({nums2[i], nums1[i]});
        }

        // Sorting by nums2 in descending order
        sort(pairs.rbegin(), pairs.rend());

        // Min-heap to keep the largest k nums1 values
        priority_queue<int, vector<int>, greater<int>> pq;

        long long sum = 0;
        long long ans = 0;

        for (auto [n2, n1] : pairs) {
            sum += n1;
            pq.push(n1);
            // Keeping only k largest nums1 values
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            // n2 is the minimum nums2 among selected elements
            if (pq.size() == k) {
                ans = max(ans, sum * n2);
            }
        }
        return ans;
    }
};