class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        long long  ans=0;
        // if(cost.size() == 1) {
        //     ans = cost[0];
        // }
        for(int i=cost.size()-1; i>=0; i-=3){
            ans += cost[i];
            if(i-1 >= 0){
                ans += cost[i-1];
            }
        }
        return ans;
    }
};