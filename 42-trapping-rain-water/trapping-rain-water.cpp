class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefixsum(n);
        prefixsum[0]=height[0];
        vector<int> suffixsum(n);
        suffixsum[n-1]=height[n-1];
        for(int i=1;i<n;i++)
        {
            prefixsum[i]=max(prefixsum[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--)
        {
            suffixsum[i]=max(suffixsum[i+1],height[i]);
        }
        int water=0;
        for(int i=0;i<n;i++)
        {
            if(height[i]<prefixsum[i] && height[i]<suffixsum[i])
            {
                water+=min(prefixsum[i],suffixsum[i])-height[i];
            }
        }
        return water;
        
    }
};