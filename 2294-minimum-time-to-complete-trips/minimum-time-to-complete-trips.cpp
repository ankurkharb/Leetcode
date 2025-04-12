class Solution {
public:
    bool ispossible(long long mid,vector<int>& time, int totalTrips)
    {
        long long trips=0; //count
        int n = time.size();
        for(int i=0;i<n;i++)
        {
            trips+= mid/time[i];
        }
        if(trips<totalTrips) return false;
        else return true;

    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n =time.size();
        long long mx =*max_element(time.begin(),time.end());
        long long high = mx * (long long)totalTrips;
        long low = 1;
        long ans = high;
        while(low<=high)
        {
            long long mid = low+(high-low)/2;
            if(ispossible(mid,time,totalTrips))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid+1;
            }
        }
        return ans;
    }
};