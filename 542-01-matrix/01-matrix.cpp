class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int,int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                }else{
                    mat[i][j] = -1;
                }
            }
        }

        vector<pair<int,int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        while(!q.empty()){
            pair<int,int> frontNode = q.front();
            q.pop();

            int x = frontNode.first;
            int y = frontNode.second;

            for(int i = 0; i < 4; i++){
                int nx = x + dir[i].first;
                int ny = y + dir[i].second;
                
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && mat[nx][ny] == -1){
                    mat[nx][ny] = mat[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
        return mat;
    }
};