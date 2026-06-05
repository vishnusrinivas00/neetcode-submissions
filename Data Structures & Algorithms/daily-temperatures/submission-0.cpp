class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n= temperatures.size();
        vector<int>result(n,0);
        stack<int>freq;

        for(int i=0;i<n;i++){
            while(!freq.empty() && temperatures[i]>temperatures[freq.top()]){
                int previous = freq.top();
                freq.pop();
                result[previous]=i-previous;
            }
            freq.push(i);
        }
        return result;
    }
};
