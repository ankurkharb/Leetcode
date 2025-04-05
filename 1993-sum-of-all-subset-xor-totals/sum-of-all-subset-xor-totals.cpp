class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        
        // There are 2^n subsets
        for (int mask = 0; mask < (1 << n); ++mask) {
            int currentXOR = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    currentXOR ^= nums[i];
                }
            }
            totalSum += currentXOR;
        }
        
        return totalSum;
    }
};