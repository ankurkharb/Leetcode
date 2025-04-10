class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int pivot = 0;

        // Step 1: Find the pivot (index of the smallest element)
        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high]) {
                // Pivot lies to the right
                low = mid + 1;
            } else {
                // Pivot is mid or to the left
                high = mid;
            }
        }

        pivot = low;

        // Step 2: Binary search in the appropriate segment
        low = 0, high = n - 1;

        // Figure out which half to perform binary search on
        if (target >= nums[pivot] && target <= nums[n - 1]) {
            low = pivot;
        } else {
            high = pivot - 1;
        }

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }
};
