class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < nums.size(); ++i) {
            pos[nums[i]].push_back(i);
        }
        
        int ans = -1;
        for (auto& entry : pos) {
            const vector<int>& idxs = entry.second;
            if (idxs.size() < 3) continue;
            
            for (int i = 0; i <= (int)idxs.size() - 3; ++i) {
                int dist = 2 * (idxs[i + 2] - idxs[i]);
                if (ans == -1 || dist < ans) {
                    ans = dist;
                }
            }
        }
        
        return ans;
    }
};