class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int,int>freq;

        for(int num : nums){
            freq[num]++;
        }
        for(auto &rem:freq){
            if(rem.second>1){
                return true;
            }    
        }
        return false;
    }
};