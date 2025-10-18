class Solution {
  public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr) {
        // code here
        for(int i=0;i<arr.size()-1;i++){
            int index = i;
            for(int j=i+1;j<arr.size();j++){
                if(arr[j]<arr[index]){
                    swap(arr[j],arr[index]);
                }
            }
        }
    }
};
