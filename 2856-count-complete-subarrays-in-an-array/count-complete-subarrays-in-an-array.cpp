class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
    int n = nums.size();
    unordered_set<int> distinctSet(nums.begin(), nums.end());
    int totalDistinct = distinctSet.size();

    int count = 0;
    unordered_map<int, int> freq;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        freq[nums[right]]++;

        while (freq.size() == totalDistinct) {
            // If window [left, right] has all distinct elements
            count += n - right; // All subarrays starting from left and ending from right to end are valid
            freq[nums[left]]--;
            if (freq[nums[left]] == 0)
                freq.erase(nums[left]);
            left++;
        }
    }

    return count;

    }
};