class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> subarray(n);
        subarray[0] = nums[0];
        for (int i = 1; i < n; i++) {
            if (subarray[i - 1] != 0)
                subarray[i] = subarray[i - 1] * nums[i];
            else
                subarray[i] = nums[i];
        }

        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, subarray[i]);
        }
        subarray[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (subarray[i + 1] != 0)
                subarray[i] = subarray[i + 1] * nums[i];
            else
                subarray[i] = nums[i];
        }

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, subarray[i]);
        }

        return maxi;
    }
};
