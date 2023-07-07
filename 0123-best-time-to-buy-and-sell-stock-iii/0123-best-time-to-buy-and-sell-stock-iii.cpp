class Solution {
public:
    int f(int ind,int buy, int cap,vector<int>& prices,vector<vector<vector<int>>>& dp){
        if(cap==0 || ind>prices.size()-1) return 0;
        
        int profit=INT_MIN;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        if(buy){
            profit=max(-prices[ind]+f(ind+1,0,cap,prices,dp),0+f(ind+1,1,cap,prices,dp));
        }
        else{
            profit=max(prices[ind]+f(ind+1,1,cap-1,prices,dp),0+f(ind+1,0,cap,prices,dp));
        }
        return dp[ind][buy][cap] =profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,2,prices,dp);
    }
};