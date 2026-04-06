#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        set<pair<int,int>> st;
        for(int i = 0; i < obstacles.size(); i++){
            int ox = obstacles[i][0];
            int oy = obstacles[i][1];
            st.insert(make_pair(ox, oy));
        }
    
        vector<pair<int,int>> dir;
        dir.push_back(make_pair(0,1));
        dir.push_back(make_pair(1,0));
        dir.push_back(make_pair(0,-1));
        dir.push_back(make_pair(-1,0));
        
        int x = 0, y = 0;
        int d = 0;
        int ans = 0;
        
        for(int i = 0; i < commands.size(); i++){
            int cmd = commands[i];
            
            if(cmd == -1){
                d = (d + 1) % 4; 
            }
            else if(cmd == -2){
                d = (d + 3) % 4;
            }
            else{
                for(int step = 0; step < cmd; step++){
                    int nx = x + dir[d].first;
                    int ny = y + dir[d].second;
                    
                    if(st.find(make_pair(nx, ny)) != st.end()){
                        break;
                    }
                    
                    x = nx;
                    y = ny;
                    
                    ans = max(ans, x*x + y*y);
                }
            }
        }
        
        return ans;
    }
};