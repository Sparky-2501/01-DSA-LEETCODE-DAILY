class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0,j=0;
        int n= word1.size(),m = word2.size();
        string ans="";
        while(i < n && j < m){
            ans = ans + word1[i];
            ans = ans + word2[j];
            i++;
            j++;
        }
        
        while(i<n){
            ans = ans + word1[i];
            i++;
        }
        while(j<m){
            ans = ans + word2[j];
            j++;
        }
        return ans;
    }
};