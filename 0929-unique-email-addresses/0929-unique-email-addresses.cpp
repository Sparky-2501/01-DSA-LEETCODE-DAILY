class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> unique;
        for (string email : emails) {
            string local = "";
            string domain = "";

            int at = email.find('@');
            local = email.substr(0, at);
            domain = email.substr(at + 1);

            // Ignoring everything after '+'
            int plus = local.find('+');
            if (plus != string::npos) {
                local = local.substr(0, plus);
            }

            // Removing '.'
            string cleardot = "";
            for (char ch : local) {
                if (ch != '.') {
                    cleardot += ch;
                }
            }
            unique.insert(cleardot + "@" + domain);
        }
        return unique.size();
    }
};