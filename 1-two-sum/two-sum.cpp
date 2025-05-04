class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            int sec = target - nums[i];
            if(mp.find(sec)==mp.end())
            {
                mp[nums[i]]=i;
            }
            else
            {
                int firs = mp[sec];
                return {i,firs};
            }
        }
        return {-1,-1};
        
    }
};