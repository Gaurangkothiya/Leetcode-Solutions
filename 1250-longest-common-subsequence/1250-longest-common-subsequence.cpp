class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[1003][1003];
        memset(dp,0,sizeof(dp));
        int n = text1.size(), m = text2.size();
        text1 = "4" + text1;
        text2 = "5" + text2;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i] == text2[j]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[n][m];
    }
};