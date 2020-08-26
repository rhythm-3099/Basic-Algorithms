class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int i,j,k,n=nums.size();
        vector<int>ans(n);
        ans[0]=1;
        k=1;
        for(i=1;i<n;i++){
            k*=nums[i-1];
            ans[i]=k;
        }
        k=1;
        for(i=n-1;i>=0;i--){
            ans[i]*=k;
            k*=nums[i];
        }
        return ans;
    }
};