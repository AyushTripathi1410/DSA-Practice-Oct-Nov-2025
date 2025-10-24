class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        
        sort(arr.begin(), arr.end());  
        sort(dep.begin(), dep.end());  
        
        int platform_needed = 1;  
        int result = 1;          
        int i = 1;
        int j = 0; 
        
        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                platform_needed++;
                i++;
            } else {
                platform_needed--;
                j++;
            }
            result = max(result, platform_needed);
        }
        return result;
    }
};
