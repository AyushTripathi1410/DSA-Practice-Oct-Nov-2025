class Solution {
  public:
   void p(int i , int n){
       if(i>n) return;
       cout<<i<<" ";
       p(i+1,n);
   }
    void printTillN(int n) {
        // code here
      return  p(1,n);
    }
};
