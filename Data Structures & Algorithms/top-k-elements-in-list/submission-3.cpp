class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;

        for(int num:nums){
            freq[num]++;
        }
        priority_queue<pair<int,int>> pq;

        for(auto &rem:freq){
            pq.push({rem.second,rem.first});
        }
        vector<int>result;
        for(int i=0;i<k;i++){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};
