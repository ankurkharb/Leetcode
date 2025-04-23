class Solution {
public:
    void subsets(int idx,int N, vector<int>& nums,vector<vector<int>> &ans,vector<int>& ds)
    {
        if(idx==N)
        {
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[idx]); // include
        subsets(idx+1,N,nums,ans,ds);
        ds.pop_back();
        int i =idx+1;
        while(i<N && nums[i]==nums[i-1])i++;
        subsets(i,N,nums,ans,ds); // exclude here exclude all duplicates after excluding that number once
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        int N = nums.size();
        subsets(0,N,nums,ans,ds);
        return ans;
    }
};