class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> hello;

        for(int num:nums){
            if(hello.count(num)){
                return true;
            }
            hello.insert(num);
        }
        return false;
    }
};