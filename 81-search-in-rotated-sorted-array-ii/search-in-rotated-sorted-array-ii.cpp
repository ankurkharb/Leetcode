class Solution {
public:
    int findpivot(vector<int>& nums,int low,int high)
    {
        while(low<high)
        {
            while(low<high && nums[low]==nums[low+1])low++; // what if mid is equal to low and high fir kaha move kroge
            while(low<high && nums[high]==nums[high-1])high--;

            int mid = low +(high-low)/2;
            if(nums[mid]>nums[high])
            {
                low=mid+1;
            }
            else
            {
                high=mid ;// possibly my pivot
            }

        }
        return high;
    }
    bool bs(vector<int>& nums,int target,int low,int high)
    {
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(nums[mid]==target)
            {
                return true;
            }
            else if (nums[mid]<target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return false;
    }

    bool search(vector<int>& nums, int target) {
        int n  = nums.size(); 
        int low = 0;
        int high = n-1 ;
        int pivot = findpivot(nums,low,high);
        int result = bs(nums,target,pivot,n-1);
        if(result!=false)
        {
            return result;
        }
        return bs(nums,target,0,pivot-1);
        
    }
};