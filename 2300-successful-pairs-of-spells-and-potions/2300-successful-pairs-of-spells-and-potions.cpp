class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        sort(potions.begin(), potions.end());

        vector<int> ans;
        for (long long spell : spells) {
            long long required = (success + spell - 1) / spell;
            int idx = lower_bound(potions.begin(), potions.end(), required) -
                      potions.begin();
            ans.push_back(potions.size() - idx);
        }
        return ans;
    }
};