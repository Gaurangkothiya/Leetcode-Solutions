class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int max_dif = 99999999, ans = -1;
        for(int i=0;i<n-2;i++){
            int l = i+1, r = n-1;
            while(l<r){
                int res = nums[i] + nums[l] + nums[r];
                if(abs(res-target) < max_dif){
                    max_dif = abs(res - target);
                    ans = res;
                }
                if(res < target) l++;
                else r--;
            }
        }
        return ans;   
    }
};