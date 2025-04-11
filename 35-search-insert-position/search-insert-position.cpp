class Solution {
public:

    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low =0;
        int high = nums.size()-1;
        if(target>nums[n-1])return n;
        while(low<high)
        {
            int mid = low+(high-low)/2;
            if(target==nums[mid])return mid;
            else if(nums[mid]<target)
            {
                low = mid +1;
            }
            else
            {
                high=mid;
            }
        }
        return high;
    }

};