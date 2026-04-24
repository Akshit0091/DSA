class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.length();
        int distL = 0;
        int distR = 0;
        for(int i=0; i<n; i++){
            if(moves[i] == 'L') distL--;
            else if(moves[i] == 'R') distL++;
            else distL--; 
        }

        for(int i=0; i<n; i++){
            if(moves[i] == 'L') distR--;
            else if(moves[i] == 'R') distR++;
            else distR++; 
        }
        int distanceR = abs(0 - distR);
        int distanceL = abs(0 - distL);
        return max(distanceL, distanceR);
    }
};