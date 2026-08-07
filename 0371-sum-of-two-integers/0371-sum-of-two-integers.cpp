class Solution {
public:
    int getSum(int a, int b) {  // 1= 0001  2= 0010
        while(b !=0){   //0010 / 2
            unsigned int car = a & b;  // 0000
            a ^= b; //0011
            b = car << 1;  //0000
        }
        return a;
    }
};
