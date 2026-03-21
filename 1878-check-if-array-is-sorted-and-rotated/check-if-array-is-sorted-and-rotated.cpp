class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int k = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] > nums[(i+1) % nums.size()]){
                k++;
            }
        }
        return k<=1;
    }
};