class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        for (auto &row : grid) {
            for (auto &val : row) {
                arr.push_back(val);
            }
        }

        int rem = arr[0] % x;
        for (int num : arr) {
            if (num % x != rem) return -1;
        }

        sort(arr.begin(), arr.end());
        int n = arr.size();
        int target = arr[n / 2];

        int operations = 0;
        for (int num : arr) {
            operations += abs(num - target) / x;
        }

        return operations;
    }
};