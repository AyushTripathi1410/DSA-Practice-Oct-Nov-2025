class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int>par(n), dp(n,1);
        for(int i=0;i<n;i++) par[i] = i;
        
        int ans = 1, st = 0;
        
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=0;j--){
                if(arr[i]>arr[j] && dp[j] <= 1 + dp[i]){
                    dp[j] = 1 + dp[i];
                    par[j] = i;
                }
                if(dp[j]>=ans){
                    ans = dp[j], st = j;
                }
            }
        }
        
        vector<int> temp;
        while(par[st]!=st) {
            temp.push_back(arr[st]);
            st = par[st];
        }
        temp.push_back(arr[st]);
        
        return temp;
    }
};
