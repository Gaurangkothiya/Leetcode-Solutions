class Solution {
public:
    long long maximumSum(vector<int>& nums) {
        int n = nums.size();
        int prime[10005];
        prime[2] = prime[3] = 0;
        for(int i=2;i<=10000;i++){
            if(prime[i] == 0){
                for(int j= 2*i;j<=10000;j += i) prime[j] = 1;
            }
        }
        long long int ans = 0;
        int vis[10005] = {0};
        for(int i=1;i<=n;i++){
            ans = max(ans, 1LL*nums[i-1]);
            if(vis[i] == 0){
                long long int res = 0;
                long long int f = 1, id = f*f*i;
                while(id <= n){
                    res += nums[id-1];
                    vis[id] = 1;
                    f++;
                    id = f*f*i;
                }
                ans = max(ans,res);
            }
        }
        return ans;
    }
};