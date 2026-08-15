class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        int n = num1.size();
        int m = num2.size();

        vector<int> ans(n + m, 0);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int product = (num1[i] - '0') * (num2[j] - '0');

                int right = i+j+1, left = i+j;
                int sum = product + ans[right]; 

                ans[right] = sum%10;
                ans[left] += sum /10;
            }
        }
        /*
        12* 10

        2*0 = 0         | prod = 2*1 =2 | 1*0 =0    |1*1 = 1
        r=3 l=2         | r=2 l=1       | 2 1       |1 0
        sum = 0 + 0;    | sum = 2+0     | 0 + 0     |1 0
        ans[r] = 0;     | ans[r] = 2    | 0         |1
        ans[l] = 0;     | ans[l] = 0    |0          |0
        ans = 0120
        */
        string res;
        int i=0;
        while (i < ans.size() && ans[i] == 0)
            i++;

        while (i < ans.size())
            res += char(ans[i++] + '0');

        return res;
    }
};