class Solution {
    private:
    vector<int> prevsmaller(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> s;
    int i = 0;

    while(i < n)
    {
        if(s.empty())
        {
            ans[i] = -1; //here it will be it should be because it should be!
            s.push(i);
            i++;
        }
        else if(arr[i] > arr[s.top()])
        {
            ans[i] = s.top();
            s.push(i);
            i++;
        }
        else
        {
            s.pop();
        }
    }
    return ans;
}
    vector<int> nextsmaller(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> s;
    int i = n - 1;

    while(i >= 0)
    {
        if(s.empty())
        {
            ans[i] = n; ///if no smaller element automatic size will go till n.
            s.push(i);
            i--;
        }
        else if(arr[i] > arr[s.top()])
        {
            ans[i] = s.top();
            s.push(i);
            i--;
        }
        else
        {
            s.pop();
        }
    }
    return ans;
}
public:
    int largestRectangleArea(vector<int>& nums) {
        int n=nums.size();
        vector<int>nse=nextsmaller(nums);
        vector<int>pse=prevsmaller(nums);
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            int height=nums[i];
            int width=nse[i]-pse[i]-1;
            int area=height*width;
            maxi=max(maxi,area);
        }
        return maxi;
    }
};
//brute force but giving tle
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& nums) {
//         int n = nums.size();
//         int maxi = 0;

//         for(int i = 0; i < n; i++) {
//             int height = nums[i];
//             int len = 1;

//             for(int j = i - 1; j >= 0; j--) {
//                 if(nums[j] >= height)
//                     len++;
//                 else
//                     break;
//             }

//             // check right
//             for(int j = i + 1; j < n; j++) {
//                 if(nums[j] >= height)
//                     len++;
//                 else
//                     break;
//             }

//             int area = height * len;
//             maxi = max(maxi, area);
//         }

//         return maxi;
//     }
// };
