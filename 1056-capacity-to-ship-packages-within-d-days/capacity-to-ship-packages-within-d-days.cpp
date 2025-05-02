bool ispossible(vector<int>& weights, int days,int capacity)
{
    int n = weights.size();
    int count=1;
    int cap=capacity;
    for(int i=0;i<n;i++)
    {
        if(cap-weights[i]>=0)
        {
            cap-=weights[i];
        }
        else
        {
            count++;
            cap=capacity;
            cap-=weights[i];
        }
        
    }
    if(count<=days)
        {
            return true;

        }
        else
        {
            return false;
        }
}
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int sum;
        int mx=-1;
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            mx=max(mx,weights[i]);
            sum+=weights[i];
        }
        int low = mx;
        int high= sum;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(ispossible(weights,days,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};