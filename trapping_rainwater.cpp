class Solution {
public:
   int trap(vector<int>& height) {
   int n = height.size();
   vector<int>lma(n,0);//remember this!!!!!!!!!!
   vector<int>rma(n,0);//remember this!!!!!!!!!!
   lma[0]=height[0];
   rma[n-1]=height[n-1];
   for(int i=1;i<n;i++)
   {
    lma[i]=max(lma[i-1],height[i]);
   }
   for(int i=n-2;i>=0;i--)
   {
    rma[i]=max(rma[i+1],height[i]);
   }
   int ans=0;
   for(int i=0;i<n;i++)
   {
    int tra=min(lma[i],rma[i])-height[i];
    ans+=tra;
   }
   return ans;
    }
};
