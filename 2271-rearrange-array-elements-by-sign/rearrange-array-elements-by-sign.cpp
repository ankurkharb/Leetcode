class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> nega;
        vector<int> posi;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                posi.push_back(nums[i]);

            }
            else
            {
                nega.push_back(nums[i]);
            }

        }
        for(int i=0;i<n/2;i++)
        {
            ans.push_back(posi[i]);
            ans.push_back(nega[i]);
        }
        return ans;
    }
};