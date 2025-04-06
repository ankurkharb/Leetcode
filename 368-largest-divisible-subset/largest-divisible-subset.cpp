class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);       // dp[i] = size of largest subset ending at i
        vector<int> prev(n, -1);    // To reconstruct the subset
        int max_idx = 0;            // Index of largest element in the result subset

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[max_idx]) {
                max_idx = i;
            }
        }

        // Reconstruct the result subset
        vector<int> res;
        while (max_idx >= 0) {
            res.push_back(nums[max_idx]);
            max_idx = prev[max_idx];
        }

        return res;
    }
};
