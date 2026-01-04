class Solution {
    bool isSign(char ch) {
        return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
    }
    int priority(char a) {
        if (a == '*' || a == '/') return 3;
        return 1;
    }
public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> sign;
        int neg = 1;
        int temp = 0;
        
        for (char ch : s) {
            if (ch == ' ') continue;
            
            if (isSign(ch)) {
                temp *= neg;
                nums.push(temp);
                temp = 0;
                
                if (ch == '-') {
                    neg = -1;
                    ch = '+';
                } else neg = 1;
                
                while (!sign.empty() && nums.size() >= 2) {
                    char topOp = sign.top();
                    if (priority(topOp) >= priority(ch)) {
                        sign.pop();
                        int x = nums.top(); nums.pop();
                        int y = nums.top(); nums.pop();
                        int result = (topOp == '+') ? y + x :
                                   (topOp == '-') ? y - x :
                                   (topOp == '*') ? y * x : y / x;
                        nums.push(result);
                    } else break;
                }
                sign.push(ch);
            } else {
                temp = temp * 10 + (ch - '0');
            }
        }
        
        temp *= neg;
        nums.push(temp);
        while (nums.size() > 1) {
            char op = sign.top(); sign.pop();
            int x = nums.top(); nums.pop();
            int y = nums.top(); nums.pop();
            int result = (op == '+') ? y + x :
                       (op == '-') ? y - x :
                       (op == '*') ? y * x : y / x;
            nums.push(result);
        }
        return nums.top();
    }
};
