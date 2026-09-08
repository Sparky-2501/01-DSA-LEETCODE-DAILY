class Solution {
public:
    int countCommas(int n) {
        //1,000 - 9,99,999 => 1 each 
        //1,000,000 - 99,999,999 =>2 each
        if(n<1000){
            return 0;
        }else{
            return n-999;
        }
    }
};