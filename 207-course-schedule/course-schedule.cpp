class Solution {
public:
    bool isCycle(int src, vector<bool> &vis, vector<bool> &rec, vector<vector<int>> &graph){
        vis[src] = true;
        rec[src] = true;

        for(int i = 0; i < graph.size(); i++){
            int u = graph[i][1];
            int v = graph[i][0];

            if(u == src){
                if(!vis[v]){
                    if(isCycle(v, vis, rec, graph))
                        return true;
                }
                else if(rec[v]){
                    return true;
                }
            }
        }

        rec[src] = false;
        return false; 
    }

    bool canFinish(int numCourses, vector<vector<int>>& graph) {
        vector<bool> vis(numCourses, false);
        vector<bool> rec(numCourses, false);

        for(int i = 0; i < numCourses; i++){
            if(!vis[i]){
                if(isCycle(i, vis, rec, graph))
                    return false;
            }
        }
        return true;
    }
};