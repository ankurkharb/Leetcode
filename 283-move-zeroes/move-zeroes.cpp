class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n = arr.size();
        int i=0;
        int j =0;
         while(i<n && arr[i]!=0)
            {
                i++;
            }
        for(int j=i+1;j<n;j++)
        {
           
            if(arr[j]!=0)
            {
                swap(arr[i],arr[j]);
                i++;
            }
        }
    }
};