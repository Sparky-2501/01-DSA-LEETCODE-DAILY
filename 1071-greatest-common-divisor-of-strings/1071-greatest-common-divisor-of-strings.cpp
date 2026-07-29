class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        //closing case 
        if (str1 + str2 != str2 + str1) {
            return "";
        }

        // for common part it must be length of gcd 
        int g = gcd(str1.length(), str2.length()); // ABABAB & ABAB ; g=2
        
        //choosing g length from any string 
        return str1.substr(0, g);
    }
};