class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n), post(n);
        pre[0] = nums[0];
        post[n-1] = nums[n-1];
        for(int i=1;i<n;i++) pre[i] = min(pre[i-1],nums[i]);
        for(int i=n-2;i>=2;i--) post[i] = min(post[i+1],nums[i]);
        int ans = 1000000000;
        for(int i=1;i<n-1;i++){
            if(pre[i-1]<nums[i] && post[i+1]<nums[i]) ans = min(ans, pre[i-1]+nums[i]+post[i+1]);
        }
        if(ans == 1000000000) ans = -1;
        return ans;
    }
};