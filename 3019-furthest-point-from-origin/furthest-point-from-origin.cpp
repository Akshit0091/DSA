class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.length();
        int distL = 0;
        int blanks = 0;
        for(int i=0; i<n; i++){
            if(moves[i] == 'L') distL--;
            else if(moves[i] == 'R') distL++;
            else blanks++; 
        }

        return abs(distL) + blanks;
    }
};