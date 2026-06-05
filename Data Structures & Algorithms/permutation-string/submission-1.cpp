class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>freq;
        unordered_map<char,int>window;
        for(int i=0;i<s1.size();i++){
            char c=s1[i];
            freq[c]++;
        }
        for(int i=0;i<s1.size();i++){
            window[s2[i]]++;
        }
        if(window==freq){
            return true;
        }
        for(int i=s1.size();i<s2.size();i++){
            char n=s2[i];
            char m=s2[i-s1.size()];
            window[n]++;
            window[m]--;
            if(window[m] == 0) window.erase(m);
            if(window==freq){
            return true;
        }

        }
        return false;
    }
};
