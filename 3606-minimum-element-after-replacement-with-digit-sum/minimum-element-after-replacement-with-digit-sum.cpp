class Solution {
public:
    int minElement(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            int a = nums[i];
            int b = 0;
            int c = 0;
            while(a>0){
                b = a%10;
                c += b;
                a = a/10;
            }
            nums[i] = c;
        }
        int mn = *min_element(nums.begin(), nums.end());
        return mn;
    }
};