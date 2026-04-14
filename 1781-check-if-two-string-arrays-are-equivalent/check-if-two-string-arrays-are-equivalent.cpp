class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int m = word1.size();
        int n = word2.size();

        int w1i = 0, i = 0;
        int w2i = 0, j = 0;

        while(w1i < m && w2i < n){
            if(word1[w1i][i] != word2[w2i][j]){
                return false;
            }

            i++;
            j++;

            if(i == word1[w1i].size()){
                i = 0;
                w1i++;
            }

            if(j == word2[w2i].size()){
                j = 0;
                w2i++;
            }
        }

        return w1i == m && w2i == n;
    }
};