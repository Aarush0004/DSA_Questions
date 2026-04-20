#include <bits/stdc++.h>
using namespace std;

void merge(int low, int mid, int high, vector<int> &nums)
{
    vector<int> ans;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (nums[left] <= nums[right])
        {
            ans.push_back(nums[left++]);
        }
        else
        {
            ans.push_back(nums[right++]);
        }
    }

    while (left <= mid)
        ans.push_back(nums[left++]);

    while (right <= high)
        ans.push_back(nums[right++]);

    for (int i = low; i <= high; i++)
    {
        nums[i] = ans[i - low];
    }
}

void msort(int low, int high, vector<int> &nums)
{
    if (low >= high) return;

    int mid = (low + high) / 2;

    msort(low, mid, nums);
    msort(mid + 1, high, nums);

    merge(low, mid, high, nums);
}

int main()
{
    int n;
    cout << "Enter Size of Array: ";
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    msort(0, n - 1, nums);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}
