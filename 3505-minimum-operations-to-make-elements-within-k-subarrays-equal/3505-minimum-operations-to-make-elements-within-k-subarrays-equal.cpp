class Solution {
public:
    using ll = long long;

    multiset<int> low, high;
    ll sumLow = 0, sumHigh = 0;

    void add(int x) {
        if (low.empty() || x <= *low.rbegin()) {
            low.insert(x);
            sumLow += x;
        } else {
            high.insert(x);
            sumHigh += x;
        }

        balance();
    }

    void remove(int x) {
        auto it = low.find(x);

        if (it != low.end()) {
            low.erase(it);
            sumLow -= x;
        } else {
            it = high.find(x);
            high.erase(it);
            sumHigh -= x;
        }

        balance();
    }

    void balance() {
        while (low.size() > high.size() + 1) {
            auto it = prev(low.end());
            int x = *it;

            low.erase(it);
            sumLow -= x;

            high.insert(x);
            sumHigh += x;
        }

        while (low.size() < high.size()) {
            auto it = high.begin();
            int x = *it;

            high.erase(it);
            sumHigh -= x;

            low.insert(x);
            sumLow += x;
        }
    }
    ll getCost() {
        ll median = *low.rbegin();

        return median * low.size() - sumLow + sumHigh - median * high.size();
    }
    long long minOperations(vector<int>& nums, int x, int k) {
        // Sliding Window + Median + DP
        int n = nums.size();

        // Step 1: Calculate cost of every window of size x.

        vector<ll> cost(n - x + 1);

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                cost[i - x + 1] = getCost();
            }
        }

        // Step 2: DP with space optimization.

        const ll INF = 1e18;
        vector<ll> prev(n + 1, 0);
        vector<ll> curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {

            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {

                //skip current element.
                curr[i] = curr[i - 1];
                //take a window ending at i-1.
                if (i >= x && prev[i - x] != INF) {
                    ll take = prev[i - x] + cost[i - x];
                    curr[i] = min(curr[i], take);
                }
            }
            prev.swap(curr);
        }
        return prev[n];
    }
};