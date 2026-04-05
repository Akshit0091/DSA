class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        vector<vector<pair<int,int>>> adj(n);
        for(int i=0; i<roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int wt = roads[i][2];

            adj[u].push_back(make_pair(v,wt));
            adj[v].push_back(make_pair(u,wt));
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int>ways (n,0);

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        dist[0] = 0;
        ways[0] = 1;

        pq.push(make_pair(0, 0));

        while(!pq.empty()){
            pair<long long,int> top = pq.top();
            pq.pop();

            long long d = top.first;
            int node = top.second;

            if(d > dist[node]) continue;

            for(int i=0; i<adj[node].size(); i++){
                int adjNode = adj[node][i].first;
                int wt = adj[node][i].second;

                if(dist[adjNode] > d + wt){
                    dist[adjNode] = d + wt;
                    ways[adjNode] = ways[node];
                    pq.push(make_pair(dist[adjNode], adjNode));
                }

                else if(d + wt == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }
        return ways[n-1];
    }
};