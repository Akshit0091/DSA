class Solution {
public:
    bool isvowel(char &ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I'
        || ch == 'O' || ch == 'U');
    }
    bool halvesAreAlike(string s) {
        int n = s.length();
        int mid = n/2;
        int i=0; int j=mid;
        int countL = 0;
        int countR = 0;

        while(i<n/2 && j<n){
        if(isvowel(s[i])) countL++;
        if(isvowel(s[j])) countR++;

        i++;
        j++;
        }
        return countL == countR;
    }
};