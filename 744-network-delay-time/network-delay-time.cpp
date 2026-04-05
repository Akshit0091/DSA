class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      vector<pair<int,int>> adj[n+1];

      for(auto it: times){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        adj[u].push_back({v, wt});
      }

      priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
      vector<int> dist(n+1, INT_MAX);
      dist[k] = 0;
      pq.push({0,k});

      while(!pq.empty()){
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it: adj[node]){
            int V = it.first;
            int wt = it.second;
            if(dist[V] > d + wt){
                dist[V] = d + wt;
                pq.push({dist[V], V});
            }
        }

      }
      int ans = INT_MIN;
        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        
        return ans;

    }
};