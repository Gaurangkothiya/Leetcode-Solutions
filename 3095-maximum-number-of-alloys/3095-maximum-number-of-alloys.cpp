class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int ans = 0;
        long long int bg = budget; 
        for(int k1=0;k1<k;k1++){
            int res = 0, l=0, r = 1000000000;
            while(l<=r){
                int mid = (l+r)/2;
                vector<long long int> need(n);
                
                for(int i=0;i<n;i++){
                    need[i] = 1LL*composition[k1][i]*mid - stock[i];
                    if(need[i] < 0) need[i] = 0;
                }
                long long int rescost = 0;
                for(int i=0;i<n;i++){
                    rescost += 1LL * (need[i])* (cost[i]);
                }
                if(rescost <= bg){
                    res = max(res, mid);
                    l = mid+1;
                }
                else{
                    r = mid - 1;
                }
            }
            ans = max(ans, res);
        }
        return ans;
    }
};