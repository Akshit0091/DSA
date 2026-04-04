class Solution {
public:
    typedef pair<int, pair<int,int>> P;
    vector<vector<int>> dirs = {{-1,0}, {0,1}, {0,-1}, {1,0}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m,INT_MAX));


        priority_queue<P,vector<P>,greater<P>> pq;
        auto isSafe = [&](int x, int y){
            return x >= 0 && x < n && y >= 0 && y < m;
        };
        pq.push({0, {0,0}});
        dist[0][0] = 0;

        while(!pq.empty()){

            int diff = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            for(auto &dir : dirs){
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if(isSafe(x_, y_)){
                    int absDiff = abs(heights[x][y] - heights[x_][y_]);
                    int maxDiff = max(diff, absDiff); 

                    if(dist[x_][y_] > maxDiff){
                        dist[x_][y_] = maxDiff;
                        pq.push({maxDiff, {x_,y_}});
                    }
                }
            }


        }
        return dist[n-1][m-1];
    }
};