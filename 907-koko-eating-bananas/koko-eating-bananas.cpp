bool ispossible(vector<int>& piles, int h,int speed)
{
    int n = piles.size();
    long long count=0;

    for(int i =0;i<n;i++)
    {
        if(speed>=piles[i])
        {
            count++;
        }
        else if(piles[i]%speed==0)
        {
            count+=(long long)piles[i]/speed;
        }
        else
        {
            count+=(long long)(piles[i]/speed)+1;
        }
    }
    if(count>(long long)h)
        return false;
    else
    {
        return true;
    }

}
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low =1;
        int mx=0;
        int ans=-1;
        for(int i=0;i<piles.size();i++)
        {
            mx=max(mx,piles[i]);
        }
        int high=mx;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(ispossible(piles,h,mid))
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