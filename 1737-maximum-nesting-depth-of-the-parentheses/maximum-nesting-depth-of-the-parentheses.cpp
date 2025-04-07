class Solution {
public:
    int maxDepth(string s) {
        int maxi=0;
        int count=0;
        int i=0;
        string str;
        while(s[i]!='\0')
        {
            if(s[i]=='(')
            {
                count++;
                maxi=max(maxi,count);
            }
            else if(s[i]==')')
            {
                count--;
            }
            i++;
        }
        return maxi;
    }
};