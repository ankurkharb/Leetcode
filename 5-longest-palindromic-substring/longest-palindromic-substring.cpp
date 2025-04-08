class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxlen=1;
        int start=0;
        int l,r;
        if (n == 0) return "";
        if (n == 1) return s;
        for(int i =1 ;i<s.size();i++)
        {
            l=i-1;
            r=i;
            while(l>=0 && r<n && s[l]==s[r] )
            {
                if(r-l+1>maxlen)
                {
                    maxlen=r-l+1;
                    start=l;
                }
                l-=1;
                r+=1;
            }
            //odd
            l=i-1;
            r=i+1;
            while(l>=0 && r<n && s[l]==s[r])
            {
                if(r-l+1>maxlen)
                {
                    maxlen=r-l+1;
                    start=l;
                }
                l-=1;
                r+=1;
            } 
        }
           return s.substr(start,maxlen);
    }
};