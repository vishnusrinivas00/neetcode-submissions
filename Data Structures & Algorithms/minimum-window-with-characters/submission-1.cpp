class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>need,window;
        int formed=0,left=0,right=0;
        int min_length=INT_MAX;
        int start;
        for(char c:t){
            need[c]++;
        }
        int required=need.size();

        while(right<s.size()){
            char c=s[right];
            window[c]++;

            if(need.count(c)&&window[c]==need[c]){
                formed++;
            }
            while(left<=right&&formed==required){
                if(right-left+1<min_length){
                    min_length=right-left+1;
                    start=left;
                }
                char lefty=s[left];
                window[lefty]--;
                if(need.count(lefty)&&window[lefty]<need[lefty]){
                    formed--;
                }
                left++;
            }
            right++;
        }
        return(min_length==INT_MAX)? "":s.substr(start,min_length);
    }
};
