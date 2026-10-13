class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products,
                                             string searchWord) {
        sort(products.begin(), products.end());

        vector<vector<string>> ans;
        string prefix = "";

        for (char ch : searchWord) {
            prefix += ch;
            vector<string> suggestions;
            for (string& product : products) {
                if (product.compare(0, prefix.size(), prefix) == 0) {
                    suggestions.push_back(product);
                }
                if (suggestions.size() == 3) {
                    break;
                }
            }
            ans.push_back(suggestions);
        }
        return ans;
    }
};