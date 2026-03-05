class Solution {
    public:
    string shortestPalindrome(string s) {
        int n = s.size();
        int p = 31, mod = 1e9 + 7;

        int i = 0;
        long long prefix = 0, suffix = 0, pow = 1;
        int long_palin = 0;

        while (i < n) {
            prefix = (prefix * p + (s[i] - 'a' + 1) + mod) % mod;
            suffix = (suffix + (s[i] - 'a' + 1) * pow + mod) % mod;
            pow = (pow * p + mod) % mod;
            if (prefix == suffix) long_palin = i + 1;
            i++;
        }

        string s1 = s.substr(long_palin);
        reverse(s1.begin(), s1.end());
        return s1 + s;
    }
                                            
};