class Solution {
public:
    int characterReplacement(string s, int k) {
      unordered_map<char,int>freq;
      int left=0,max_len=0,max_count=0;  
      for(int i=0;i<s.size();i++){
        char c=s[i];
        freq[c]++;
        max_count=max(max_count,freq[c]);
      
      while((i-left+1)-max_count>k){
        freq[s[left]]--;
        left++;
      }
      max_len=max(max_len,i-left+1);
      }
      return max_len;
    }
};
