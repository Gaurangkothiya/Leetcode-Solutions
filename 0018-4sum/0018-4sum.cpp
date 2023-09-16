class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        set<vector<int>> anss;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                long sum = (long)target - nums[i] - nums[j];
                int l = j+1, r = n-1;
                while(l<r){
                    int res = nums[l] + nums[r];
                    if(res < sum) l++;
                    else if(res > sum) r--;
                    else{
                        anss.insert({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                    }
                }
            }
        }
        for(auto x: anss) ans.push_back(x);
        return ans;
    }
};