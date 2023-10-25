class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        map<int,int> fre;
        for(auto x:nums){
            fre[x]++;
        }
        
        vector<int> groups;
        for(auto x:fre){
            groups.push_back(x.second);
        }
        if(groups.size() == 1) return 1;
        int x = *min_element(groups.begin(),groups.end());

        int l=max(1,x-1), r = x+1, ans = nums.size();
        
        for(int mid=1;mid<=r;mid++){
            int res = 0;
            bool f = true;
            
            for(auto x:groups){
                int tmp = x;
                int cur = 0;
                while(tmp > 0){
                    if(tmp%mid == 0) {
                        res += tmp/mid;
                        tmp = 0;
                        break;
                    }
                    else{
                        if(tmp >= mid-1){
                            tmp -= (mid -1);
                            res++;
                        }
                        else {
                            f = false;
                            break;
                        }
                    }
                }
                if(f == false) break;
            }

            if(f){
                ans = min(ans, res);
                l = mid + 1;
            }
        }
        return ans;
    }
};