class Solution {
public:
    int minimumDeletions(vector<int>& A) {
        int n = A.size();
        int low = 0, high = 0;

        for (int i = 0; i < n; i++) {
            if (A[i] > A[high]) high = i;
            if (A[i] < A[low])  low = i;
        }

        if (low > high) swap(low, high);

        int left = high + 1;              
        int right = n - low;              
        int both = (low + 1) + (n - high); 

        return min({left, right, both});
    }
};
