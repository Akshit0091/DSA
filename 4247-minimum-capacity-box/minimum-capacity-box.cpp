class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int mini = INT_MAX;
        int ans = -1;
        for (int i=0; i<=capacity.size()-1; i++){
            if(capacity[i] >= itemSize && capacity[i] < mini){
                mini = capacity[i];
                ans = i;
            }
        }
        return ans; 
    }
};