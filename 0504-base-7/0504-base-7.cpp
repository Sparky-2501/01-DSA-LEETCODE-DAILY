class Solution {
public:
    string convertToBase7(int num) {
        /*
        less than 0 -> - sign
        while loop till num > 0
        dividing and keeping remainder
        lastly adding together
        */
        if (num == 0) {
            return "0";
        }

        bool negative = (num < 0);
        num = abs(num);

        string ans = "";

        while (num > 0) {
            ans += char('0' + (num % 7));
            num /= 7;
        }

        if (negative)
            ans += '-';

        reverse(ans.begin(), ans.end());
        return ans;
    }
};