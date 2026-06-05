class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int>window;
        int left = 0 , right = 0; 
        int max_length = 0;
        while(right<s.size()){
            if(window.find(s[right])==window.end()){
                window.insert(s[right]);
                max_length=max(max_length,right-left+1);
                right++;
            }else{
                window.erase(s[left]);
                left++;
            }
        }
        return max_length;
    }
};
