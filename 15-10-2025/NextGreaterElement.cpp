class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        vector<int>ans;
        for(auto num:nums1){
            st.push(num);
        }
        while(!st.empty()){
            int ele=st.top();
            st.pop();
            int j=-1;
            for(int i=0;i<nums2.size();i++){
                if(ele==nums2[i]){
                   j=i;
                   break; 
                    
                }
            }
            bool flag =0;
            for(int k=j;k<nums2.size();k++){
                if(nums2[k]>ele){
                    flag=1;
                    ans.push_back(nums2[k]);
                    break;
                }

            }
            if(flag==0){
                ans.push_back(-1);
            }
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
