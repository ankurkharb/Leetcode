#include <sstream>
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string temp;
        string temp1;
        vector<string> str;
        while(ss>>temp)
        {
            str.push_back(temp);
           
        }
        reverse(str.begin(),str.end());
        // temp1;
        for(int i=0;i<str.size();i++)
        {
            temp1+=str[i];
            if(i!=str.size()-1)
                temp1+=" ";
        }
        return temp1;

    }
};