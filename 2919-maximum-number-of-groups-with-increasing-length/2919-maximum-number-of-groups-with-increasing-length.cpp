class Solution {
public:
    int maxIncreasingGroups(vector<int>& arr) {
        long int ans = 0;
        long int total = 0;
        sort(arr.begin(), arr.end());
        for(int x: arr){
            total += x;
            if(total >= ((ans+1)*(ans+2))/2 ) ans++;
        }
        return ans;
    }
};