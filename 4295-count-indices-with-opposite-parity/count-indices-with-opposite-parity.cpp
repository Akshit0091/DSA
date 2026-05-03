class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        vector<int> score(nums.size(),0);
        for(int i=0; i<nums.size(); i++)
            {
                for(int j=i+1; j<nums.size(); j++){
                    if((nums[i] % 2 == 0 && nums[j] % 2 != 0) || (nums[j] % 2 == 0 && nums[i] % 2 != 0)){
                        score[i]++;
                    }
                }
            }   
        return score;}
};