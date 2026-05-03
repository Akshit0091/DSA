class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        for(int i=0; i<nums.size(); i++){
            int maxi = nums[0]; 
            int mini = nums[i];
            for(int j=0; j<=i; j++){
                maxi = max(maxi, nums[j]);
            }

            for(int j=i; j<nums.size(); j++){
                mini = min(mini, nums[j]);
            }
            int compare = maxi-mini;
            if(compare <= k){
                return i;
            }
        }
        return -1;
    }
};