class Solution {
public:
    string processStr(string s) {
        string ans = "";
        for(int i=0; i<s.length(); i++){
            if(s[i] == '*'){
                if(ans.size() > 0) ans = ans.substr(0,ans.length()-1);
                else continue;
            }else if(s[i] == '#'){
                ans = ans + ans;
            }else if(s[i] == '%'){
                reverse(ans.begin(), ans.end());
            }else{
                ans += s[i];
            }
        }
        return ans;
    }
};