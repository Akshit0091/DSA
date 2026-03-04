class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp(n+1), dpp(n+1);
                for(int i=2; i<=n; i++) {
            dp[i] = dp[i-1];
            if(i > 1) dp[i] = max(dp[i], dp[i-2] + nums[i-1]);
            else dp[i] = max(dp[i], nums[i-1]);
        }
        for(int i=1; i<n; i++) {
            dpp[i] = dpp[i-1];
            if(i > 1) dpp[i] = max(dpp[i], dpp[i-2] + nums[i-1]);
            else dpp[i] = max(dpp[i], nums[i-1]);
        }
        return max(dp[n], dpp[n-1]);
    }
};