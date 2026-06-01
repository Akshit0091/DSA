class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int> freq(10,0);
        int a =0;
        int b = 0;
        while(n>0){
            a = n%10;
            freq[a]++;
            n = n/10;
        }
        long long ans = 0;
        for(int i=0; i<10; i++){
            ans += i*freq[i];
        }
        return ans;

    }
};