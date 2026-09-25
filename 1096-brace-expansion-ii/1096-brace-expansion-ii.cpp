class Solution {
public:
    string s;
    int i;
    set<string> parseExpression() {
        set<string> res = parseTerm();
        while (i < s.size() && s[i] == ',') {
            i++; // skip ','
            set<string> next = parseTerm();
            res.insert(next.begin(), next.end());
        }
        return res;
    }

    set<string> parseTerm() {
        set<string> res = {""};
        while (i < s.size() && s[i] != '}' && s[i] != ',') {
            set<string> cur = parseFactor();
            set<string> temp;
            for (const string& a : res) {
                for (const string& b : cur) {
                    temp.insert(a + b);
                }
            }
            res = temp;
        }
        return res;
    }

    set<string> parseFactor() {
        if (s[i] == '{') {
            i++; // skip '{'
            set<string> res = parseExpression();
            i++; // skip '}'
            return res;
        }
        // Single lowercase letter
        return {string(1, s[i++])};
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        i = 0;
        set<string> ans = parseExpression();
        return vector<string>(ans.begin(), ans.end());
    }
};