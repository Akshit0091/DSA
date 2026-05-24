class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            if(nums[i] % 2 == 0){
                int count = 0;
                for(int j=0; j<nums.size(); j++){
                    if(nums[j] == nums[i]){
                        count++;
                    }
                }
                if(count == 1){
                return nums[i];}
            }
        }
        return -1;
    }
};