class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n = nums2.size();
        map<int,int> mpp;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=nums2[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                mpp[nums2[i]]=-1;
            }
            if(!st.empty())
            {
                mpp[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }
        vector<int> ans;
        for(int num:nums1)
        {
            ans.push_back(mpp[num]);
        }
        return ans;
    }
};