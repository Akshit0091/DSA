class Solution {
public:
    int reverse(int n){
        int r = 0;
        while(n != 0){
            int digit = n%10;
            r = r * 10 + digit;
            n= n/10;
        }
        return r;
    }

    bool isPrime(int n){
        if (n<=1) return false;

        for(int i=2; i<n; i++){
            if(n%i == 0){
                return false;
            }
        }
        return true;
    }
    int sumOfPrimesInRange(int n) {
        int r = reverse(n);
        int sum = 0;
        int start = min(n,r);
        int end = max(n,r);
        for(int i=start; i<=end; i++){
            if(isPrime(i)){
                sum += i;
            }
        }
        return sum;
    }
};