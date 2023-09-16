class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size();
        map<int,int> vis;
        for(int i=0;i<n;i++) vis[nums[i]]++;
        int ans = n&1;
        for(auto x: vis){
            ans = max(ans, 2*x.second - n);
        }
        return ans;
    }
};