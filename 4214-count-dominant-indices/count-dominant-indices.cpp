class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int cnt = 0;
      for(int i=0; i<nums.size()-1; i++){
        int SuffixSum = 0;
        int num = 0;
        for(int j=nums.size()-1; j>i; j--){
            SuffixSum += nums[j];
            num++;
        }
        int avg = SuffixSum/num;
        if(nums[i] > avg){
            cnt++;
        }
      } 
      return cnt; 
    }
};