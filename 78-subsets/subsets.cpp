class Solution {
public:
    void getallsubsets(vector<int> &ans,int idx,vector<int>& nums,vector<vector<int>>& allsubsets)
    {
        if(idx==nums.size())
        {
            allsubsets.push_back({ans});
            return ;
        }
        ans.push_back(nums[idx]);
        getallsubsets(ans,idx+1,nums,allsubsets);
        ans.pop_back();
        getallsubsets(ans,idx+1,nums,allsubsets);
        
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allsubsets;
        vector<int> ans;
        getallsubsets(ans,0,nums,allsubsets);
        return allsubsets;
    }
};