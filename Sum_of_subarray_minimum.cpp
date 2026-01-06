class Solution {
    private:
    vector<int> nextsmaller(vector<int> &nums)
    {
        int n =nums.size();
        vector<int>ans(n);
        stack<int>stk;
        int i=n-1;
        for(int i=n-1;i>=0;i--)
        {
        while(!stk.empty() && nums[stk.top()]>=nums[i])
        {
            stk.pop();
        }
        ans[i]=stk.empty() ? n:stk.top();
        stk.push(i);
        }
        return ans;
    }
    vector<int> prevsmaller(vector<int> &nums)
    {
        int n =nums.size();
        vector<int>ans(n);
        stack<int>stk;
        for(int i=0;i<n;i++)
        {
        while(!stk.empty() && nums[stk.top()]>nums[i])
        {
            stk.pop();
        }
        ans[i]= stk.empty()?-1:stk.top();
        stk.push(i); 
    }
    return ans;
}
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n =arr.size();
        int MOD=1e9 + 7;
        vector<int>nse=nextsmaller(arr);
        vector<int>pse=prevsmaller(arr);
        long long ans =0;
        for(int i=0;i<n;i++)
        {
            long long left=i-pse[i];
            long long right=nse[i]-i;
             ans=(ans+(left*right*arr[i]))%MOD;
        }
       return ans;
    }
};
