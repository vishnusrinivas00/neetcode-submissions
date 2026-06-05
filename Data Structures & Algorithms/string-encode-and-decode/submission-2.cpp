using namespace std;

class Solution {
public:
    string encode(vector<string>& strs) {
        string merged;
        for (string s : strs) {
            merged += to_string(s.size()) + "#" + s;
        }
        return merged;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') j++;               // find delimiter
            int len = stoi(s.substr(i, j - i));    // get length
            result.push_back(s.substr(j + 1, len)); // extract string
            i = j + 1 + len;                       // move to next block
        }
        return result;
    }
};
