class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> nega;
        vector<int> posi;
        vector<int> neu;
        for(int num:nums)
        {
            if(num<0)
                nega.push_back(num);
            else
                posi.push_back(num);
        }
        int i=0,j=0;
        while(i<n/2 && j<n/2){
            neu.push_back(posi[i]);
            i++;
            neu.push_back(nega[j]);
            j++;
        }
        return neu;
    
    }
};