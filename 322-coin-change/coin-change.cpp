class Solution {
public:
    int coinChange(vector<int>& coins, int target) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(target+1,0));
        for(int T=0; T<= target; T++){
            if(T%coins[0] == 0) dp[0][T] = T/coins[0];
            else dp[0][T] = 1e9;
        }

        for(int ind=1; ind<n; ind++){
            for(int T=0; T<= target; T++){
                int notTake = 0 + dp[ind-1][T];
                int Take = INT_MAX;
                if(coins[ind] <= T){
                    Take = 1 + dp[ind][T-coins[ind]];
                }
                dp[ind][T] = min(Take,notTake);
            }
        }
        int ans = dp[n-1][target];
        if(ans >= 1e9) return -1;
        return ans;

    }
};