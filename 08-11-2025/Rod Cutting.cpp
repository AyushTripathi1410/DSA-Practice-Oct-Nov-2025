class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<int> dp(n+1, 0);

        for (int len = 1; len <= n; len++) {    
            for (int cut = 1; cut <= len; cut++) { 
                dp[len] = max(dp[len], price[cut-1] + dp[len - cut]);
            }
        }

        return dp[n];
    }
};
