class Solution {
public:
    
    int f(int i,int j, string &s, string &t,vector<vector<int>> &dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]=f(i-1,j-1,s,t,dp);
        }
        return dp[i][j]= 1+min(min(f(i,j-1,s,t,dp),f(i-1,j,s,t,dp)),f(i-1,j-1,s,t,dp));
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,0));
        // return f(word1.size()-1,word2.size()-1,word1,word2,dp);
        
        for(int i=0;i<=word1.size();i++){
            dp[i][0]=i;
        }
        for(int j=0;j<=word2.size();j++){
            dp[0][j]=j;
        }
        
        for(int i=1;i<=word1.size();i++){
            for(int j=1;j<=word2.size();j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else dp[i][j]= 1+min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1]);
            }
        }
        return dp[word1.size()][word2.size()];
    }
};