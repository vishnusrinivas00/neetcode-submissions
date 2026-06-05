class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int complement;
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            complement = target-nums[i];
            if(freq.count(complement)){
                return{freq[complement],i};
            }
            freq[nums[i]]=i;
        }
        return {};
    }
};
