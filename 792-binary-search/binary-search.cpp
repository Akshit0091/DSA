class Solution {
public:
    int f(vector<int> &nums, int low, int high, int target){
        if(low > high) return -1;

        int mid = (low+high) / 2;
        if(nums[mid] == target) return mid;
        else if(target > nums[mid]) return f(nums, mid+1, high, target);

        return f(nums, low, mid-1, target);
    }
    int search(vector<int>& nums, int target) {
        return f(nums, 0 , nums.size()-1, target);
    }
};