class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> tail;       
        vector<int> tailIndex;        
        vector<int> parent(n, -1);        

        for (int i = 0; i < n; i++) {

            int x = arr[i];
            int pos = lower_bound(tail.begin(), tail.end(), x) - tail.begin();
            if (pos == tail.size()) {
                tail.push_back(x);
                tailIndex.push_back(i);
            }
            else {
                tail[pos] = x;
                tailIndex[pos] = i;
            }

            if (pos != 0)
                parent[i] = tailIndex[pos - 1];
        }

        vector<int> lis;
        int lastIndex = tailIndex.back();

        while (lastIndex != -1) {
            lis.push_back(arr[lastIndex]);
            lastIndex = parent[lastIndex];
        }

        reverse(lis.begin(), lis.end());
        return lis;
    }
};
