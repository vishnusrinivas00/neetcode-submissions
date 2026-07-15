class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>>freq;
        for(string s:strs){
            string word = s;
            sort(word.begin(),word.end());
            freq[word].push_back(s);
        }
        vector<vector<string>> result;
        for(auto &rem:freq){
            result.push_back(rem.second);
        }
        return result;
    }
};
