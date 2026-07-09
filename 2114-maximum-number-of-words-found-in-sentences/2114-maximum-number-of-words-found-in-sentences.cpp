class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        
        int maxi=0;
        for(string x : sentences){
            int words =0;
            for(char ch:x){
                if(ch==' ')
                  words++;
            }
            maxi=max(maxi,words);
        }
        return maxi+1;
    }
};