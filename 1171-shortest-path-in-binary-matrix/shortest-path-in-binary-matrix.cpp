class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1){
            return -1;
        }

        vector<pair<int,int>> dir = {
            {1,0}, {-1,0}, {0,1}, {0,-1},
            {1,1}, {1,-1}, {-1,1}, {-1,-1}
        };

        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;

        int steps = 1;

        while(!q.empty()){
            int size = q.size();

            for(int i=0; i<size; i++){
                pair<int,int> front = q.front();
                q.pop();

                int x = front.first;
                int y = front.second;

                if(x == n-1 && y == n-1){
                    return steps;
                }

                for(int j=0; j< dir.size(); j++){
                    int nx = x + dir[j].first;
                    int ny = y + dir[j].second;

                    if(nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0){
                        q.push(make_pair(nx,ny));
                        grid[nx][ny] = 1;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};