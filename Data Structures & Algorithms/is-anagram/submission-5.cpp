class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<char>hello(26,0);
        if(s.size()!=t.size()){
            return false;
        }
        for(char c:s){hello[c-'a']++;}
        for(char c:t){hello[c-'a']--;}

        for(int i:hello){
            if(i!=0){
                return false;
            }
        }
        return true;

    }
};
