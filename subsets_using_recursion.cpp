class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int index=0;
        vector<int>temp;
        vector<vector<int>>ans;
        sets(nums,index,temp,ans);
        return ans;
    }
private:
int sets(vector<int>& nums,int ind, vector<int>&temp,vector<vector<int>>&ans) 
{
    if(ind>=nums.size())
    {
        ans.push_back(temp);
        return;
    }

    //exclude
    sets(nums,ind+1,temp,ans);

    //include
    temp.push_back(nums[ind]);
    sets(nums,ind+1,temp,ans);
    temp.pop_back();
  }   
};
