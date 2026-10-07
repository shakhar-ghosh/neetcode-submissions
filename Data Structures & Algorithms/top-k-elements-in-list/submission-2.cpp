class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;
        vector<pair<int,int>> values;
        unordered_map<int, int> mp;
        for(int i = 0; i< nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        for(const auto& [val, count]: mp)
            values.push_back(pair<int,int>(count,val));
        sort(values.begin(),values.end(), [](const auto& a, const auto& b){
            return a.first > b.first;
        });
        for(int i=0; i<k;i++)
            ret.push_back(values[i].second);
        return ret;
    }
};
