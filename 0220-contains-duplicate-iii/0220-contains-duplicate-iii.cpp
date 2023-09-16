class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<int,vector<int>> bucket;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int bucketId = (nums[i]/(t+1));
            if(nums[i] < 0) bucketId--;
            for(int buck=bucketId-1;buck<=bucketId+1;buck++){
                if(bucket[buck].size() > 0){
                    for(auto x: bucket[buck]){
                        if (abs(x-nums[i]) <= t) return true;
                    }
                }
            }
            bucket[bucketId].push_back(nums[i]);
            if(i>=k){
                int buckId = (nums[i-k]/(t+1));
                bucket[buckId].clear();
            }
        }
        return false;
    }
};