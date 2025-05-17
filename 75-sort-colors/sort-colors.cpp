class Solution {
public:
    void sortColors(vector<int>& arr) { // 0 to low-1 will be 0 
                                         // low to mid-1 wil be 1
                                         // high+1 to n-1 will be 2
                                         // mid to high is unsorted
    int n = arr.size();
    int low =0;
    int mid = 0;
    
    int high =n-1;
    while(mid<=high){
        if(arr[mid]==0)
        {
            swap(arr[low],arr[mid]);
            mid++;
            low++;
        }
        else if(arr[mid]==1)
        {
            mid++;

        }
        else if(arr[mid]==2)
        {
            swap(arr[mid],arr[high]);
            high--;
        }
    }

        
    }
};