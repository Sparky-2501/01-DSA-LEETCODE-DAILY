class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long a = min(need1, need2);
        long long b = max(need1, need2);

        long long costA = 1LL * need1 * cost1 + 1LL * need2 * cost2;

        long long remainingCost = (need1 > need2) ? cost1 : cost2;

        long long costB = a * costBoth
                        + (b - a) * remainingCost;

        long long costC = b * costBoth;

        return min({costA, costB, costC});
    }
};