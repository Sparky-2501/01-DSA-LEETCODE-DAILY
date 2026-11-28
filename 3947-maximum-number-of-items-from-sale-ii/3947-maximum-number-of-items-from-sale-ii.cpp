class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        /*Each purchase can unlock at most one free item, and each (i,j) pair can unlock at most once.
        
        Precompute gain[i] = number of j such that factor[i] | factor[j]

        Group items by price and use greedy with sorting by cost, 
        possibly combined with a sieve-like counting of divisible relationships

        Complexity: O(n log n) or O(n log r) using frequency arrays and divisor multiples */
        int n = items.size(), maxFactor = 0, minPrice = INT_MAX;
        for (auto& item : items) {
            maxFactor = max(maxFactor, item[0]);
            minPrice = min(minPrice, item[1]);
        }

        // Count frequency of each factor
        vector<int> freq(maxFactor + 1, 0);
        for (auto& item : items) {
            freq[item[0]]++;
        }

        // Count items whose factors are multiples of i
        vector<int> cnt(maxFactor + 1, 0);
        for (int i = 1; i <= maxFactor; i++) {
            for (int j = i; j <= maxFactor; j += i) {
                cnt[i] += freq[j];
            }
        }

        // Store {price, available free-item opportunities}
        vector<pair<int, int>> deals;
        for (auto& item : items) {
            int price = item[1], freeCount = cnt[item[0]] - 1;
            if (freeCount > 0 && price < 2LL * minPrice) {
                deals.push_back({price, freeCount});
            }
        }

        // Cheapest deals first
        sort(deals.begin(), deals.end());
        long long ans = 0;
        for (auto& [price, freeCount] : deals) {
            int take = min(freeCount, budget / price);
            budget -= take * price;
            ans += 2LL * take;
        }
        // remaining budget on cheap items
        ans += budget / minPrice;
        return ans;
    }
};