class Solution {
  public:
  
  vector<string>ans;
  void helper(string &s,int idx,vector<string> &temp,unordered_set<string>&dict_set){
      if(idx==s.size()){
          string sentence;
          for(int j=0;j<temp.size();j++){
              sentence+=temp[j];
              if(j!=temp.size()-1){
                  sentence+=" ";//for space 
              }
          }
          ans.push_back(sentence);
          return;
      }
      string word;
      for(int i=idx;i<s.size();i++){
          word+=s[i];
          if(dict_set.find(word)!=dict_set.end()){
              temp.push_back(word);
              helper(s,i+1,temp,dict_set);
              temp.pop_back();
          }
      }
  }
    vector<string> wordBreak(vector<string>& dict, string s) {
        // code here
        vector<string> temp;
        unordered_set<string>dict_set;
        for(int i=0;i<dict.size();i++){
            dict_set.insert(dict[i]);
        }
        helper(s,0,temp,dict_set);
        return ans;
    }
};
