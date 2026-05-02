class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int largest = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > nums[largest]){
                largest = i;
            }
        }
        long long ascSum = 0;
        long long desSum = 0;
        for(int i=0; i<=largest; i++){
            ascSum += nums[i];
        }

        for(int i=largest; i<nums.size(); i++){
            desSum += nums[i];
        }

        if(ascSum > desSum) return 0;
        else if(ascSum < desSum) return 1;
        else return -1;

    }
};