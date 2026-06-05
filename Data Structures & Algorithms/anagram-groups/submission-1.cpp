using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>freq;
        for(string c :strs){
            string word =c;
            sort(word.begin(),word.end());
            freq[word].push_back(c);

        }
        vector<vector<string>>result;
        for(auto &rem:freq){
            result.push_back(rem.second);
        }
        return result;
    }
};
