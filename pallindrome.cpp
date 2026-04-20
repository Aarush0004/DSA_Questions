#include <bits/stdc++.h>
using namespace std;
bool checkifpalin(vector<int>nums)
{
    int n = nums.size();
    int i=0;
    int j=n-1;
    if(nums.empty())return true;
    while(i<=j)
    {
        if(nums[i]==nums[j])
        {
            i++;
            j--;
        }
        else return false;
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    if(checkifpalin(arr)==true)
    {
        cout<<"yes it is a palindrome";
    }
    else cout<<"no it is not a palindrome";
    return 0;
     
}
