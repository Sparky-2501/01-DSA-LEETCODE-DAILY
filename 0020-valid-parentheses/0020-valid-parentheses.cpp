class Solution {
public:
    bool isValid(string s) {
        char arr[s.length()];
        int top = -1;

        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                arr[++top] = ch;
            } else {
                if (top == -1)
                    return false;
                if ((ch == ')' && arr[top] != '(') ||
                    (ch == '}' && arr[top] != '{') ||
                    (ch == ']' && arr[top] != '[')) {
                    return false;
                }
                top--;
            }
        }
        return top == -1;
    }
};