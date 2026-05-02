class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        for(int i=0; i<=n-1; i++){
            int maxLeft = INT_MIN;
            int maxRight = INT_MIN;
            for(int j=0; j<i; j++){
                    maxLeft = max(maxLeft, nums[j]);
            }
            for(int j=i+1; j<n; j++){
                    maxRight = max(maxRight, nums[j]);
            }

            if(maxLeft < nums[i] || nums[i] > maxRight){
                result.push_back(nums[i]);
            }
        }
        return result;
    }
};