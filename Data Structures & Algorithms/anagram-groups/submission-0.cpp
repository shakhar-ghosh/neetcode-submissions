
class Solution {
public:
    string signature(string str) {
        int freq[28] = {0};
        string sign;
        for(int i=0; i< str.size(); i++) {
            freq[str[i]-'a']++;
        }
        for(int i=0; i<26; i++)
        {
            sign.push_back(char(i+'a'));
            sign.push_back(freq[i]);
        }
        return sign;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        map<string, vector<int>> mp;
        for(int i=0; i< strs.size(); i++)
        {
            mp[signature(strs[i])].push_back(i);
        }
        for(const auto& [sign, idx_vector]: mp) 
        {
            vector<string> curr;
            for(int i=0; i<idx_vector.size(); i++)
                curr.push_back(strs[idx_vector[i]]);
            ret.push_back(curr);
        }
        return ret;
    }
};
