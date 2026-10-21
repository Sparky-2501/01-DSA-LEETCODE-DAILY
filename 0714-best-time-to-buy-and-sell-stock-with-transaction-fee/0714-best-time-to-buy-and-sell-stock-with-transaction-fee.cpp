class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0;
        int hold = -prices[0];

        for (int i = 1; i < prices.size(); i++) {
            int p = prices[i];
            int newCash = max(cash, hold + p - fee);
            int newHold = max(hold, cash - p);
            cash = newCash;
            hold = newHold;
        }
        return cash;
    }
};