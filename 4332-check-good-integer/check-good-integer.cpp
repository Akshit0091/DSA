class Solution {
public:
    bool checkGoodInteger(int n) {
        int digitSum = 0;
        int SquareSum = 0;
        while(n > 0){
            int digit = n % 10;
            digitSum += digit;
            SquareSum += digit*digit;
            n = n/10;
        }
        if((SquareSum - digitSum) >= 50)return true;
        return false;
    }
};