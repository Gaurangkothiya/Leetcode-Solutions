class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix.size();
        int ans = 9999999;
        if(n == 1){
            for(int i=0;i<m;i++) ans = min(ans, matrix[0][i]);
            return ans;
        }
        for (int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int res = 9999999;
                if(j>0) res = min(res, matrix[i-1][j-1]);
                res = min(res, matrix[i-1][j]);

                if(j+1<m) res = min(res, matrix[i-1][j+1]);
                matrix[i][j] += res;
                
                if(i == n-1) ans = min(ans, matrix[i][j]);
            }
        }
        return ans;
    }
};