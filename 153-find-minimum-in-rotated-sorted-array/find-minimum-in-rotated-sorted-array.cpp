class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low =0;
        int high =n-1;
        while(low<high)
        {
            int mid = low+(high-low)/2;
            // if(nums[mid]<nums[mid-1] && nums[mid]<nums[mid+1])
            // {
            //     return nums[mid];
            // }
            if(nums[mid]>nums[high])
            {
                low=mid+1;
            }
            else// if(nums[mid]<nums[mid+1])
            {
                high=mid;
            }

        }
        return nums[high];
    }
   
};