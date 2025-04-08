class Solution {
public:
    int getmax(vector<int> &freq)
    {
        int maxcount=0;
        for(int &count: freq)
        {
            maxcount = max(maxcount,count);
        }
        return maxcount;
    }
    int getmin(vector<int> &freq)
    {
        int mincount = INT_MAX;
         for(int &count: freq)
        {
            if(count!=0)
                mincount = min(mincount,count);
        }
        return mincount;
    }
    int beautySum(string s) {
        int n = s.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            vector<int> freq(26,0);
            for(int j=i;j<n;j++)
            {
                freq[s[j]-'a']++;
                int beauty = getmax(freq)-getmin(freq);
                ans+=beauty;
            }
        }
        return ans;
    }
};