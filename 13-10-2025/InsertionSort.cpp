class Solution {
  public:
    // Please change the array in-place
    void insertionSort(vector<int>& arr) {
        // code here
        for(int i=1;i<arr.size();i++){
            for(int j=i;j>0;j--){
                if(arr[j]<arr[j-1]){
                    swap(arr[j],arr[j-1]);
                }
            }
        }
    }
};
