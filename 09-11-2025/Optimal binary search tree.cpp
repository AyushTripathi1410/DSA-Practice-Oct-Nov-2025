class Solution {
  public:
    int optimalSearchTree(int keys[], int freq[], int n) {
        // code here
        vector<vector<int>>v(n, vector<int>(n,0));
        vector<int>vp(n+1,0);
        for(int i=0;i<n; i++){
            vp[i+1]=vp[i]+freq[i];
        }
        
        for(int i=0; i<n; i++){
            v[i][i]=freq[i];
        }
        
        for(int l=2; l<n+1; l++){
            for(int i=0; i<n+1-l; i++){
                int j=i+l-1;
                v[i][j]=INT_MAX;
                for(int k=i; k<=j; k++){
                    int l= (k>i?v[i][k-1]: 0);
                    int r= (k<j?v[k+1][j]: 0);
                    v[i][j] = min (v[i][j], l+r+vp[j+1]-vp[i]);
                }
            }
        }
        return v[0][n-1];
    }
};
