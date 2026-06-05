using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            int counter_target=target-nums[i];
            if(freq.count(counter_target)){
                return {freq[counter_target],i};
            }
            freq[nums[i]]=i;
        }
                    return {};
        }
        };
