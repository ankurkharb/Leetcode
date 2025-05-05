class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();
        int longest =0;
        int current =1;
        int lastsmall=INT_MIN;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++)
        {
            if(arr[i]-1 == lastsmall)
            {
                current++;
                lastsmall=arr[i];
            }else if(arr[i]!=lastsmall)
            {
                current = 1;
                lastsmall = arr[i];
            }
            longest = max(longest,current);
        }
        return longest;
        
    }
};