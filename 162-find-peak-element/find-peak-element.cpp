class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();
        int low=0;
        int high=n-1;
        // if(arr[0]>arr[1])return arr[0];
        // if(arr[n-1])>arr[n-2]return arr[n-1];
        while(low<high)
        {
            int mid = low+(high-low)/2;
           // if(mid>0 && mid<n-1 &&  arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])return mid;
            if(arr[mid]<arr[mid+1])
            {
                low=mid+1;
            }
            else
            {
                high=mid;
            }
          
        }
        return low;
    }
}; 