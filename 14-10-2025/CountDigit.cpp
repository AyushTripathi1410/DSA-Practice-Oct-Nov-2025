class Solution {
  public:
    // Function to count the number of digits in n that evenly divide n
    int evenlyDivides(int n) {
        // code here
        int i=n;
        int count=0;
        while(i>0){
            int digit=i%10;
            
            if(digit!=0 && n%digit==0){
                count++;
            }
            i/=10;
        }
        return count;
    }
};
