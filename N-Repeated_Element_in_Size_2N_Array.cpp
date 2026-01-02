class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        int size = n/2;
        unordered_map<int,int>mpp;

        for(int i=0;i<n;i++)
        {
         mpp[nums[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(mpp[nums[i]]==size)
            {
                return nums[i];
            }
        }
        return -1;
    }
};
