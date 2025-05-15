class Solution {
public:
    vector<int> getNSL(vector<int>& arr)
    {
        int n = arr.size();
        stack<int> st;
        vector<int> result(n);
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[i]<arr[st.top()])
            {
                st.pop();
            }
            if(st.empty())
            {
                result[i]=-1;
            }
            else
            {
                result[i]=st.top();
            }

            st.push(i);
        }
        return result;

    }
    vector<int> getNSR(vector<int>& arr)
    {
        int n = arr.size();
        stack<int> st;
        vector<int> result(n);
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[i]<=arr[st.top()])
            {
                st.pop();
            }
            if(st.empty())
            {
                result[i]=n;
            }
            else
            {
                result[i]=st.top();
            }
            st.push(i);
        }
        return result;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int Mod = 1000000007;
        long long sum=0;
        vector<int> NSL = getNSL(arr);
        vector<int> NSR = getNSR(arr);
        for(int i=0;i<n;i++)
        {
            long long ls=i-NSL[i];
            long long rs=NSR[i]-i;
            long long totalsubarray = ls*rs;

            long long totalsum=totalsubarray*arr[i];
            sum=(sum+totalsum)%Mod;

        }
        return sum;
        
    }
};