class Solution {
public:
    int helper(vector<int> &nums, vector<int> &dp){
        dp[0] = nums[0];
        int neg = 0;
        int n = nums.size();
        for(int i=1; i<n; i++){
            int tablu = nums[i];
            if(i>1) tablu += dp[i-2];
            int nontablu = 0 + dp[i-1];

            dp[i] = max(tablu,nontablu);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return helper(nums,dp);
    }
};