class Solution {
public:
    string largestOddNumber(string num) {
        string str="";
        for(int i =num.size()-1;i>=0;i--)
        {
            if((num[i]-'0')%2!=0)
            {
                str =num.substr(0,i+1);
                return str;
            }
        }
        return str;
    }
};