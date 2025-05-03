class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n =nums.size();
        int count=1;
        int i=0;
        int j =0;
        for(j=0;j<n;j++)
        {
            if(nums[j]!=nums[i])
            {
                i++;
                nums[i]=nums[j];
                count++;
            }
        }
        return count;
    }
};