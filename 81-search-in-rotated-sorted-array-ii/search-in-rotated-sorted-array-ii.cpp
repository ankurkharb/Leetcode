class Solution {
public:
int findpivot(vector<int>& nums, int l,int r)
{
    while(l<r)
    {
        while(l<r && nums[l]==nums[l+1])l++;
        while(l<r && nums[r]==nums[r-1])r--;

        int mid = l+(r-l)/2;
        if(nums[mid]>nums[r])
        {
            l=mid+1;
        }
        else
        {
            r=mid; //possibily my pivot
        }
       
    }
     return r;
}
    bool bs(vector<int>& nums, int l , int r, int & target)
    {
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(nums[mid]==target)
            {
                return true;
            }
            else if(nums[mid]<target)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        int n =nums.size();
        int pivot = findpivot(nums,0,n-1);
        int result = bs(nums,0,pivot-1,target);
        if(result !=false)
        {
            return result;
        }
        return bs(nums,pivot,n-1,target);
    }
};