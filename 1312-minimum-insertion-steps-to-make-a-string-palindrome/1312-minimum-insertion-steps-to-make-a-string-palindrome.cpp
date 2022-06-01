class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        vector<int> prev(text2.length()+1,0);
        vector<int> curr(text2.length()+1,0);
        for(int i=1;i<=text1.length();++i){
            for(int j=1;j<=text2.length();++j){
                if(text1[i-1] == text2[j-1]){
                    curr[j] = 1 + prev[j-1];
                }
                else{
                    curr[j] = max(prev[j],curr[j-1]);
                }
            }
            prev = curr;
        }
        return prev[text2.length()];
    }
    
    int minInsertions(string s) {
        string s2 = s;
        reverse(s2.begin(),s2.end());
        
        int lps = longestCommonSubsequence(s,s2);
        return s.length() - lps;
    }
};