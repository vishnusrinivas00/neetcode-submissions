class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>freq;
        int max_length=0,left=0;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            while(freq.count(c))
            {
                freq.erase(s[left]);
                left++;
            }
            freq.insert(s[i]);
            max_length=max(max_length,i-left+1);
        }
        return max_length;
    }
};
