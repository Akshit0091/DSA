class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score = 0;
        int counter = 0;
        for(int i=0; i<=events.size()-1; i++){
            if(counter < 10){
            if(events[i] == "W") counter++;
            if(events[i] == "WD" || events[i] == "NB") score++;
            if(events[i] == "0" || events[i] == "1" || events[i] == "2" || events[i] == "3" || events[i] == "4" ||
            events[i] == "5" || events[i] == "6"){
                score += stoi(events[i]);
            }
            }
        }

        vector<int> ans(2);
        ans[0] = score;
        ans[1] = counter;
        return ans;
    }
};