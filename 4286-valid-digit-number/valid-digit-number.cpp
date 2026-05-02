class Solution {
public:
    bool validDigit(int n, int x) {
            bool found = false;
            while(n>0){
                int digit = n%10;
                
                if(digit == x) found = true;

                if (n < 10) {
                    if (digit == x) return false;
                }
                n = n/10;
            }

            
        return found;
    }
};