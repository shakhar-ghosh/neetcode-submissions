class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        unordered_map<int,int> prefix, suffix;
        int len = nums.size();
        prefix[0] = nums[0];
        suffix[len-1] = nums[len-1];
        for(int i=1; i<len; i++) {
            prefix[i] = prefix[i-1] * nums[i];
            suffix[len-i-1] = suffix[len-i] * nums[len-i-1];
        }
        vector<int> ret(len);
        ret[0] = suffix[1];
        ret[len-1] = prefix[len-2];
        for(int i=1; i<len-1; i++) {
            ret[i] = prefix[i-1] * suffix[i+1];
        }
        return ret;
    }
};
