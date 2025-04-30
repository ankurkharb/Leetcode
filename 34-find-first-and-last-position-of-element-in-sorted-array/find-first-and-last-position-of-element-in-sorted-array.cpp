class Solution {
public:
    int leftmost(vector<int>& nums, int target)
    {
        int n =nums.size();
        int ans=-1;
        int low=0;
        int high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                high=mid-1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
    int rightmost(vector<int>& nums, int target)
    {
        int n =nums.size();
        int ans=-1;
        int low=0;
        int high=n-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
        
            if(nums[mid]==target)
            {
                ans=mid;
                low=mid+1;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
        
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = leftmost(nums,target);
        int right = rightmost(nums,target);
        return {left,right};

    }
};