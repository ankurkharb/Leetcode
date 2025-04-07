class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int i=0;i<s.size();i++)
        {
            if(s==goal)return true;
            reverse(s.begin(),s.end());
            reverse(s.begin(),s.end()-1);
        }
        return false;
    }
};