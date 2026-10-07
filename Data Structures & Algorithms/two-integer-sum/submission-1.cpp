class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        vector<int> ret;
        for(int i=0; i< nums.size(); i++)
            mp[nums[i]] = i + 1;
        for(int i=0; i< nums.size(); i++)
        {
            if(mp.contains(target - nums[i]) && mp[target - nums[i]] != i+1) 
            {
                ret.push_back(i>(mp[target - nums[i]]-1)?(mp[target - nums[i]]-1):i);
                ret.push_back(i<(mp[target - nums[i]]-1)?(mp[target - nums[i]]-1):i);
                break;
            }
        }
        return ret;
    }
};
