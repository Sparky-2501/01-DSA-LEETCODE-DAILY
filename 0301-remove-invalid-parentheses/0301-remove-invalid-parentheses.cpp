class Solution {
public:
    bool isValid(const string& s) {
        int balance = 0;

        for (char c : s) {
            if (c == '(') {
                balance++;
            } else if (c == ')') {
                balance--;
                if (balance < 0)
                    return false;
            }
        }
        return balance == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            if (isValid(curr)) {
                ans.push_back(curr);
                found = true;
            }

            // If valid strings are found at this level,
            // don't generate strings with more removals.
            if (found)
                continue;

            for (int i = 0; i < curr.size(); i++) {
                // to  only remove parentheses, not letters.
                if (curr[i] != '(' && curr[i] != ')')
                    continue;

                string next = curr.substr(0, i) + curr.substr(i + 1);

                if (visited.insert(next).second) {
                    q.push(next);
                }
            }
        }
        return ans;
    }
};