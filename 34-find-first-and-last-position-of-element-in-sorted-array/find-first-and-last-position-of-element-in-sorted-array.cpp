class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low =0;
        int high = n-1;
        int l=-1;
        int h=-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(nums[mid]==target)
            {
                l = mid;
                h = mid;
                while(l>0 && nums[mid]==nums[l-1]) l--;
                while(h<n-1 && nums[mid] == nums[h+1]) h++;
                break;
            }
            else if(nums[mid]<target)
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        return {l,h};
    }
};