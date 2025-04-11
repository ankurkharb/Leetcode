class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> v(k);
        int n = arr.size();
        if(x<arr[0])
        {
            for(int i=0;i<k;i++)
            {
                v[i]=arr[i];
            }
            return v;
        }
        if(x>arr[n-1])
        {
            int i = n-1;
            int j = k-1;
            while(j>=0)
            {
                v[j]=arr[i];
                i--;
                j--;
            }
            return v;
        }
        int low = 0;
        int high=n-1;
        bool flag = false; // if x is present or not
        int t=0; //index of ans
        int mid=-1;
        //BINARY SEARCH
        while(low<=high)
        {
            mid = low+(high-low)/2;
            if(arr[mid]==x)
            {
                flag= true; // present
                v[t]=arr[mid];
                t++;
                break;
            }
            else if(arr[mid]<x)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        int lb=high;
        int ub=low;
        if(flag==true)
        {
            lb=mid-1;
            ub=mid+1;
        }
        while(t<k && lb>=0 && ub<=n-1)
        {
            int diff1 = abs(x-arr[lb]);
            int diff2 = abs(x-arr[ub]);
            if(diff1<=diff2)
            {
                v[t]=arr[lb];
                lb--;
            }
            else
            {
                v[t]=arr[ub];
                ub++;
            }
            t++;
        }
        if(lb<0)
        {
            while(t<k)
            {
                v[t]=arr[ub];
                ub++;
                t++;
            }
        }
        if(ub>n-1)
        {
            while(t<k)
            {
                v[t]=arr[lb];
                t++;
                lb--;
            }
        }
        sort(v.begin(),v.end());
        return v;

    }
};