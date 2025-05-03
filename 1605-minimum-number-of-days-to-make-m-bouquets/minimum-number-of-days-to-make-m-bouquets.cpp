bool ispossible(vector<int>& bloomDay, int bouquet, int flowers,long long mid)
{
    long long n = bloomDay.size();
    long long bouNo = 0;
     long long count=0;
    for(long long i=0;i<n;i++)
    {
        if(bloomDay[i]<=mid)
            count++;
    
        else
        {
            bouNo+=count/(long long)(flowers);
            count=0;
        }
    }
    bouNo+=count/(long long)(flowers); // agr koi chota nai aya and array finish hogya to last wale elements
    if(bouNo>=(long long)bouquet)
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
    int minDays(vector<int>& bloomDay, int m, int k) {// m bouquet bnane h , k adjacent flowers
    long long n = bloomDay.size();
    long long val = m *1LL *k *1LL;
    if(val>n)return -1;
        int low =  *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(low<=high)
        {
            long long mid=low+(high-low)/2;
            if(ispossible(bloomDay,m,k,mid))
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