class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>> q;

        for(int i=0; i<tickets.size(); i++){
            q.push({tickets[i],i});
        }

        int time = 0;

        while(!q.empty()){
            pair<int,int> front = q.front();
            q.pop();

            front.first--;
            time++;

            if(front.first == 0){
                if(front.second == k){
                    return time;
                }
            }
            else{
                q.push(front);
            }
        }
        return time;
    }
};