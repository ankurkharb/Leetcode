class Solution {
public:
    bool isperfectsquare(int n)
    {
        int root = sqrt(n);
        if(root*root == n)return true;
        else return false;

    }
    bool judgeSquareSum(int c) {
        int x =0;
        int y = c;
        while(x<=y)
        {
            if(isperfectsquare(x) && isperfectsquare(y))
            {
                return true;
            }
            else if(!isperfectsquare(y))
            {
                y=(int)sqrt(y)*(int)sqrt(y);
                x=c-y;
            }
            else // x is not perfect
            {
                x = ((int)sqrt(x)+1) * ((int)sqrt(x)+1); // x ko aage badhara
                y = c-x;
            }
        }
        return false;

    }
};