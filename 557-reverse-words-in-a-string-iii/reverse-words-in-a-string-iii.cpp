class Solution {
public:
    string reverseWords(string s) {
        string ans;

        for(int i=0; i<s.length(); i++){
            string word = "";
            while(i<s.length() && s[i] != ' '){
                word += s[i];
                i++;
            }

            reverse(word.begin(), word.end());
            ans += word + " ";
        }
        ans.pop_back();

        return ans;
    }
};