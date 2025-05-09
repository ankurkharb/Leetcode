class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        if(n==0)return 0;
        int longest = 1;
        for(int num:nums)
        {
            st.insert(num);
        }
        for(auto it : st)
        {
            if(st.find(it - 1)==st.end())
            {
                int cnt = 1 ;
                int x = it;
                while(st.find(x+1) != st.end())
                {
                    x=x+1;
                    cnt++;

                }
                longest = max(longest,cnt);
            }
        }

        return longest;
    }
};