class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0 ,  max_length=0, result=0 ;
        unordered_map<char,int>freq;

        for(int right=0;right<s.size();right++){
            freq[s[right]]++;
            max_length = max(max_length,freq[s[right]]);
        
        if((right-left+1)-max_length>k){
            freq[s[left]]--;
            left++;
        }

        result = max(result,right-left+1);
        }
        return result;
    }
};
