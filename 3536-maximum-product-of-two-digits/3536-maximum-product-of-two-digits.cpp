class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);

        int first =0,second =0;
        for(char x : s){
            int ch = x -'0';

            if(ch >=first){
                second = first;
                first = ch;
            }
            else if(ch > second){
                second = ch;
            }
        }
        return first * second;
    }
};