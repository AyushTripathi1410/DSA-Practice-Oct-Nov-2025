class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        for(int i:nums){
            sum+=i;
        }
        int s=0;
        for(int i=0;i<nums.size();i++){
            if(s+s==sum-nums[i]){
                return i;
            }
            else{
                s+=nums[i];
            }
        }
        return -1;
    }
};
