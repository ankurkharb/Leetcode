class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        stack<char> st;
        string ans="";
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            if(ch=='(')
            {
                if(!st.empty()) // meaning this is not a outer bracket
                {
                    ans.push_back(ch); // hence add this to ans
                }
                st.push(ch);
            }
            else
            {
                st.pop();
                if(!st.empty())
                {
                    ans.push_back(ch);
                }
            }
        }
        return ans;
    }
};